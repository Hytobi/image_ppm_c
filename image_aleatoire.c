#include <stdio.h>
#include <stdlib.h>
/*
produit une image aléatoire, c’est-à-dire une image dans laquelle
les pixels sont choisis aléatoirement
*/
int main(){
    int nb_col = 128;
    int nb_lig = 128;
    int i,j;

    printf("P3 \n %d %d \n 255 \n",nb_lig,nb_col);
    for (i=0;i<nb_lig;i++){
        for (j=0;j<nb_col;j++){
            printf("%d %d %d\n",random()%256,random()%256,random()%256);
        }
    }
    return 0;
}
