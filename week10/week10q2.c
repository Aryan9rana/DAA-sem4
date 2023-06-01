#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task
typedef struct Task {
    int time;
    int deadline;
} Task;

// Function to compare tasks based on their deadlines (used for sorting)
int compare(const void* a, const void* b)
{
    return ((Task*)a)->deadline - ((Task*)b)->deadline;
}

// Function to find the maximum number of tasks that can be completed without crossing their deadlines
int findMaxTasks(Task tasks[], int n, Task selectedTasks[])
{
    // Sort the tasks based on their deadlines
    qsort(tasks, n, sizeof(Task), compare);

    int maxTasks = 0;
    int currentTime = 0;

    printf("Selected tasks:\n");

    // Consider each task
    for (int i = 0; i < n; i++) {
        // If the current time plus the task's time is less than or equal to the task's deadline
        if (currentTime + tasks[i].time <= tasks[i].deadline) {
            // Select the task
            selectedTasks[maxTasks] = tasks[i];
            maxTasks++;
            currentTime += tasks[i].time;
            printf("Task %d: Time: %d, Deadline: %d\n", maxTasks, tasks[i].time, tasks[i].deadline);
        }
    }

    return maxTasks;
}

// Main function
int main()
{
    // Example tasks
    Task tasks[] = {
        {5, 10},
        {2, 7},
        {7, 14},
        {4, 8},
        {3, 12},
        {6, 15}
    };
    int n = sizeof(tasks) / sizeof(tasks[0]);

    printf("Given tasks:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: Time: %d, Deadline: %d\n", i + 1, tasks[i].time, tasks[i].deadline);
    }

    printf("\n");

    Task selectedTasks[n];
    int maxTasks = findMaxTasks(tasks, n, selectedTasks);

    printf("\nMaximum number of tasks that can be completed without crossing their deadlines: %d\n", maxTasks);

    return 0;
}
