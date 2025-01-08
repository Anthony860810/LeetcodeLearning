class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;

        for (int num : num_set) {
            if (num_set.count(num - 1) == 0) {
                int current_num = num;
                int cnt = 1;

                while (num_set.count(current_num + 1)) {
                    current_num++;
                    cnt++;
                }

                max_length = max(max_length, cnt);
            }
        }

        return max_length;
    }
};