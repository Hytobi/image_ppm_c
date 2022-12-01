#include <stdio.h>
#include <stdlib.h>

/*
produit une image qui du centre et le rayon, affiche un cercle de
center (x,y) et de rayon r
*/
int main() {
    int nb_col = 128;
    int nb_lig = 128;
    int i, j, dim = nb_col * 4;
    int x = 100, y = 25;
    int inter;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    for (i = 0; i < nb_lig; i++) {
        for (j = 0; j < nb_col; j++) {
            inter = (j - x) * (j - x) + (i - y) * (i - y);
            if (inter < dim)
                printf("%d %d %d\n", 0, 0, 0);
            else if (inter < dim + 60)
                printf("%d %d %d\n", 255, 0, 0);
            else
                printf("%d %d %d\n", 255, 255, 255);
        }
    }
    return 0;
}
