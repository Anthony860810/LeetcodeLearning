# 36. Valid Sudoku

## Problem

給定一個 `9 x 9` 的 Sudoku board，判斷目前填入的數字是否有效。

只需要檢查目前已填入的格子，不需要判斷這個 Sudoku 最後是否一定能被解出來。

一個有效的 Sudoku 需要符合：

- 每一列 row 中，數字 `1` 到 `9` 不能重複
- 每一行 column 中，數字 `1` 到 `9` 不能重複
- 每一個 `3 x 3` box 中，數字 `1` 到 `9` 不能重複

空格會用 `'.'` 表示，可以直接跳過。

## solution1

第一種做法使用 `set` 來記錄每個 row、column、box 已經出現過哪些數字。

```cpp
unordered_map<int, set<int>> row_cal;
unordered_map<int, set<int>> col_cal;
unordered_map<int, set<int>> matrix_cal;
```

每次走訪到一個不是 `'.'` 的格子，就檢查這個數字是否已經出現在：

- 目前 row
- 目前 column
- 目前 `3 x 3` box

如果已經出現過，代表 Sudoku 不合法，直接回傳 `false`。

### Box Index

`3 x 3` box 的編號可以用：

```cpp
int matrix_num = 3 * (row / 3) + col / 3;
```

例如：

```text
row = 4, col = 5
row / 3 = 1
col / 3 = 1
matrix_num = 3 * 1 + 1 = 4
```

所以 `(4, 5)` 會落在中間的 box，也就是 box `4`。

### 複雜度

時間複雜度: `O(1)`

- board 固定是 `9 x 9`
- 最多只檢查 81 個格子

空間複雜度: `O(1)`

- row、column、box 的數量都是固定的
- 每個 set 最多也只會存 9 個數字

如果把 board 大小泛化成 `n x n`，這類做法可以視為 `O(n^2)` 時間。

## solution2

第二種做法使用 bitmask。

因為 Sudoku 只會有數字 `1` 到 `9`，所以可以用一個 integer 的 9 個 bit 來記錄某個 row、column、box 中出現過哪些數字。

```cpp
vector<int> rows(9, 0);
vector<int> cols(9, 0);
vector<int> square(9, 0);
```

其中：

- `rows[row]` 記錄第 `row` 列出現過哪些數字
- `cols[col]` 記錄第 `col` 行出現過哪些數字
- `square[square_loc]` 記錄第 `square_loc` 個 `3 x 3` box 出現過哪些數字

### Bitmask 想法

先把字元轉成 `0` 到 `8`：

```cpp
int num = val - '1';
```

例如：

```text
val = '1' -> num = 0
val = '5' -> num = 4
val = '9' -> num = 8
```

接著建立這個數字對應的 bit：

```cpp
int num_flag = 1 << num;
```

例如：

```text
'1' -> 1 << 0 -> 000000001
'5' -> 1 << 4 -> 000010000
'9' -> 1 << 8 -> 100000000
```

如果某個 mask 已經包含這個 bit，代表數字重複出現：

```cpp
if (rows[row] & num_flag ||
    cols[col] & num_flag ||
    square[square_loc] & num_flag) {
    return false;
}
```

如果沒有重複，就用 OR 把這個 bit 記錄進去：

```cpp
rows[row] |= num_flag;
cols[col] |= num_flag;
square[square_loc] |= num_flag;
```

### Box Index

bitmask 版本也使用一樣的公式找出目前格子屬於哪一個 `3 x 3` box：

```cpp
int square_loc = (row / 3) * 3 + (col / 3);
```

box 編號如下：

```text
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
------+-------+------
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
------+-------+------
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
```

### 複雜度

時間複雜度: `O(1)`

- Sudoku board 固定只有 81 格
- 每格只做固定次數的 bit operation

空間複雜度: `O(1)`

- `rows`、`cols`、`square` 都固定長度 9

## Challenge

你的 bitmask 做法比 `set` 做法更精簡，也更接近這題的最佳解之一。

幾個值得注意的地方：

- `rows[row] & num_flag` 是檢查這個數字是否出現過
- `rows[row] |= num_flag` 是把這個數字標記成已出現
- `square_loc = (row / 3) * 3 + (col / 3)` 是 Sudoku 題常用的 box index 公式

`solution1` 和 `solution2` 的 Big-O 都是 `O(1)`，因為 board 大小固定；但 `solution2` 的常數成本更低，而且不需要 `set` 的查找與節點配置。

## Hints for Optimization

- 可以思考為什麼 `val - '1'` 比 `val - '0'` 更適合這裡的 bit index。
- 如果想讓 code 更語意化，可以把 `square` 命名成 `boxes`。
- 也可以嘗試把 `rows`、`cols`、`square` 改成固定陣列 `int rows[9] = {};`。
