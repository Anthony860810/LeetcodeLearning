class Solution {
    
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(auto i : nums){
            if(i==0)
                count++;
        }
        nums.erase( remove(nums.begin() , nums.end(), 0) , nums.end());
        
        while(count!=0){
            count--;
            nums.push_back(0);
        }
    }
};