#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Fougere de  Michael Barnsley

• Le premier point est O est (0, 0) ;
• À partir de ce point O, chaque point est obtenu à partir de son prédécesseur
en appliquant une des quatre transformations suivantes : – f1 avec une
probabilité de 0,01 ; – f2 avec une probabilité de 0,85 ; – f3 avec une
probabilité de 0,07 ; – f4 avec une probabilité de 0,07.

– pour f1 : M1 =(0,0,0,0.16) et V1 = (0,0)
– pour f2 : M2 =(0.85,0.04,−0.04,0.85) et V2 = (0,1.6)
– pour f3 : M3 =(0.2,−0.26,0.23,0.22) et V3 = (0,1.6)
– pour f4 : M4 =(−0.15,0.28,0.26,0.24) et V4 = (0,0.44)

où M est la matrice de transformation (2X2) et V est le vecteur de translation
(2X1).
*/

int main(int argc, char** argv) {
    // srand(time(NULL));
    assert(argc == 2);

    int nb_col = 1024;
    int nb_lig = 1024;

    int nbIte = atoi(argv[1]), rdm, px, py, i, j;
    unsigned char pixels[1024][1024] = {};

    float x = 0, y = 0, ox, oy;

    while (--nbIte) {
        rdm = random() % 100;
        ox = x;
        oy = y;
        if (rdm < 1) {
            x = 0;
            y = 0.16 * oy;
        } else if (rdm < 86) {
            x = 0.85 * ox + 0.04 * oy;
            y = -0.04 * ox + 0.85 * oy + 1.6;
        } else if (rdm < 93) {
            x = 0.2 * ox - 0.26 * oy;
            y = 0.23 * ox + 0.22 * oy + 1.6;
        } else {
            x = -0.15 * ox + 0.28 * oy;
            y = 0.26 * ox + 0.24 * oy + 0.44;
        }

        px = nb_col / 2 + (nb_col * (x / 6));
        py = nb_lig - (nb_lig * (y / 10));
        assert(px >= 0 && px < nb_col && py >= 0 && py < nb_lig);
        pixels[py][px] = 1;
    }

    printf("P3 \n %d %d \n 255 \n", nb_col, nb_lig);
    for (i = 0; i < nb_lig; i++) {
        for (j = 0; j < nb_col; j++) {
            if (pixels[i][j])
                printf("0 0 0\n");
            else
                printf("255 255 255\n");
        }
    }

    return 0;
}
