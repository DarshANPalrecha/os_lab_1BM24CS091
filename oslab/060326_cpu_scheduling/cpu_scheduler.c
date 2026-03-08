#include<stdio.h>
struct scheduler{
    int arr;
    int burst;
    int proc_id;
    int tat;
    int wait;
    int comp;
};
int main(){
int n;
scanf("%d",&n);
struct scheduler s[n];
int curr=0;
int avg_wait=0;
int avg_tat=0;
for(int i=0;i<n;i++){
    scanf("%d",&s[i].arr);
    scanf("%d",&s[i].burst);
    s[i].proc_id=i;
    }
for(int i=0;i<n;i++){
    if(curr<s[i].arr)curr=s[i].arr;
        s[i].comp=curr+s[i].burst;   
        s[i].tat=s[i].comp-s[i].arr;   
        s[i].wait=s[i].tat-s[i].burst;   
        curr=s[i].comp;
        avg_wait+=s[i].wait;
        avg_tat+=s[i].tat;
    }
for(int i=0;i<n;i++){
    printf("\nproc_id=%d",s[i].proc_id);
    printf("\narr_time=%d",s[i].arr);
    printf("\nburst_time=%d",s[i].burst);
    printf("\ncomp_time=%d",s[i].comp);
    printf("\nwait_time=%d",s[i].wait);
    printf("\ntotal_turn_ard_time=%d",s[i].tat);
    printf("\n");
    }
printf("avg_waiting_time=%f\n",(float)avg_wait/n);
printf("avg_turn_around_time=%f\n",(float)avg_tat/n);
}