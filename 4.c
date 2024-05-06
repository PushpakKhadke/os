#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

int main() {
    int blocks[MAX_BLOCKS], processes[MAX_PROCESSES];
    int num_blocks, num_processes;

    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    // Input the size of each memory block
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // Input the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    // Input the size of each process
    printf("Enter the size of each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Allocate memory using First Fit algorithm
    printf("\nMemory Allocation using First Fit:\n");
    for (int i = 0; i < num_processes; i++) 
    {
        printf("Process %d (size %d): ", i + 1, processes[i]);
        int allocated = 0;
        for (int j = 0; j < num_blocks; j++)
        {
            if (blocks[j] >= processes[i]) 
            {
                printf("Allocated to Block %d (size %d)\n", j + 1, blocks[j]);
                blocks[j] -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) 
        {
            printf("Cannot be allocated\n");
        }
    }

    return 0;
}
