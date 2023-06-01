#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode(Node** head, int data)
{   Node* start = (*head);   
    Node* temp = createNode(data);
    if ((*head) == NULL || (*head)->data > data) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->data < data) {
            start = start->next;}
        temp->next = start->next;
        start->next = temp;}}
int extractMin(Node** head)
{
    Node* temp = *head;
    int data = temp->data;
    (*head) = (*head)->next;
    free(temp);
    return data;
}
int mergeFiles(int arr[], int size)
{
    Node* pq = NULL;
    int computationCost = 0;
    for (int i = 0; i < size; i++) {
        insertNode(&pq, arr[i]);
    }
    while (pq->next != NULL) {
        int file1 = extractMin(&pq);
        int file2 = extractMin(&pq);
        int mergedSize = file1 + file2;
        computationCost += mergedSize;
        insertNode(&pq, mergedSize);
    }
    free(pq);
    return computationCost;
}
int main()
{
    int arr[] = { 2, 3, 4, 6, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("file sizes are: ");
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int minComputationCost = mergeFiles(arr, size);
    printf("Minimum computation cost for merging all files: %d\n", minComputationCost);
    return 0;
}
