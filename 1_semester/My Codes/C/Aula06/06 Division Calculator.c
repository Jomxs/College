#include <stdio.h>
int main(){
    int n1, n2, quotient, remainder;
    printf("-----------Division Calculator-----------\n\n");
    printf("Enter the First Number:\n");
    scanf("%d", &n1);
    printf("Enter the Second Number:\n");
    scanf("%d", &n2);
    quotient = n1 / n2;

    remainder = n1 % n2;

    printf("Your Answer is: %d", quotient);
    printf(".%d", remainder);
    return 0;
}
