class Solution {

vector<string> ans;

private:
    bool valid(string str) {
        int open = 0;

        for(char ch: str) {
            open += (ch == '(' ? 1 : -1);
            if (open < 0)
                return false;
        }

        return open == 0 ? true : false;
    }

    void dfs(int n, string str) {
        if (str.size() == n * 2) {
            if (valid(str))
                ans.push_back(str);
            return;
        }

        dfs(n, str + '(');
        dfs(n, str + ')');
    }

public:
    vector<string> generateParenthesis(int n) {
        ans = {};

        dfs(n,"");
        
        return ans;
    }
};
