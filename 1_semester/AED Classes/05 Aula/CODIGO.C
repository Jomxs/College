#include <stdio.h>

int main() {
    int m[4][4] = {
        { 6, -1, 5, 3 },
        { 2, 9, 1, -4 },
        { 7, 2, -7, 8 },
        { -2, 6, 4, -3 }
    };

    int vd[4], i, j;
    int k = 0;

    printf("Aula Diagonal Matriz\n");
    printf("============================================\n\n");
for (i = 0; i < 4; i++) {

    for (j = 0; j < 4; j++) {

        if (i == j) {

            vd[k] = m[i][j];
            k++;

        }

}

 }
    for (i = 0; i < 4; i++) {
        printf("%3d\n ", vd[i]);
    }
}
