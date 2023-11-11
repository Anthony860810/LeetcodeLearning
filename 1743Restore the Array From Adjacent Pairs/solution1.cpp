class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> num_freq; // 用來計算每個數字的頻率
        unordered_map<int, vector<int>> neighbor_nums; // 用來存儲每個數字的相鄰數字
        int n = adjacentPairs.size()+1;
        vector<int> output(n);
        int start=0;

        for(auto &pair: adjacentPairs) {
            num_freq[pair[0]]++;
            num_freq[pair[1]]++;
            neighbor_nums[pair[0]].push_back(pair[1]);
            neighbor_nums[pair[1]].push_back(pair[0]);
        }

        for(auto &num: num_freq) {
            if(num.second == 1) {
                start = num.first;
                break; 
            }
        }

        output[0] = start;
        output[1] = neighbor_nums[start][0];
        for(int idx=2; idx<n; idx++) {
            if(output[idx-2] == neighbor_nums[output[idx-1]][0])
                output[idx] = neighbor_nums[output[idx-1]][1];
            else
                output[idx] = neighbor_nums[output[idx-1]][0];
        }
        return output;
    }
};
