#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct no
{
    char dado;
    struct no *prox;
} No;

typedef struct
{
    No *topo;
    int tamPilha;
} Pilha;

void cria(Pilha *s);
int empilha(Pilha *s, char dado);
int desempilha(Pilha *s, char *dado);
int estaVazia(Pilha s);
char getTopo(Pilha s);
int getTamanho(Pilha s);
void mostra(Pilha s);

int verificaExpresao(char *exp);

int main()
{
    printf("Atividade pilha\n");
    printf("==========================================================\n\n");

    char expresao[50];
    printf("Digite a expressao aritimetica a ser avaliada:\n");
    fgets(expresao, 50, stdin);

    printf("A expresao eh: %s\n", expresao);

    if(verificaExpresao(expresao))
        printf("A expressao e valida");
    else
        printf("A expressao e invalida!");

 return 1;
}


void cria(Pilha *s)
{
    s->topo = NULL;
    s->tamPilha = 0;
}


int empilha(Pilha *s, char dado)
{
    No *aux;
    aux = (No *)malloc(sizeof(No));
    if (aux == NULL)
        return 0;

    aux->dado = dado;
    aux->prox = s->topo;
    s->topo = aux;
    s->tamPilha++;

    return 1;
}


int desempilha(Pilha *s, char *dado)
{
    No *aux = s->topo;
    if (aux == NULL)
        return 0;

    *dado = aux->dado;
    s->topo = aux->prox;
    s->tamPilha--;
    free(aux);

    return 1;
}


int estaVazia(Pilha s)
{
    if (s.topo == NULL)
        return 1;
    return 0;
}


char getTopo(Pilha s)
{
    return s.topo->dado;
}


int getTamanho(Pilha s)
{
    return s.tamPilha;
}


void mostra(Pilha s)
{
    No *aux = s.topo;
    if (aux == NULL)
        printf("Pilha vazia...\n");
    else
    {
        while (aux != NULL)
        {
            printf("Dado armazenado: %c\n", aux->dado);
            aux = aux->prox;
        }
    }
}
int verificaExpresao(char *exp) {
    Pilha s;
    char simbolo;

    cria(&s);

    int tam = strlen(exp);
    for(int i = 0; i < tam; i++) {

        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            if(!empilha(&s, exp[i])) {
                printf("Falha em empilhar\n");
                return 0;
            }
        }


        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {

            if(estaVazia(s))
                return 0;

            desempilha(&s, &simbolo);


            if(exp[i] == ')' && simbolo != '(')
                return 0;
            if(exp[i] == ']' && simbolo != '[')
                return 0;
            if(exp[i] == '}' && simbolo != '{')
                return 0;
        }
    }


    if(!estaVazia(s))
        return 0;
    return 1;
}
