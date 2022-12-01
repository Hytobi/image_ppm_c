#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
Produit une liaison entre un ensemble de point
*/

int isIn(float px, float py, float Ax, float Ay, float Bx, float By) {
    float coeffA;
    if (Bx - Ax == 0)
        coeffA = 0;
    else
        coeffA = (By - Ay) / (Bx - Ax);
    float coeffB = Ay - Ax * coeffA;
    if (py <= coeffA * px + coeffB + 1 && py >= coeffA * px + coeffB - 1)
        return 1;
    return 0;
}

void printTab(int size, ...) {
    int v, j, inc = 0, i = 0, stop = 0;
    int longueur = size;
    float* tab = malloc(size * sizeof(float));
    int nb_col = 500;
    int nb_lig = 500;
    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);

    va_list args;
    va_start(args, size);
    while (size) {
        v = va_arg(args, int);
        // printf("%d\n",v);
        tab[i] = v;
        size--;
        i++;
    }
    va_end(args);

    for (i = 0; i < nb_lig; i++) {
        for (j = 0; j < nb_col; j++) {
            if (isIn(i, j, tab[inc], tab[inc + 1], tab[inc + 2],
                     tab[inc + 3]) &&
                !stop) {
                printf("0 255 255\n");
                if (i == tab[inc + 2] && j == tab[inc + 3]) {
                    inc += 2;
                    if ((inc + 4) > longueur + 1) stop = 1;
                }
            } else
                printf("255 0 0\n");
        }
    }
}

int main(int arg, int** args) {
    printTab(8, 1, 1, 250, 100, 300, 350, 450, 450);
}
