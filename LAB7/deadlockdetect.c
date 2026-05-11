#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m];
    int available[m];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter Allocation -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }

        printf("Enter Request -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    int finish[n], work[m];
    int safe[n];
    int count = 0;

    for(i = 0; i < n; i++)
    {
        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    while(1)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    printf("\nP%d is executed { ", i);
                    for(k = 0; k < m; k++)
                    {
                        printf("%d ", work[k]);
                    }
                    printf("}");

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }


    printf("\n\nProcesses in Safe State:\n");
    for(i = 0; i < count; i++)
    {
        printf("P%d ", safe[i]);
    }

s
    int deadlock = 0;

    printf("\n\nProcesses in Deadlock:\n");

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
    {
        printf("No Deadlock");
    }

    printf("\n\nProcess\tAllocation\tRequest\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);

        for(j = 0; j < m; j++)
        {
            printf("%d ", allocation[i][j]);
        }

        printf("\t\t");

        for(j = 0; j < m; j++)
        {
            printf("%d ", request[i][j]);
        }

        printf("\n");
    }

    return 0;
}
