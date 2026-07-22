class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> ans(temperatures.size(), 0);
            unordered_map<int, int> map;
    
            for (int idx = 0; idx < temperatures.size(); idx++) {
                if (map.find(temperatures[idx]) != map.end() && map[temperatures[idx]] > idx) {
                    ans[idx] = (map[temperatures[idx]] - idx);
                    continue;
                }
                
                for (int next_day = idx + 1; next_day < temperatures.size(); next_day++) {
                    if (temperatures[next_day] > temperatures[idx]) {
                        ans[idx] = (next_day - idx);
                        map[temperatures[idx]] = next_day;
                        break;
                    }  
                }
            }
    
            return ans;
        }
    };
    