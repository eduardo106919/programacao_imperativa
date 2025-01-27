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

int altura(ABin a) {
    if (!a)
        return 0;
    int left = altura(a->esq);
    int right = altura(a->dir);

    return 1 + (left > right ? left : right);
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

void rodaEsquerda(ABin *a) {
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita(ABin *a) {
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

// Exercicios

// Questão 1
ABin removeMenor(ABin *a) {
    if (*a == NULL)
        return NULL;

    while ((*a)->esq != NULL)
        a = &((*a)->esq);

    ABin result = *a;
    *a = (*a)->dir;

    return result;
}

void removeRaiz(ABin *a) {
    ABin subst = NULL;
    if ((*a)->dir == NULL)
        subst = (*a)->esq;
    else {
        subst = removeMenor(&((*a)->dir));
        subst->esq = (*a)->esq;
        subst->dir = (*a)->dir;
    }
    free(*a);
    *a = subst;
}

int removeElem(ABin *a, int x) {
    if (*a != NULL) {
        ABin temp = *a, anterior = NULL;
        while (*a && (*a)->valor != x) {
            if ((*a)->valor < x)
                a = &((*a)->dir);
            else
                a = &((*a)->esq);
        }
        // se x for encontrado
        if (*a != NULL)
            removeRaiz(a);
    }
    return 1;
}

// Questão 2

void promoveMenor(ABin *a) {
    if (*a && (*a)->esq) {
        promoveMenor(&((*a)->esq));
        rodaDireita(a);
    }
}

void promoveMaior(ABin *a) {
    if (*a && (*a)->dir) {
        promoveMaior(&((*a)->dir));
        rodaEsquerda(a);
    }
}

ABin removeMenorAlt(ABin *a) {
    if (*a == NULL)
        return NULL;

    promoveMenor(a);
    ABin right = (*a)->dir;
    ABin menor = *a;
    *a = right;
    return menor;
}

// Questão 3
int constroiEspinhaAux(ABin *a, ABin *ult) { return (-1); }

int constroiEspinha(ABin *a) {
    int count = 0;
    while (*a != NULL) {
        while ((*a)->esq != NULL)
            rodaDireita(a);
        
        a = &((*a)->dir);
        count++;
    }

    return count;
}

ABin equilibraEspinha(ABin *a, int n) {
    if (n < 3 || *a == NULL)
        return NULL;

    int half = n / 2;
    if ((*a)->esq == NULL) {
        while (half > 0 && (*a)->dir) {
            rodaEsquerda(a);
            half--;
        }

        half = n / 2;
        equilibraEspinha(&((*a)->esq), half);
        equilibraEspinha(&((*a)->dir), n - half - 1);
    } else if ((*a)->dir == NULL) {
        while (half > 0 && (*a)->esq) {
            rodaDireita(a);
            half--;
        }

        half = n / 2;
        equilibraEspinha(&((*a)->esq), n - half - 1);
        equilibraEspinha(&((*a)->dir), half);
    }
}

void equilibra(ABin *a) {
    int n = constroiEspinha(a);
    equilibraEspinha(a, n);
}