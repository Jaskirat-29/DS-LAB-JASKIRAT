#include <stdio.h>

void bubblesort(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array after Bubble sort: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

void insertion(int a[], int size)
{
    int i, j, current;
    for (i = 1; i < size; i++)
    {
        current = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
    printf("Array after Insertion sort: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

void selection(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        int minindex = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        temp = a[minindex];
        a[minindex] = a[i];
        a[i] = temp;
    }
    printf("Array after Selection sort: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main()
{
    int arr[100];
    int n, i;
    char choice;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n=====SORTING OPERATIONS=====\n");
    printf("B = Bubble Sort\nI = Insertion Sort\nS = Selection Sort\nM = Merge Sort\nQ = Quick Sort");
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'B':
    case 'b':
        bubblesort(arr, n);
        break;

    case 'I':
    case 'i':
        insertion(arr, n);
        break;

    case 'S':
    case 's':
        selection(arr, n);
        break;

    case 'M':
    case 'm':
        mergesort(arr, 0, n - 1);
        printf("Array after Merge sort: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        break;

    case 'Q':
    case 'q':
        quicksort(arr, 0, n - 1);
        printf("Array after Quick sort: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        break;

    default:
        printf("Invalid choice!");
    }

    return 0;
}