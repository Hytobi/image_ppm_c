#include <stdio.h>

/*
Le jeu des bâtonnets est un jeu popularisé par l’émission de divertissement fort
Boyard. C’est un jeu deux joueurs, où les joueurs retirent chacun leur tour 1,
2, ou 3 bâtonnets il ne faut pas être celui qui retirera le dernier.
*/
int main() {
    int n;
    printf("choisir le nb de batons : ");
    scanf("%d", &n);

    int choix;
    int joueur;
    int i;

    while (n) {
        for (i = 0; i < n; i++) printf(" | ");
        printf("\n");

        printf("choisir le nb de batons enlevé par le joueur %d: ",
               1 + (joueur & 1));
        scanf("%d", &choix);
        if (choix >= 1 && choix <= 3 && choix <= n) {
            n -= choix;
            joueur++;
        }
    }
    printf("Le joueur %d à gagné.\n", 1 + (joueur & 1));
    return 0;
}