#include<stdio.h>
#include<stdlib.h>




//int m;
//int dm;
//int cm;
//int mm;
//int km;
//int m, dm, cm, mm, km;
int main(){
    float m, dm, cm, mm, km;
    printf("------------Meter calculator------------\n");
    printf("Write a random number:\n");

    scanf("%f", &m);

    // m * 1000 = km; is wrong because it needs to be in the other side of the equation.
    cm = m * 100;    // 1 meter = 100 centimeters
    dm = m * 10;     // 1 meter = 10 decimeters
    mm = m * 1000;   // 1 meter = 1000 millimeters
    km = m / 1000;   // 1 meter = 0.001 kilometers
    //you make the opposite of the equation
    printf("the results are:\n");
    printf("Centimeters: %.2f cm\n", cm);
    printf("Decimeters: %.2f dm\n", dm);
    printf("Millimeters: %.2f mm\n", mm);
    printf("Kilometers: %.6f km\n", km);


    return 0;

}
