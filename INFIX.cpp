#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
bool isOp(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;   // takes input like A+B*C

    int n = s.size();
    char st[100];  // stack array (fixed, simple)
    int top = -1;
    string out = "";

    for (int i=0; i<n; i++) {
        char c = s[i];
        if (isalnum(c)) {
            out += c;          // operand
        }
        else if (c == '(') {
            st[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && st[top] != '(') out += st[top--];
            top--;  // pop '('
        }
        else if (isOp(c)) {
            while (top >= 0 && isOp(st[top]) &&
                   (prec(st[top]) > prec(c) ||
                   (prec(st[top]) == prec(c) && c != '^'))) {
                out += st[top--];
            }
            st[++top] = c;
        }
    }
    while (top >= 0) {
        if (st[top] != '(') out += st[top];
        top--;
    }

    cout << "Postfix: " << out << endl;
    return 0;
}