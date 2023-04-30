#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
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
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int hasDuplicates(int arr[], int n) {
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return 1;
        }
    }

    return 0;
}
int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);    
   
    clock_t start,end;
    double total_time;


    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; 
    }

    printf("The array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    start=clock();
      int t=hasDuplicates(arr, n);
    end= clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time taken: %lf seconds\n",total_time*1000);
    if (t) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
