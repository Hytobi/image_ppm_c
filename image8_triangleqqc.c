#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Produit un triangle grace a 3 points
*/
float area(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
    return fabs(0.5 * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)));
}

int isIn(int px, int py, int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
    float a = area(Ax, Ay, Bx, By, Cx, Cy);
    float a1 = area(px, py, Bx, By, Cx, Cy);
    float a2 = area(Ax, Ay, px, py, Cx, Cy);
    float a3 = area(Ax, Ay, Bx, By, px, py);
    return a == a1 + a2 + a3;
}

void triangle(int ligne, int colonne, int Ax, int Ay, int Bx, int By, int Cx,
              int Cy) {
    int i, j;
    for (i = 0; i < ligne; i++) {
        for (j = 0; j < colonne; j++) {
            if (isIn(i, j, Ax, Ay, Bx, By, Cx, Cy))
                printf("0 255 255\n");
            else
                printf("0 0 0\n");
        }
    }
}

int main() {
    int nb_col = 500;
    int nb_lig = 500;
    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    triangle(nb_lig, nb_col, 100, 10, 40, 103, 250, 250);
    return 0;
}
