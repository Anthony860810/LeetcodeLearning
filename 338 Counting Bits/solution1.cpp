class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> ans(n+1, 0);
    
            for (int num = 1; num <= n; num++)
                ans[num] = ans[num>>1] + (num&1);
    
            return ans;
        }
    };