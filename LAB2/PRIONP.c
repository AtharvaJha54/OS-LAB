#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int at[20],bt[20],pr[20],ct[20],wt[20],tat[20];
    int done[20]={0};
    float total_tat=0, total_wt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("AT P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("BT P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority P%d: ",i+1);
        scanf("%d",&pr[i]);
    }

    while(completed<n)
    {
        int idx=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                if(idx==-1 || pr[i]<pr[idx])
                    idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        time += bt[idx];

        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        done[idx]=1;
        completed++;
    }

    printf("\nP AT BT PR CT WT TAT\n");

    for(i=0;i<n;i++)
        printf("P%d %d %d %d %d %d %d\n",
        i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    for(i=0;i<n;i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }
    float avg_tat = total_tat/n;
    float avg_wt = total_wt/n;
    printf("The average Turnaround time is %f\n", avg_tat);
    printf("The waiting time is %f", avg_wt);
}


