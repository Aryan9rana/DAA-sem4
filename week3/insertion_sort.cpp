// Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.
#include <iostream>
#include <time.h>
using namespace std;

int comp=0;
int shifts=0;
void printarray(int *a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insertionSort(int * a, int n){
    int temp;
    for(int i=1;i<n;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){ comp++;
            a[j+1]=a[j];shifts++;
            j--;
            
        }
        a[j+1]=temp;
        shifts++;
    }
}

int main(){
    int n=0;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    printf("Random array elements: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printarray(arr,n);
    clock_t start=clock();
    insertionSort(arr,n);
    clock_t end=clock();
    double total= (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"after sorting"<<endl;
    printarray(arr,n);
    printf("time taken: %lf seconds\n",total*1000);
    cout<<"comparisions ="<<comp<<endl<<"shifts ="<<shifts<<endl;
    return 0;
}