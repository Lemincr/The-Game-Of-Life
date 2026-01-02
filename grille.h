#ifndef GRILLE_H
#define GRILLE_H

#define MAX_L 100
#define MAX_C 100

// Using a struct to wrap the array and its current dimensions [cite: 15, 16]
typedef struct {
    int lines;
    int cols;
    int matrix[MAX_L][MAX_C];
} Grid;

void init_empty_grid(Grid *g, int L, int C); [cite: 29]
void init_random_grid(Grid *g); [cite: 30]
void display_grid(Grid *g); [cite: 31]

#endif
