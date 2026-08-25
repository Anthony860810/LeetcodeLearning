# 238. Product of Array Except Self

## Problem

給定一個整數陣列 `nums`，請回傳一個陣列 `answer`，其中：

```text
answer[i] = nums 中除了 nums[i] 以外，其他所有元素的乘積
```

題目要求演算法時間複雜度為 `O(n)`。

### Examples

```text
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

```text
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

### Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

## solution1

這個做法是先計算所有非零元素的乘積，並同時記錄陣列中有幾個 `0`。

因為 `0` 會影響乘積結果，所以要分情況討論。

### Step 1: 統計非零乘積與 zero 數量

```cpp
int product = 1;
int zeros = 0;

for (auto num: nums) {
    if (num != 0)
        product *= num;
    else
        zeros++;
}
```

這裡的 `product` 只乘非零元素。

### Step 2: 如果 zero 超過一個

如果 `nums` 裡面有超過一個 `0`，那每個位置的 product except self 都一定會包含至少一個 `0`。

所以答案會全部都是 `0`：

```cpp
if (zeros > 1)
    return vector<int>(nums.size(), 0);
```

例如：

```text
nums = [1, 0, 3, 0]
output = [0, 0, 0, 0]
```

### Step 3: 如果剛好有一個 zero

如果只有一個 `0`：

- `num == 0` 的位置，答案是所有非零元素的乘積
- 其他位置，因為 product except self 會包含那個 `0`，所以答案是 `0`

例如：

```text
nums = [-1, 1, 0, -3, 3]
非零乘積 = 9
output = [0, 0, 9, 0, 0]
```

### Step 4: 如果沒有 zero

如果沒有 `0`，就可以先算出所有元素的總乘積，再對每個位置除以自己：

```cpp
ans.push_back(product / num);
```

例如：

```text
nums = [1,2,3,4]
product = 24
output = [24/1, 24/2, 24/3, 24/4]
       = [24,12,8,6]
```

## 複雜度

時間複雜度: `O(n)`

- 第一次 loop 統計乘積和 zero 數量
- 第二次 loop 建立答案

空間複雜度: `O(1)`

- 如果不計算 output array，只使用 `product` 和 `zeros` 這些額外變數
- 如果把回傳結果也算進去，則是 `O(n)`

## solution2

`solution2` 是不用除法的做法，使用 prefix product 和 suffix product。

核心想法是：對每個 index `i`，答案可以拆成兩部分：

```text
answer[i] = i 左邊所有元素乘積 * i 右邊所有元素乘積
```

例如：

```text
nums = [1,2,3,4]
```

對 index `2` 來說，也就是 `nums[2] = 3`：

```text
左邊乘積 = 1 * 2
右邊乘積 = 4
answer[2] = 1 * 2 * 4 = 8
```

### Step 1: 建立 left 和 right

`left[i]` 表示從 index `0` 乘到 index `i` 的 prefix product。

`right[i]` 表示從 index `i` 乘到最後一個 index 的 suffix product。

```cpp
vector<int> left(nums.size());
vector<int> right(nums.size());

left[0] = nums[0];
right[end] = nums[end];
```

接著可以在同一個 loop 裡同時建立 `left` 和 `right`：

```cpp
for (int i = 1; i < nums.size(); i++) {
    left[i] = left[i - 1] * nums[i];
    right[end - i] = right[end - i + 1] * nums[end - i];
}
```

### Step 2: 建立答案

第一個位置沒有左邊元素，所以答案是右邊全部元素的乘積：

```cpp
res[0] = right[1];
```

最後一個位置沒有右邊元素，所以答案是左邊全部元素的乘積：

```cpp
res[end] = left[end - 1];
```

中間的位置則是：

```cpp
res[i] = left[i - 1] * right[i + 1];
```

也就是左邊所有元素乘積乘上右邊所有元素乘積，不包含自己。

### 為什麼這個方法能處理 zero？

因為這個方法沒有使用除法，只是直接把「自己左邊」和「自己右邊」的元素相乘。

所以就算陣列中有 `0`，prefix / suffix product 也會自然把 `0` 的影響帶進結果，不需要另外分 `zeros == 0`、`zeros == 1`、`zeros > 1`。

## 複雜度

時間複雜度: `O(n)`

- 建立 `left` 和 `right` 是 `O(n)`
- 建立 `res` 是 `O(n)`

空間複雜度: `O(n)`

- `left` 需要 `O(n)`
- `right` 需要 `O(n)`
- 如果不計算 output array，額外空間是 `O(n)`

## solution3

`solution3` 是 `solution2` 的空間優化版。

`solution2` 使用兩個額外陣列：

```text
left[i]  = index 0 到 i 的乘積
right[i] = index i 到最後的乘積
```

但其實不一定要另外開 `left` 和 `right`。我們可以直接把左邊乘積先存在 `res` 裡，再用一個變數 `right` 從右往左補上右邊乘積。

### Step 1: 先在 res 中建立左邊乘積

`res[i]` 先代表 `i` 左邊所有元素的乘積。

```cpp
res[1] = nums[0];

for (int i = 2; i < nums.size(); i++) {
    res[i] = res[i - 1] * nums[i - 1];
}
```

例如：

```text
nums = [1,2,3,4]
```

建立左邊乘積後：

```text
res[1] = 1
res[2] = 1 * 2 = 2
res[3] = 1 * 2 * 3 = 6
```

也就是：

```text
res = [?, 1, 2, 6]
```

`res[0]` 因為左邊沒有元素，所以先設成 `1`，代表空乘積：

```cpp
res[0] = 1;
```

### Step 2: 用 right 從右往左補上右邊乘積

```cpp
int right = nums[nums.size() - 1];

for (int i = nums.size() - 2; i >= 0; i--) {
    res[i] *= right;
    right *= nums[i];
}
```

`right` 代表目前 index 右邊所有元素的乘積。

每次做：

```cpp
res[i] *= right;
```

就是把左邊乘積乘上右邊乘積。

接著更新：

```cpp
right *= nums[i];
```

讓 `right` 往左擴大一格。

因為 loop 會一路跑到 `i == 0`，所以 `res[0]` 也會用同一套規則乘上右邊所有元素的乘積，不需要額外在最後特別處理。

### 複雜度

時間複雜度: `O(n)`

- 從左到右建立左邊乘積
- 從右到左補上右邊乘積

空間複雜度: `O(1)`

- 如果不計算 output array，只額外使用一個 `right` 變數
- 如果把 output array 也算進去，則是 `O(n)`

## Challenge

`solution1` 邏輯是正確的，而且有完整處理 `0` 的情況，比單純 `product / nums[i]` 更安全。

不過要注意：LeetCode 238 的標準題目要求通常包含「不能使用除法」。`solution2` 和 `solution3` 都符合這個限制，因為它們只用 prefix product 和 suffix product。

可以思考：

- `solution2` 使用兩個額外陣列 `left` 和 `right`，空間是 `O(n)`
- `solution3` 已經把左邊乘積直接存在 `res` 裡，並用一個 `right` 變數處理右邊乘積
- 目前 `solution3` 已經先讓 `res[0] = 1`，再統一處理所有 index，邊界比前一版更少

## Hints for Optimization

- 可以比較 `solution2` 和 `solution3`：兩者時間都是 `O(n)`，但 `solution3` 把額外空間從 `O(n)` 降到 `O(1)`。
- 正式提交時記得移除 debug `cout`，避免影響判題輸出。
- 可以再想想是否能把第一段建立左邊乘積也寫成從 `i = 0` 開始的統一形式。
