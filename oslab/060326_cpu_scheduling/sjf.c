#include <stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], p[n];
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(bt[j] > bt[j + 1]) {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    float tot_wt,tot_tat=bt[0];
    wt[0] = 0;
    tat[0] = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt+=wt[i];
        tat[i] = wt[i] + bt[i];
        tot_tat+=tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAvg_TAT:%.2fs\n",tot_tat/n);
    printf("Avg_WT:%.2fs",tot_wt/n);
    return 0;
}

// SJF gives minimum waiting time