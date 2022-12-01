#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
Jeu de la vie regle 22 avec decalage de bit
*/
const unsigned SIZE = 512;
const unsigned WIDTH = 1024;
const unsigned HEIGHT = 1024;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "USAGE %s RULE NB_ITERATION", *argv);
        exit(EXIT_FAILURE);
    }

    int rule = -1, i, shift, j;
    unsigned char state[SIZE], tmpState[SIZE];
    unsigned splitX, splitY;

    // Initialisation
    for (i = 0; i < SIZE; i++) state[i] = 0;
    state[SIZE >> 1] = 1;

    // Recuperation des arguments
    int regle = atoi(argv[1]);
    int nbIte = atoi(argv[2]);
    assert(regle >= 0 && regle < 256);
    assert(nbIte > 0);

    splitX = WIDTH / SIZE;
    splitY = HEIGHT / nbIte;

    printf("P3 \n %d %d \n 255 \n", WIDTH, HEIGHT);
    while (nbIte--) {
        // La copie a son pépère
        for (i = 0; i < SIZE; i++) tmpState[i] = state[i];
        for (i = 1; i < SIZE - 1; i++) {
            shift =
                (tmpState[i - 1] << 2) + (tmpState[i] << 1) + tmpState[i + 1];
            state[i] = (regle >> shift) & 1;
        }
        for (i = 0; i < splitY; i++) {
            for (j = 0; j < WIDTH; j++) {
                if (state[j / splitX])
                    printf("255 255 255\n");
                else
                    printf("0 0 0\n");
            }
        }
    }
    return EXIT_SUCCESS;
}