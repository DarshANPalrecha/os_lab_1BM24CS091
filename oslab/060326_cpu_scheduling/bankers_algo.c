#include <stdio.h>
int main() {

    int n, m, i, j, k;
    printf("Enter num of proc:");
    scanf("%d", &n);
    printf("Enter num of res: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m];
    int need[n][m], finish[n];

    printf("Enter Allocation Mat:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Res:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int safeSeq[n];
    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0) {
            printf("System is NOT in safe state\n");
            return 0;
        }
    }
    printf("Safe Sequence:\n");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    return 0;
}