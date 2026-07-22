class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int dic[26] = {};

        for (int i = 0; i < s.size(); i++) {
            dic[s[i] - 'a']++;
            dic[t[i] - 'a']--;
        }

        for (auto cnt: dic) {
            if (cnt != 0)
                return false;
        }

        return true;
    }
};
