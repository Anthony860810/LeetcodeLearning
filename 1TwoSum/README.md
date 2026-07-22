# 1. Two Sum

## Problem

給定一個整數陣列 `nums` 和一個整數 `target`，請找出兩個不同位置的數字，使它們相加等於 `target`，並回傳這兩個 index。

題目保證每組 input 只會有一組解，而且同一個元素不能重複使用。

### Examples

```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9
```

```text
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

```text
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints

- `2 <= nums.length <= 10^3`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

## Tools

### map

- 底層通常是紅黑樹
- search / insert: `O(log n)`
- key 會維持排序

### unordered_map

- 底層通常是 hash table
- average search / insert: `O(1)`
- key 不會維持排序
- 這題只需要快速查找 complement，不需要排序，所以 `unordered_map` 更適合

## solution1

直接使用兩層迴圈，枚舉所有可能的 index pair。

對每個 `i`，再從 `i + 1` 開始找 `j`，檢查：

```cpp
nums[i] + nums[j] == target
```

如果成立，就把 `i` 和 `j` 放進答案。

### 複雜度

- 時間複雜度: `O(n^2)`
- 空間複雜度: `O(1)`，不計算回傳答案的空間

## solution2

這題可以用 complement 的概念來解。

如果目前數字是 `nums[i]`，那麼它需要的另一個數字就是：

```text
complement = target - nums[i]
```

也就是：

```text
target = nums[i] + complement
```

所以我們可以用 `unordered_map<int, int>` 儲存已經看過的數字和它的 index：

- key: 數字本身
- value: 該數字的 index

每次走訪到 `nums[i]` 時，先檢查 `target - nums[i]` 是否已經存在 hash table 裡。

如果不存在，代表目前還找不到配對，就把 `nums[i]` 和 index `i` 存進 hash table。

如果存在，代表之前看過的某個數字可以和目前的 `nums[i]` 加總成 `target`，因此回傳：

```cpp
return {hash_table[target - nums[i]], i};
```

### Code idea

```cpp
if (!hash_table.count(target - nums[i])) {
    hash_table.insert(make_pair(nums[i], i));
} else {
    return {hash_table[target - nums[i]], i};
}
```

因為題目保證只有一組答案，所以找到答案後可以直接 `return`，不用繼續走訪後面的元素。

### 為什麼要先查 complement 再 insert 目前數字？

因為題目規定不能使用同一個元素兩次。

例如：

```text
nums = [3], target = 6
```

如果先把目前的 `3` 放進 hash table，再查 `target - 3`，就可能把同一個 index 拿來配自己。

所以正確順序是：

1. 先查之前看過的數字裡，有沒有 complement
2. 找不到時，才把目前數字存起來，留給後面的元素使用

### 複雜度

- 時間複雜度: `O(n)` average
  - 每個元素最多被走訪一次
  - `unordered_map` 的 `count` / `insert` 平均是 `O(1)`
- 空間複雜度: `O(n)`
  - 最壞情況下，可能需要把大部分元素都存進 hash table

## Challenge

你的做法方向是對的，從 `map` 改成 `unordered_map` 後，查找 complement 的平均時間可以從 `O(log n)` 降到 `O(1)`。

有一個地方可以再想得更精準：

目前的寫法會先 `count`，找到後再用 `hash_table[target - nums[i]]` 取值，這等於查了兩次。可以試著用 `find` 把查找和取 iterator 合併。

## Hints for Optimization

- 可以把 `target - nums[i]` 先存成 `complement`，讓程式更容易讀。
- 試著改用 `auto it = hash_table.find(complement);`，找到時直接使用 `it->second`。
- 使用 `find` 後，找到答案時可以直接 `return {it->second, i};`，讓程式更短，也避免重複查找。
