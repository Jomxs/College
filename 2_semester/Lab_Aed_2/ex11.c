#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Pessoa {
    char nome[40];
    char cpf[12];
    int senha;
    struct no *prox;
} Pessoa;

typedef struct no {
    Pessoa dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamFila;
} Fila;

void cria(Fila *q);
int insere(Fila *q, Pessoa dado);
int retira(Fila *q, Pessoa *dado);
int estaVazia(Fila q);
int getTamanho(Fila q);
void mostra(Fila q);

int main() {
    Fila fila;
    cria(&fila);
    Pessoa pessoa;
    int sucesso, i;
    srand(time(NULL));

    printf("Fila de Pessoas\n");
    printf("========================================\n\n");

    for(i = 0; i < 20; i++) {
        int numero = rand() % 100 + 1;

        if (numero <= 60) {

            printf("\nDigite o nome da pessoa: \n");
            fgets(pessoa.nome, 40, stdin);
            pessoa.nome[strcspn(pessoa.nome, "\n")] = 0;

            printf("Digite o CPF (11 digitos): \n");
            fgets(pessoa.cpf, 12, stdin);
            pessoa.cpf[strcspn(pessoa.cpf, "\n")] = 0;

            printf("Digite a senha numerica: \n");
            scanf("%d", &pessoa.senha);
            getchar();

            sucesso = insere(&fila, pessoa);
            if (sucesso) {
                printf("Pessoa inserida com sucesso!\n");
            }
        } else if (!estaVazia(fila)) {

            sucesso = retira(&fila, &pessoa);
            if (sucesso) {
                printf("\nPessoa removida da fila:\n");
                printf("Nome: %s\n", pessoa.nome);
                printf("CPF: %s\n", pessoa.cpf);
                printf("Senha: %d\n", pessoa.senha);
            }
        } else {
            printf("\nFila vazia, ninguém para remover.\n");
        }
    }


    while (!estaVazia(fila)) {
        sucesso = retira(&fila, &pessoa);
        if (sucesso) {
            printf("\nPessoa removida da fila:\n");
            printf("Nome: %s\n", pessoa.nome);
            printf("CPF: %s\n", pessoa.cpf);
            printf("Senha: %d\n", pessoa.senha);
        }
    }

    return 0;
}

void cria(Fila *q) {
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

int insere(Fila *q, Pessoa dado) {
    No *aux = (No *) malloc(sizeof(No));
    if (aux == NULL)
        return 0;

    aux->dado = dado;
    aux->prox = NULL;
    q->tamFila++;

    if (q->inicio == NULL) {
        q->inicio = aux;
        q->fim = aux;
    } else {
        q->fim->prox = aux;
        q->fim = aux;
    }
    return 1;
}

int retira(Fila *q, Pessoa *dado) {
    if (q->inicio == NULL)
        return 0;

    No *aux = q->inicio;
    *dado = aux->dado;
    q->inicio = aux->prox;
    q->tamFila--;

    if (q->inicio == NULL)
        q->fim = NULL;

    free(aux);
    return 1;
}

int estaVazia(Fila q) {
    return (q.inicio == NULL);
}

int getTamanho(Fila q) {
    return q.tamFila;
}

void mostra(Fila q) {
    No *aux = q.inicio;
    if (aux == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    while (aux != NULL) {
        printf("Nome: %s, CPF: %s, Senha: %d\n", aux->dado.nome, aux->dado.cpf, aux->dado.senha);
        aux = aux->prox;
    }
}
