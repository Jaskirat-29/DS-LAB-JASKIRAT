#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool empty() { return top == -1; }
};

int evaluatePostfix(string exp) {
    Stack s;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string exp;
    cout << "Enter Postfix Expression: ";
    getline(cin, exp);
    cout << "Result: " << evaluatePostfix(exp) << "\n";
    return 0;
}
