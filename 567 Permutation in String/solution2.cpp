class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        
        vector<int> s1_cnt(26, 0), window_cnt(26, 0);

        for (auto ch: s1)
            s1_cnt[ch - 'a']++;
        
        for (int idx = 0; idx < s1.size(); idx++)
            window_cnt[s2[idx] - 'a']++;

        if (s1_cnt == window_cnt)
            return true;
        
        for (int idx = s1.size(); idx < s2.size(); idx++) {
            window_cnt[s2[idx] - 'a']++;
            window_cnt[s2[idx - s1.size()] - 'a']--;

            if (s1_cnt == window_cnt)
            return true;
        }

        return false;
    }
};
