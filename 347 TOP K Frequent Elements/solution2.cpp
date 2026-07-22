class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dic;

        for (auto num: nums) {
            dic[num]++;
        }

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (const auto& [num, count] : dic) {
            minHeap.push({count, num});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
