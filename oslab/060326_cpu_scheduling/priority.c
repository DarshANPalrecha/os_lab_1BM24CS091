// #include <stdio.h>
// struct ps{
//     int tat;
//     int wt;
//     int ct;
//     int at;
//     int bt;
//     int p;
// };
// struct ps suv[n];
// for(int i=0;i<n;i++){
//     scanf("%d%d%d",suv[i].at,suv[i].bt,suv[i].p);
// }
// int curr=0;
// struct ps temp;
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(ps[i].p>ps[j].p){
//         temp=ps[i];
//         ps[i]=ps[j];
//         ps[j]=temp;
//     }
// }
// }
// for(int i=0;i<N;i++){
//     s[i].ct=s[i].bt+curr;
//     tat-s[i].at;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     return 0;
// }

// #include <stdio.h>
// struct P {int id,at,bt,pr,ct,wt,tat,d;};
// int main(){
//     int n,i,t=0,c=0,m,x; float tw=0,tt=0;
//     struct P p[20];
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         p[i].id=i+1;
//         scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pr);
//         p[i].d=0;
//     }
//     while(c<n){
//         m=9999; x=-1;
//         for(i=0;i<n;i++)
//             if(p[i].at<=t&&!p[i].d&&p[i].pr<m)
//                 m=p[i].pr,x=i;
//         if(x==-1) t++;
//         else{
//             p[x].ct=t+p[x].bt;
//             p[x].tat=p[x].ct-p[x].at;
//             p[x].wt=p[x].tat-p[x].bt;
//             t=p[x].ct; p[x].d=1; c++;
//             tw+=p[x].wt; tt+=p[x].tat;
//         }
//     }
//     for(i=0;i<n;i++)
//         printf("P%d %d %d %d %d %d %d\n",
//         p[i].id,p[i].at,p[i].bt,p[i].pr,
//         p[i].ct,p[i].wt,p[i].tat);

//     printf("AvgWT=%.2f\nAvgTAT=%.2f",tw/n,tt/n);
// }



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