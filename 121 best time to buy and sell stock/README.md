# 121. Best Time to Buy and Sell Stock

## 題目描述

給定陣列 `prices`，其中 `prices[i]` 代表第 `i` 天的股票價格。只能選擇一天買進，並在未來某一天賣出，請找出可以獲得的最大利潤。

如果無法獲利，回傳 `0`。

## Solution 1：記錄每天的最大利潤

使用 `cur_day_max_profit` 陣列記錄截至目前這一天所能得到的最大利潤，同時維護到目前為止的最低買入價格。

這種做法可以清楚保存每一天的狀態，但需要額外的陣列空間。

- 時間複雜度：`O(N)`
- 額外空間複雜度：`O(N)`

## Solution 2：只保留必要狀態

每天只需要兩個資訊：

- `min_price`：到目前為止看過的最低價格。
- `cur_day_max_profit`：到目前為止看過的最大利潤。

對目前價格 `prices[day]`，先更新最低買入價格，再計算如果今天賣出能得到的利潤：

```cpp
min_price = min(min_price, prices[day]);
cur_day_max_profit = max(
    cur_day_max_profit,
    prices[day] - min_price
);
```

因為只需要前一天累積的結果，不需要保存整個陣列，因此可以將空間複雜度從 `O(N)` 優化成 `O(1)`。

- 時間複雜度：`O(N)`
- 額外空間複雜度：`O(1)`

## 你的解法

你的程式就是 Solution 2 的寫法，使用 `profit` 取代 `cur_day_max_profit`，邏輯完全相同。
