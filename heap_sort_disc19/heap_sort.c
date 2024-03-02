
#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if it is not greater than children, swap the node and children.
    if (left < n && arr[left] > arr[largest])
    {
        // TODO: CODE HERE;
        int temp = arr[left];
        arr[left] = arr[largest];
        arr[largest] = temp;
    }
    if (right < n && arr[right] > arr[largest])
    {
        // TODO: CODE HERE;
        int temp = arr[right];
        arr[right] = arr[largest];
        arr[largest] = temp;
    }
    if (largest != i)
    {
        // if the largest is not at index i, swap it with index i
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    // Build max heap
    buildMaxHeap(arr, n);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Swap the root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        // TODO: CODE HERE;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    // Initialize an array
    int arr[] = {7, 5, 8, 12, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Perform heap sort
    heapSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}