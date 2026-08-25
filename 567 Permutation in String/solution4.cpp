class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        array<int, 26> target = {};
        array<int, 26> window = {};
        int matched = 0;
        for (int i = 0; i < 26; ++i) {
            if (target[i] == 0)
                ++matched;
        }

        for (char ch : s1) {
            ++target[ch - 'a'];
        }

        auto update = [&](int index, int delta) {
            if (window[index] == target[index])
                --matched;

            window[index] += delta;

            if (window[index] == target[index])
                ++matched;
        };

        for (int idx = 0; idx < s1.size(); ++idx) {
            update(s2[idx] - 'a', 1);
        }

        if (matched == 26)
            return true;

        for (int idx = s1.size(); idx < s2.size(); ++idx) {
            update(s2[idx] - 'a', 1);
            update(s2[idx - s1.size()] - 'a', -1);

            if (matched == 26)
                return true;
        }

        return false;
    }
};
