#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100]; 
    int choice, n;

    do {
        cout << "\nMenu:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
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

            switch (choice) {
                case 1:
                    bubbleSort(arr, n);
                    cout << "Array sorted using Bubble Sort:\n";
                    break;
                case 2:
                    selectionSort(arr, n);
                    cout << "Array sorted using Selection Sort:\n";
                    break;
                case 3:
                    insertionSort(arr, n);
                    cout << "Array sorted using Insertion Sort:\n";
                    break;
            }
            printArray(arr, n);
        } else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
