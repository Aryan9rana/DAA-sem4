#include <stdio.h>
#include <stdlib.h>


typedef struct Activity {
    int start;
    int finish;
} Activity;


int compare(const void* a, const void* b)
{
    return ((Activity*)a)->finish - ((Activity*)b)->finish;
}


void selectActivities(Activity activities[], int n)
{
    
    qsort(activities, n, sizeof(Activity), compare);

    int selected = 0;
    printf("Selected activities:\n");

    
    int i = 0;
    printf("(%d, %d)\n", activities[i].start, activities[i].finish);

    
    for (int j = 1; j < n; j++) {
        
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d)\n", activities[j].start, activities[j].finish);
            i = j; 
        }
    }
}


int main()
{
    
    Activity activities[] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    printf("Given activities:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", activities[i].start, activities[i].finish);
    }

    printf("\n");

    selectActivities(activities, n);

    return 0;
}
