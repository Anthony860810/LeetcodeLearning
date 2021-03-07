class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         map<int, int> dic;
          int duplicate, sum;
          int miss_num;
         
          for(int idx=0; idx<nums.size();idx++){
              if(dic.find(nums[idx]) == dic.end()){
                  dic.insert(pair<int,int> (nums[idx], idx));
                  sum+=nums[idx];
                }
              else{
                  duplicate=nums[idx];
                }
              }
        if((sum - (1+nums.size())*nums.size()/2) < 0){
            miss_num = sum - (1+nums.size())*nums.size()/2;
        }
            
        else{
            miss_num = (1+nums.size())*nums.size()/2 - sum;
        }
            
        return {duplicate ,  miss_num};
    }
};