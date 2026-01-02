#include "automate.h"

int count_neighbors(Grid *g, int l, int c) {
    int count = 0;
    // Check the 8 surrounding cells [cite: 21, 63]
    for (int i = l - 1; i <= l + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i == l && j == c) continue; // Skip the cell itself
            if (i >= 0 && i < g->lines && j >= 0 && j < g->cols) {
                count += g->matrix[i][j];
            }
        }
    }
    return count;
}

void apply_rules(Grid *current, Grid *next) {
    next->lines = current->lines;
    next->cols = current->cols;

    for (int i = 0; i < current->lines; i++) {
        for (int j = 0; j < current->cols; j++) {
            int nb = count_neighbors(current, i, j);
            int is_alive = current->matrix[i][j];

            if (is_alive == 1) {
                // Rule: Survives if 2 or 3 neighbors [cite: 23]
                // Rule: Dies if < 2 or > 3 neighbors [cite: 24]
                if (nb == 2 || nb == 3) next->matrix[i][j] = 1;
                else next->matrix[i][j] = 0;
            } else {
                // Rule: Becomes alive if exactly 3 neighbors [cite: 25]
                if (nb == 3) next->matrix[i][j] = 1;
                else next->matrix[i][j] = 0;
            }
        }
    }
}
