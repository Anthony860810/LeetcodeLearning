class Solution {

vector<string> ans;

private:
    bool valid(string str) {
        stack<char> buffer;

        for(int idx = 0; idx < str.size(); idx++) {
            if (str[idx] == '(') {
                buffer.push(str[idx]);
            } else {
                if (buffer.empty())
                    return false;
                else
                    buffer.pop();
            }
        }

        if (buffer.empty())
            return true;
        else
            return false;
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
