#include <stdio.h>
#include <locale.h>
#include <math.h>


main() {

    double n, r, e, p, aMax, aMin;

    setlocale(LC_ALL, "Portuguese");
    //define o idioma do texto, assim podendo ussar �.
    printf("Recusos Matem�ticos da math.h\n");
    printf("=======================================");

    printf("Digite um n�mero real = ");
    scanf("%lf",&n);
    //Ao trocar o idoma para portug�es come�a a se usar virgula invez de ponto com n�meros


    r = sqrt(n);
    printf("A raiz quadrada de %5.2f � %5.2f\n", n, r);
    printf("Digite um expoente=");
    scanf("%lf", &e);
    p = pow(n, e);
    //elevado
    printf("%5.2f elevado a %5.2f � igual a %12.2f \n\n", n, e, p);

    aMin = floor(r);
    //aredondar para baixo
    aMax = ceil(r);
    //aredondar para cima
    printf("%f arredondado para baixo � %f\n", r, aMin);
    printf("%f arredondado para cima � %f\n", r, aMax);


}
