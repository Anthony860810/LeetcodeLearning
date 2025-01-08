class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for (int start = 0; start < s.size(); start++) {
            for (int end = start; end < s.size(); end++) {
                int left = start, right = end;
                while (left < right && s[left] == s[right]) {
                    left++;
                    right--;
                }

                if (left >= right && resLen < (end - start + 1)) {
                    res = s.substr(start, end - start + 1);
                    resLen = end - start + 1;
                }
            }
        }

        return res;
    }
};