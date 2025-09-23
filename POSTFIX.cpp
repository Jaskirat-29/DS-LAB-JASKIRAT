#include <iostream>
using namespace std;

#define N 10
char ele[N];
int top = -1;

void push(char x) {
    if (top == N - 1) {
        cout << "Stack overflow\n";
    } else {
        ele[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        cout << "Underflow\n";
        return 0;
    } else {
        return ele[top--];
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixtopostfix(string infix) {
    string postfix = "";
    for (char c : infix) {
        if (!isOperator(c) && c != '(' && c != ')') {
            postfix += c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && ele[top] != '(') {
                postfix += pop();
            }
            if (top != -1 && ele[top] == '(') {
                pop();
            }
        } else if (isOperator(c)) {
            while (top != -1 && precedence(ele[top]) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix += pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixtopostfix(infix);
    cout << "Postfix expression: " << postfix << "\n";

    return 0;
}