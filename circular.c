#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }
    struct Node* last = head;
    while (last->next != head) last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}

void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int search(int key) {
    if (head == NULL) return -1;
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);

    printf("List: ");
    traverse();

    deleteAtBeginning();
    printf("After deletion: ");
    traverse();

    int key = 20;
    int pos = search(key);
    if (pos != -1)
        printf("%d found at position %d\n", key, pos);
    else
        printf("%d not found\n", key);

    return 0;
}
