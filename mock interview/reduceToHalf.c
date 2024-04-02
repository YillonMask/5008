// name:Xinrui Yi
// link:https://leetcode.com/problems/reduce-array-size-to-the-half/

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int minSetSize(int *arr, int arrSize)
{
    // find the max value of given arr
    int max = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // create freq array of size max + 1
    int *freq = (int *)calloc((max + 1), sizeof(int));
    // traverse the array and keep the frequence of every integer in arr
    for (int i = 0; i < arrSize; i++)
    {
        freq[arr[i]]++;
    }
    // add all the frequency into another array
    int *freqArr = (int *)malloc(arrSize * sizeof(int));
    int freqArrSize = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (freq[i] > 0)
        {
            freqArr[freqArrSize++] = freq[i];
        }
    }
    // sort the frequency array in descending order
    qsort(freqArr, freqArrSize, sizeof(int), cmp);
    // travere the frequency array
    int sum = 0;
    int res = 0;
    for (int i = 0; i < freqArrSize; i++)
    {
        sum += freqArr[i];
        res++;
        if (sum >= (arrSize / 2))
            break;
    }
    // free the memory
    free(freqArr);
    free(freq);
    return res;
}