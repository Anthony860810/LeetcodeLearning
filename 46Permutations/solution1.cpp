class Solution {
public:
    
    vector<vector<int>> ans;
    void swap(int &a, int &b){
       int temp=a;
        a=b;
        b=temp;
    }
    void permutation(vector<int>& nums, int start){
        if(start == nums.size()){
            ans.push_back(nums);
        }
        for(int i=start ; i<nums.size() ; i++){
            swap(nums[start], nums[i]);
            permutation(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums, 0);
        return ans;
    }
};