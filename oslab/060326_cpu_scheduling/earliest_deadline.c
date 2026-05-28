#include <stdio.h>

struct Process {
    int id;
    int burst;
    int deadline;
};

int main() {
    int n, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        p[i].id = i + 1;

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Enter Deadline: ");
        scanf("%d", &p[i].deadline);
    }

    // Sort according to deadline
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(p[j].deadline > p[j + 1].deadline) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
    }

    return 0;
}