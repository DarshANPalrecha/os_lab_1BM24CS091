// Each process gets fixed CPU time called quantum.
#include <stdio.h>

int main() {
    int n, i, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], rem[n], wt[n], tat[n];

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    int time = 0;
    float tot_tat=0,tot_wt=0;

    while(1) {
        int done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                }
                else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    tot_wt+=wt[i];
                    tot_tat+=wt[i];
                    tot_tat+=bt[i];
                    rem[i] = 0;
                }
            }
        }
        if(done == 1)
            break;
    }
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tat[i]);
    }
    printf("\nAvg_TAT:%.2fs\n",tot_tat/n);
    printf("Avg_WT:%.2fs",tot_wt/n);
    return 0;
}



// If quantum too small?
// Too many context switches.
// If quantum too large?
// Behaves like FCFS.
