#include <iostream>
using namespace std;

// Function prototypes
void traverseArray(int arr[], int size);
void insertAtBeginning(int arr[], int& size, int capacity, int value);
void insertAtLocation(int arr[], int& size, int capacity, int value, int position);
void insertAtEnd(int arr[], int& size, int capacity, int value);
void deleteAtBeginning(int arr[], int& size);
void deleteAtLocation(int arr[], int& size, int position);
void deleteAtEnd(int arr[], int& size);
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int low, int high, int key);
void insertionSort(int arr[], int size);

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value, position, key;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Traverse array\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at user-specific location\n";
        cout << "4. Insert at end\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from user-specific location\n";
        cout << "7. Delete from end\n";
        cout << "8. Linear search in array\n";
        cout << "9. Binary search in array\n";
        cout << "10. Insertion sort on array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverseArray(arr, size);
                break;
            case 2:
                if (size < MAX_SIZE) {
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insertAtBeginning(arr, size, MAX_SIZE, value);
                } else {
                    cout << "Array is full\n";
                }
                break;
            case 3:
                if (size < MAX_SIZE) {
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter position to insert at (0-based index): ";
                    cin >> position;
                    if (position >= 0 && position <= size) {
                        insertAtLocation(arr, size, MAX_SIZE, value, position);
                    } else {
                        cout << "Invalid position\n";
                    }
                } else {
                    cout << "Array is full\n";
                }
                break;
            case 4:
                if (size < MAX_SIZE) {
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insertAtEnd(arr, size, MAX_SIZE, value);
                } else {
                    cout << "Array is full\n";
                }
                break;
            case 5:
                if (size > 0) {
                    deleteAtBeginning(arr, size);
                } else {
                    cout << "Array is empty\n";
                }
                break;
            case 6:
                if (size > 0) {
                    cout << "Enter position to delete from (0-based index): ";
                    cin >> position;
                    if (position >= 0 && position < size) {
                        deleteAtLocation(arr, size, position);
                    } else {
                        cout << "Invalid position\n";
                    }
                } else {
                    cout << "Array is empty\n";
                }
                break;
            case 7:
                if (size > 0) {
                    deleteAtEnd(arr, size);
                } else {
                    cout << "Array is empty\n";
                }
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                position = linearSearch(arr, size, key);
                if (position != -1) {
                    cout << "Element found at index " << position << endl;
                } else {
                    cout << "Element not found\n";
                }
                break;
            case 9:
                cout << "Enter size of sorted array: ";
                cin >> size;
                cout << "Enter sorted array elements:\n";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                cout << "Enter value to search: ";
                cin >> key;
                position = binarySearch(arr, 0, size - 1, key);
                if (position != -1) {
                    cout << "Element found at index " << position << endl;
                } else {
                    cout << "Element not found\n";
                }
                break;
            case 10:
                cout << "Enter size of array: ";
                cin >> size;
                cout << "Enter array elements:\n";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                insertionSort(arr, size);
                cout << "Sorted array:\n";
                traverseArray(arr, size);
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}

// Function implementations

// Traverse the array
void traverseArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert at the beginning of the array
void insertAtBeginning(int arr[], int& size, int capacity, int value) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

// Insert at a user-specified location in the array
void insertAtLocation(int arr[], int& size, int capacity, int value, int position) {
    if (size >= capacity) {
        cout << "Array is full\n";
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    size++;
}

// Insert at the end of the array
void insertAtEnd(int arr[], int& size, int capacity, int value) {
    if (size >= capacity) {
        cout << "Array is full\n";
        return;
    }
    arr[size] = value;
    size++;
}

// Delete from the beginning of the array
void deleteAtBeginning(int arr[], int& size) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Delete from a user-specified location in the array
void deleteAtLocation(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Delete from the end of the array
void deleteAtEnd(int arr[], int& size) {
    if (size > 0) {
        size--;
    }
}

// Linear search in the array
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary search using recursion in a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

// Insertion sort on the array
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
