#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções auxiliares

ABin newABin(int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a != NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

ABin RandArvFromArray(int v[], int N) {
    ABin a = NULL;
    int m;
    if (N > 0) {
        m = rand() % N;
        a = newABin(v[m], RandArvFromArray(v, m),
                    RandArvFromArray(v + m + 1, N - m - 1));
    }
    return a;
}

void freeABin(ABin a) {
    if (a) {
        ABin e_temp = a->esq;
        ABin d_temp = a->dir;
        free(a);
        freeABin(e_temp);
        freeABin(d_temp);
    }
}

void breath_first_traversal(ABin root, ABin storage[], int size) {
    int start = 0, end = 0;
    // enqueue
    storage[end++] = root;

    while (start < end && end < size) {
        // dequeue
        root = storage[start++];
        // NULL is an empty node
        if (root != NULL) {
            // enqueue
            storage[end++] = root->esq;
            storage[end++] = root->dir;
        } else if (end + 2 < size)
            end += 2;
    }
}

void showABin(ABin btree) {
    int total = (int) pow(2, altura(btree)) - 1;

    ABin storage[total];
    int iterate = 0;
    for (; iterate < total; iterate++)
        storage[iterate] = NULL;

    breath_first_traversal(btree, storage, total);

    int level = 1, count = 0, space = 0;
    for (iterate = 0; iterate < total; iterate++) {
        if (count == level) {
            printf("\n");
            level *= 2;
            count = 0;
            space = 0;
        }
        if (space == 2) {
            printf(" ");
            space = 0;
        }
        space++;
        count++;

        if (storage[iterate] != NULL)
            printf("%d ", storage[iterate]->valor);
        else
            printf("X ");

    }

    printf("\n");
}

// Exercícios

int altura(ABin a) {
    if (!a)
        return 0;
    int left = altura(a->esq);
    int right = altura(a->dir);

    return 1 + (left > right ? left : right);
}

int nFolhas(ABin a) {
    if (!a)
        return 0;
    if (a->esq == NULL && a->dir == NULL)
        return 1;

    return nFolhas(a->dir) + nFolhas(a->esq);
}

ABin maisEsquerda(ABin a) {
    if (!a)
        return NULL;

    while (a->esq)
        a = a->esq;
    return a;
}

void imprimeNivel(ABin a, int l) {
    if (a) {
        if (l == 0)
            printf("%d\n", a->valor);
        else {
            imprimeNivel(a->esq, l - 1);
            imprimeNivel(a->dir, l - 1);
        }
    }
}

int procuraE(ABin a, int x) {
    if (!a)
        return 0;
    if (a->valor == x)
        return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

struct nodo *procura(ABin a, int x) {
    while (a) {
        if (a->valor == x)
            return a;
        if (a->valor < x)
            a = a->dir;
        else
            a = a->esq;
    }
    return NULL;
}

int nivel(ABin a, int x) {
    int count = 0;
    while (a) {
        if (a->valor == x)
            return count;
        if (a->valor < x)
            a = a->dir;
        else
            a = a->esq;
        count++;
    }
    return (-1);
}

void imprimeAte(ABin a, int x) {
    if (a) {
        imprimeAte(a->esq, x);
        if (a->valor < x) {
            printf("%d\n", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}
