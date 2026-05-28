#include <stdio.h>
int main() {
    int n, i;
    float tot_tat=0,tot_wt=0;
    int bt[n], wt[n], tat[n];
    int comp=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;

    for(i = 0; i < n; i++) {
        tat[i] = comp + bt[i];
        tot_tat+=tat[i];
        comp+=bt[i];
        wt[i] = tat[i] - bt[i];
        tot_wt+=wt[i];
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
    printf("Avg_WT:%.2fs\n",tot_wt/n);
    return 0;
}