# 3. Longest Substring Without Repeating Characters

## 題目描述

給定一個字串 `s`，找出其中不包含重複字元的最長子字串，並回傳它的長度。

例如：

```text
s = "abcabcbb"
答案 = 3
最長子字串是 "abc"
```

## 解題思路：Sliding Window

使用兩個指標建立一個滑動視窗：

- `start`：目前子字串的起點。
- `end`：目前正在檢查的字元位置。
- `dictionary`：記錄目前視窗中出現過的字元。

每次將 `s[end]` 加入視窗前，先確認它是否已經存在於 `dictionary` 中。如果已經存在，就持續移除 `s[start]`，並將 `start` 向右移動，直到目前視窗不再包含重複的字元。

加入新字元後，使用：

```cpp
end - start + 1
```

計算目前視窗長度，並更新最長答案。

## 為什麼是 O(N)？

雖然程式中有一個 `while` 迴圈，但每個字元最多被加入 `unordered_set` 一次，也最多被移除一次。因此 `start` 和 `end` 都只會向右移動，總操作次數仍然是線性的。

## 複雜度

- 時間複雜度：`O(N)`
- 額外空間複雜度：`O(min(N, 字元集大小))`
