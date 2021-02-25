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