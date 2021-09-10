# 91.Decode Ways

A message containing letters from A-Z can be encoded into numbers using the following mapping:
```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

* "AAJF" with the grouping (1 1 10 6)
* "KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.



## 解題思路:
這一題一開始會想到這是一個 **Recursive** 的題目，原因在於你不只需要考慮當前位置的數字是否為合法，同時也需要去觀測前一個數字與他的組合是否合法，因此我們需要不停地往前解構字串列，這就是 **Recursive** 的核心思想。然而面對數列的增長，我們需要用空間換取時間，因此我們需要一個容器來儲存過往數字所組成的字串所能構成幾種不同型態的英文字串，也因此這可以被轉換成一個 **Dynamic programming** 的問題

若以抽象來看的話，這其實跟爬樓梯有異曲同工之妙，只是他追加了一些設定，如 只有數字1~26有對應到字母，由此可知我們需要針對這個部分來做一些限制

```C++
class Solution {
public:
    int SingleCheck(char ch){
        //check 0 or not
        return ch=='0' ? 0 : 1;
    }

    int Check(char ch1, char ch2){
        //check it's between 10 and 26
        return (ch1=='1' || (ch1=='2' && ch2<='6')) ? 1: 0;
    }
    
    int numDecodings(string s) {
        if (s.size()==0 || s[0]=='0') return 0;
        if (s.size()==1) return 1;

        vector<int> dp(s.size(),0);

        dp[0] = SingleCheck(s[0]);
        dp[1] = SingleCheck(s[0]) *  SingleCheck(s[1]) +Check(s[0], s[1]) ;
        for (int i=2; i<s.size(); i++) {
            if (SingleCheck(s[i])) {
                dp[i] = dp[i-1];
            }
            if (Check(s[i-1], s[i])) {
                dp[i] += dp[i-2];
            }

        }
        return dp[s.size()-1];
    }
};
```
## 實作想法
* 核心程式碼的前兩行是將 string 長度低於2者，先 return 回去
* dp[idx] 代表到 s[idx] 能 decode 出幾種不同的方法
* 由於在前面已將長度為1的不適合數列移除掉，所以剩餘數列必定至少會有一種解法，因此dp[0]=1
* 由於 s[1]不一定合法，但是可以與s[0]合併成合法數字，因此用 SingleCheck() 來檢查是否兩者數字皆合法， 而 Check() 則測試是否組成後才為合法數字。
* 最後由於已有 dp[0] 和 dp[1] 因此我們只須檢測 s[i]和s[i-1]是否為合法組合，若是s[i]為非0數字的話，那麼即可加上dp[i-1]，因為他可以自己獨立組成一個數字放在移除掉s[i]的數列中，而若是s[i]為0話，那麼我們只能將s[i]和s[i-1]放在一起組成一個合法數字，這也就造成我們只能將dp[i]加上dp[i-2]