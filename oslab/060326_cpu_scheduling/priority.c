
#include <stdio.h>

struct P{int bt,rt,wt,tat;};

int main(){
    int n,i,t=0,r,tq;
    scanf("%d",&n);
    struct P p[n];

    for(i=0;i<n;i++) scanf("%d",&p[i].bt),p[i].rt=p[i].bt;

    scanf("%d",&tq);
    r=n;

    while(r)
        for(i=0;i<n;i++)
            if(p[i].rt)
                if(p[i].rt<=tq)
                    t+=p[i].rt,p[i].wt=t-p[i].bt,p[i].rt=0,r--;
                else
                    t+=tq,p[i].rt-=tq;

    float tw=0,tt=0;
    for(i=0;i<n;i++)
        p[i].tat=p[i].bt+p[i].wt,
        printf("P%d %d %d %d\n",i+1,p[i].bt,p[i].wt,p[i].tat),
        tw+=p[i].wt,tt+=p[i].tat;

    printf("AvgWT=%.2f\nAvgTAT=%.2f",tw/n,tt/n);
}
