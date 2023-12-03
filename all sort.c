#include <stdio.h>
#include <stdlib.h>

// Function declarations
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heapSort(int arr[], int n);
void buildMaxHeap(int arr[], int n);
void maxHeapify(int arr[], int n, int i);

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read an array from user input
void readArray(int arr[], int n, int i) {
    if (i < n) {
        scanf("%d", &arr[i]);
        readArray(arr, n, i + 1);
    }
}

int main() {
    int n;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read the array elements
    printf("Enter the elements of the array: ");
    readArray(arr, n, 0);

    // Bubble Sort
    printf("Bubble Sort: ");
    bubbleSort(arr, n);
    printArray(arr, n);

    // Selection Sort
    printf("Selection Sort: ");
    selectionSort(arr, n);
    printArray(arr, n);

    // Insertion Sort
    printf("Insertion Sort: ");
    insertionSort(arr, n);
    printArray(arr, n);

    // Merge Sort
    printf("Merge Sort: ");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    // Quick Sort
    printf("Quick Sort: ");
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    // Heap Sort
    printf("Heap Sort: ");
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    if (n <= 1)
        return;

    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap arr[i] and arr[i+1]
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    if (n <= 1)
        return;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partition index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = low - 1;

    // Traverse through all elements
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the partition index
    return i + 1;
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    buildMaxHeap(arr, n);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Swap root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

