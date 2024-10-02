#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    float coordX;
    float coordY;
} Ponto;

void registraPonto(Ponto *p) {
    printf("Coloque o valor de X:\n");
    scanf("%f", &(p->coordX));// O operador -> é utilizado para acessar membros da struct através de um ponteiro.
    printf("Agora coloque o valor de Y:\n");
    scanf("%f", &(p->coordY));
}

float calculaDistancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.coordX - p1.coordX, 2) + pow(p2.coordY - p1.coordY, 2));
}

int verificaTipoTriangulo(Ponto *p) {
    float d1 = calculaDistancia(p[0], p[1]);
    float d2 = calculaDistancia(p[1], p[2]);
    float d3 = calculaDistancia(p[2], p[0]);

    if (d1 == d2 && d2 == d3) {
        return 2; // Equilátero
    } else if (d1 == d2 || d2 == d3 || d1 == d3) {
        return 1; // Isósceles
    } else {
        return 3; // Escaleno
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Ponto v[3];

    for (int i = 0; i < 3; i++) {
        printf("Ponto %d: ", i + 1);
        registraPonto(&v[i]);
    }

    int tipo = verificaTipoTriangulo(v);

    if (tipo == 1) {
        printf("O triângulo é Isósceles.\n");
    } else if (tipo == 2) {
        printf("O triângulo é Equilátero.\n");
    } else if (tipo == 3){
        printf("O triângulo é Escaleno.\n");
    } else {
      printf("Algum erro foi encontrado.\n");
    }

    return 0;
}
