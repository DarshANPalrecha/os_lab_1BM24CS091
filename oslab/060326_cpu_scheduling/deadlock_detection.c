#include <stdio.h>

int main() {

    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n];

    printf("Enter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");

    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int found;

    do {

        found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {

                    if(req[i][j] > avail[j]) {

                        flag = 0;
                        break;
                    }
                }

                if(flag) {

                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    int deadlock = 0;

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {

            deadlock = 1;

            printf("Process P%d is deadlocked\n", i);
        }
    }

    if(deadlock == 0)
        printf("No Deadlock Detected\n");

    return 0;
}

