# 125. Valid Palindrome

## Problem

給定一個字串 `s`，判斷它在只保留英文字母和數字、並忽略大小寫後，是否是一個 palindrome。

Palindrome 的意思是從左讀到右、從右讀到左都一樣。

### Examples

```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: 轉換後是 "amanaplanacanalpanama"
```

```text
Input: s = "race a car"
Output: false
Explanation: 轉換後是 "raceacar"
```

```text
Input: s = " "
Output: true
Explanation: 只保留英數後是空字串，視為 palindrome
```

### Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters.

## solution1

第一種做法是先把字串全部轉成小寫，接著建立一個新的字串 `str`，只放入英文字母和數字。

```cpp
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

再走訪原字串：

```cpp
if (('a' <= s[idx] && 'z' >= s[idx]) ||
     ('0' <= s[idx] && s[idx] <= '9')) {
    str += s[idx];
}
```

最後用 two pointers 檢查 `str` 是否左右對稱。

### 複雜度

時間複雜度: `O(n)`

- 轉小寫需要走訪一次
- 建立 clean string 需要走訪一次
- 檢查 palindrome 需要走訪一次

空間複雜度: `O(n)`

- 需要額外建立一個只包含英數字元的 `str`

## solution2

第二種做法不額外建立 clean string，而是直接在原字串上使用 two pointers。

先把整個字串轉成小寫：

```cpp
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

接著設定兩個指標：

```cpp
int front = 0;
int end = s.size() - 1;
```

- `front` 從左往右走
- `end` 從右往左走

### 跳過非英數字元

新版用 `isalnum` 判斷一個字元是否為英文字母或數字，比手寫 ASCII 條件更簡潔。

如果 `front` 指到的字元不是英數字元，就往右移：

```cpp
while (front < end && !isalnum(s[front])) {
    front++;
}
```

如果 `end` 指到的字元不是英數字元，就往左移：

```cpp
while (front < end && !isalnum(s[end])) {
    end--;
}
```

找到左右兩邊下一個有效字元後，就比較：

```cpp
if (tolower(s[front]) != tolower(s[end])) {
    return false;
}
```

如果相同，就繼續往中間靠近：

```cpp
front++;
end--;
```

直到兩個指標交錯，代表所有有效字元都符合 palindrome。

### 為什麼 while 條件用 `front < end`？

因為只要兩個指標還沒有碰在一起，就繼續跳過非英數字元。

例如：

```text
s = ".,"
```

`front` 會往右移，直到和 `end` 相遇。這時比較同一個位置的字元，不會造成錯誤，最後會回傳 `true`。

這版不需要額外寫 `front > end` 的檢查，因為內層 while 已經用 `front < end` 控制邊界。

### 複雜度

時間複雜度: `O(n)`

- 轉小寫需要 `O(n)`
- two pointers 最多各自走過整個字串一次

空間複雜度: `O(1)`

- 沒有額外建立 clean string
- 注意：參數 `string s` 本身是 pass by value，會複製一份字串；如果把這個複製也算入，會是 `O(n)`

## Challenge

你的 `solution2` 比 `solution1` 更省空間，因為它直接在原字串上比對，不需要建立新的 `str`。

有兩個細節可以再想想：

1. 你現在先把整個字串轉成小寫，又在比較時呼叫 `tolower`。這不影響正確性，但其實做一次就夠了。
2. `isalnum` 讓判斷更簡潔；在更嚴謹的 C++ 寫法中，可以把字元轉成 `unsigned char` 再傳入。

## Hints for Optimization

- 如果想再簡化，可以移除一開始的 `transform`，只在比較時使用 `tolower`。
- 如果想保留一開始的 `transform`，比較時就可以直接寫 `s[front] != s[end]`。
- 這題的核心 pattern 是 two pointers：左邊找下一個有效字元，右邊也找下一個有效字元，再比較。
