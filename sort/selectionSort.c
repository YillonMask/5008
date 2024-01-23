#include <stdio.h>
#include <stdlib.h>

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
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int numbers[] = {8, 5, 1, 3, 7};
    selectionSort(numbers, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
}