#include<stdio.h>

void ordena(int n1, int n2, int n3);

int main(){

    int n1, n2, n3;

    printf("Digite tres numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    ordena(n1, n2, n3);

    return 1;
}

void ordena(int n1, int n2, int n3){

    int menor, meio, maior;

    if ((n1 <= n2) && (n1 <= n3)){
        menor = n1;
        if(n2 <= n3){
            meio = n2;
            maior = n3;
        } else {
            meio = n3;
            maior = n2;
        }
    }
    else if ((n2 <= n1) && (n2 <= n3)){
        menor = n2;
        if(n1 <= n3){
            meio = n1;
            maior = n3;
        } else {
            meio = n3;
            maior = n1;
        }
    }
    else {
        menor = n3;
        if(n1 <= n2){
            meio = n1;
            maior = n2;
        } else {
            meio = n2;
            maior = n1;
        }
    }

    printf("%d, %d, %d", menor, meio, maior);


}
