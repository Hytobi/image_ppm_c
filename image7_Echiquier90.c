#include <stdio.h>
#include <stdlib.h>

/*
Echiquier 90 degrée
*/

/*
void losange(int ligne, int colonne, int splitX, int splitY){
    int l,c;
    for (l=0;l<ligne;l++){
        for (c=0;c<colonne;c++){
            if (l&1==0 && c&1==0){
                if (l<splitX-c)printf("%d %d %d\n",255,0,0);
                else printf("%d %d %d\n",255,255,255);
            }
            if (l&1==0 && c&1==1){
                if (c>l)printf("%d %d %d\n",255,0,0);
                else printf("%d %d %d\n",255,255,255);
            }
            if (l&1==1 && c&1==0){
                if (l>c)printf("%d %d %d\n",255,0,0);
                else printf("%d %d %d\n",255,255,255);
            }
            if (l&1==1 && c&1==1){
                if (c<splitY-l)printf("%d %d %d\n",255,0,0);
                else printf("%d %d %d\n",255,255,255);
            }

        }
    }
}
*/

void losange(int ligne, int colonne, int splitX, int splitY) {
    int i, j, r, li, lj;
    int couleur;
    int stepX = colonne / splitX, stepY = ligne / splitY;

    for (i = 0; i < ligne; i++) {
        for (j = 0; j < colonne; j++) {
            li = i % stepY;  // avec ca on se place dans le petit carré
            lj = j % stepX;
            r = (i / stepY) &
                1;  // pour savoir si on est sur une ligne pair ou impair
            couleur = 255 * r;
            if ((r + (j / stepX)) % 2 == 0) {
                if (li < stepX - lj) couleur = 255 - couleur;
            } else {
                if (li < lj) couleur = 255 - couleur;
            }
            printf("%d %d %d\n", couleur, couleur, couleur);
        }
    }
}

int main() {
    int nb_col = 500;
    int nb_lig = 500;

    printf("P3 \n %d %d \n 255 \n", nb_lig, nb_col);
    losange(nb_lig, nb_col, 10, 10);
    return 0;
}
