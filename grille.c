#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

void init_empty_grid(Grid *g, int L, int C) {
    g->lines = L;
    g->cols = C;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            g->matrix[i][j] = 0; // Set all cells to dead [cite: 17, 29]
        }
    }
}

void init_random_grid(Grid *g) {
    for (int i = 0; i < g->lines; i++) {
        for (int j = 0; j < g->cols; j++) {
            g->matrix[i][j] = rand() % 2; // Randomly 0 or 1 [cite: 18, 30]
        }
    }
}

void display_grid(Grid *g) {
    for (int i = 0; i < g->lines; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->matrix[i][j] == 1) printf("X "); // Living cell [cite: 18]
            else printf(". "); // Dead cell [cite: 17]
        }
        printf("\n");
    }
}
