class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int end = s.size() - 1;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        while (front <= end) {
            while (front < end && !isalnum(s[front])) {
                front++;
            }

            while (front < end && !isalnum(s[end])) {
                end--;
            }

            if (tolower(s[front]) != tolower(s[end])) {
                return false;
            }

            front++;
            end--;
        }

        return true;
    }
};
