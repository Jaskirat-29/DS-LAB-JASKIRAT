#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                chars.push(ch);
            } else {
                if (chars.empty()) {
                    return false;
                }
                char topChar = chars.top();
                chars.pop();
                if ((ch == ')' && topChar != '(') ||
                    (ch == '}' && topChar != '{') ||
                    (ch == ']' && topChar != '[')) {
                    return false;
                }
            }
        }
        return chars.empty();
    }
};

