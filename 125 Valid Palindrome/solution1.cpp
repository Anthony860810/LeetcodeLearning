class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int end;
        string str = "";

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (int idx = 0; idx < s.size(); idx++) {
            if (('a' <= s[idx] && 'z' >= s[idx]) ||
                 ('0' <= s[idx] && s[idx] <= '9')) {
                str += s[idx];
            }
        }

        end = str.size() - 1;

        while (front <= end) {
            if (str[front] != str[end])
                return false;
            front++;
            end--;
        }
        return true;
    }
};