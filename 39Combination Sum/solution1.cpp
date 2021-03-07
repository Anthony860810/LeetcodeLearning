class Solution {
public:
    vector<vector<int>> ans;
    void GetCimbination(vector<int>& candidates, vector<int> output, int target, int idx){
        if(target<0){
            return;
        }
        else if(target==0){
            ans.push_back(output);
            return;
        }
        else{
            for(int i=idx; i<candidates.size(); i++){
                output.push_back(candidates[i]);
                GetCimbination(candidates, output, target-candidates[i], i);
                output.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> output;
        GetCimbination(candidates, output, target, 0);
        return ans;
    }
};