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
    bool empty() { return top == -1; }
    char peek() { return arr[top]; }
};

bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}