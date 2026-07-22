class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        
        int end = 0;
        int farthest = 0;
        int jump = 0;

        for (int idx = 0; idx < nums.size(); idx++) {
            farthest = max(farthest, idx + nums[idx]);

            if (idx == end) {
                if (end < nums.size() - 1) {
                    end = farthest;
                    jump++;
                } else {
                    return jump;
                }
                
            }
        }

        return jump;

    }
};