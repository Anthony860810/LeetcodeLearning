class Solution {

public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;

        map<char, int, greater<char>> freq;
        for(auto ch : s) freq[ch]++;

        for(int i = 0, repeat_cnt = 0; i < s.size(); i++, repeat_cnt++) {
            auto ptr = freq.begin();
            if(repeat_cnt == repeatLimit) {
                if(freq.size() == 1)
                    break;
                
                ptr++;
                ans.push_back(ptr -> first);
                freq[ptr -> first] -= 1;

                if(freq[ptr -> first] == 0)
                    freq.erase(ptr);

                repeat_cnt = -1;
            } else {
                ans.push_back(ptr -> first);
                freq[ptr -> first] -= 1;

                if(freq[ptr -> first] == 0) {
                    freq.erase(ptr);
                    repeat_cnt = -1;
                }
            }
        }
        return ans;
    }
};