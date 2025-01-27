#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programas Iterativos */

void square(int dim);

void chessBoard(int dim);

void sideTriangle(int dim);

void upTriangle(int dim);

int circle(int raio);

int main() {
    srand(time(0));

    // int size = 0;
    // scanf("%d", &size);

    puts("Square:");
    square(rand() % 20);

    puts("Chess Board:");
    chessBoard(rand() % 20);

    puts("Side Triangle:");
    sideTriangle(rand() % 20);

    puts("Up Triangle:");
    upTriangle(rand() % 20);

    puts("Circle:");
    circle(rand() % 20);

    return 0;
}

/* Functions */

void square(int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            putchar('#');
        putchar('\n');
    }
    putchar('\n');
}

void chessBoard(int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i % 2 == 0)
                (j % 2 == 0) ? putchar('#') : putchar('_');
            else
                (j % 2 == 0) ? putchar('_') : putchar('#');
        }
        putchar('\n');
    }
    putchar('\n');
}

void sideTriangle(int dim) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j <= i; j++)
            putchar('#');
        putchar('\n');
    }
    for (i = dim - 1; i > 0; i--) {
        for (j = i; j > 0; j--)
            putchar('#');
        putchar('\n');
    }
    putchar('\n');
}

void upTriangle(int dim) {
    for (int i = 1; i <= dim; i++) {
        for (int k = dim - i; k > 0; k--)
            putchar(' ');
        for (int j = 0; j < (i * 2) - 1; j++)
            putchar('#');
        putchar('\n');
    }
    putchar('\n');
}

int circle(int raio) {
    int total = 0;
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (raio * raio >= i * i + j * j) {
                putchar('#');
                total++;
            } else
                putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
    return total;
}
