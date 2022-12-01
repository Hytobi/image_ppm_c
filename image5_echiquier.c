#include <stdio.h>
#include <stdlib.h>

/*
produit une image qui affiche un échiquier
*/
int main() {
    int nb_col = 128;
    int nb_lig = 128;
    int i, j, dim = nb_col / 8;
    int changer = 0, nb = 0;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    for (i = 0; i < nb_lig; i++) {
        if (nb == dim) {
            nb = 0;
            changer = (changer + 1) % 2;
        }
        if (changer) {
            for (j = 0; j < nb_col; j++) {
                if (j < dim || (j >= 2 * dim && j < 3 * dim) ||
                    (j >= 4 * dim && j < 5 * dim) ||
                    (j >= 6 * dim && j < 7 * dim))
                    printf("%d %d %d\n", 0, 0, 0);
                else
                    printf("%d %d %d\n", 255, 255, 255);
            }
        } else {
            for (j = 0; j < nb_col; j++) {
                if (j < dim || (j >= 2 * dim && j < 3 * dim) ||
                    (j >= 4 * dim && j < 5 * dim) ||
                    (j >= 6 * dim && j < 7 * dim))
                    printf("%d %d %d\n", 255, 255, 255);
                else
                    printf("%d %d %d\n", 0, 0, 0);
            }
        }
        nb++;
    }
    return 0;
}
