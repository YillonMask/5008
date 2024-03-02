// find the kth largest element in the array using priority queue and max heap
#include <stdio.h>
#include <stdlib.h>

// 1. structure priority queue to store heap array and size of heap:PrioQ
typedef struct PrioQ
{
    int *heap;
    int size;
} PrioQ_t;
// 2.a function to initialize the priority queue:initprioQ
PrioQ_t *initprioQ(int size)
{
    PrioQ_t *pq = (PrioQ_t *)malloc(sizeof(PrioQ_t));
    pq->heap = (int *)malloc(size * sizeof(int));
    pq->size = 0;
    return pq;
}
// 3. an insert function to insert value in heap:insert
void insert(PrioQ_t *pq, int value)
{
    pq->heap[pq->size] = value;
    int i = pq->size;
    pq->size++;
    while (i > 0 && pq->heap[i] > pq->heap[(i - 1) / 2])
    {
        int temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
// 4. a function to maintain the max heap property:maxheapifyup
// 从下至上，比较child与parent
void maxheapifyup(PrioQ_t *pq, int i)
{
    while (i > 0 && pq->heap[i] > pq->heap[(i - 1) / 2])
    {
        int temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;
        // 此时将i转换成这一层的parent，继续向上比较
        i = (i - 1) / 2;
    }
}
// 5. swap() function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 6. a function to extract the max(root of the heap):extract
void maxheapifyDown(PrioQ_t *pq, int i);
int extract(PrioQ_t *pq)
{
    int max = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    maxheapifyDown(pq, 0);
    return max;
}
// 7. a function to heapify down:maxheapify 从上到下 比较parent 与child
void maxheapifyDown(PrioQ_t *pq, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < pq->size && pq->heap[left] > pq->heap[largest])
    {
        largest = left;
    }
    if (right < pq->size && pq->heap[right] > pq->heap[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&pq->heap[i], &pq->heap[largest]);
        // 继续向下比较 largest这一层比较的child
        maxheapifyDown(pq, largest);
    }
}
// 8. a function to find the kth largest:findKthLargest
int findKthLargest(int arr[], int n, int k)
{
    PrioQ_t *pq = initprioQ(n);
    for (int i = 0; i < n; i++)
    {
        insert(pq, arr[i]);
    }
    for (int i = 0; i < k - 1; i++)
    {
        extract(pq);
    }
    return pq->heap[0];
}
// 9.free the memory: freeQ():
void freeQ(PrioQ_t *pq)
{
    free(pq->heap);
    free(pq);
}
// 10.the main function
int main()
{
    int arr[] = {7, 5, 8, 12, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("The %dth largest element is %d\n", k, findKthLargest(arr, n, k));
    return 0;
}