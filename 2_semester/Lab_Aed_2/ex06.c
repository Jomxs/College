#include <stdio.h>

int mdc (int , int y);


int main() {
    int x = 30, y = 20;


    printf("Determinador do maior divisor\n");
    printf("================================\n\n\n");

    printf("O MDC entre %d e %d e: \n%d\n\n", x, y, mdc(x, y));

    return 1;
}
int mdc(int x, int y){
    if ((y <= x) && (x % y == 0))
        return y;
    if(x < y)
        return mdc(y, x);

    return mdc(y, x % y);


}

