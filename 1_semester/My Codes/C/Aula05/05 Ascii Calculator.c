#include <stdio.h>
int main(){
    char c;
    printf("-----------ASCII CALCULATOR-----------\n\n");
    printf("Enter a Character:");
    scanf("%c", &c);

    // %d displays the integer value of a character
    // %c displays the actual character

    printf("Tht ASCII Value of this character is: %c = %d", c, c);

    return 0;


}
