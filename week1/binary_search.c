#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int binarySearch(int * a,int start, int end , int key){
if (end >= start){
      int middle = start + (end - start )/2;
      if (a[middle] == key){
         return 1;
         }
         count++;
      if (a[middle] > key)
         return binarySearch(a, start, middle-1, key);
         count++;
      return binarySearch(a, middle+1, end, key);
   }

   return -1;
}
int main(){
    int n;
    clock_t start_t, end_t;
   double total_t;
    printf("enter the num: ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
     printarray(a,n);
     int key;
     printf("enter number to search: ");
     scanf("%d",&key);
start_t = clock();
    int b= binarySearch(a,0,n-1,key);
     end_t = clock();
     if(b== 1) printf("found\n");
     else printf(" not found\n");

     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", total_t*1000);
   printf("comparisions= %d", count);
    return 0;
}
