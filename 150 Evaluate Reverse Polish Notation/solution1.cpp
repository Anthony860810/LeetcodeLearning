class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack = {};
        int num = 0;        
        for (int idx = 0; idx < tokens.size(); idx++) {
            int num;
            
            if (tokens[idx] == "+") {
                num = stack.back();
                stack.pop_back();
                stack.back() += num;
            } else if (tokens[idx] == "-") {
                num = stack.back();
                stack.pop_back();
                stack.back() -= num;
            } else if (tokens[idx] == "*") {
                num = stack.back();
                stack.pop_back();
                stack.back() *= num;
            } else if (tokens[idx] == "/") {
                num = stack.back();
                stack.pop_back();
                stack.back() /= num;
            } else {
                stack.push_back(stoi(tokens[idx]));
            }
                
        }

        return stack.back();
    }
};
