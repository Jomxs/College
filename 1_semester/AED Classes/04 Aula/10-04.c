#include <stdio.h>

int JoseI, JoseN, Josesum = 0;


int main() {
    printf("Digite um Numero inteiro:\n");
    scanf("%d", &JoseN);

    if (JoseN < 0) {
        printf("Numero negativo! Calculo nao realizado\n");
    } else {


     for (JoseI = JoseN; JoseI >= 0; JoseI--)
        {

        Josesum = Josesum + JoseI;

        }
        printf("O somatorio de %d ate 0 e: %d\n", JoseN, Josesum);
    }





    return 0;

}
