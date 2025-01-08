class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<int, int> s_map;
        unordered_map<int, int> t_map;

        for (int idx = 0; idx < s.size(); idx++) {
            s_map[s[idx]]++;
            t_map[t[idx]]++;
        }

        return s_map == t_map;
    }
};
