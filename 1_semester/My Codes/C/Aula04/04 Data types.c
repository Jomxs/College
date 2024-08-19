#include <stdio.h>
//a variable can ONLY have up to a number that is 4 bytes or 32 bits that is 2^32 so it's a number of -2147483648 and +2147483647.

int main (){
    printf("\n\nDouble--------------");
    double number = 12.45;
    printf("\n%lf" , number);

    //since its 8 bytes it will put a number with four zeros. But we can write "%.2lf" that olny gets 2 numbers of double.
    float number01 = 10.9f;
    printf("\n\nFloat--------------");
    //f in the end indicates that is different from a double number.
    printf("\n%.1f", number01);

    double number02 = 5.5e6;
     printf("\n\nExponential--------------");
    //we can store exponential numbers
    printf("\n%lf", number02);

    char character = 'z';
    printf("\n\nChar--------------");
    printf("\n%c",character);
    printf("\n%d",character);
    //122 is 'z' in the Ascii table



//int              (4 bytes) | %d for printing
//double           (8 bytes) | %lf for printing
//float            (4 bytes) | %f for printing
//char             (1 byte)  | % for printing

return 0;
}

