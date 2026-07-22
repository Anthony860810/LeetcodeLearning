# 49. Group Anagrams

## Problem

給定一個字串陣列 `strs`，請把所有 anagram 分成同一組，並回傳分組後的結果。

Anagram 指的是由相同字元、相同出現次數組成的字串，只是排列順序不同。

### Examples

```text
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

```text
Input: strs = [""]
Output: [[""]]
```

```text
Input: strs = ["a"]
Output: [["a"]]
```

### Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

## solution1

這題可以延續 Valid Anagram 的想法：如果兩個字串是 anagram，那它們排序後會變成一樣的字串。

例如：

```text
"eat" -> "aet"
"tea" -> "aet"
"ate" -> "aet"
```

所以我們可以把「排序後的字串」當作 key。key 相同的字串，就放進同一組。

這份解法使用：

- `unordered_map<string, vector<string>> category_dict`
  - key: 排序後的字串
  - value: 屬於這個 anagram group 的所有原字串
- `vector<vector<string>> ans`
  - 將 map 裡面的每個 group 收集成最後答案

流程是：

1. 走訪每個 `str`
2. 複製一份成 `word`
3. 將 `word` 排序，得到這組 anagram 的 key
4. 使用 `category_dict[word].push_back(str)`，把原本的字串放進對應 group
5. 走訪 `category_dict`，把每個 group 加進 `ans`

### Code idea

```cpp
string word = str;
sort(word.begin(), word.end());
category_dict[word].push_back(str);
```

最後再把 map 裡的每一組 anagram 放進答案：

```cpp
for (auto str_group: category_dict)
    ans.push_back(str_group.second);
```

### 複雜度

假設：

- `n` 是 `strs` 的字串數量
- `k` 是每個字串的最大長度

時間複雜度:

- 每個字串都需要排序，排序成本是 `O(k log k)`
- 總共有 `n` 個字串
- 將字串放進 `unordered_map` 平均是 `O(1)`，但 key 本身長度是 `k`，hash string 會和字串長度有關
- 最主要的成本仍然是排序，所以通常寫成 `O(n * k log k)`
- 最後把所有 group 放進 `ans`，總共會處理 `n` 個字串，約是 `O(n)`

空間複雜度:

- `category_dict` 會儲存所有字串分組結果，為 `O(n * k)`
- map 的 key 是排序後字串，最壞情況每個字串都不同，也會接近 `O(n * k)`
- `ans` 最後也會存放所有 group
- 所以整體空間複雜度是 `O(n * k)`

## solution2

`solution2` 的優化方向是：不要排序字串，改用 26 個英文字母的出現次數當 key。

因為題目限制 `strs[i]` 只會包含 lowercase English letters，所以每個字串都可以被表示成一個長度 26 的 count array。

例如：

```text
"eat" -> a:1, e:1, t:1
"tea" -> a:1, e:1, t:1
"ate" -> a:1, e:1, t:1
```

這三個字串的字母數量完全一樣，所以它們是同一組 anagram。

實作上先建立一個長度 26 的 array：

```cpp
int count[26] = {};
```

接著走訪字串，把每個字母的數量加一：

```cpp
for (auto ch: str) {
    count[ch - 'a']++;
}
```

但 `unordered_map` 的 key 不能直接使用一般 C-style array，所以要把 26 個數字轉成一個字串 key：

```cpp
string key;
for (int i = 0; i < 26; i++) {
    key += "#";
    key += to_string(count[i]);
}
```

這裡加上 `#` 是為了避免 key 發生歧義。

例如如果不加分隔符號，`[1, 11]` 和 `[11, 1]` 都可能組成類似 `"111"` 的字串，很難分辨原本的 count 結構。加上分隔符後會變成：

```text
[1, 11] -> "#1#11"
[11, 1] -> "#11#1"
```

這樣 key 就能清楚區分不同的字母數量。

最後一樣用：

```cpp
category_dict[key].push_back(str);
```

把相同 key 的字串放在同一組。

### 複雜度

假設：

- `n` 是 `strs` 的字串數量
- `k` 是每個字串的最大長度

時間複雜度:

- 每個字串只需要走訪一次，計算字母數量是 `O(k)`
- 建立 26 個字母的 key 是 `O(26)`，可以視為 `O(1)`
- 總時間複雜度是 `O(n * k)`

空間複雜度:

- `category_dict` 和 `ans` 需要儲存所有字串，為 `O(n * k)`
- 每個 group 的 key 是固定 26 個 count 組成的字串，key 的長度可以視為 `O(1)`
- 所以整體空間複雜度仍然是 `O(n * k)`

## Challenge

你的做法是對的，用排序後字串當 key 很直覺，也很適合這題。

有兩個地方可以再想想：

1. `category_dict[word].push_back(str)` 寫法很簡潔，因為 `operator[]` 在 key 不存在時會自動建立一個空的 `vector<string>`。
2. `solution2` 已經避免排序，把每個字串的處理從 `O(k log k)` 降到 `O(k)`。不過 key 的建立方式會影響可讀性和實作細節，分隔符號不能省略。

## Hints for Optimization

- 可以試著比較 `solution1` 和 `solution2`：一個 key 是排序後字串，一個 key 是字母 count。
- 如果想讓 `solution2` 更 C++ 一點，可以研究 `array<int, 26>` 能不能直接當 `unordered_map` 的 key，需要額外處理什麼？
- 如果字串最大長度很短，排序法已經很夠用；如果字串很多或很長，count key 的優勢會比較明顯。
