# 271. Encode and Decode Strings

## Problem

設計一組方法，可以把 `vector<string>` encode 成一個 single string，之後再 decode 回原本的 `vector<string>`。

重點是 encode 後的字串必須保留足夠資訊，讓 decode 可以正確還原每一個原始 string。

### Example

```text
Input: ["lint","code","love","you"]
Encoded: "4#lint4#code4#love3#you"
Decoded: ["lint","code","love","you"]
```

如果 string 裡面本身包含分隔符號，也要能正確處理：

```text
Input: ["a#b","c"]
Encoded: "3#a#b1#c"
Decoded: ["a#b","c"]
```

## solution1

原本的做法是用單一 delimiter 分隔每一個 string，例如：

```cpp
encode_str.append(str);
encode_str += '/';
```

decode 時再遇到 `/` 就切開。

這個想法一開始可以通過一些基本測資，但問題是：如果原本的 string 裡面也包含 delimiter，就會解析錯誤。

例如：

```text
Input: ["a/b", "c"]
```

如果只用 `/` 分隔，decode 很難知道 `/` 是原始字串內容，還是不同 string 之間的邊界。

所以單純依靠特殊符號分隔是不夠安全的。

## solution2

新的做法是使用：

```text
長度 + "#" + 原始字串
```

也就是每個 string encode 時都先記錄它的長度，再用 `#` 區隔長度資訊和真正的字串內容。

### Encode

```cpp
for (auto str: strs) {
    res += to_string(str.size());
    res += "#";
    res += str;
}
```

例如：

```text
str = "a#b"
```

因為長度是 `3`，所以會被 encode 成：

```text
3#a#b
```

這裡即使原始字串裡面也有 `#`，也不會影響 decode，因為 decode 不是靠遇到下一個 `#` 來判斷字串結束，而是靠前面記錄的長度。

### Decode

decode 時使用 two pointer 的想法：

- `idx` 指向目前要解析的長度起點
- `anchor` 從 `idx` 開始往後找，直到遇到 `#`

```cpp
int anchor = idx;

while (s[anchor] != '#') {
    anchor++;
}
```

找到 `#` 後，`idx` 到 `anchor - 1` 這段就是長度資訊：

```cpp
int size = stoi(s.substr(idx, anchor - idx));
```

真正的字串內容從 `anchor + 1` 開始，長度是 `size`：

```cpp
int start = anchor + 1;
string str = s.substr(start, size);
```

取出這段後，把 `idx` 移到下一個 encoded string 的起點：

```cpp
idx = start + size;
```

### 為什麼這樣可以處理 `#`？

因為 `#` 只用來分隔「長度」和「內容」。

一旦 decode 讀出長度後，就直接用 `substr(start, size)` 抓固定長度的內容，不需要管內容裡面有沒有 `#`。

例如：

```text
Encoded: "3#a#b1#c"
```

解析流程：

1. 讀到 `3#`，知道下一個 string 長度是 3
2. 從 `#` 後面抓 3 個字元，得到 `"a#b"`
3. 下一個位置是 `1#c`
4. 讀到 `1#`，知道下一個 string 長度是 1
5. 抓 1 個字元，得到 `"c"`

## 複雜度

假設：

- `n` 是 `strs` 的數量
- `m` 是所有 string 長度加總

Encode:

- 時間複雜度: `O(m)`
- 空間複雜度: `O(m)`

Decode:

- 時間複雜度: `O(m)`
- 空間複雜度: `O(m)`

整體來說，這個方法會線性處理所有字元。

## Challenge

你的新理解是對的：只用 `#` 當分隔符不夠，因為原始字串裡也可能包含 `#`。加上長度後，decode 就不需要猜邊界。

有兩個細節可以再注意：

1. `cout` 是 debug 用，正式提交時建議拿掉，避免輸出干擾判題。
2. `substr(start, size)` 是這題的關鍵，因為它讓我們可以精準抓出固定長度的字串內容。

## Hints for Optimization

- 可以把 `anchor` 命名成 `delimiter`，讓它更明確表示 `#` 的位置。
- 如果想避免 encode 時字串多次重新配置，可以研究 `res.reserve(...)`。
- 如果 encoded string 可能不合法，decode 時可以加上邊界檢查；但 LeetCode 這題通常假設輸入來自自己的 encode。
