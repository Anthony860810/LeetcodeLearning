class Solution {
public:
    string simplifyPath(string path) {
        stack<string> buf;
        string ans = "";
        for (int idx = 0; idx < path.size(); idx++) {
            if (path[idx] == '/')
                continue;
            
            string str;
            while (idx < path.size() && path[idx] != '/') {
                str += path[idx];
                idx++;
            }

            if (str == ".") {
                continue;
            } else if (str == "..") {
                if (!buf.empty())
                    buf.pop();
            } else {
                buf.push(str);
            }
        }

    if (buf.empty())
        return "/";
    
    while (!buf.empty()) {
        ans = '/' + buf.top() + ans;
        buf.pop();
    }

    return ans;
    }
};