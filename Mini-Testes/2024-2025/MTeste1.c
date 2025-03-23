#include <stdio.h>
#include <math.h>

/*
 * compile:
 *      gcc MTeste1.c -lm
 * execute:
 *      ./a.out
 */


void question1(void) {
    long x, y;
    int v;
    char d;

    x = 28;
    y = 2;
    d = 'w';
    v = 1;

    for (int t = 1; t < 10000; t++) {
        if (t % 3 == 0 && t % 5 == 0) {
            if (d == 'n')
                d = 'e';
            else if (d == 'e')
                d = 's';
            else if (d == 's')
                d = 'w';
            else
                d = 'n';
        } else if (t % 3 == 0)
            v += 2;
        else if (t % 5 == 0)
            v -= 1;
        else {
            if (d == 'n')
                y += v;
            else if (d == 'e')
                x += v;
            else if (d == 's')
                y -= v;
            else
                x -= v;
        }
    }

    printf("question 1:\n");
    printf("x: %ld\ny: %ld\n", x, y);
}

void question2(void) {
    long x = 28, y = 2;
    int v = 1;
    char d = 'w';
    long max[4] = {0,0,0,0};
    long curr[4] = {0,0,0,0};

    for (int t = 1; t < 10000; t++) {
        if (t % 3 == 0 && t % 5 == 0) {
            if (d == 'n')
                d = 'e';
            else if (d == 'e')
                d = 's';
            else if (d == 's')
                d = 'w';
            else
                d = 'n';
        } else if (t % 3 == 0)
            v += 2;
        else if (t % 5 == 0)
            v -= 1;
        else {
            if (d == 'n') {
                y += v;
                curr[0] += v;
                
                max[1] = fmax(max[1], curr[1]);
                curr[1] = 0;
                max[2] = fmax(max[2], curr[2]);
                curr[2] = 0;
                max[3] = fmax(max[3], curr[3]);
                curr[3] = 0;

            } else if (d == 'e') {
                x += v;
                curr[1] += v;

                max[0] = fmax(max[0], curr[0]);
                curr[0] = 0;
                max[2] = fmax(max[2], curr[2]);
                curr[2] = 0;
                max[3] = fmax(max[3], curr[3]);
                curr[3] = 0;

            } else if (d == 's') {
                y -= v;
                curr[2] += v;

                max[0] = fmax(max[0], curr[0]);
                curr[0] = 0;
                max[1] = fmax(max[1], curr[1]);
                curr[1] = 0;
                max[3] = fmax(max[3], curr[3]);
                curr[3] = 0;

            } else {
                x -= v;
                curr[3] += v;

                max[1] = fmax(max[1], curr[1]);
                curr[1] = 0;
                max[2] = fmax(max[2], curr[2]);
                curr[2] = 0;
                max[0] = fmax(max[0], curr[0]);
                curr[0] = 0;

            }
        }
    }

    printf("\nquestion 2:\n");
    printf("norte: %ld\n", max[0]);
    printf("este: %ld\n", max[1]);
    printf("sul: %ld\n", max[2]);
    printf("oeste: %ld\n", max[3]);
}


int main(void) {

    question1();

    question2();

    return 0;
}


