#include <stdio.h>
#include <string.h>// precisei pra strlen
#include <locale.h>

int potencia(int x,int n){
    if (n == 1)
        return x;//pra acabar a função

        //não precissa do else pois é so uma instrução e esta logo após um if
    return x *potencia(x, n - 1);

}

int mod(int x, int y) {
    if (x == y) {
        return 0;
    }if (x < y) {
        return x;
    }if (x > y){
        return mod(x - y, y);//mod: a sobra da divisao
    }
}


void inverterString(char str[], int inicio, int fim) {
        if(inicio < fim){
            char temp = str[inicio];
            str[inicio] = str[fim];
            str[fim] = temp; //oque ele explicou na aula
            inverterString(str, inicio + 1, fim - 1);
    }
}

int somaVetor(int vetor[], int tamanho){
if(tamanho == 0){
    return 0;// pra acabar a função
}
else {
    return vetor[tamanho - 1] + somaVetor(vetor, tamanho - 1);//tira um do tamanho
    }
}


int main(){
setlocale(LC_ALL, "Portuguese");

int x = 8, n = 4;

int a = 27, b = 5;

char str[50] = "Aula Lab Aed 2";

int vetor[] = {1,2,4,5,7,8,12};
int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Atividade Avaliativa 02 - Recursividade\n");
    printf("=========================================================\n");
    printf("Exercício 01\n\n\n");
    printf("Potência de %d^%d = %d\n\n\n", x, n, potencia(x, n));
    printf("=========================================================\n");
    printf("Exercício 02\n\n\n");
    printf("O resto da divisão é(%d, %d) = %d\n", a, b, mod(a, b));
    printf("=========================================================\n");
    printf("Exercício 03\n\n\n");
    inverterString(str, 0, strlen(str) - 1);
    printf("A String invertida é: %s\n", str);
    printf("=========================================================\n");
    printf("Exercício 04\n\n\n");
    printf("Soma do vetor = %d\n", somaVetor(vetor, tamanho));
    printf("=========================================================\n");

}
