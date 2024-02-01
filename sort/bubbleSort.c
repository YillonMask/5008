#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortInteger(int *array, unsigned int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        // length - i - 1 is for ignoring comparisons of
        // elements which have already been compared in earlier iterations
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swap if greater is at the rear position
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    // assign a size of the array
    long size = 100;
    int* numbers = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        // assign random numbers from 0 to size of the array
        numbers[i] = rand() % size;

    }
    clock_t start_time = clock();
    //bubbleSort(numbers, size);
    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("total time spent during bubble sort is: %f\n", time_spent);
}