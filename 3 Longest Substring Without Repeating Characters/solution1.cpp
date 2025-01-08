class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ans = 0;
        unordered_set<char> dictionary;

        for (int end = 0; end < s.size(); end++) {
            while (dictionary.find(s[end]) != dictionary.end()) {
                dictionary.erase(s[start]);
                start++;
            }
            dictionary.insert(s[end]);
            ans = max(ans, end - start + 1);
            
        }

        return ans;
    }
};