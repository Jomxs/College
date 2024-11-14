#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char cor[20];
    float coordX;
    float coordY;
} Ponto;

int lePonto(FILE *f, Ponto *p);
Ponto cadastraPonto();
int escrevePonto(FILE *f);

int main() {
    Ponto p;
    int n;

    FILE *f = fopen("pontos.txt", "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Pontos existentes no arquivo: \n");

    while (lePonto(f, &p) > 0) {
        printf("%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
    }

    printf("-------------Registrando novos pontos-------------\n");
    printf("Quantos pontos você deseja registrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        escrevePonto(f);
    }
    fclose(f);
    return 0;
}

int lePonto(FILE *f, Ponto *p) {
    return fscanf(f, "%d %s %f %f", &p->id, p->cor, &p->coordX, &p->coordY);
}

Ponto cadastraPonto() {
    Ponto p;

    printf("Digite as informações do ponto: \n");
    printf("Id: ");
    scanf("%d", &p.id);
    getchar();
    printf("Cor: ");
    scanf("%s", p.cor);
    printf("CoordenadaX: ");
    scanf("%f", &p.coordX);
    printf("CoordenadaY: ");
    scanf("%f", &p.coordY);

    return p;
}

int escrevePonto(FILE *f) {
    Ponto p = cadastraPonto();

    return fprintf(f, "%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
}
