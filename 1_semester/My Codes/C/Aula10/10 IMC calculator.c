#include <stdio.h>
#include <math.h>
#include <locale.h>
#define THR 18.5

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configurando o locale para Português
    char nome[256]; // Usando uma matriz de caracteres para armazenar o nome
    unsigned int idade; // Usando unsigned int para idade
    float peso = 0; // Usando float para peso, imc e altura
    float altura = 0;
    float imc = 0;

    printf("Calculadora IMC :)\n");
    printf("==========================================\n");
    printf("Insira seu nome: ");
    scanf("%s", nome); // Usando %s para ler uma string (nome)
    printf("Insira sua idade: ");
    scanf("%u", &idade); // Lendo idade como unsigned int
    printf("Insira seu peso (em kg): ");
    scanf("%f", &peso);
    printf("Insira sua altura (em metros): ");
    scanf("%f", &altura);

    // Cálculo do IMC
    imc = peso / (altura * altura);

    // Exibindo os resultados
    printf("\n%s tem %u anos de idade.\n", nome, idade);
    printf("Seu IMC é: %.2f\n", imc);
    //LEMBRNADO: como esta em portues você coloca virgula na altura para ficar correto

       if (imc <= 26) {

    printf("O seu Imc indica que você esta no peso ideal :)");

    }  if (imc >= 26) {

    printf("O seu Imc indica que você esta sobrepeso  :(");

    }  if (imc >= 30) {

    printf("O seu Imc indica que você esta OBESO :0");

    }

    return 0;
}
