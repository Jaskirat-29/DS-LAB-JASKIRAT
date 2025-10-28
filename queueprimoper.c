#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    }
    printf("%d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int peek() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front];
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    printf("%d\n", peek());
    printf("%d\n", isFull());
    printf("%d\n", isEmpty());
    return 0;
}
