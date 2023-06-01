#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight;
    int value;
    float fraction;
} Item;
int compareItems(const void *a, const void *b)
{
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    float ratioA = (float)itemA->value / itemA->weight;
    float ratioB = (float)itemB->value / itemB->weight;
    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}
void knapsack(Item items[], int n, int capacity)
{
    qsort(items, n, sizeof(Item), compareItems);

    int currWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].weight <= capacity)
        {
            items[i].fraction = 1.0;
            currWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            items[i].fraction = (float)(capacity - currWeight) / items[i].weight;
            totalValue += items[i].fraction * items[i].value;
            break;
        }
    }

    
    printf("Maximum Value: %.2f\n", totalValue);
    printf("Selected Items:\n");
    for (int i = 0; i < n; i++)
    {
        if (items[i].fraction > 0.0)
            printf("Item %d (Fraction: %.2f)\n", i + 1, items[i].fraction);
    }
}

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