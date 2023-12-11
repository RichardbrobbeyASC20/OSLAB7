#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "util.h"
#include "list.h"

/**
 * Returns an array of process that are parsed from
 * the input file descriptor passed as argument
 * CAUTION: You need to free up the space that is allocated
 * by this function
 */
void parse_file(FILE * f, int input[][2], int *n, int *PARTITION_SIZE)
{
  
  // Get the initial partition size
    if (fscanf(f, "%d\n", PARTITION_SIZE) != 1) {
        fprintf(stderr, "Error reading initial partition size\n");
        exit(EXIT_FAILURE);
    }
    printf("PARTITION_SIZE = %d\n", *PARTITION_SIZE);

    *n = 0; // Initialize the number of processes read
    int pid, size;
    while (fscanf(f, "%d %d\n", &pid, &size) == 2) {
        input[*n][0] = pid;
        input[*n][1] = size;
        *n += 1;
        // Ensure you don't exceed the bounds of the input array
    }
}