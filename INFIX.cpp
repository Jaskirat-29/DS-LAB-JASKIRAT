#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool empty() { return top == -1; }
};
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPostfix(string exp) {
    Stack s;
    string result = "";
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == ' ') continue;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
            result += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.peek() != '(') {
                result += s.pop();
            }
            if (!s.empty() && s.peek() == '(') s.pop();
        }
        else {
            while (!s.empty() && precedence(s.peek()) >= precedence(c)) {
                result += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        result += s.pop();
    }
    return result;
}
int main() {
    string exp;
    cout << "Enter Infix Expression: ";
    cin >> exp;
    cout << "Postfix: " << infixToPostfix(exp) << "\n";
    return 0;
}
