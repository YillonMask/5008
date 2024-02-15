// name: Xinrui Yi
// Email:yi.xin@northeastern.edu
#include <stdio.h>

int merge(int arr[], int temp[], int l, int mid, int r)
{                    // TODO: COMMENT ON EVERY LINE IN MERGE FUNCTION
    int cnt = 0;     // initialize count
    int i = l;       // first element of left part of array
    int j = mid + 1; // first element of right part of aray
    int k = l;       // make another copy of first element of left apart of array

    while (i <= mid && j <= r)
    { // iterate through left and right part of array
        if (arr[i] <= arr[j])
        {                         // if element of left part array is smaller
            temp[k++] = arr[i++]; // use temp array to record the smaller element and increment both array index by 1
        }
        else
        {                         // if element of right part of array is smaller
            temp[k++] = arr[j++]; // use temp array to record the smaller element and increment both array index by 1
            // j and any of [i, mid] form an inverse pair.
            cnt += (mid - i + 1); // since arr[j] < arr[i], so all of the element in left part is greater than arr[j], increment count by number of element of left array
        }
    }
    while (i <= mid)
    {                         // if there are still element left in left part of array
        temp[k++] = arr[i++]; // use temp array to record all the element
    }
    while (j <= r)
    {                         // if there are still elements left in the right part of array
        temp[k++] = arr[j++]; // use temp array to record all the element
    }
    for (i = l; i <= r; i++)
    {
        arr[i] = temp[i]; // merge the two sorted parts into array
    }
    return cnt; // return the number of inversion pairs
}

int mergeSort(int arr[], int temp[], int l, int r)
{
    if (l >= r)
    {             // base case when array is empty
        return 0; // number of inversion pair of an empty array is 0
    }
    int mid = (l + r) / 2; // find the mid point
    int cnt = 0;           // initialize count variable
    // call the merge for the left half
    cnt += mergeSort(arr, temp, l, mid);
    // call the merge for the right half
    cnt += mergeSort(arr, temp, mid + 1, r);
    // merge two halves sorted in previous two steps
    cnt += merge(arr, temp, l, mid, r);
    return cnt;
}

int main()
{
    int arr[] = {4, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    printf("The number of inverse pair is %d.\n", mergeSort(arr, temp, 0, n - 1));
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}