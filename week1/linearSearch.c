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
int linearSearch(int* a, int n,int key){
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[i]== key) {
            return 1;
        }
            count++;
    }
    return -1;
}
int main(){
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);
    while(t--){
    int n;
    clock_t start_t, end_t;
    double total_t;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=(int)rand()%100;
    }
     printarray(a,n);
     int key;
     printf("enter number to search: ");
     scanf("%d",&key);
start_t = clock();
    int b= linearSearch(a,n,key);
     end_t = clock();
     if(b== 1) printf("present %d\n",key);
     else printf(" not present %d\n",key);

     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", total_t*1000  );
    }
    printf("comparisions= %d",count);
    return 0;
}


