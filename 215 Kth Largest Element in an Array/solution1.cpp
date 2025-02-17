class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (auto num : nums) {
            maxHeap.push(num);
        }

        while (k > 1) {
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }
};
