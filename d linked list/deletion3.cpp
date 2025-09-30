#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;

struct node *createnewnode(int item) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->info = item;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert() {
    int item;
    cout << "Enter item value: ";
    cin >> item;
    struct node *ptr = createnewnode(item);
    if(ptr == NULL){
        cout << "Failed to allocate memory\n";
        return;
    }
    if(start == NULL){
        start = ptr;
    } else {
        ptr->next = start;
        start->prev = ptr;
        start = ptr;
    }
    cout << "Item inserted\n";
}

void display() {
    if(start == NULL){
        cout << "Linked list is empty\n";
        return;
    }
    struct node *temp = start;
    while(temp != NULL){
        cout << "The element is: " << temp->info << "\n";
        temp = temp->next;
    }
}

void delet_frompos() {
    if(start == NULL){
        cout << "Linked list is empty\n";
        return;
    }
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;
    if(pos == 1){
        struct node *temp = start;
        cout << "Deleted element: " << temp->info << "\n";
        start = start->next;
        if(start != NULL) start->prev = NULL;
        free(temp);
        return;
    }
    struct node *temp = start;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Position out of bounds\n";
        return;
    }
    cout << "Deleted element: " << temp->info << "\n";
    if(temp->prev != NULL) temp->prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "\nPress 1. To insert item at beginning\n2. To Display\n3. To delete from specified position\n4. To exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                delet_frompos();
                break;
            case 4:
                break;
            default:
                cout << "Wrong Input\n";
        }
    }
}