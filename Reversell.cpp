#include<iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

node* start = NULL;


node* create_node(int item) {
    node* new_node = new node;
    new_node->info = item;
    new_node->next = NULL;
    return new_node;
}


void insert() {
    int item;
    cout << "Enter the item: ";
    cin >> item;

    node* ptr = create_node(item);

    if (start == NULL) {
        start = ptr;
    } else {
        ptr->next = start;
        start = ptr;
    }
}


void display() {
    if (start == NULL) {
        cout << "LL is empty" << endl;
    } else {
        node* temp = start;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


void reverse() {
    node* prev = NULL;
    node* temp = start;
    node* next = NULL;

    while (temp != NULL) {
        next = temp->next;   
        temp->next = prev;   
        prev = temp;         
        temp = next;         
    }
    start = prev;

    cout << "List reversed successfully!" << endl;
}

int main() {
    int choice = 0;

    while (choice != 4) {
        cout << "\n1. Insert item\n2. Display\n3. Reverse\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                reverse();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
