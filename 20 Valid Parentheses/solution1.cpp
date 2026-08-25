class Solution {
public:
    bool isValid(string s) {
        stack<char> container;

        for (int idx = 0; idx < s.size(); idx++) {
            if (s[idx] == '(' ||
                s[idx] == '[' ||
                s[idx] == '{') {
                container.push(s[idx]);
            } else if (s[idx] == ')' ||
                       s[idx] == ']' ||
                       s[idx] == '}') {
                if (container.empty()) {
                    return false;
                }

                if ((s[idx] == ')' && container.top() == '(') ||
                    (s[idx] == ']' && container.top() == '[') ||
                    (s[idx] == '}' && container.top() == '{')) {
                    container.pop();
                } else {
                    return false;
                }
            }
        }

        return container.empty();
    }
};
