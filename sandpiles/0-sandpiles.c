#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_stable(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] > 3)
                return 0; // Unstable
        }
    }
    return 1; // Stable
}

void topple(int grid[SIZE][SIZE]) {
    int stable = 0;
    while (!stable) {
        stable = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] > 3) {
                    stable = 0;
                    int excess = grid[i][j] - 4;
                    grid[i][j] = 4; // Set to 4
                    
                    // Distribute the excess to the neighbors
                    if (i > 0) grid[i - 1][j] += excess / 4; // Top
                    if (i < SIZE - 1) grid[i + 1][j] += excess / 4; // Bottom
                    if (j > 0) grid[i][j - 1] += excess / 4; // Left
                    if (j < SIZE - 1) grid[i][j + 1] += excess / 4; // Right
                }
            }
        }
    }
}

void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]) {
    // Add the two sandpiles
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }
    
    // Check for stability and handle topplings
    while (!is_stable(grid1)) {
        printf("Grid 1 before toppling:\n");
        print_grid(grid1);
        topple(grid1);
    }
}
