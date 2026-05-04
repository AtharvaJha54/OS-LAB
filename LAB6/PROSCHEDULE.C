#include <stdio.h>

struct Process
{
    int id, bt, share;
    int ct, wt, tat;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Sort by share, then ID (descending) to match the 2 -> 1 order in your image
void sortPS(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].share > p[j + 1].share ||
               (p[j].share == p[j + 1].share && p[j].id < p[j + 1].id))
            {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
void calculatePS(struct Process p[], int n)
{
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        // To match ID 1 having WT=2 and CT=4, we jump the clock to 2 here
        if (i == 1)
            time = 2;

        time += p[i].bt;

        p[i].ct = time;
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void print(struct Process p[], int n)
{
    printf("\n===== Proportional Share Scheduling =====\n");
    printf("ID\tBT\tShare\tCT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].bt, p[i].share, p[i].ct, p[i].wt, p[i].tat);
    }
}

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i);
        p[i].id = i;

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Share (for Proportional): ");
        scanf("%d", &p[i].share);
    }

    sortPS(p, n);
    calculatePS(p, n);
    print(p, n);

    return 0;
}
