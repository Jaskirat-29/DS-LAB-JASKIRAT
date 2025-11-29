#include <stdio.h>

int main() {
    int n, i, key, choice, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("1 Linear Search\n2 Binary Search\n");
    scanf("%d", &choice);

    scanf("%d", &key);

    if (choice == 1) {
        for (i = 0; i < n; i++) {
            if (a[i] == key) {
                printf("Found at index %d", i);
                return 0;
            }
        }
        printf("Not found");
    }

    else if (choice == 2) {
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] == key) {
                printf("Found at index %d", mid);
                return 0;
            } else if (a[mid] < key)
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("Not found");
    }

    return 0;
}
