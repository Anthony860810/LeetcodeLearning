class Solution {
public:
    string longestPalindrome(string s) {
        int start_idx = 0, length = 0;

        for (int left = 0; left < s.size(); left++) {
            
            int start = left, end = left;
            while (start >= 0 && end < s.size() &&
                   s[start] == s[end]) {
                if (end - start + 1 > length) {
                    start_idx = start;
                    length = end - start + 1;
                }

                start--;
                end++;
            }

            start = left;
            end = left + 1;
            while (start >= 0 && end < s.size() &&
                   s[start] == s[end]) {
                if (end - start + 1 > length) {
                    start_idx = start;
                    length = end - start + 1;
                }

                start--;
                end++;
            }

        }

        return s.substr(start_idx, length);
    }
};