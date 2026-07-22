# 217. Contains Duplicate

## Problem

給定一個整數陣列 `nums`，判斷陣列中是否有任何數字重複出現。

- 如果某個值出現至少兩次，回傳 `true`
- 如果所有值都只出現一次，回傳 `false`

### Examples

```text
Input: nums = [1,2,3,1]
Output: true
```

```text
Input: nums = [1,2,3,4]
Output: false
```

```text
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## solution1

使用 `unordered_map<int, int>` 紀錄每個數字出現的次數。

每次走訪到一個 `num` 時，就把它的 count 加一；如果 count 大於 `1`，代表這個數字已經重複出現，可以直接回傳 `true`。

### 複雜度

- 時間複雜度: `O(n)` average
- 空間複雜度: `O(n)`

## solution2

我的目標是讓時間複雜度達到 `O(n)`，所以使用 `unordered_set` 來紀錄已經看過的數字。

想法是：

1. 建立一個 `unordered_set<int>`，用來存放已經走訪過的 `num`
2. 每次拿到新的 `num` 時，先去 set 裡面搜尋
3. 如果找得到，代表這個數字之前出現過，直接回傳 `true`
4. 如果找不到，就把這個 `num` 放進 set
5. 全部走完都沒有重複，回傳 `false`

這樣做的核心是利用 hash table 的快速查找能力，讓每個數字平均只需要 `O(1)` 的搜尋時間。

### 複雜度

- 時間複雜度: `O(n)` average
- 空間複雜度: `O(n)`

## solution3

`solution3` 延續 `solution2` 的想法，但把「搜尋」和「插入」合併成一次 `insert` 操作。

`unordered_set::insert` 會回傳一個 `pair<iterator, bool>`：

- `.first` 是指向該元素的 iterator
- `.second` 代表這次插入是否成功

如果 `.second` 是 `true`，代表這個數字原本不存在，成功插入 set。

如果 `.second` 是 `false`，代表這個數字原本已經存在，插入失敗，也就是找到 duplicate，可以直接回傳 `true`。

```cpp
if (!hash_table.insert(num).second)
    return true;
```

這樣可以避免 `find` 後又 `insert` 的寫法，讓 hash table 只做一次主要操作，程式也更精簡。

### 複雜度

- 時間複雜度: `O(n)` average
- 空間複雜度: `O(n)`

## Challenge

你的方向是對的，不過有兩個細節可以再想得更精準：

1. 在 C++ 裡，`set` 和 `unordered_set` 不一樣。
   - `set` 通常是紅黑樹，搜尋是 `O(log n)`
   - `unordered_set` 通常是 hash table，平均搜尋是 `O(1)`
   - 所以如果目標是平均 `O(n)`，這題更適合用 `unordered_set`

2. 「時間複雜度要達到 `O(n)` 以內」這句可以更精確地說成「希望達到 `O(n)`」。
   - 因為最壞情況下，如果陣列沒有重複，你至少要看過所有元素才能確定答案
   - 所以這題在一般模型下很難比 `O(n)` 更快

## Hints for Optimization

- `solution3` 已經使用 `insert(...).second` 簡化查找和插入。你也可以試著用 `auto [it, inserted] = hash_table.insert(num);` 寫成更清楚的版本。
- 如果想減少 hash table rehash 的成本，可以研究 `reserve(nums.size())`。
- 也可以試試排序法：先排序，再檢查相鄰元素是否相同。這會犧牲時間複雜度到 `O(n log n)`，但不需要額外的 hash set 空間。
