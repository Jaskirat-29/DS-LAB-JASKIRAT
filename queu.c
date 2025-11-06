#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int lqueue[SIZE];
int lfront = -1, lrear = -1;
int cqueue[SIZE];
int cfront = -1, crear = -1;
int dqueue[SIZE];
int dfront = -1, drear = -1;
void linearEnqueue() {
    int val;
    if (lrear == SIZE - 1)
        printf("Queue Overflow!\n");
    else {
        if (lfront == -1) lfront = 0;
        printf("Enter element to insert: ");
        scanf("%d", &val);
        lqueue[++lrear] = val;
        printf("%d inserted.\n", val);
    }
}
void linearDequeue() {
    if (lfront == -1 || lfront > lrear)
        printf("Queue Underflow!\n");
    else {
        printf("%d deleted.\n", lqueue[lfront]);
        lfront++;
        if (lfront > lrear) lfront = lrear = -1;
    }
}
void linearDisplay() {
    if (lfront == -1)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = lfront; i <= lrear; i++)
            printf("%d ", lqueue[i]);
        printf("\n");
    }
}
void circularEnqueue() {
    int val;
    if ((crear + 1) % SIZE == cfront)
        printf("Circular Queue Overflow!\n");
    else {
        printf("Enter element to insert: ");
        scanf("%d", &val);
        if (cfront == -1)
            cfront = crear = 0;
        else
            crear = (crear + 1) % SIZE;
        cqueue[crear] = val;
        printf("%d inserted.\n", val);
    }
}
void circularDequeue() {
    if (cfront == -1)
        printf("Circular Queue Underflow!\n");
    else {
        printf("%d deleted.\n", cqueue[cfront]);
        if (cfront == crear)
            cfront = crear = -1;
        else
            cfront = (cfront + 1) % SIZE;
    }
}
void circularDisplay() {
    if (cfront == -1)
        printf("Circular Queue is empty.\n");
    else {
        printf("Circular Queue elements: ");
        int i = cfront;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == crear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}
void dequeInsertFront() {
    int val;
    if ((dfront == 0 && drear == SIZE - 1) || (dfront == drear + 1))
        printf("Deque Overflow!\n");
    else {
        printf("Enter element to insert at front: ");
        scanf("%d", &val);
        if (dfront == -1)
            dfront = drear = 0;
        else if (dfront == 0)
            dfront = SIZE - 1;
        else
            dfront--;
        dqueue[dfront] = val;
        printf("%d inserted at front.\n", val);
    }
}
void dequeInsertRear() {
    int val;
    if ((dfront == 0 && drear == SIZE - 1) || (dfront == drear + 1))
        printf("Deque Overflow!\n");
    else {
        printf("Enter element to insert at rear: ");
        scanf("%d", &val);
        if (dfront == -1)
            dfront = drear = 0;
        else if (drear == SIZE - 1)
            drear = 0;
        else
            drear++;
        dqueue[drear] = val;
        printf("%d inserted at rear.\n", val);
    }
}
void dequeDeleteFront() {
    if (dfront == -1)
        printf("Deque Underflow!\n");
    else {
        printf("%d deleted from front.\n", dqueue[dfront]);
        if (dfront == drear)
            dfront = drear = -1;
        else if (dfront == SIZE - 1)
            dfront = 0;
        else
            dfront++;
    }
}
void dequeDeleteRear() {
    if (drear == -1)
        printf("Deque Underflow!\n");
    else {
        printf("%d deleted from rear.\n", dqueue[drear]);
        if (dfront == drear)
            dfront = drear = -1;
        else if (drear == 0)
            drear = SIZE - 1;
        else
            drear--;
    }
}
void dequeDisplay() {
    if (dfront == -1)
        printf("Deque is empty.\n");
    else {
        printf("Deque elements: ");
        int i = dfront;
        while (1) {
            printf("%d ", dqueue[i]);
            if (i == drear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}
int main() {
    int mainChoice, choice;
    while (1) {
        printf("\n=========================================\n");
        printf("QUEUE TYPES MENU\n");
        printf("1. Linear Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Double Ended Queue (Deque)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice) {
            case 1:
                while (1) {
                    printf("\n--- Linear Queue Operations ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1: linearEnqueue(); break;
                        case 2: linearDequeue(); break;
                        case 3: linearDisplay(); break;
                        case 4: goto endLinear;
                        default: printf("Invalid choice!\n");
                    }
                }
                endLinear:
                break;
            case 2:
                while (1) {
                    printf("\n--- Circular Queue Operations ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1: circularEnqueue(); break;
                        case 2: circularDequeue(); break;
                        case 3: circularDisplay(); break;
                        case 4: goto endCircular;
                        default: printf("Invalid choice!\n");
                    }
                }
                endCircular:
                break;
            case 3:
                while (1) {
                    printf("\n--- Double Ended Queue Operations ---\n");
                    printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1: dequeInsertFront(); break;
                        case 2: dequeInsertRear(); break;
                        case 3: dequeDeleteFront(); break;
                        case 4: dequeDeleteRear(); break;
                        case 5: dequeDisplay(); break;
                        case 6: goto endDeque;
                        default: printf("Invalid choice!\n");
                    }
                }
                endDeque:
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid main menu choice!\n");
        }
    }
    return 0;
}