class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_str = "";
        for (auto str: strs) {
            encode_str.append(str);
            encode_str += '/';
        }
        
        return encode_str;
    }

    vector<string> decode(string s) {
        vector<string> decode_str;
        string str = "";
        
        for (int idx = 0; idx < s.size(); idx++) {
            if (s[idx] != '/')
                str += s[idx];
            else {
                decode_str.push_back(str);
                str = "";
            }
        }
        return decode_str;
    }
};
