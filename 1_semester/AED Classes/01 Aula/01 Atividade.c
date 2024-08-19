#include <stdio.h>

int main() {
    char nome[20];
    unsigned short int idade;
    float peso;
    float altura;
    float imc;

    printf("---Calculadora IMC---\n\n\n");
    printf("Escreva seu nome:\n");
    scanf("%s", nome);
    //nome é string

    printf("Escreva sua idade:\n");
    scanf("%hu", &idade);
    //unsigned short int = %hu

    printf("Escreva seu peso:\n");
    scanf("%f", &peso);

    printf("Escreva sua altura:\n");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Nome: %s, Idade: %hu, Peso: %2.f, Altura: %.3f, IMC: %f\n", nome, idade, peso, altura, imc);
    //você têm que colocar cada formato para mandar a resposta
    //.2 e .3 para delimitar o tamanho da resposta você apenas coloca no printf.

    return 0;
    //SEMPRE RETORNAR ZERO

}

