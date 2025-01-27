#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} * LInt;

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} * ABin;

ABin newABin(int r, ABin e, ABin d) {
    ABin new = (ABin)malloc(sizeof(struct ABin_nodo));

    if (new != NULL) {
        new->valor = r;
        new->esq = e;
        new->dir = d;
    }
    return new;
}

LInt newLInt(int v, LInt t) {
    LInt new = (LInt)malloc(sizeof(struct LInt_nodo));
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

void printList(LInt l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }

    puts("NULL");
}

// Questão 1

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubbleSort(int v[], int N) {
    for (int i = N; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (v[j - 1] > v[j])
                swap(v, j - 1, j);
        }
    }
}

int nesimo(int a[], int N, int i) {
    bubbleSort(a, N);
    return a[i - 1];
}

// Questão 2

void freeL(LInt l) {
    while (l) {
        LInt temp = l->prox;
        free(l);
        l = temp;
    }
}

LInt removeMaiores(LInt l, int x) {
    LInt *temp = &l;
    while (*temp && (*temp)->valor <= x)
        temp = &((*temp)->prox);

    freeL(*temp);
    *temp = NULL;
    return l;
}

// Questão 3

LInt caminho(ABin a, int x) {
    LInt list = NULL, *final = &list;
    while (a && a->valor != x) {
        *final = (LInt)malloc(sizeof(struct LInt_nodo));
        (*final)->valor = a->valor;
        final = &((*final)->prox);
        a = (a->valor > x) ? a->esq : a->dir;
    }
    if (a) {
        *final = (LInt)malloc(sizeof(struct LInt_nodo));
        (*final)->valor = a->valor; // podia ser x em vez de a->valor
        (*final)->prox = NULL;
    } else {
        freeL(list);
        list = NULL;
    }
    return list;
}

// Questão 4

void inc(char s[]) {
    int len = 0;
    for (; s[len]; len++)
        ;

    len--;
    int num = 0, i = 0;
    for (; s[i]; i++)
        num += (s[i] - '0') * pow(10, len--);

    num++;
    int end = i + 1;
    if (num < pow(10, i)) {
        end--;
        i--;
    }

    for (len = 0; len < end; len++, i--) {
        s[len] = (num / ((int)pow(10, i))) + '0';
        num %= (int)pow(10, i);
    }
    s[len] = '\0';
}

// Questão 5
// no idea what to do here
int sacos(int p[], int N, int C) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += p[i];
    if (sum <= C)
        return 1;

    return (sum / C) + (sum % C > 0);
}

int main() {
    int test1[] = {5, 1, 9, 0, 4, 7, 3, 2, 1};

    assert(nesimo(test1, 9, 1) == 0);
    assert(nesimo(test1, 9, 9) == 9);
    assert(nesimo(test1, 9, 5) == 3);
    assert(nesimo(test1, 9, 3) == 1);

    LInt list = listaNorm(10);
    // puts("Lista:");
    // printList(list);
    list = removeMaiores(list, 4);
    // printList(list);

    ABin arvore = newABin(7,
                          newABin(4, newABin(1, NULL, newABin(2, NULL, NULL)),
                                  newABin(6, NULL, NULL)),
                          newABin(9, newABin(8, NULL, NULL),
                                  newABin(13, NULL, newABin(15, NULL, NULL))));
    LInt list2 = caminho(arvore, 2);
    // puts("Lista 2:");
    // printList(list2);
    LInt list3 = caminho(arvore, 8);
    // puts("Lista 3:");
    // printList(list3);
    LInt list4 = caminho(arvore, 5);
    // puts("Lista 4:");
    // printList(list4);

    char numero1[10] = "19605", numero2[10] = "0", numero3[10] = "999",
         numero4[10] = "199";
    inc(numero1);
    // printf("Numero 1: %s\n", numero1);
    inc(numero2);
    // printf("Numero 2: %s\n", numero2);
    inc(numero3);
    // printf("Numero 3: %s\n", numero3);
    inc(numero4);
    // printf("Numero 4: %s\n", numero4);

    int saco1[] = {3, 6, 2, 1, 5, 7, 2, 4, 1}, saco2[] = {3, 3, 3, 3, 5, 5, 11};

    assert(sacos(saco1, 9, 10) == 4);
    assert(sacos(saco2, 7, 11) == 3);

    return 0;
}