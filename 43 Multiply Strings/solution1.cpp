class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0")
                return "0";
            
            vector<int> num(num1.size() + num2.size(), 0);
            int skip_zero_idx = 0;
            string ans;
    
            for (int i = num1.size() - 1; i >= 0; i--){
               for (int j = num2.size() - 1; j >= 0 ; j--){
                    num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                    num[i + j] += num[i + j + 1] / 10;
                    num[i + j + 1] %= 10;
                }
            }
    
            while (skip_zero_idx < num.size() && num[skip_zero_idx] == 0)
                skip_zero_idx++;
    
            while (skip_zero_idx < num.size()) {
                ans.push_back(num[skip_zero_idx] + '0');
                skip_zero_idx++;
            }
            
            return ans;
        }
    };