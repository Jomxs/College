#include<stdio.h>

void impares(int n);

int main(){

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    impares(n);

    return 1;
}

void impares(int n){
    for(int i = n; i > 0; i--){
        if(i % 2 == 1)
            printf("%d\n", i);
    }
}
