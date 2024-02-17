// Name: Xinrui Yi
// Email: yi.xin@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95 // 95 printing characters x20-x7E

// return random character
char randChar()
{
    // 0 -> x20 -> ' '
    // 1 -> x21 -> '!'
    // ,,,
    // 94 -> x7E -> '~'
    // see https://ascii.cl
    return ((char)((rand() % RAND_RANGE) + 0x20));
}

// return location mid way between left and right
int midPoint(int left, int right)
{
    // note integer division always returns an integer
    return (left + (right - left) / 2);
}

// min of two integers
int findMin(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// merge two sorted sub arrays
void mergeIt(
    char *data,
    int leftStart,
    int leftStop,
    int rightStart,
    int rightStop)
{

    // ADD YOUR CODE HERE
    int leftsize = leftStop - leftStart + 1;
    int rightsize = rightStop - rightStart + 1;

    int L[leftsize], R[rightsize];

    for (int i = 0; i < leftsize; i++)
    {
        L[i] = data[leftStart + i];
    }

    for (int i = 0; i < rightsize; i++)
    {
        R[i] = data[rightStart + i];
    }
    int i = 0;
    int j = 0;
    int k = leftStart;
    while (i < leftsize && j < rightsize)
    {
        if (L[i] < R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    // while not if, we want all the remained array
    while (i < leftsize)
    {
        data[k++] = L[i++];
    }
    // while
    while (j < rightsize)
    {
        data[k++] = R[j++];
    }
    return;
}

// break data array up into halves until down to single elements
// then merge them
void msort(char *data, int left, int right)
{

    if (left >= right)
    {
        // base case of 1 element
        return;
    }
    else
    {
        // sort left half
        msort(data, left, midPoint(left, right));

        // sort right half
        msort(data, midPoint(left, right) + 1, right);

        // merge left and right halves
        mergeIt(
            data,
            left, midPoint(left, right),
            midPoint(left, right) + 1, right);
    }
    return;
}

int main()
{

    char source[LIMIT]; // array to hold input data values

    int i;        // loop variable
    int j;        // loop variable
    int smallest; // current smallest element

    // seed random numbers
    srand((unsigned)time(NULL));

    // initialize source array with random character
    for (i = 0; i < LIMIT; i++)
    {
        source[i] = randChar();
    }

    // print out source array in rows of 20 elments
    printf("Source array:\n");
    for (i = 0; i < ((LIMIT / 20) + 1); i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (i * 20 + j < LIMIT)
            {
                printf("%c ", source[i * 20 + j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // do the sorting
    msort(source, 0, LIMIT - 1);

    // print out sorted array in rows of 10
    printf("Destination array:\n");
    for (i = 0; i < ((LIMIT / 10) + 1); i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i * 10 + j < LIMIT)
            {
                printf("%c ", source[i * 10 + j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    char dataset5[] = {-1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10};
    int dataset5_length = sizeof(dataset5) / sizeof(dataset5[0]);
    msort(dataset5, 0, dataset5_length - 1);
    for (int i = 0; i < dataset5_length; i++)
    {
        printf("%d ", dataset5[i]);
    }

    return 0;
}