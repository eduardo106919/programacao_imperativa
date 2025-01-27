#include <assert.h>
#include <stdio.h>


float multInt1(int n, float m) {
    float r = 0;
    for (int i = 0; i < n; i++)
        r += m;
    return r;
}

float multInt2(int n, float m) {
    float r = 0;
    while (n > 0) {
        if (n % 2 == 1)
            r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

float multInt3(int n, float m, int *count) {
    float r = 0;
    while (n > 0) {
        if (n % 2 == 1)
            r += m;
        n /= 2;
        m *= 2;
        (*count)++;
    }
    return r;
}

int mdc1(int a, int b) {
    int menor = (a < b) ? a : b, maior = (a > b) ? a : b, mdc = menor;
    while (menor > 0) {
        if (maior % mdc == 0 && menor % mdc == 0)
            return mdc;
        mdc--;
    }
    return 1;
}

int mdc2(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int mdc3(int a, int b, int *count) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
        (*count)++;
    }
    return a;
}

int mdc4(int a, int b, int *count) {
    while (a != 0 && b != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
        (*count)++;
    }
    return (a > b) ? a : b;
}
int fib(int n) { return (n < 2) ? 1 : fib(n - 1) + fib(n - 2); }

int fastfib(int n) {
    if (n < 2)
        return 1;

    int ant1 = 1, ant2 = 1, fib = ant1 + ant2;
    while (n > 2) {
        ant1 = ant2;
        ant2 = fib;
        fib = ant1 + ant2;
        n--;
    }
    return fib;
}

int main() {
    int a, b, r1, r2, r3, r4, c1 = 0, c2 = 0;
    float f, f1, f2, f3;

    printf("Introduza dois números para input das funções de multiplicação: ");
    assert(scanf("%d %f", &a, &f) == 2);
    f1 = multInt1(a, f);
    f2 = multInt2(a, f);
    f3 = multInt3(a, f, &c1);
    printf("Resultados das multiplicações: %f, %f, %f (%d)\n", f1, f2, f3, c1);

    printf("Introduza dois números para input das funções de múltiplo comum: ");
    assert(scanf("%d %d", &a, &b) == 2);

    r1 = mdc1(a, b);
    r2 = mdc2(a, b);
    r3 = mdc3(a, b, &c1);
    r4 = mdc4(a, b, &c2);
    printf("Resultados do mdc: %d, %d, %d (%d), %d (%d)\n", r1, r2, r3, c1, r4,
           c2);

    printf("Introduza um número para calcular o fib: ");
    assert(scanf("%d", &a) == 1);
    printf("FastFib (%d) = %d \n", a, fastfib(a));
    printf("Fib (%d) = %d \n", a, fib(a));

    return 0;
}