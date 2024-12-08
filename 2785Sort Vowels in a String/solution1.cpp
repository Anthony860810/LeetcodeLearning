class Solution {
public:
    string sortVowels(string s) {
        // 計算元音字母的數量
        int vowelCount = 0;
        vector<char> vowels;
        vector<int> vowels_position;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.push_back(s[i]);
                vowels_position.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowels_position.size(); i++)
            s[vowels_position[i]] = vowels[i];

        return s;
    }
};