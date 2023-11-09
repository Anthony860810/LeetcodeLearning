# 9. Palindrome Number
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 

Example 1:
```
Input: x = 121
Output: true
```
Example 2:
```
Input: x = -121
Output: false

Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```
Example 3:
```
Input: x = 10
Output: false

Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```
Example 4:
```
Input: x = -101
Output: false
``` 

Constraints:

* $-2^{31}  \leq x \leq 2^{31} - 1$

## Concept
根據compiler的不同，其長度可能會不一樣，但是int至少要4bytes, 而long則是8bytes
* int (4 bytes): $-2^{31}  \leq x \leq 2^{31} - 1$
* long (8 bytes): $-2^{32}  \leq x \leq 2^{32} - 1$
* unsigned long (8 bytes) : $0  \leq x \leq 2^{33}-1$
* float (4bytes): $2.939*10^{−38} \leq x \leq 3.403*10^{38}$
* double (8 bytes): $5.563x10^{−309} \leq x \leq 1.798x10^{+308}$
```C++ 
// g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
//Operating System: Ubuntu 18.04.5 LTS
//Kernel: Linux 5.4.0-67-generic
// Architecture: x86-64

#include <iostream>                                                         
using namespace std;
  int main(){
     cout<<"int: "<<sizeof(int)<<endl;
     cout<<"long: "<<sizeof(long)<<endl;
     cout<<"long int: "<<sizeof(long int)<<endl;
     cout<<"long long: "<<sizeof(long long)<<endl;
     cout<<"unsigned long: "<<sizeof(unsigned long)<<endl;
     cout<<"float: "<<sizeof(float)<<endl;
     cout<<"double: "<<sizeof(double)<<endl;
     return 0;
  }
/*
Output
    int: 4
    long: 8
    long int: 8
    long long: 8
    unsigned long: 8
    float: 4
    double: 8
*/

```
## solution1
這是一個迴文數字代表就算將他反轉也會是相同的數字。那個我就可以利用 mod 來得到反轉後的數字。但是因為反轉後的數字可能能超過 int 的範圍， 因此reverse的數字改用 unsigned long儲存