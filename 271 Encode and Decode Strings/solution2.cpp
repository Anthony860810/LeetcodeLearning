class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (auto str: strs) {
            res += to_string(str.size());
            res += "#";
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0;

        while (idx < s.size()) {
            int anchor = idx;

            while (s[anchor] != '#') {
                anchor++;
            }

            int size = stoi(s.substr(idx, anchor - idx));

            int start = anchor + 1;
            string str = s.substr(start, size);

            res.push_back(str);
            idx = start + size;
        }

        return res;
    }
};
