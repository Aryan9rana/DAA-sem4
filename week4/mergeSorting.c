#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count =0;

void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            count++;
        }
        else {
            arr[k] = R[j];
            j++;
            count++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main(){
    int n;
    clock_t start,end;
    double total_time;
    int inversion;
    printf("Enter number of elems: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=(int)rand()%100;
    }
    printarray(arr,n);
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) inversion++;
        }
    }
    start=clock();
    mergeSort(arr,0,n-1);
    end= clock();
    printf("sorted array: ");
    printarray(arr,n);
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time taken: %lf seconds\n",total_time*1000);
    printf("comparision: %d \n",count);
    printf("inversion: %d \n",inversion);
    return 0;
}
