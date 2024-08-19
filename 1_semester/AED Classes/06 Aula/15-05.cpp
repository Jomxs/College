#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    float pontuacao;
} jogador;

int main() {
    jogador lista[4];
    int i, vencedor;
    float maior;

    printf("Arranjo de Dados - Vetor e Registro\n");
    printf("===================================================\n\n");
    printf("Fornecendo os dados de cada jogador...\n");

    for(i = 0; i < 4; i++) {
        // adiciona mais 1 pra não ser 0 o primeiro
        printf("Digite o id do jogador %d = ", i+1);
        scanf("%d", &lista[i].id);
        getchar();
         // getchar para não dar erro
        printf("Digite o nome do jogador %d = ", i+1);
        gets(lista[i].nome);
        printf("Digite a pontuacao do jogador %d  = ", i+1);
        scanf("%f", &lista[i].pontuacao);
        getchar();
    }

    printf("Localizando o(a) maior vencedor(a)... \n\n");
    maior = lista[0].pontuacao;
    vencedor = 0;
    for(i = 1; i < 4; i++) {
        if(lista[i].pontuacao > maior) {
            maior = lista[i].pontuacao;
            vencedor = i;
        }
    }
    printf("\nO(A) vencedor(a) foi %s com id %d\n\n", lista[vencedor].nome, lista[vencedor].id);

    return 0;
}
