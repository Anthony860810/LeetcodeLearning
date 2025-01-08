class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue <pair<int, int>> queue;
        vector<int> ans;

        for (auto num: nums)
            map[num]++;
        
        for (auto element: map)
            queue.push({element.second, element.first});
        
        while (k > 0) {
            ans.push_back(queue.top().second);
            queue.pop();
            k--;
        }

        return ans;
    }
};