#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 int comparisons=0, swaps=0;
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
    }
}

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));

    printf("Random array elements: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1001; 
        printf("%d ", arr[i]);
    }
    printf("\n");
  double ts = 0.0;
 clock_t start = clock();
    selection_sort(arr, n);
    clock_t end = clock();
 ts  = (double)(end - start)/CLOCKS_PER_SEC;
 printf("time = %f sec\n",ts*1000);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\ncomparisons: %d\n", comparisons);
    printf("swaps: %d\n", swaps);
    return 0;
}
