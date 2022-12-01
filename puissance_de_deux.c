#include <stdio.h>

/*
vérifie si un nombre est une puissance de 2
*/
int main() {
    int nb;
    printf("entrer un nombre : ");
    scanf("%d", &nb);

    if (!(nb & (nb - 1)))
        printf("oui\n");
    else
        printf("non\n");
    return 0;
}