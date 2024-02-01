#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // assign a size of the array
    int size = 1000;
    int numbers[size] ;
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
