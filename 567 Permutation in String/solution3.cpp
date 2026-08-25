class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        array<int, 26> target = {};
        array<int, 26> window = {};

        for (char ch : s1) {
            ++target[ch - 'a'];
        }

        for (int idx = 0; idx < s1.size(); ++idx) {
            ++window[s2[idx] - 'a'];
        }

        if (target == window)
            return true;

        for (int idx = s1.size(); idx < s2.size(); ++idx) {
            ++window[s2[idx] - 'a'];
            --window[s2[idx - s1.size()] - 'a'];

            if (target == window)
                return true;
        }

        return false;
    }
};
