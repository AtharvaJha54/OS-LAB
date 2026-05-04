#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int total_philosophers, hungry_count, hungry_positions[20], choice;
    int i, j, k;

    printf("\nEnter the total number of philosophers: "); //
    scanf("%d", &total_philosophers);

    printf("How many are hungry: "); //
    scanf("%d", &hungry_count);

    if (hungry_count == total_philosophers) {
        printf("\nAll are hungry. Deadlock stage will occur. Exiting...\n");
        return 0;
    }

 
    for (i = 0; i < hungry_count; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, total_philosophers); // [cite: 5-16]
        scanf("%d", &hungry_positions[i]);
    }
    while (1) {
        printf("\n1. One can eat at a time"); 
        printf("\n2. Two can eat at a time"); 
        printf("\n3. Exit");              
        printf("\nEnter your choice: ");    
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAllow one philosopher to eat at any time\n"); 
            for (i = 0; i < hungry_count; i++) {
                for (j = 0; j < hungry_count; j++) {
                    printf("P %d is waiting\n", hungry_positions[j]); 
                }
                printf("P %d is granted to eat\n", hungry_positions[i]);
                printf("P %d has finished eating\n", hungry_positions[i]); 
            }
        }
        else if (choice == 2) {
            printf("\nAllow two philosophers to eat at the same time\n");
            for (i = 0; i < hungry_count; i++) {
                for (j = i + 1; j < hungry_count; j++) {
                    int distance = abs(hungry_positions[i] - hungry_positions[j]);
                    if (distance > 1 && distance != (total_philosophers - 1)) {
                        printf("\nP %d and P %d are granted to eat\n", hungry_positions[i], hungry_positions[j]);
                        for (k = 0; k < hungry_count; k++) {
                            if (hungry_positions[k] != hungry_positions[i] &&
                                hungry_positions[k] != hungry_positions[j]) {
                                printf("P %d is waiting\n", hungry_positions[k]);
                            }
                        }
                    }
                }
            }
        }
        else if (choice == 3) {
            exit(0);
        }
        else {
            printf("\nInvalid option..");
        }
    }
    return 0;
}
