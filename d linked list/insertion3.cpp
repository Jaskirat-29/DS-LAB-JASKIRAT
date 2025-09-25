#include<iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

struct node *createnewnode(int item)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->info = item;
    new_node->next = NULL;
    new_node->prev = NULL; // prev pointer initialized
    return new_node;
}

void insert(){
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
        start->prev = ptr; // update prev of old start
        start = ptr;
    }

    cout << "Item inserted\n";
}

void display(){
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

void insert_pos(){
    int item, pos;
    cout << "Enter value to insert: ";
    cin >> item;
    cout << "Enter the position to insert at: ";
    cin >> pos;

    struct node *new_node = createnewnode(item);

    if(pos == 1){
        new_node->next = start;
        if(start != NULL) start->prev = new_node; // update prev of old start
        start = new_node;
        return;
    }

    struct node *temp = start;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Position out of bounds\n";
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    if(temp->next != NULL) temp->next->prev = new_node; // update prev of next node
    temp->next = new_node;
    new_node->prev = temp; // set prev of new node

    cout << "Item inserted at position " << pos << "\n";
}

int main() {
    int choice = 0;
    while(choice != 3){
        cout << "Press 1. To insert item at beginning\n2. To Display\n3. To exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                break;
            default:
                cout << "Wrong Input\n";
        }
    }

    int perform;
    cout << "Press 1 to insert element at a specific position: ";
    cin >> perform;
    if(perform == 1){
        insert_pos();
        display();
    } else {
        cout << "Wrong input\n";
    }

    return 0;
}