#include "sorting.h"

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, choice, key;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter the number of elements in the array (maximum 100): ";
            cin >> n;

            if (n > 100) {
                cout << "Number of elements exceeds the maximum allowed (100). Please try again.\n";
                continue;
            }

            cout << "Enter the elements of the array:\n";
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }

            cout << "Enter the element to search for: ";
            cin >> key;

            if (choice == 1) {
                int result = linearSearch(arr, n, key);
                if (result != -1) {
                    cout << "Element found at index " << result << " (0-based).\n";
                } else {
                    cout << "Element not found in the array.\n";
                }
            } else if (choice == 2) {
                cout << "Sorting the array using Bubble Sort for Binary Search...\n";
                bubbleSort(arr, n); // Sort the array before binary search
                cout << "Sorted Array:\n";
                printArray(arr, n);

                int result = binarySearch(arr, n, key);
                if (result != -1) {
                    cout << "Element found at index " << result << " (0-based).\n";
                } else {
                    cout << "Element not found in the array.\n";
                }
            }
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
