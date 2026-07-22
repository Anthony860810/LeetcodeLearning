class Solution {
    public:
        int characterReplacement(string s, int k) {
            unordered_map<char, int> map;
            int ans = 0;
    
            int left = 0;
            int max_ch_cnt = 0;
            for (int right = 0; right < s.size(); right++) {
                map[s[right]]++;
                max_ch_cnt = max(max_ch_cnt, map[s[right]]);
    
                while ((right - left + 1) - max_ch_cnt > k) {
                    map[s[left]]--;
                    left++;
                }
    
                ans = max(ans, right - left + 1);
            }
    
            return ans;
            
        }
    };