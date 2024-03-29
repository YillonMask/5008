#include <stdio.h>
#include <stdlib.h>

#define LARGEST_TRIANGLE 32

// calculate and return the i-th row of Pascal's Triangle
// rowIndex = the index of the row that should be calculated
// returnSize = the size of the row that was calculated
// returns a pointer to an array of size `returnSize`,
//    assume that the caller calls free on the returned array
//
// coincidentally, this problem is the same as one of the problems
// on LeetCode: https://leetcode.com/problems/pascals-triangle-ii/

int *getRow(int rowIndex, int *returnSize)
{
    // TODO: Implement me!!
    // Allocate memory for the row array
    int *row_array = (int *)malloc((rowIndex + 1) * sizeof(int));

    // Set the first and last elements of the row array to 1
    row_array[0] = 1;
    row_array[rowIndex] = 1;

    // Calculate the middle elements of the row array
    for (int i = 1; i < rowIndex; i++)
    {
        row_array[i] = row_array[i - 1] * (rowIndex - i + 1) / i;
    }

    // Set the returnSize to the size of the row array
    *returnSize = rowIndex + 1;

    // Return the row array
    return row_array;
}

int main(int argc, char *argv[])
{
    // Make sure that there is one argument
    if (argc != 2)
    {
        printf("One argument expected: ./pascal 42\n");
        return 1;
    }

    // Convert the argument of the program into an integer
    // and make sure that it is between 0 and LARGEST_TRIANGLE - 1
    const int row = atoi(argv[1]);
    if (row < 0 || row > LARGEST_TRIANGLE - 1)
    {
        printf("row must between 0 and %d (inclusive)\n", LARGEST_TRIANGLE - 1);
        return 1;
    }

    int size = 0;
    int *row_values = getRow(row, &size);

    printf("Row %d of Pascal's Triangle\n", row);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", row_values[i]);
    }
    printf("\n");

    // free the memory that was returned from function
    free(row_values);
    return 0;
}