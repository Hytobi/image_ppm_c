#include <stdio.h>
#include <stdlib.h>

/*
produit une image qui affiche un drapeau
*/
int main() {
    int nb_col = 128;
    int nb_lig = 128;
    int i, j, l, r;
    float split = nb_col / 3;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    for (i = 0; i < nb_lig; i++) {
        for (j = 0; j < nb_col; j++) {
            if (j <= split)
                printf("%d %d %d\n", 0, 0, 255);
            else if (j <= 2 * split)
                printf("%d %d %d\n", 255, 255, 255);
            else
                printf("%d %d %d\n", 255, 0, 0);
        }
    }
    return 0;
}