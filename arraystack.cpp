#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return; }
        arr[++top] = x;  }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return; }
        cout << "Popped: " << arr[top--] << "\n";
    }
    void peek() {
        if (top == -1) cout << "Stack is Empty\n";
        else cout << "Top element: " << arr[top] << "\n"; }
    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return; }
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n"; }
};
int main() {
    Stack s;
    int choice, val;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n"; }
    } while (choice != 5);
    return 0;} 
