#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    float dado;
    struct no *prox;
} No;


No *aloca(float dado) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro\n");
        exit(1);
    }
    novo_no->dado = dado;
    novo_no->prox = NULL;
    return novo_no;
}


float encontra_maior(No *inicio) {
    if (inicio == NULL) {
        fprintf(stderr, "A lista esta vazia.\n");
        return -1;
    }

    float maior = inicio->dado;
    No *atual = inicio->prox;

    while (atual != NULL) {
        if (atual->dado > maior) {
            maior = atual->dado;
        }
        atual = atual->prox;
    }
    return maior;
}


int main() {
    printf("Maior Valor Lista\n");
    printf("==================================\n\n");



    No *n1 = aloca(6.9);
    No *n2 = aloca(3.2);
    No *n3 = aloca(0.7);
    No *n4 = aloca(4.6);
    No *n5 = aloca(2.8);


    n1->prox = n2;
    n2->prox = n3;
    n3->prox = n4;
    n4->prox = n5;
    n5->prox = NULL;


    float maior = encontra_maior(n1);
    if (maior != -1) {
        printf("O maior valor na lista e: %.1f\n", maior);
    }


    No *atual = n1;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
