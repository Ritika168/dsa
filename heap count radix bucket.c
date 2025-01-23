#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Function to perform Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 1;
    int temp;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Function to perform Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j;
    if (n <= 0)
        return;
    
    int max = arr[0];
    int min = arr[0];
    
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    
    int bucketCount = max - min + 1;
    int *bucket[bucketCount];
    
    for (i = 0; i < bucketCount; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] == i + min) {
                bucket[i][j] = arr[j];
            }
        }
    }
    
    printf("\nSorted Array: ");
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < n; j++) {
            if (bucket[i][j] == i + min)
                printf("%d ", bucket[i][j]);
        }
    }
}

int main() {
    int n, choice;
    int arr[MAX];
    
    // Take input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose a sorting algorithm:\n");
    printf("1. Heap Sort\n");
    printf("2. Counting Sort\n");
    printf("3. Radix Sort\n");
    printf("4. Bucket Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            heapSort(arr, n);
            printf("Sorted array using Heap Sort: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        
        case 2:
            countingSort(arr, n);
            printf("Sorted array using Counting Sort: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        
        case 3:
            radixSort(arr, n);
            printf("Sorted array using Radix Sort: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        
        case 4:
            bucketSort(arr, n);
            break;
        
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
