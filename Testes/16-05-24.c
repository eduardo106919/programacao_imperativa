#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} * LInt;

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} * ABin;

LInt newLInt(int v, LInt t) {
    LInt new = (LInt)malloc(sizeof(struct lint_nodo));
    assert(new != NULL);
    new->valor = v;
    new->prox = t;
    return new;
}

LInt listaNorm(int max) {
    LInt list = NULL;
    for (int i = max; i > 0; i--)
        list = newLInt(i, list);

    return list;
}

LInt listaRandom(int max) {
    LInt list = NULL;
    for (int i = 0; i < max; i++)
        list = newLInt(rand() % max + 1, list);

    return list;
}

void show_array(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

void show_list(LInt l) {
    while (l) {
        printf("%d", l->valor);
        l = l->prox;
        printf(" -> ");
    }
    puts("NULL");
}

int fizz(int n) { return ((n + 4) % 43) == 0; }

int buzz(int n) { return ((n - 5) % 47) == 0; }

int fizzbuzz(int n) {
    int first = 0, end = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (fizz(i) && buzz(i)) {
            printf("FizzBuzz\n");
            if (!first && !end)
                first = 1;

        } else if (fizz(i))
            printf("Fizz\n");
        else if (buzz(i)) {
            printf("Buzz\n");
            if (first && !end) {
                first = 0;
                end = 1;
            }
        } else {
            printf("%d\n", i);
            if (first && !end)
                count++;
        }
    }
    return (!first && end) ? count : -1;
}

// nao funciona direito para valores maiores que N
void rodaEsq(int a[], int N, int r) {
    int aux[N];
    int i;
    for (i = 0; i < N; i++) {
        int index = (i - r < 0) ? N - r + i : i - r;
        aux[index] = a[i];
    }

    for (i = 0; i < N; i++)
        a[i] = aux[i];
}

int delete (int n, LInt *l) {
    // se n == 0 e n == 1 elimina o primero elemento, ambos
    // caso não seja desta forma basta: n > 0
    while (*l && n > 1) {
        l = &((*l)->prox);
        n--;
    }

    if (*l) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        return 0;
    }

    // código de erro
    return 1;
}

int maxCresc(LInt l) {
    if (l == NULL)
        return 0;
    int ref = l->valor, freq = 1, freqMax = 1;
    l = l->prox;
    while (l) {
        if (l->valor > ref)
            freq++;
        else {
            if (freq > freqMax)
                freqMax = freq;
            freq = 1;
        }
        ref = l->valor;
        l = l->prox;
    }
    return (freq > freqMax) ? freq : freqMax;
}

ABin folhaEsq(ABin a) {
    while (a) {
        if (!a->esq && !a->dir)
            return a;
        a = !a->esq ? a->dir : a->esq;
    }
    return NULL;
}

int parentesisOk(char exp[]) {
    int len = strlen(exp);
    int aux[len];
    for (int i = 0; i < len; i++)
        aux[i] = 0;

    int j = 0;
    for (int i = 0; exp[i]; i++) {
        switch (exp[i]) {
            case '(':
                aux[j++] = 1;
                break;
            case ')':
                aux[j++] = -1;
                break;
            case '[':
                aux[j++] = 2;
                break;
            case ']':
                aux[j++] = -2;
                break;
            case '{':
                aux[j++] = 3;
                break;
            case '}':
                aux[j++] = -3;
                break;
            default:
                break;
        }
    }
    j--;
    for (int i = 0; i < j; i++, j--) {
        if (aux[i] != -aux[j])
            return 0;
    }
    return 1;
}

int main() {
    srand(time(0));
    // assert(fizzbuzz(100) == -1);
    // assert(fizzbuzz(20) == -1);
    // int n = fizzbuzz(2000);
    // printf("val: %d\n", n); // esta correto, penso eu

    int test1[] = {1, 2, 3, 4, 5, 6}, test2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        test3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // rodaEsq(test1, 6, 2);
    // show_array(test1, 6);
    // rodaEsq(test2, 10, 9);
    // show_array(test2, 10);
    // rodaEsq(test3, 15, 15);
    // show_array(test3, 15);

    LInt listA = listaNorm(10);

    assert(delete (3, &listA) == 0);
    // show_list(listA);
    assert(delete (0, &listA) == 0);
    // show_list(listA);
    assert(delete (10, &listA) == 1);
    // show_list(listA);

    LInt listaB = listaRandom(10);
    // show_list(listaB);
    // printf("maxCresc: %d\n", maxCresc(listaB));

    char str1[] = "3 + [2 - (3 - x)] + 4", str2[] = "3 + [2 - (3 - x]) + 4";
    assert(parentesisOk(str1) == 1);
    assert(parentesisOk(str2) == 0);

    return 0;
}