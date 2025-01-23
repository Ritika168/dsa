#include <stdio.h>

#define SIZE 100

void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int arr[], int *n, int value) {
    if (*n >= SIZE) {
        printf("Array is full.\n");
        return;
    }
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
}

void insertAtPosition(int arr[], int *n, int pos, int value) {
    if (*n >= SIZE) {
        printf("Array is full.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void insertAtEnd(int arr[], int *n, int value) {
    if (*n >= SIZE) {
        printf("Array is full.\n");
        return;
    }
    arr[*n] = value;
    (*n)++;
}

void deleteAtBeginning(int arr[], int *n) {
    if (*n <= 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void deleteAtPosition(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void deleteAtEnd(int arr[], int *n) {
    if (*n <= 0) {
        printf("Array is empty.\n");
        return;
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] > key) return binarySearch(arr, low, mid - 1, key);
    else return binarySearch(arr, mid + 1, high, key);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array sorted using insertion sort.\n");
}

int main() {
    int arr[SIZE];
    int n = 0;
    int choice, value, pos, key, result;

    do {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Position\n");
        printf("7. Delete at End\n");
        printf("8. Linear Search\n");
        printf("9. Binary Search (requires sorted array)\n");
        printf("10. Insertion Sort\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(arr, &n, value);
                traverse(arr, n);
                break;
            case 3:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtPosition(arr, &n, pos, value);
                traverse(arr, n);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(arr, &n, value);
                traverse(arr, n);
                break;
            case 5:
                deleteAtBeginning(arr, &n);
                traverse(arr, n);
                break;
            case 6:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                deleteAtPosition(arr, &n, pos);
                traverse(arr, n);
                break;
            case 7:
                deleteAtEnd(arr, &n);
                traverse(arr, n);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1) printf("Element found at index %d\n", result);
                else printf("Element not found\n");
                traverse(arr, n);
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, 0, n - 1, key);
                if (result != -1) printf("Element found at index %d\n", result);
                else printf("Element not found\n");
                traverse(arr, n);
                break;
            case 10:
                insertionSort(arr, n);
                traverse(arr, n);
                break;
            case 11:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 11);

    return 0;
}
