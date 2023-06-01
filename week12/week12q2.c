#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight;
    int value;
} Item;
int max(int a, int b){   return (a > b) ? a : b;}
void knapsack(Item items[], int n, int capacity)
{
    int i, w;
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    int selectedItems[n];
    int numSelected = 0;
    i = n;
    w = capacity;
    while (i > 0 && w > 0)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selectedItems[numSelected++] = i;    w -= items[i - 1].weight;     i--;
        }
        else
        {
            i--;
        }
    }
    printf("Selected Items:\n");
    for (i = numSelected - 1; i >= 0; i--)
    {
        int index = selectedItems[i] - 1;
        printf("Item %d (Weight: %d, Value: %d)\n", selectedItems[i], items[index].weight, items[index].value);
    }
    printf("Maximum Value: %d\n", dp[n][capacity]);

    // Freeing the dynamically allocated memory
    for (i = 0; i <= n; i++)
        free(dp[i]);
    free(dp); }
int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].value);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    knapsack(items, n, capacity);
    return 0;
}
