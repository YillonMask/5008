#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{ // int *a here is to indicate a and b are pointers
    // here asterisk *a indicate it is dereferencing the pointers to values
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i; // min holds the index of the smallest element
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // swap the smallest element with the element at i
        swap(&arr[i], &arr[min]); // when call swap, we pass the addresses of arr[], the & operator is used to  get the address
    }
}

int main()
{
    int numbers[] = {8, 6, 1, 3, 7};
    selectionSort(numbers, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
}
