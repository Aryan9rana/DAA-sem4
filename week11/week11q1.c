#include <stdio.h>
#include <limits.h>
int min(int a, int b)
{
    return (a < b) ? a : b;}
int matrixChainMultiplication(int dimensions[], int n)
{   int dp[n][n];   
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len < n; len++){
        for (int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++){
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                dp[i][j] = min(dp[i][j], cost);}}}
    return dp[1][n - 1];}

int main(){
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];

    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("Dimension %d: ", i);
        scanf("%d", &dimensions[i]);
    }

    int minOperations = matrixChainMultiplication(dimensions, n + 1);

    printf("Minimum number of operations: %d\n", minOperations);

    return 0;
}