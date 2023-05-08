#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int comparisions = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = lb - 1;
    for (int j = lb; j < ub; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[ub]);
    return i + 1;
}

int quickselect(int arr[], int lb, int ub, int k) {
    if (lb == ub) {
        return arr[lb];
    }
    int pivotIndex = partition(arr, lb, ub);
    int leftSize = pivotIndex - lb + 1;
    if (k == leftSize) {
        return arr[pivotIndex];
    } else if (k < leftSize) {
        comparisions += 1;
        return quickselect(arr, lb, pivotIndex - 1, k);
    } else {
        comparisions += 2;
        return quickselect(arr, pivotIndex + 1, ub, k - leftSize);
    }
}
void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main() {
    int n;
     printf("Enter number of elems: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=(int)rand()%100;
    }
    printarray(arr,n);
    int k;
    printf("Enter k: ");
    k=(int)rand()%100;
        double total_time =0.0;
        clock_t start_time = clock();
        int kthSmallest = quickselect(arr, 0, n - 1, k);
        clock_t end_time = clock();
 total_time  = (double)(end_time - start_time)/CLOCKS_PER_SEC;
        printf("%d'th smallest element is %d \n", k,kthSmallest);
        printf("comparision: %d\n",comparisions);
        printf("time = %f seconds\n",total_time*1000);
    return 0;
    }

