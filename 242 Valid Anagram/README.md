# 242. Valid Anagram

## Problem

給定兩個字串 `s` 和 `t`，判斷 `t` 是否為 `s` 的 anagram。

Anagram 的意思是：兩個字串使用的字元種類和每個字元出現的次數都一樣，只是排列順序可以不同。

### Examples

```text
Input: s = "anagram", t = "nagaram"
Output: true
```

```text
Input: s = "rat", t = "car"
Output: false
```

### Constraints

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## solution1

第一種方法是先檢查兩個字串長度是否相同。

如果長度不同，代表兩個字串不可能由同樣數量的字元組成，所以可以直接回傳 `false`。

接著把 `s` 和 `t` 都排序。排序後，如果兩個字串是 anagram，它們會變成完全一樣的字串；反之，如果排序後不一樣，就代表至少有某個字元種類或數量不同。

```cpp
sort(s.begin(), s.end());
sort(t.begin(), t.end());
return s == t;
```

### 複雜度

- 時間複雜度: `O(n log n)`
  - 排序 `s` 需要 `O(n log n)`
  - 排序 `t` 也需要 `O(n log n)`
  - 最後比對兩個字串需要 `O(n)`
  - 合起來仍然是 `O(n log n)`
- 空間複雜度: `O(1)` 或 `O(log n)`
  - 概念上是直接排序字串本身，沒有額外建立 map
  - C++ `sort` 可能會使用遞迴堆疊空間，所以也可以記成 `O(log n)`
  - 如果把函式參數 `string s, string t` 的複製成本也算進去，則會有 `O(n)` 的字串拷貝空間

## solution2

第二種方法是用 `unordered_map` 分別記錄兩個字串中每個 character 出現的次數。

因為 anagram 要求「每個字元出現次數完全相同」，所以可以一邊走訪 `s` 和 `t`，一邊更新兩個 map：

```cpp
s_map[s[idx]]++;
t_map[t[idx]]++;
```

走訪結束後，比較兩個 map 是否相同：

```cpp
return s_map == t_map;
```

如果兩邊的 key 和 value 都一樣，代表每個字元的出現次數一致，所以回傳 `true`。

### 複雜度

- 時間複雜度: `O(n)` average
  - 走訪兩個字串需要 `O(n)`
  - 比較兩個 map 最多比較所有不同字元的數量
- 空間複雜度: `O(k)`
  - `k` 是不同字元的種類數
  - 這題限制只有 lowercase English letters，所以 `k <= 26`，也可以視為 `O(1)`
  - 如果字元集不固定，例如 Unicode，則空間會隨不同字元數增加

## solution3

第三種方法是把 `solution2` 的 map 優化成固定長度的 array。

因為題目限制 `s` 和 `t` 都只會包含 lowercase English letters，所以字元種類最多只有 26 種。我們可以建立一個長度為 `26` 的陣列 `dic`，每個 index 對應一個字母：

```cpp
int dic[26] = {};
```

這裡要記得初始化成 `0`。如果只寫 `int dic[26];`，陣列裡面的值不會自動歸零，後面做加減時可能會得到錯誤結果。

接著用同一個 loop 同時處理 `s` 和 `t`：

```cpp
for (int i = 0; i < s.size(); i++) {
    dic[s[i] - 'a']++;
    dic[t[i] - 'a']--;
}
```

對 `s[i]` 對應的字母加一，代表 `s` 多出這個字元；對 `t[i]` 對應的字母減一，代表 `t` 消耗掉這個字元。

如果 `s` 和 `t` 是 anagram，兩邊的字元數量會互相抵消，最後 `dic` 裡面所有值都應該是 `0`。只要有任何一格不是 `0`，就代表某個字元數量不同，回傳 `false`。

### 複雜度

- 時間複雜度: `O(n)`
  - 同一個 loop 同時走訪 `s` 和 `t`
  - 最後檢查固定長度 26 的 array，是 `O(26)`，可以視為 `O(1)`
- 空間複雜度: `O(1)`
  - array 長度固定為 26，不會隨著輸入字串長度增加

## Challenge

你的兩個方向都對，而且剛好呈現這題常見的 trade-off：

- `solution1`: 寫法簡單，額外資料結構少，但排序讓時間變成 `O(n log n)`
- `solution2`: 使用 hash map 換取平均 `O(n)` 時間，但需要額外空間記錄字元頻率
- `solution3`: 利用題目只有小寫英文字母的限制，把 hash map 換成固定 array，時間是 `O(n)`，空間是 `O(1)`

有一個複雜度觀念可以修正：`solution2` 的空間複雜度不會寫成 `O(4N)`。

Big-O 會省略常數，所以即使建立兩個 map，每個 map 裡面又有 key 和 value，仍然不會把它記成 `4N`。更標準的寫法是：

- 如果字元種類可能很多，寫 `O(k)`
- 如果只考慮此題 lowercase English letters，寫 `O(1)`，因為最多只有 26 種字母

## Hints for Optimization

- `solution3` 已經把 `s` 和 `t` 的計數合併到同一個 loop。可以再想想看：最後檢查 26 格 array 的步驟是否一定需要保留？
- 如果想提早判斷，要小心單純看到某個字元被扣成負數不一定能立刻回傳，因為後面可能還會在 `s` 中補回來。
- 如果題目改成支援 Unicode，`solution3` 的固定 array 還適合嗎？這時候 `unordered_map` 反而可能更通用。
