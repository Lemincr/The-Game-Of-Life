#include <stdio.h>
#include "analyse.h"

int count_alive(Grid *g) {
    int count = 0;
    for (int i = 0; i < g->lines; i++) {
        for (int j = 0; j < g->cols; j++) {
            count += g->matrix[i][j];
        }
    }
    return count;
}

void show_stats(Grid *g) {
    int alive = count_alive(g);
    float density = (float)alive / (g->lines * g->cols);
    printf("Population: %d\n", alive); [cite: 37]
    printf("Density: %.2f\n", density); [cite: 38]
}

int check_stable(Grid *g1, Grid *g2) {
    for (int i = 0; i < g1->lines; i++) {
        for (int j = 0; j < g1->cols; j++) {
            if (g1->matrix[i][j] != g2->matrix[i][j]) return 0; // Not stable [cite: 41]
        }
    }
    return 1; // Grids are identical [cite: 41]
}
