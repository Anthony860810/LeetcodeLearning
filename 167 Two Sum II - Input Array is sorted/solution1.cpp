class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans = {};

        int head = 0;
        int tail = numbers.size()-1;

        while (head < tail) {
            if (numbers[head] + numbers[tail] == target) {
                ans.push_back(head+1);
                ans.push_back(tail+1);
                break;
            } else if (numbers[head] + numbers[tail] > target) {
                tail--;
            } else {
                head++;
            }
        }

        return ans;
    }
};