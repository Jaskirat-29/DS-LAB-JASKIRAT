#include<iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *start;

struct node *createnewnode(int item)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
};

void insert(){
    struct node *ptr;
    int item;
    cout<<"Enter item value:";
    cin>>item;
    ptr= createnewnode(item);
    if (ptr==NULL){
        cout<<"Failed to allocate memory";
    }
    else if(start==NULL){
        start=ptr;
        cout<<"Item inserted\n";
    }
    else {
        ptr->next=start;
        start=ptr;
        cout<<"Item inserted\n";
    }
}

void display(){
    if (start==NULL){
        cout<<"Linked list is empry\n";
    }
    else {
        struct node *temp;
        temp=start;
        while (temp != NULL)
        {
            cout<<"The element is:"<<temp->info<<"\n";
            temp=temp->next;
        }
        
    }
}
void insert_end(){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    int item;
    cout<<"Enter value to insert at the end:"<<"\n";
    cin>>item;
    new_node->info=item;
    new_node->next=NULL;
    struct node *temp;
    temp=start;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    
}
main() {
    int choice=0;
    while (choice!=3)
    {
        cout<<"Press 1. To insert item at beginning\n 2.Press 2. To Display\n 3.To exit";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        default:
            cout<<"Wrong Input\n";
            break;
        }
    }
    int perform;
    cout<<"Press 1 to insert element at the end\n";
    cin>>perform;
    if (perform==1){
        insert_end();
    }
    else {
        cout<<"Wrong input";
    }
    display();
}