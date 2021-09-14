# 342. Power of Four
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example1:
```c
Input: n = 16
Output: true
```

Example2:
```c
Input: n = 5
Output: false
```

Example3:
```c
Input: n = 1
Output: true
```

Constraints:

* $-2^{31} <= n <= 2^{31} - 1$

## Solution1
```c
bool isPowerOfFour(int n){
    return (n > 0) && !(n & (n - 1)) && !(__builtin_ctz(n) & 1);
}
```
### 解題思路
#### 思路一
因為4為正數，所以其次方必為大於0
#### 思路二
從二進位來看
* $4^0 = 1$
* $4^1 = 100$
* $4^2 = 10000$
* $4^3 = 1000000$
* $4^4 = 100000000$
* $12 = 1100$
* $28 = 11100$
若是我們單純用偶數個0來判定是否為4的次方會偵測到很多四的倍數，因此用!(n & (n-1)) 過濾。
* $4^1$ & 3 = 100 & 011 =0
* $4^2$ & 15 = 10000 & 01111 =0
* $4^3$ & 63 = 1000000 & 0111111=0
* $4^4$ & 255 = 100000000 & 011111111=0
* $12$ & 11 = 1100 & 1011 > 1
* $28$ & 27 = 11100 & 11011 >1

#### 思路三
* [gcc 內建處理二進位函數](http://sunmoon-template.blogspot.com/2017/04/gcc-built-in-functions-for-binary-gcc.html)
__builtin_ctz(n) 用來找尋從右邊起數來第一個1後0的個數，做and可以判定是否為偶數個0