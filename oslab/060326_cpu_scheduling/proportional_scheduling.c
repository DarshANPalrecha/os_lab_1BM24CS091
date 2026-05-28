#include <stdio.h>

int main() {

    int n, i;
    int share[10], total = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("Enter CPU share for P%d: ", i + 1);
        scanf("%d", &share[i]);

        total += share[i];
    }

    printf("\nCPU Allocation:\n");

    for(i = 0; i < n; i++) {

        float percent =
            ((float)share[i] / total) * 100;

        printf("P%d = %.2f%% CPU\n",
               i + 1,
               percent);
    }

    return 0;
}
// fair cpu dist
