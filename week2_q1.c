//Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void bubblesort(int * a,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
        if(a[i]<a[j])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int n;
          clock_t start_t, end_t;
   double total_t;
    printf("enter the num: ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=(int)rand()%100;
    }
     printarray(a,n);
start_t = clock();
     insertionSort(a,n);
     end_t = clock();
     printarray(a,n);

     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", total_t  );
    return 0;
}
