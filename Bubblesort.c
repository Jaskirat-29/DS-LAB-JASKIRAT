#include <stdio.h>
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        
        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void printArray(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a)/sizeof(a[0]);
    
    printf("Unsorted array: \n");
    printArray(a, n);
    
    bubbleSort(a, n);
    
    printf("Sorted array: \n");
    printArray(a, n);
    
    return 0;
}