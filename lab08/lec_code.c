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
    // pq is size of its struct PrioQ_t
    PrioQ_t *pq = (PrioQ_t *)malloc(sizeof(PrioQ_t));
    pq->heap = (int *)malloc(size * (sizeof(int)));
    pq->size = 0;
    return pq;
}
// swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//
void maxHeapifyUp(PrioQ_t *pq, int index)
{
    // check if the element if not the root (index >0)
    // if the parent  < child, swap their pointers
    while (index > 0 && pq->heap[(index - 1) / 2] < pq->heap[index])
    {
        swap(&pq->heap[(index - 1) / 2], &pq->heap[index]);
        index = (index - 1) / 2;
    }
}

void maxHeapifyDown(PrioQ_t *pq, int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left < pq->size && pq->heap[left] > pq->heap[largest])
    {
        largest = left;
    }
    if (right < pq->size && pq->heap[right] > pq->heap[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(&pq->heap[index], &pq->heap[largest]);
        maxHeapifyDown(pq, largest);
    }
}

// 3. an insert function to insert value in heap:insert
void insert(PrioQ_t *pq, int value)
{
    // add the value to the end of pq.
    // and increment the size by one
    pq->heap[pq->size++] = value;
    // heaplify the pq
    maxHeapifyUp(pq, pq->size - 1);
}

// extract the largest element
int extractMax(PrioQ_t *pq)
{
    if (pq->size == 0)
    {
        printf("PQ is empty. \n");
        return -1;
    }
    int max = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    maxHeapifyDown(pq, 0);
    return max;
}

void freepq(PrioQ_t *pq)
{
    free(pq->heap);
    free(pq);
}

int findKthLargest(int *nums, int numsSize, int k)
{
    PrioQ_t *pq = initprioQ(numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        insert(pq, nums[i]);
    }
    for (int i = 0; i < k - 1; i++)
    {
        extractMax(pq);
    }
    int res = extractMax(pq);
    freepq(pq);
    return res;
}

int main()
{
    int arr[] = {7, 5, 8, 12, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("The %dth largest element is %d\n", k, findKthLargest(arr, n, k));
    return 0;
}