class Solution {
    public:
        void generate(string digits, int idx, vector<string> map, vector<string> &ans, string output) {
            if (output.size() == digits.size()) {
                ans.push_back(output);
                return;
            }
    
            int num = digits[idx] - '0';
    
            for (int i = 0; i < map[num].size(); i++) {
                output.push_back(map[num][i]);
                idx++;
                generate(digits, idx, map, ans, output);
                idx--;
                output.pop_back();
            }
        }
        
        vector<string> letterCombinations(string digits) {
            int idx = 0;
            vector<string> map= {"", "", "abc", "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
            vector<string> ans;
            string output;
    
            if (digits.size() == 0)
                return ans;
            
            generate(digits, idx, map, ans, output);
            
            return ans;
        }
    };