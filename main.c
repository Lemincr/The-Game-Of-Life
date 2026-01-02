#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "automate.h"
#include "analyse.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <L> <C>\n", argv[0]); [cite: 45]
        return 1;
    }

    int L = atoi(argv[1]); [cite: 47]
    int C = atoi(argv[2]); [cite: 48]
    
    if (L > MAX_L || C > MAX_C) {
        printf("Size exceeds limits (%dx%d)\n", MAX_L, MAX_C);
        return 1;
    }

    Grid g, next;
    init_empty_grid(&g, L, C);
    int choice = -1;

    while (choice != 0) {
        printf("\n--- LifeSim Menu ---\n"); [cite: 28]
        printf("1. Random Init | 2. Display | 3. Step | 4. Stats | 5. Reset | 0. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) init_random_grid(&g);
        else if (choice == 2) display_grid(&g);
        else if (choice == 3) {
            apply_rules(&g, &next);
            if (check_stable(&g, &next)) printf("STABLE STATE DETECTED\n");
            g = next; // Basic array copy [cite: 19]
            if (count_alive(&g) == 0) printf("EXTINCTION DETECTED\n");
        }
        else if (choice == 4) show_stats(&g);
        else if (choice == 5) init_empty_grid(&g, L, C);
    }

    return 0;
}
