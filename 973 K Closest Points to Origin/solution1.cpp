class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (auto point: points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({distance, {point[0], point[1]}});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            ans.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }

        return ans;
    }
};
