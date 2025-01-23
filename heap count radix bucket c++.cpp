#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100 // Maximum range for counting and bucket sort arrays

// Heapify function for Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i; // Root node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting Sort
void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX] = {0};

    // Count occurrences of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Accumulate counts
    for (int i = 1; i < MAX; i++)
        count[i] += count[i - 1];

    // Place elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted output back to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Get maximum value for Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting Sort helper for Radix Sort
void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences for each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Accumulate counts
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy sorted output back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    vector<float> buckets[MAX];

    // Place array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * MAX;
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < MAX; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (float val : buckets[i])
            arr[index++] = val;
    }
}

// Helper function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original Array (Heap Sort): ";
    printArray(arr1, n1);
    heapSort(arr1, n1);
    cout << "Sorted Array (Heap Sort): ";
    printArray(arr1, n1);

    int arr2[] = {4, 2, 2, 8, 3, 3, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "\nOriginal Array (Counting Sort): ";
    printArray(arr2, n2);
    countingSort(arr2, n2);
    cout << "Sorted Array (Counting Sort): ";
    printArray(arr2, n2);

    int arr3[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "\nOriginal Array (Radix Sort): ";
    printArray(arr3, n3);
    radixSort(arr3, n3);
    cout << "Sorted Array (Radix Sort): ";
    printArray(arr3, n3);

    float arr4[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    cout << "\nOriginal Array (Bucket Sort): ";
    for (int i = 0; i < n4; i++) cout << arr4[i] << " ";
    cout << endl;

    bucketSort(arr4, n4);
    cout << "Sorted Array (Bucket Sort): ";
    for (int i = 0; i < n4; i++) cout << arr4[i] << " ";
    cout << endl;

    return 0;
}
