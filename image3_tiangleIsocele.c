#include <stdio.h>
#include <stdlib.h>

/*
produit une image qui affiche un triangle isocèle
*/
int main() {
    int nb_col = 128;
    int nb_lig = 128;
    int i, j, l, r;
    float split = 2 * nb_lig / nb_col;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    for (i = 0; i < nb_lig; i++) {
        l = nb_col / 2 - (i / split);
        r = nb_col / 2 + (i / split);
        for (j = 0; j < nb_col; j++) {
            if (l > 0 && r < nb_col && j >= l && j <= r)
                printf("%d %d %d\n", 255, 255, 255);
            else
                printf("%d %d %d\n", 0, 0, 0);
        }
    }
    return 0;
}