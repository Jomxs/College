#include <stdio.h>
#include <locale.h>
#include <math.h>


main() {

    double n, r, e, p, aMax, aMin;

    setlocale(LC_ALL, "Portuguese");
    //define o idioma do texto, assim podendo ussar ç.
    printf("Recusos Matemáticos da math.h\n");
    printf("=======================================");

    printf("Digite um número real = ");
    scanf("%lf",&n);
    //Ao trocar o idoma para portugûes começa a se usar virgula invez de ponto com números


    r = sqrt(n);
    printf("A raiz quadrada de %5.2f é %5.2f\n", n, r);
    printf("Digite um expoente=");
    scanf("%lf", &e);
    p = pow(n, e);
    //elevado
    printf("%5.2f elevado a %5.2f é igual a %12.2f \n\n", n, e, p);

    aMin = floor(r);
    //aredondar para baixo
    aMax = ceil(r);
    //aredondar para cima
    printf("%f arredondado para baixo é %f\n", r, aMin);
    printf("%f arredondado para cima é %f\n", r, aMax);


}
