class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> s1_map;
        
        for (char ch: s1) {
            if (s1_map.find(ch) == s1_map.end())
                s1_map[ch] = 1;
            else
                s1_map[ch] += 1;
        }



        for (int start = 0; start < s2.size(); start++) {
            if (s1_map.find(s2[start]) != s1_map.end()) {
                unordered_map<char, int> s1_check = s1_map;

                for (int end = start; end < start + s1.size(); end++) {
                    if (s1_check.find(s2[end]) != s1_check.end())
                        s1_check[s2[end]] -= 1;
                    else
                        break;
                    if (s1_check[s2[end]] == 0)
                        s1_check.erase(s2[end]);
                    if (s1_check.empty())
                        return true;
                }
            }
        }

        return false;
    }
};
