#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int at[20],bt[20],pr[20],ct[20],wt[20],tat[20];
    int done[20]={0};

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
}


