#include<stdio.h>
#include<stdlib.h>


typedef struct{
    int id;
    char cor[20];
    float coordX;
    float coordY;
} Ponto;

int lePonto(FILE *f, Ponto *p);

int main(){
    Ponto p;

    FILE *f = fopen("pontos.txt", "a+");
    if(f == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Pontos eexitentes no arquivo: \n");

    while(lePonto(f, &p)){
          printf("%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
          }
    fclose(f);
    return 0;
}


int lePonto(FILE *f, Ponto *p){

    return fscanf(f, "%d %s %f %f", &p->id, p->cor,&p->coordX, &p->coordY);
}
