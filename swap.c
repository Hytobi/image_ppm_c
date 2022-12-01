#include <stdio.h>

/*
étant données deux variables entières a et b, échange le contenu
de a et b sans déclarer de nouvelles variables
*/
int main() {
    int num1, num2;
    scanf("%d%d", &num1, &num2);

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("num1 apres swap = %d\n", num1);
    printf("num2 apres swap = %d\n", num2);
    return 0;
}