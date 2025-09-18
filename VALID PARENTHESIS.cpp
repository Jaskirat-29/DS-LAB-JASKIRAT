#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int> chars;
        int top = -1;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                chars.push(ch);
            } else {
                if (chars.empty()) {
                    return false;
                }
                char top = chars.top();
                chars.pop();
                if (ch == ')' && top != '(') {

                    return false;
                }
                if (ch == '}' && top != '{') {
                    return false;
                }
                if (ch == ']' && top != '[') {
                    return false;
                }
            }
        }
        return chars.empty();
    }
};