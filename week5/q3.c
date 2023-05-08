#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findCommon(int a1[], int a2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a1[i] < a2[j])i++;
        else if (a2[j] < a1[i]) j++;
        else { printf("%d ", a2[j++]);i++;}}}
int main(){
    int m, n, i;
    printf("Enter size of first array: ");
    scanf("%d", &m);
    printf("Enter size of second array: ");
    scanf("%d", &n);
    int a1[m], a2[n];
    srand(time(0));
    printf("First array elements:\n");
    for (i = 0; i < m; i++) {
        a1[i] = rand() % 100;
        printf("%d ", a1[i]);}
    printf("\nSecond array elements:\n");
    for (i = 0; i < n; i++) {
        a2[i] = rand() % 100;
        printf("%d ", a2[i]);}
    printf("\nCommon elements: ");
    clock_t tb = clock();
    findCommon(a1, a2, m, n);
    clock_t te = clock();
    double ts = (double)(te - tb)/CLOCKS_PER_SEC;
    printf("\ntime taken= %lf microseconds",ts*1000);
    return 0;
}
