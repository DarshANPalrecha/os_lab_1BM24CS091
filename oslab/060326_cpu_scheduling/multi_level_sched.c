#include <stdio.h>

int main() {
    int sys_n, user_n;
    int i;

    // Input system processes
    printf("Enter number of system processes: ");
    scanf("%d", &sys_n);

    int sys_bt[sys_n], sys_wt[sys_n], sys_tat[sys_n];

    for(i = 0; i < sys_n; i++) {
        printf("Enter burst time for System Process S%d: ", i + 1);
        scanf("%d", &sys_bt[i]);
    }

    // Input user processes
    printf("\nEnter number of user processes: ");
    scanf("%d", &user_n);

    int user_bt[user_n], user_wt[user_n], user_tat[user_n];

    for(i = 0; i < user_n; i++) {
        printf("Enter burst time for User Process U%d: ", i + 1);
        scanf("%d", &user_bt[i]);
    }

    // Calculate WT and TAT for system processes
    sys_wt[0] = 0;
    sys_tat[0] = sys_bt[0];

    for(i = 1; i < sys_n; i++) {
        sys_wt[i] = sys_wt[i - 1] + sys_bt[i - 1];
        sys_tat[i] = sys_wt[i] + sys_bt[i];
    }

    // User queue starts after all system processes finish
    int start_time = sys_tat[sys_n - 1];

    user_wt[0] = start_time;
    user_tat[0] = user_wt[0] + user_bt[0];

    for(i = 1; i < user_n; i++) {
        user_wt[i] = user_wt[i - 1] + user_bt[i - 1];
        user_tat[i] = user_wt[i] + user_bt[i];
    }

    // Gantt Chart
    printf("\n===== GANTT CHART =====\n\n");

    for(i = 0; i < sys_n; i++) {
        printf("| S%d ", i + 1);
    }

    for(i = 0; i < user_n; i++) {
        printf("| U%d ", i + 1);
    }

    printf("|\n");

    // Print times
    int time = 0;
    printf("0");

    for(i = 0; i < sys_n; i++) {
        time += sys_bt[i];
        printf("    %d", time);
    }

    for(i = 0; i < user_n; i++) {
        time += user_bt[i];
        printf("    %d", time);
    }

    // System process table
    printf("\n\n===== SYSTEM PROCESS TABLE =====\n");
    printf("Process\tBT\tWT\tTAT\n");

    for(i = 0; i < sys_n; i++) {
        printf("S%d\t%d\t%d\t%d\n",
               i + 1,
               sys_bt[i],
               sys_wt[i],
               sys_tat[i]);
    }

    // User process table
    printf("\n===== USER PROCESS TABLE =====\n");
    printf("Process\tBT\tWT\tTAT\n");

    for(i = 0; i < user_n; i++) {
        printf("U%d\t%d\t%d\t%d\n",
               i + 1,
               user_bt[i],
               user_wt[i],
               user_tat[i]);
    }

    return 0;
}