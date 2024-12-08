class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransom_map;
        for (auto &ch: ransomNote) {
            if (ransom_map.find(ch) == ransom_map.end())
                ransom_map[ch] = 1;
            else
                ransom_map[ch] += 1;
        }

        for (auto &ch: magazine) {
            if (ransom_map.find(ch) != ransom_map.end())
                ransom_map[ch] -= 1;
        }

        for (auto &pair: ransom_map) {
            if (pair.second > 0)
                return false;
        }

        return true;
    }
};