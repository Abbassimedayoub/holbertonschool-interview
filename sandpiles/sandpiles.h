#ifndef SANDPILES__H
#define SANDPILES__H

#define SIZE 3

void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]);
void print_grid(int grid[3][3]);
int is_stable(int grid[SIZE][SIZE]);
void topple(int grid[SIZE][SIZE]);

#endif // SANDPILES__H
