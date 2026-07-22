class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> ans(temperatures.size(), 0);
    
            for (int day = temperatures.size() - 2; day >= 0; day--) {
                int next_day = day + 1;
    
                while (next_day < temperatures.size() &&
                       temperatures[next_day] <= temperatures[day]) {
                        if (ans[next_day] == 0) {
                            next_day = temperatures.size();
                            break;
                        }
                        next_day += ans[next_day];
                }
    
                if (next_day < temperatures.size())
                    ans[day] = next_day - day;
            }
    
            return ans;
        }
    };
    