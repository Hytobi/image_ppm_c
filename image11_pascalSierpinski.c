#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nbL 40

/*
Pascal -> Sierpiński.
On met un caractere pour les impaires et un rien pour les paires.
*/

int main() {
    int triangle[nbL][1 + 2 * nbL] = {};
    int i, j;
    triangle[0][nbL] = 1;
    for (i = 1; i < nbL; i++) {
        for (j = 1; j < (2 * nbL); j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j + 1];
        }
    }
    printf("P3 \n %d %d \n 255 \n", 1 + nbL * 2, nbL);
    for (i = 0; i < nbL; i++) {
        for (j = 0; j < (1 + 2 * nbL); j++) {
            if (triangle[i][j] % 2)
                printf("0 0 0\n");  // printf("\u25B2");
            else
                printf("255 255 255\n");  // printf(" ");
        }
        printf("\n");
    }

    return 0;
}