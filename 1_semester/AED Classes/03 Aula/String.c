#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char s1[8], s2[8],s3[16]="";
    //voce deve colocar o ="" na s3 pois quando voce conecta as duas variaveis na s3 voc� cria lixo de memoria dentro da s3

    printf("Manipulando Strings....\n");
    printf("--------------------------\n\n");

    printf("Digite a primeira sequ�ncia : \n");
    gets(s1);
    //gets e melhor que scanf para string pois usando o scanf nao reconhece espa�o
    printf("Digite a segunda sequ�ncia : \n");
    gets(s2);

    printf("Primeira sequ�ncia : %s\n", s1);
    printf("Segunda sequ�ncia : %s\n",s2);

    printf("Tamanho da primeira sequ�ncia : %d\n", strlen(s1));
    printf("Tamanho da segunda sequ�ncia : %d\n", strlen(s2));

    printf("Convertendo caractere para maiusculo: \n");
    s1[0] = toupper(s1[0]);
    s2[0] = toupper(s2[0]);

    printf("Primeira sequ�ncia : %s\n", s1);
    printf("Segunda sequ�ncia : %s\n",s2);

    printf("Concetando sequ�cias: \n");
    strcat(s3,s1);
    strcat(s3,s2);
    //junta duas strings

    printf("Sequ�ncia resultante : %s\n\n", s3);

    printf("Comparando as sequ�ncias: \n");
    if (strcmp(s1, s2) == 0) {
        printf("As sequ�ncias s�o iguais \n\n");
    } else {
        printf("As sequ�ncias s�o diferentes \n\n");
    }
    return 0;
}






