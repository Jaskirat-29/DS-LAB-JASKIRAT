#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int info;
    struct node*next;
};
struct node*start=NULL, *new_node;
struct node *create_node(int item){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=item;
    new_node->next=NULL;
    return new_node;

};
void insert(){
    struct node *ptr;
    int item;
    cout<<"enter the item:";
    cin>>item;
    ptr=create_node(item);
if(ptr==NULL){
    cout<<"failed to allocate the memory";

}
else if(start==NULL){
    start=ptr;
}
else{
    ptr->next=start;
    start=ptr;
}
}
void display(){
    if(start==NULL){
        cout<<"LL is empty"<<endl;
    }
    else{
        struct node*temp;
        temp=start;
        while(temp!=NULL){
            cout<<temp->info<<endl;
            temp=temp->next;

        }

    }
}
void del(){
  
     if(start==NULL){
        cout<<"LL is empty"<<endl;
    }
    else if(start->next=NULL){
        cout<<start->info;
        free(start);

    }
    else{
        struct node*temp=start;
        struct node*ptr=start-> next;
        cout<<temp-> info;
        free(temp);
        start=ptr;
    }
    }

 int main(){
    int choice=0;
   
    while(choice!=3){
       
        cout<<"1.Press 1 to insert item\n2. Press 2 to display\n3. Press 3 to delete\n4. Press 4 to exit\n";
         cin>>choice;
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
            case 3: 
            del();
            break;
            case 4:
            exit(0);
            break;
            default:
            cout<<"Invalid choice";
            break;
        }
}
}



