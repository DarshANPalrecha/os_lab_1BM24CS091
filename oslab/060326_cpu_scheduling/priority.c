#include <stdio.h>
int main() {

    int n, i, j, temp;
    float tot_wt=0,tot_tat=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n], p[n];

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nProcess P%d\n", i + 1);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Enter Priority: ");
        scanf("%d", &pr[i]);
    }

    // Sort according to priority
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {

            if(pr[j] > pr[j + 1]) {

                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;tot_tat=bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt+=wt[i];
        tat[i] = wt[i] + bt[i];
        tot_tat+=tat[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    printf("\nAvg_TAT:%.2fs\n",tot_tat/n);
    printf("Avg_WT:%.2fs\n",tot_wt/n);
    return 0;
}

// logic
// Higher priority executes first.
// Smaller number = higher priority
// problem : starvation
// sol : aging