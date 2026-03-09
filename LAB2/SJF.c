#include<stdio.h>
int main(){
    int n,i,time=0,complete=0;
    int at[20],bt[20],ct[20],wt[20],tat[20],done[20]={0};
    printf("Enter the number of process:");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter arrival time of P%d", i+1);
        scanf("%d", at[i]);
        printf("Enter burst time of P%d", i+1);
        scanf("%d", bt[i]);
    }
    while(complete<n){
        int idx = -1;
        for(i=0; i<n; i++){
            if(at[i]<=time && done[i]==0){
                if(idx == -1 || bt[i]<bt[idx]){
                    idx = i;
                }
            }
        }
        if(idx==-1){
            time++;
            continue;
        }
        time+=bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[i] = 1;
        complete++;
    }
    printf("Process\tAT\tBT\tTAT\tWT\n");
      for(i=0;i<n;i++){
        printf("P%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
      }


}

