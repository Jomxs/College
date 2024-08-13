#include<stdio.h>

int potencia(int x, int n);

int main(){

    int x, n;

    printf("Digite a potencia x^n que voce quer resolver. Digite primeiro o x e depois o n:");
    scanf("%d %d", &x, &n);

    printf("O resultado eh: %d", potencia(x, n));

    return 1;
}

int potencia(int x, int n){
    int res = 1;

    for(int i = 1; i <= n; i++){
        res *= x;
    }

    return res;

}
