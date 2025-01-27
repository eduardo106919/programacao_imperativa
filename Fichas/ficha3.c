#include <assert.h>
#include <stdio.h>


void showArray(int v[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

void swapM(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int v[], int i, int j) { swapM(&(v[i]), &(v[j])); }

int soma(int v[], int N) {
    int total = 0;
    for (int i = 0; i < N; i++)
        total += v[i];
    return total;
}

// usando swapM
void inverteArray1(int v[], int N) {
    int end = N - 1;
    for (int i = 0; i < end; i++, end--)
        swapM(&(v[i]), &(v[end]));
}

// usando swap
void inverteArray2(int v[], int N) {
    int end = N - 1;
    for (int i = 0; i < end; i++, end--)
        swap(v, i, end);
}

int maximum(int v[], int N, int *m) {
    if (N <= 0)
        return 1;

    *m = v[0];
    for (int i = 1; i < N; i++)
        if (v[i] > *m)
            *m = v[i];
    return 0;
}

void quadrados(int q[], int N) {
    q[0] = 0;
    for (int i = 1; i < N; i++)
        q[i] = q[i - 1] + 2 * i - 1;
}

void pascal(int v[], int N) {
    if (N == 1)
        v[0] = 1;
    else {
        int ant[N - 1];
        pascal(ant, N - 1);
        v[0] = 1;
        v[N - 1] = 1;

        for (int i = 1; i < N - 1; i++)
            v[i] = ant[i] + ant[i - 1];
    }
}

void show_pascal(int v[], int N) {
    if (N == 1) {
        v[0] = 1;
        putchar('1');
    } else {
        int ant[N - 1];
        pascal(ant, N - 1);
        v[0] = 1;
        v[N - 1] = 1;

        for (int i = 1; i < N - 1; i++)
            v[i] = ant[i] + ant[i - 1];

        showArray(v, N);
    }
}

int main() {
    int x = 3, y = 5;
    swapM(&x, &y);
    assert(x == 5 && y == 3);

    int v[] = {4, 8, 1, 9, 5}, v2[] = {8, 9, 0, 1, 4, 5, 3, 1},
        v3[] = {6, 1, 3};
    swap(v, 1, 4);
    showArray(v, 5);

    puts("Soma:");
    assert(soma(v, 5) == 27);
    assert(soma(v2, 8) == 31);
    assert(soma(v3, 3) == 10);

    puts("Inverte:");
    inverteArray1(v2, 8);
    showArray(v2, 8);
    inverteArray1(v3, 3);
    showArray(v3, 3);

    inverteArray2(v2, 8);
    showArray(v2, 8);
    inverteArray2(v3, 3);
    showArray(v3, 3);

    int m;
    assert(maximum(v3, 3, &m) == 0);
    assert(m == 6);
    assert(maximum(v, 5, &m) == 0);
    assert(m == 9);

    int vet[30];
    puts("Quadrados:");
    quadrados(vet, 9);
    showArray(vet, 9);

    int array[10];
    puts("Pascal:");
    pascal(array, 10);
    // showArray(array, 10);

    show_pascal(array, 10);

    return 0;
}

/*
Exercicio 1
a)
    int x[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x + 3;
    for(i = 0; i < 5; i++){
        printf("%d %d %d\n", x[i], *y, *z);
        y = y + 1;  z = z + 2;
    }
    output:
    1 1 4
    2 2 6
    3 3 8
    4 4 10
    5 5 12

b)
    int i, j, *a, *b;
    i = 3, j = 5;
    a = b = 42;         dá erro (nao posso fazer isto)
    a = &i; b = &j;
    i++;                i -> 4
    j = i + *b;         j -> 4 + 5 = 9
    b = a;              b passa a ter o endereço guardado em a
    j = j + *b;         j -> 9 + i = 9 + 4 = 13
    printf("%d\n", j);

    output: 13
*/