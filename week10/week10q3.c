#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


int findMedian(int arr[], int n)
{
    int mid = n / 2;
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == mid)
            return arr[mid];
        else if (pivotIndex < mid)
            low = pivotIndex + 1;
        else
            high = pivotIndex - 1;
    }

    
    return -1;
}


int checkMajority(int arr[], int n)
{
    int majorityCount = n / 2 + 1;
    int count = 1;
    int candidate = arr[0];

    
    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count >= majorityCount)
        return candidate;
    else
        return -1;
}


int main()
{
    int arr[] = { 3, 8, 2, 3, 3, 6, 3, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("array elements are: ");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int majorityElement = checkMajority(arr, n);
    if (majorityElement != -1)
        printf("Majority element exists: %d\n", majorityElement);
    else
        printf("Majority element does not exist.\n");

    int median = findMedian(arr, n);
    if (median != -1)
        printf("Median of the array: %d\n", median);
    else
        printf("Median cannot be found.\n");

    return 0;
}
