#include <iostream>
using namespace std;

#define N 10
char num[N];
int Top = -1;

void push() {
    if (Top == N - 1) {
        cout << "Overflow\n";
    } else {
        char item;
        cout << "Enter element to push: ";
        cin >> item;
        Top++;
        num[Top] = item;
        cout << "Pushed " << item << " onto the stack.\n";
    }
}

void pop() {
    if (Top == -1) {
        cout << "Underflow\n";
    } else {
        char item = num[Top];
        cout << "Popped element: " << item << endl;
        Top--;
    }
}

void display() {
    if (Top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements:\n";
        for (int i = Top; i >= 0; i--) {
            cout << num[i] << "\n";
        }
    }
}

int main() {
    char choice;
    while (true) {   
        cout << "\nStack Operations Menu\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': push(); break;
            case '2': pop(); break;
            case '3': display(); break;
            case '4': return 0; 
            default: cout << "Wrong input\n";
        }
    }
}
