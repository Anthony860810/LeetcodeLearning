bool vector_sorting(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(), vector_sorting);
        
        vector<int> head = intervals[0];
        
        for (auto interval: intervals) {
            if (head[1] < interval[0]) {
                ans.push_back(head);
                head = interval;
            } else {
                head[1] = max(head[1], interval[1]);
            }
        }
        
        ans.push_back(head);

        return ans;
    }
};