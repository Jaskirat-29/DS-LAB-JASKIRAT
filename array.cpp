#include <iostream>
using namespace std;
int main() {
    int arr[100];
    int n, pos, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  }
    cout << "\nArray elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";}
    cout << "\n";
    cout << "\nEnter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
    } else {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1]; }
        arr[pos] = value;
        n++;  }
    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "\nEnter position to delete (0-based index): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
    } else {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    cout << "Array after deletion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
