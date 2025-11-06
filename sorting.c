#include <stdio.h>
void printArray(int a[], int n) {
    int i,j;
    for ( i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubbleSort(int a[], int n) {
    int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int a[], int n) {
    int i,j;
    for ( i = 0; i < n - 1; i++) {
        int minIndex = i;
        for ( j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}
void insertionSort(int a[], int n) {
    int i,j;
    for ( i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main() {
    int i,j;
    int a[100], n, choice;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Original array: ");
    printArray(a, n);
    
    switch (choice) {
        case 1:
            bubbleSort(a, n);
            printf("Sorted with Bubble Sort: ");
            break;
        case 2:
            selectionSort(a, n);
            printf("Sorted with Selection Sort: ");
            break;
        case 3:
            insertionSort(a, n);
            printf("Sorted with Insertion Sort: ");
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printArray(a, n);
    return 0;
}
