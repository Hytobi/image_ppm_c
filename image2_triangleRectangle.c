#include <stdio.h>
#include <stdlib.h>

/*
produit une image qui affiche un triangle rectangle qui sépare
l’image en 2
*/
int main() {
    int nb_col = 128;
    int nb_lig = 128;
    int i, j = 0;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    while (j != nb_col) {
        for (i = 0; i < nb_lig - j; i++) printf("%d %d %d\n", 255, 255, 255);
        for (i = nb_lig - j; i < nb_col; i++) printf("%d %d %d\n", 0, 0, 0);
        j++;
    }

    return 0;
}

/*
int main(){
    int nb_col = 128;
    int nb_lig = 128;
    int i,j;

    printf("P3 \n %d %d \n 255 \n",nb_lig,nb_col);
    for (i=0;i<nb_lig;i++){
        for (j=0;j<nb_col;j++){
            if (i+j<nb_col && i+j<nb_lig) printf("%d %d %d\n",0,255,255);
            else printf("%d %d %d\n",255,255,255);
        }
    }
    return 0;
}
*/