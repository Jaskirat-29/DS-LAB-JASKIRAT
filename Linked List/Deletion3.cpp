#include<iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

struct node *createnewnode(int item)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->info = item;
    new_node->next = NULL;
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
    ptr->next = start;
    start = ptr;
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
    temp->next = new_node;
    cout << "Item inserted at position " << pos << "\n";
}

void delet_frompos(){
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
        free(temp);
        return;
    }

    struct node *temp = start;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        cout << "Position out of bounds\n";
        return;
    }

    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    cout << "Deleted element: " << to_delete->info << "\n";
    free(to_delete);
}

int main() {
    int choice = 0;
    while (choice != 4)
    {
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