class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            vector<int> count(26, 0);
            int idle;
    
            for(auto ch: tasks)
                count[ch - 'A']++;
    
            sort(count.begin(), count.end());
            idle = (count[25] - 1) * n;
    
            for (int idx = 24; idx >= 0; idx--) {
                idle -= min(count[idx], count[25] - 1);
            }
    
            return max(idle, 0) + tasks.size();
        }
    };