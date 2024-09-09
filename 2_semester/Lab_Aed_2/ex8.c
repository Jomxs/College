#include <stdlib.h>
#include <stdio.h>

int* alocaVetor(int tam);
void preencheVetor(int* v, int tam);
float calculaMedia(int* v, int tam);

int main() {
    int tam, *v;

    printf("Calcule a média do vetor dinâmico\n");
    printf("==========================================\n");
    printf("Digite o tamanho do seu vetor: \n");
    scanf("%d", &tam);

    v = alocaVetor(tam);
    preencheVetor(v, tam);


    printf("A média é: %.2f\n", calculaMedia(v, tam));

    free(v);

    return 0;
}


int* alocaVetor(int tam) {
    int* v = (int*)malloc(sizeof(int) * tam);
    if (v == NULL) {
        printf("\nErro: problema de memoria\n");
        exit(1);
    }
    return v;
}


void preencheVetor(int* v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &v[i]);
    }
}


float calculaMedia(int* v, int tam) {
    float soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += v[i];
    }
    return soma / tam;
}
