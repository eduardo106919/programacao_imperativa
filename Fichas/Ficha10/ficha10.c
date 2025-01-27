#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

// Function to print the binary tree in-order
void dumpABin(ABin root) {
    if (root != NULL) {
        dumpABin(root->esq);
        printf("%d ", root->valor);
        dumpABin(root->dir);
    }
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

// Questão 1
ABin removeMenor(ABin *a) {
    if (*a == NULL)
        return NULL;

    ABin temp = *a, anterior = NULL;
    while (temp->esq) {
        anterior = temp;
        temp = temp->esq;
    }

    // se a raiz for o mais nodo mais pequeno
    if (temp == *a)
        *a = (*a)->dir;
    else
        anterior->esq = temp->dir;

    return temp;
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
}

int removeElem(ABin *a, int x) {
    if (*a != NULL) {
        ABin temp = *a, anterior = NULL;
        while (temp && temp->valor != x) {
            anterior = temp;
            if (temp->valor < x)
                temp = temp->dir;
            else
                temp = temp->esq;
        }
        // se x for a raiz da árvore
        if (temp == *a)
            removeRaiz(a);
        else {
            removeRaiz(&temp);
            if (anterior->valor > x)
                anterior->esq = temp;
            else
                anterior->dir = temp;
        }
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
    // o menor passa a ser a raiz da árvore
    promoveMenor(a);
    ABin right = (*a)->dir;
    ABin menor = *a;
    *a = right;
    return menor;
}

// Questão 3
// TODO
int constroiEspinhaAux(ABin *a, ABin *ult) { return (-1); }
int constroiEspinha(ABin *a) {
    ABin ult;

    return (constroiEspinhaAux(a, &ult));
}

ABin equilibraEspinha(ABin *a, int n) { return NULL; }

void equilibra(ABin *a) {}