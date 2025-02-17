class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_largest;

public:
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        for (auto num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k_largest)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k_largest)
            minHeap.pop();
        return minHeap.top();
    }
};
