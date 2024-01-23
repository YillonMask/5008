#include <stdio.h>
#include <stdlib.h>

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
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int numbers[] = {1, 5, 3, 4, 2};
    sortInteger(numbers, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
}