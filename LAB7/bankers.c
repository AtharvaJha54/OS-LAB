#include <stdio.h>
int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes\t--\t");
    scanf("%d", &n);

    printf("Enter number of resources\t--\t");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m];


    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation\t--\t");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }

        printf("Enter Max\t\t--\t");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources --\t");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int pid, request[m];

    printf("\nEnter New Request Details --\n");

    printf("Enter pid\t--\t");
    scanf("%d", &pid);

    printf("Enter Request for Resources\t--\t");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &request[i]);
    }

  
    for(i = 0; i < m; i++)
    {
        if(request[i] > need[pid][i])
        {
            printf("\nError: Process exceeded maximum claim\n");
            return 0;
        }
    }

  
    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("\nResources not available\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    int finish[n], safe[n], work[m];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    for(i = 0; i < m; i++)
        work[i] = available[i];

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    printf("\nP%d is visited{ ", i);
                    for(k = 0; k < m; k++)
                    {
                        printf("%d ", work[k]);
                    }
                    printf("}");

                    safe[count] = i;
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if(found == 0)
            break;
    }

 
    if(count == n)
    {
        printf("\n\nSYSTEM IS IN SAFE STATE\n");

        printf("The Safe Sequence is -- { ");
        for(i = 0; i < n; i++)
        {
            printf("P%d ", safe[i]);
        }
        printf("}\n");
    }
    else
    {
        printf("\nSYSTEM IS NOT IN SAFE STATE\n");
    }

    printf("\n");
    printf("Process\t\tAllocation\t\tMax\t\tNeed\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t", i);

        for(j = 0; j < m; j++)
        {
            printf("%d ", allocation[i][j]);
        }

        printf("\t\t");

        for(j = 0; j < m; j++)
        {
            printf("%d ", max[i][j]);
        }

        printf("\t\t");

        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    return 0;
}
