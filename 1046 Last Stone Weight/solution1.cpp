class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (auto weight: stones)
            maxHeap.push(weight);
        
        while (maxHeap.size() > 1) {
            int x;
            int y;

            x = maxHeap.top();
            maxHeap.pop();
            y = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(x - y);
        }

        return maxHeap.top();
    }
};
