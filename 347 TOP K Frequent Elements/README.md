# 347. Top K Frequent Elements

## Problem

給定一個整數陣列 `nums` 和一個整數 `k`，請回傳出現頻率最高的 `k` 個元素。

題目保證答案唯一，回傳順序可以不同。

### Examples

```text
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

```text
Input: nums = [1], k = 1
Output: [1]
```

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`
- The answer is guaranteed to be unique.

## solution1

這個做法分成兩個步驟：

1. 使用 `unordered_map<int, int>` 統計每個數字出現的次數
2. 使用 `priority_queue<pair<int, int>>`，依照出現次數由大到小取出前 `k` 個元素

### Step 1: 統計頻率

目前的寫法是：

```cpp
for (auto num: nums)
    map[num]++;
```

`unordered_map` 的 key 是數字本身，value 是出現次數。

例如：

```text
nums = [1,1,1,2,2,3]
```

統計後會得到：

```text
1 -> 3
2 -> 2
3 -> 1
```

你提供的寫法也可以：

```cpp
bool ret = dic.insert({num, 1}).second;
if (!ret) {
    dic[num]++;
}
```

意思是先嘗試把 `num` 以 count `1` 插入 map。

- 如果 `.second` 是 `true`，代表這個數字第一次出現，插入成功
- 如果 `.second` 是 `false`，代表這個數字已經存在，需要把 count 加一

不過在這題裡，`map[num]++` 更簡潔，也更常見。

### Step 2: 使用 max heap

接著把 map 裡的資料放進 priority queue：

```cpp
for (auto element: map)
    queue.push({element.second, element.first});
```

這裡放進 heap 的 pair 是：

```text
{frequency, number}
```

因為 C++ 的 `priority_queue<pair<int, int>>` 預設是 max heap，會先比較 pair 的 `.first`，也就是 frequency。因此出現次數越高的元素會越接近 top。

最後取出前 `k` 個：

```cpp
while (k > 0) {
    ans.push_back(queue.top().second);
    queue.pop();
    k--;
}
```

`queue.top().second` 是原本的數字。

## 複雜度

假設：

- `n` 是 `nums` 的長度
- `m` 是不同數字的數量

時間複雜度：

- 統計頻率需要 `O(n)`
- 把 `m` 個不同數字放進 heap，每次 push 是 `O(log m)`，所以是 `O(m log m)`
- 取出 `k` 個元素，每次 pop 是 `O(log m)`，所以是 `O(k log m)`
- 總時間複雜度是 `O(n + m log m + k log m)`
- 因為 `m <= n`，通常也可以寫成 `O(n log n)`

空間複雜度：

- `unordered_map` 需要存 `m` 個不同數字，為 `O(m)`
- `priority_queue` 也會存 `m` 個 pair，為 `O(m)`
- 答案需要存 `k` 個元素，為 `O(k)`
- 整體空間複雜度是 `O(m)`，最壞情況是 `O(n)`

## solution2

`solution2` 使用固定大小為 `k` 的 min heap。

前半段一樣先用 `unordered_map` 統計每個數字的頻率：

```cpp
for (auto num: nums) {
    dic[num]++;
}
```

接著建立 min heap：

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> minHeap;
```

這裡的 `pair` 一樣是：

```text
{frequency, number}
```

但因為使用 `greater<pair<int, int>>`，所以 heap top 會是目前 heap 裡頻率最小的元素。

### 核心想法

我們只需要前 `k` 個高頻元素，所以 heap 不需要保存所有元素。

每次把 `{count, num}` 放進 min heap 後，如果 heap size 超過 `k`，就把目前頻率最小的元素 pop 掉：

```cpp
for (const auto& [num, count] : dic) {
    minHeap.push({count, num});

    if (minHeap.size() > k) {
        minHeap.pop();
    }
}
```

這樣最後 heap 裡會留下頻率最高的 `k` 個元素。

最後把 heap 裡的元素取出：

```cpp
while (!minHeap.empty()) {
    res.push_back(minHeap.top().second);
    minHeap.pop();
}
```

題目允許答案順序不同，所以不需要再排序 `res`。

### 複雜度

假設：

- `n` 是 `nums` 的長度
- `m` 是不同數字的數量

時間複雜度：

- 統計頻率需要 `O(n)`
- 走訪 `m` 個不同數字
- min heap 最多只保留 `k` 個元素，所以每次 push / pop 是 `O(log k)`
- 總時間複雜度是 `O(n + m log k)`

空間複雜度：

- `unordered_map` 需要 `O(m)`
- min heap 最多存 `k` 個元素，為 `O(k)`
- 答案需要 `O(k)`
- 整體空間複雜度是 `O(m + k)`，因為 `k <= m`，通常也可以寫成 `O(m)`

## Challenge

你的方法是正確的，而且很直覺：先知道每個數字出現幾次，再用 heap 把頻率最高的拿出來。

可以再想兩個優化方向：

1. `solution2` 已經用固定大小的 min heap，把 heap 操作從 `O(log m)` 降到 `O(log k)`。
2. 這題還有機會做到 `O(n)`：可以思考 bucket sort，因為頻率最大不會超過 `nums.size()`。

## Hints for Optimization

- bucket sort 做法：建立 `nums.size() + 1` 個 bucket，index 代表 frequency，把數字放到對應頻率的 bucket 裡。
- 如果使用 bucket sort，可以從最高頻率的 bucket 往回收集答案，直到拿滿 `k` 個。
- 如果想讓 `solution2` 的輸出由高頻到低頻，可以在取出 heap 後 reverse `res`，但 LeetCode 這題不要求順序。
