# 128. Longest Consecutive Sequence

## Problem

給定一個未排序的整數陣列 `nums`，請找出最長的連續數字序列長度。

連續序列不需要在原本陣列中相鄰，只要數值上是連續的即可。

### Examples

```text
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: 最長連續序列是 [1,2,3,4]
```

```text
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Explanation: 最長連續序列是 [0,1,2,3,4,5,6,7,8]
```

### Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## solution1

第一種做法是先排序。

排序後，連續的數字會排在一起，所以可以從左到右檢查：

- 如果 `nums[i] == nums[i - 1] + 1`，代表連續序列長度加一
- 如果 `nums[i] == nums[i - 1]`，代表遇到重複數字，跳過
- 否則代表連續序列中斷，更新答案並重新計數

### 複雜度

時間複雜度: `O(n log n)`

- 主要成本是排序
- 排序後掃過陣列一次是 `O(n)`

空間複雜度: `O(1)` 或 `O(log n)`

- 如果不計算排序內部使用的空間，可以視為 `O(1)`
- C++ `sort` 可能使用遞迴堆疊空間，所以也可以記成 `O(log n)`

## solution2

第二種做法使用 `unordered_set`，目標是把時間複雜度降到平均 `O(n)`。

先把所有數字放進 set：

```cpp
unordered_set<int> num_set(nums.begin(), nums.end());
```

這樣可以用平均 `O(1)` 的時間查詢某個數字是否存在。

### 核心想法

不要從每個數字都開始往後找，否則會重複做很多工作。

只從「連續序列的起點」開始找。

一個數字 `num` 會是起點，代表：

```text
num - 1 不存在
```

所以可以用：

```cpp
if (!num_set.count(num - 1)) {
    ...
}
```

如果 `num - 1` 存在，代表 `num` 不是起點，它一定會被前面的序列算到，所以可以跳過。

### 延伸序列

找到起點後，就一路檢查 `cur_num + 1` 是否存在：

```cpp
int cur_num = num;
int len = 1;

while (num_set.count(cur_num + 1)) {
    cur_num++;
    len++;
}
```

每次找到更長的序列，就更新答案：

```cpp
max_length = max(max_length, len);
```

### Example

```text
nums = [100,4,200,1,3,2]
num_set = {100,4,200,1,3,2}
```

檢查 `1`：

```text
1 - 1 = 0 不存在，所以 1 是起點
1 -> 2 -> 3 -> 4
len = 4
```

檢查 `2`：

```text
2 - 1 = 1 存在，所以 2 不是起點，跳過
```

這就是為什麼每段連續序列只會被完整走訪一次。

### 複雜度

時間複雜度: `O(n)` average

- 建立 `unordered_set` 需要 `O(n)`
- 每個數字最多只會被當作序列的一部分走訪一次
- `unordered_set::count` 平均是 `O(1)`

空間複雜度: `O(n)`

- 需要用 set 儲存所有不同的數字

## Challenge

你的 `solution2` 想法是這題的關鍵：不是看到每個數字都往後找，而是先判斷它是不是起點。

這個判斷很重要：

```cpp
if (!num_set.count(num - 1))
```

如果少了這個條件，像 `[1,2,3,4]` 會從 `1` 找一次、從 `2` 又找一次、從 `3` 又找一次，時間就可能退化。

另外提醒：`solution1.cpp` 裡目前有一行 debug 輸出：

```cpp
cout << nums[i] << " ";
```

正式提交時建議移除，避免影響 judge output。

## Hints for Optimization

- `unordered_set` 版本已經是這題常見的最佳解，平均時間 `O(n)`。
- 可以想想為什麼走訪 `num_set` 比走訪原本 `nums` 更自然：它可以自動去掉 duplicates。
- 如果想練另一種資料結構，可以研究 union-find，但這題用 set 已經最直覺。
