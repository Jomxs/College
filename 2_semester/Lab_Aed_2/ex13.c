#include<stdio.h>
#include<stdlib.h>

typedef struct no {

    int dado;
    struct no *esq;
    struct no *dir;
} No;

void cria(No **t);
int insere(No **t, int dado);
No *encontraMaxDireita(No **t);
int retira(No **t, int dado);


void preOrdem(No *t);
void emOrdem(No *t);
void posOrdem(No *t);
int  maiorElemento(No *t);
int  AlturaArvore(No *t);
int  ContaArvore(No *t);

int main(){

    No *arvore;
    int sucesso;

    cria(&arvore);

    sucesso = insere(&arvore, 30);
    sucesso = insere(&arvore, 10);
    sucesso = insere(&arvore, 70);
    sucesso = insere(&arvore, 100);
    sucesso = insere(&arvore, 5);
    sucesso = insere(&arvore, 20);
    sucesso = insere(&arvore, 15);
    sucesso = insere(&arvore, 13);
    sucesso = insere(&arvore, 19);
    sucesso = insere(&arvore, 17);

    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\nMaior valor: %d", maiorElemento(arvore));

    printf("\n\nAltura: %d", AlturaArvore(arvore));

    printf("\n\nNumero da nos da Arvore: %d\n\n", ContaArvore(arvore));

}

void cria(No **t){

    *t = NULL;
}


int insere(No **t, int dado){

    if(*t == NULL) {
        *t = (No *) malloc(sizeof(No));
        if(*t == NULL)
            return 0;

        (*t)->dado = dado;
        (*t)->esq = NULL;
        (*t)->dir = NULL;

        return 1;
    }



    if(dado < (*t)->dado)
        return insere(&(*t)->esq, dado);

    return insere(&(*t)->dir, dado);
}


No *encontraMaxDireita(No **t){
    if((*t)->dir != NULL)
        return encontraMaxDireita(&(*t)->dir);

    No *aux = *t;
    if((*t)->esq != NULL)
        *t = (*t)->esq;
    else
        *t = NULL;

    return aux;

}


int retira(No **t, int dado){

    if(*t == NULL){
        printf("Elemento inexistente: %d\n\n", dado);
        return 0;
    }

    if(dado < (*t)-> dado)
        return retira(&(*t)->esq, dado);

    if(dado > (*t)->dado)
        return retira(&(*t)->dir, dado);



    No *aux = *t;


    if(((*t)->esq == NULL) && ((*t)->dir == NULL)) {
        *t = NULL;
        free(aux);
        return 1;
    }


    if((*t)->dir == NULL) {
        *t = (*t)->esq;
        free(aux);
        return 1;
    }


    if((*t)->esq == NULL) {
        *t = (*t)->dir;
        free(aux);
        return 1;
    }



    No *substituto = encontraMaxDireita(&(*t)->esq);
    substituto->esq = (*t)->esq;
    substituto->dir = (*t)->dir;
    *t = substituto;
    free(aux);
    return 1;

}

void preOrdem(No *t) {

    if(t != NULL) {
        printf("%d ", t->dado);
        preOrdem(t->esq);
        preOrdem(t->dir);
    }
}

void emOrdem(No *t) {

    if(t != NULL) {
        emOrdem(t->esq);
        printf("%d ", t->dado);
        emOrdem(t->dir);
    }
}

void posOrdem(No *t) {

    if(t != NULL) {
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf("%d ", t->dado);
    }
}
int maiorElemento(No *t) {

    if(t != NULL) {
       if(t->dir != NULL)
            return maiorElemento(t->dir);
        return t->dado;
        }
    return -1;
}


int AlturaArvore(No *t) {

    if(t == NULL)
        return -1;

    int dir = AlturaArvore(t->dir);
    int esq = AlturaArvore(t->esq);

    if(dir > esq)
        return dir + 1;
    return esq + 1;


}

int ContaArvore(No *t){
    if(t == NULL)
        return 0;
    return ContaArvore(t->esq) + ContaArvore(t->dir) + 1;
}


