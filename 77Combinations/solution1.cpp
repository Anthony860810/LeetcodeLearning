class Solution {
public:
    vector <vector<int>> ans;
    void DFS(vector<int> &tmp, int start, int n , int k){
        if(tmp.size()==k){
            ans.push_back(tmp);
        }
        for(int i=start; i<=n; i++){
            tmp.push_back(i);
            DFS(tmp, i+1, n, k);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> tmp;
        DFS(tmp, 1, n, k);
        return ans;
    }
};