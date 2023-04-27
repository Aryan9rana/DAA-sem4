
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int swaps=0,comparisions=0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}
void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int partition(int arr[], int s, int e) {
    
    srand(time(NULL));
    int pivot_index = s + rand() % (e - s + 1);
    int pivot_value = arr[pivot_index];
    
    
    swap(&arr[pivot_index], &arr[e]);
    
    int i = s - 1;
    for (int j = s; j <= e - 1; j++) {
        if (arr[j] < pivot_value) {
        comparisions++;
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[e]);
    return i + 1;
}

void quicksort(int arr[], int s, int e) {
    if (s < e) {
        int pivot_index = partition(arr, s, e);
        quicksort(arr, s, pivot_index - 1);
        quicksort(arr, pivot_index + 1, e);
    }
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
        double total_time = 0.0;
        clock_t start_time = clock();
        quicksort(arr, 0, n-1);
        clock_t end_time = clock();
        total_time  = (double)(end_time - start_time)/CLOCKS_PER_SEC;
        printarray(arr,n);
        printf("comparisons =%d\n", comparisions);
        
        printf("swaps =%d\n", swaps);
        printf("time = %f seconds \n",total_time*1000);
    return 0;
    }
  
    

