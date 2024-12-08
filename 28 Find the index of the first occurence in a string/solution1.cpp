class Solution {
public:
    int strStr(string haystack, string needle) {

        for (int idx = 0; idx < haystack.size(); idx++) {
            if (haystack[idx] == needle[0])
                if (haystack.substr(idx, needle.size()) == needle)
                    return idx;
        }

        return -1;
    }
};