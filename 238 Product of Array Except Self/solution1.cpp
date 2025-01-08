class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product = 1;
        int zeros = 0;

        for (auto num: nums) {
            if (num != 0)
                product *= num;
            else
                zeros++;
        }

        if (zeros > 1)
            return  vector<int>(nums.size(), 0);

        for (auto num: nums) {
            if (zeros != 0)
                num == 0 ? ans.push_back(product) : ans.push_back(0);
            else
                ans.push_back(product / num);
        }

        return ans;
    }
};