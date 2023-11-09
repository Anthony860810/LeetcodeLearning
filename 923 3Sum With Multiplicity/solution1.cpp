class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> dic;
        for(auto num: arr){
          dic[num]++;  
        }
        long ans=0;
        for(auto iter1 : dic){
            for(auto iter2 : dic){
                int i = iter1.first;
                int j = iter2.first;
                int k = target - i - j;
                if(!dic.count(k))
                    continue;
                if(i==j && j==k){
                   ans += dic[i] * (dic[i]-1) *(dic[i]-2) / 6;
                }
                else if( i==j && j!=k){
                    ans += dic[i] * (dic[i]-1) *dic[k] / 2;
                }
                
                else if(i<j && j<k){
                    ans += dic[i] * dic[j] * dic[k];
                }
            }
        }
        return ans % int(1e9+7);
    }
};