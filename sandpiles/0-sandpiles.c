#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3)
                return 0; // Unstable
        }
    }
    return 1; // Stable
}

void topple(int grid[3][3]) {
    int stable = 0;
    while (!stable) {
        stable = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 3) {
                    stable = 0;
                    int excess = grid[i][j] - 4;
                    grid[i][j] = 4; // Set to 4
                    
                    // Distribute the excess to the neighbors
                    if (i > 0) grid[i - 1][j] += excess / 4; // Top
                    if (i < 3 - 1) grid[i + 1][j] += excess / 4; // Bottom
                    if (j > 0) grid[i][j - 1] += excess / 4; // Left
                    if (j < 3 - 1) grid[i][j + 1] += excess / 4; // Right
                }
            }
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Add the two sandpiles
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
