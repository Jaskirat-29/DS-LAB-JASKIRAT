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
    new_node->prev = NULL;
    return new_node;
}

void insert(){
    struct node *ptr;
    int item;
    cout << "Enter item value: ";
    cin >> item;
    ptr = createnewnode(item);
    if (ptr == NULL){
        cout << "Failed to allocate memory\n";
    }
    else if(start == NULL){
        start = ptr;
        cout << "Item inserted\n";
    }
    else {
        ptr->next = start;
        start->prev=ptr;
        start = ptr;
        cout << "Item inserted\n";
    }
}

void display(){
    if (start == NULL){
        cout << "Linked list is empty\n";
    }
    else {
        struct node *temp = start;
        while (temp != NULL)
        {
            cout << "The element is: " << temp->info << "\n";
            temp = temp->next;
        }
    }
}

// void insert_pos(){
//     int item, pos;
//     cout << "Enter value to insert: ";
//     cin >> item;
//     cout << "Enter the position to insert at: ";
//     cin >> pos;

//     struct node *new_node = createnewnode(item);

//     if(pos == 1){
//         new_node->next = start;
//         start = new_node;
//         return;
//     }

//     struct node *temp = start;
//     for(int i = 1; i < pos - 1 && temp != NULL; i++){
//         temp = temp->next;
//     }

//     if(temp == NULL){
//         cout << "Position out of bounds\n";
//         free(new_node);
//         return;
//     }

//     new_node->next = temp->next;
//     temp->next = new_node;
//     cout << "Item inserted at position " << pos << "\n";
// }
void delet (){
    if (start == NULL){
        cout << "Linked list is empty\n";
    }
    else if (start->next==NULL){
        cout<<start->info;
        free(start);
    }
    else {
        struct node *temp=start;
        struct node *ptr=start->next;
        cout<<temp->info;
        free(temp);
        start=ptr;
    }
}

int main() {
    int choice = 0;
    while (choice != 4)
    {
        cout << "Press 1. To insert item at beginning\n2. To Display\n3. To delete from beginnig\n4. To exit";
        cin >> choice;
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                delet();
                break;
            case 4:
                break;
            default:
                cout << "Wrong Input\n";
        }
    }
}