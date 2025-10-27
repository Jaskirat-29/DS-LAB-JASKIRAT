#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int searchNode(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return position;
        temp = temp->next;
        position++;
    }
    return -1;}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    int key = 20;
    int pos = searchNode(head, key);
    if (pos != -1)
        printf("%d found at position %d\n", key, pos);
    else
        printf("%d not found\n", key);
    return 0;
}

