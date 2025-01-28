#include "Questoes2.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* AUXILIARES */

LInt newLInt(int v, LInt t) {
    LInt new = (LInt)malloc(sizeof(struct lligada));
    assert(new != NULL);
    new->valor = v;
    new->prox = t;
    return new;
}

void printList(LInt l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }

    puts("NULL");
}

// IP indica se quer valores pares ou impares (resto 1 ou 0)
LInt listaPares(int max, int IP) {
    LInt list = NULL;
    for (int i = max; i > 0; i--)
        if (i % 2 == IP)
            list = newLInt(i, list);

    return list;
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

ABin newABin(int r, ABin e, ABin d) {
    ABin new = (ABin)malloc(sizeof(struct nodo));

    if (new != NULL) {
        new->valor = r;
        new->esq = e;
        new->dir = d;
    }
    return new;
}

// Function to print a binary tree using inorder traversal
void printBinaryTree(ABin root) {
    if (root != NULL) {
        printBinaryTree(root->esq);
        printf("%d ", root->valor);
        printBinaryTree(root->dir);
    }
}

void showABin(ABin a) {
    printBinaryTree(a);
    putchar('\n');
}

/* EXERCICIOS */

/* Listas Ligadas */

// Exercicio 1
int length(LInt l) {
    int total = 0;
    for (LInt temp = l; temp; total++, temp = temp->prox)
        ;
    return total;
}

// Exercicio 2
void freeL(LInt l) {
    LInt temp;
    while (l) {
        temp = l->prox;
        free(l);
        l = temp;
    }
}

// Exercicio 3
void imprimeL(LInt l) {
    for (LInt temp = l; temp; temp = temp->prox)
        printf("%d\n", temp->valor);
}

// Exercicio 4
LInt reverseL(LInt l) {
    LInt result = NULL;

    while (l) {
        LInt temp = l->prox;
        temp->prox = result;
        result = l;
        l = temp;
    }
    l = result;
    return l;
}

// Exercicio 5
/*
    Ao usar *l, é equivalente a criar um *e,
    assim não altero o valor de l, mas sim o apontador que aponta para l
*/
void insertOrd(LInt *l, int v) {
    while (*l && (*l)->valor < v)
        l = &((*l)->prox);

    LInt new = newLInt(v, *l);
    *l = new;
}

// Exercicio 6
int removeOneOrd(LInt *l, int v) {
    // percorro a lista até chegar ao fim ou encontrar v
    while (*l && (*l)->valor != v)
        l = &((*l)->prox);

    // se chegar ao fim, não posso remover, pois não existe
    if (*l == NULL)
        return 1;

    // caso exista, guardo o endereço do proximo,
    // e elimino o que tenho, e depois conecto a lista
    LInt temp = (*l)->prox;
    free(*l);
    *l = temp;

    return 0;
}

// Exercicio 7
void mergeLInt(LInt *r, LInt a, LInt b) {
    while (a && b) {
        if (a->valor < b->valor) {
            *r = a;
            a = a->prox;
        } else {
            *r = b;
            b = b->prox;
        }
        r = &((*r)->prox);
    }

    *r = (!a) ? b : a;
}

// Exercicio 8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    LInt *aux = &l;
    *mx = *Mx = NULL;

    while (*aux) {
        if ((*aux)->valor < x) {
            *mx = *aux;
            mx = &((*mx)->prox);
        } else {
            *Mx = *aux;
            Mx = &((*Mx)->prox);
        }
        aux = &((*aux)->prox);
    }
    *mx = *Mx = NULL;
}

// Exercicio 9
LInt parteAmeio(LInt *l) {
    LInt acc = *l, *aux = &acc;
    int comp = length(*l) / 2;

    while (comp > 0 && *l) {
        aux = &((*aux)->prox);
        comp--;
    }

    *l = *aux;
    *aux = NULL;

    return acc;
}

// Exercicio 10
int removeAll(LInt *l, int x) {
    int total = 0;

    while (*l) {
        if ((*l)->valor == x) {
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
            total++;
        } else
            l = &((*l)->prox);
    }
    return total;
}

// Exercicio 11
int removeDups(LInt *l) {
    int total = 0;
    while (*l) {
        total += removeAll(&((*l)->prox), (*l)->valor);
        l = &((*l)->prox);
    }
    return total;
}

// Exercicio 12
int removeMaiorL(LInt *l) {
    int maior = (*l)->valor;
    LInt temp = *l;
    while (*l) {
        if ((*l)->valor > maior)
            maior = (*l)->valor;
        l = &((*l)->prox);
    }

    LInt *aux = &temp;
    while (*aux) {
        if ((*aux)->valor == maior) {
            temp = (*aux)->prox;
            free(*aux);
            *aux = temp;
        } else
            aux = &((*aux)->prox);
    }
    return maior;
}

// Exercicio 13
void init(LInt *l) {
    if (*l != NULL) {
        while ((*l)->prox) {
            l = &((*l)->prox);
        }

        free(*l);
        *l = NULL;
    }
}

// Exercicio 14
void appendL(LInt *l, int x) {
    while (*l)
        l = &((*l)->prox);
    LInt new = newLInt(x, *l);
    *l = new;
}

// Exercicio 15
void concatL(LInt *a, LInt b) {
    if (*a == NULL)
        *a = b;
    else {
        while ((*a)->prox) {
            a = &((*a)->prox);
        }
        (*a)->prox = b;
    }
}

// Exercicio 16
LInt cloneL(LInt l) {
    LInt aux = NULL, *temp = &aux;

    while (l) {
        *temp = (LInt)malloc(sizeof(struct lligada));
        (*temp)->valor = l->valor;
        temp = &((*temp)->prox);
        l = l->prox;
    }
    *temp = NULL;
    return aux;
}

// Exercicio 17
LInt cloneRev(LInt l) {
    LInt aux = NULL, final = NULL;

    while (l) {
        aux = (LInt)malloc(sizeof(struct lligada));
        aux->valor = l->valor;
        aux->prox = final;
        final = aux;
        l = l->prox;
    }

    return final;
}

// Exercicio 18
int maximo(LInt l) {
    int maior = l->valor;
    l = l->prox;

    while (l) {
        if (l->valor > maior)
            maior = l->valor;
        l = l->prox;
    }
    return maior;
}

// Exercicio 19
int take(int n, LInt *l) {
    int cont = 0;

    while (*l && n > 0) {
        l = &((*l)->prox);
        cont++;
        n--;
    }

    freeL(*l);
    *l = NULL;

    return cont;
}

// Exercicio 20
int drop(int n, LInt *l) {
    int cont = 0;
    LInt aux = NULL;

    while (*l && n > 0) {
        aux = (*l)->prox;
        free(*l);
        *l = aux;
        cont++;
        n--;
    }

    return cont;
}

// Exercicio 21
LInt Nforward(LInt l, int N) {
    while (N > 0) {
        l = l->prox;
        N--;
    }
    return l;
}

// Exercicio 22
int listToArray(LInt l, int v[], int N) {
    int cont = 0;
    while (l && cont < N) {
        v[cont] = l->valor;
        cont++;
        l = l->prox;
    }
    return cont;
}

// Exercicio 23
LInt arrayToList(int v[], int N) {
    LInt final = NULL, *aux = &final;
    int i = 0;

    while (i < N) {
        *aux = (LInt)malloc(sizeof(struct lligada));
        (*aux)->valor = v[i++];
        aux = &((*aux)->prox);
    }

    return final;
}

// Exercicio 24
LInt somasAcL(LInt l) {
    int acc = 0;
    LInt final = NULL, *temp = &final;

    if (l) {
        acc = l->valor;
        l = l->prox;
        *temp = newLInt(acc, NULL);
        temp = &(*temp)->prox;

        while (l) {
            acc += l->valor;
            *temp = newLInt(acc, NULL);
            temp = &((*temp)->prox);
            l = l->prox;
        }
    }
    return final;
}

// Exercicio 25
void remreps(LInt l) {
    LInt *temp = &l;
    if (*temp == NULL)
        return;

    int reference = (*temp)->valor;
    temp = &((*temp)->prox);

    while (*temp) {
        if ((*temp)->valor == reference) {
            LInt aux = (*temp)->prox;
            free(*temp);
            *temp = aux;
        } else {
            reference = (*temp)->valor;
            temp = &((*temp)->prox);
        }
    }
}

// Exercicio 26
LInt rotateL(LInt l) {
    if (l && l->prox) {
        LInt *temp = &l;

        while (*temp)
            temp = &((*temp)->prox);

        // guardo a segunda posicao da lista
        LInt aux = l->prox;
        // a lista passa a ter um só elemento (a cabeça)
        l->prox = NULL;
        // coloco a cabeça no fim de l
        *temp = l;
        // coloco a segunda posição na cabeça da lista
        l = aux;
    }
    return l;
}

// Exercicio 27
LInt parte(LInt l) {
    LInt y = NULL, *ytemp = &y, *ltemp = &l;
    /*
        ltemp constroi a lista dos indices impares
        ytemp constroi a lista dos indices pares
    */

    if (l) {
        int i = 1;
        ltemp = &(*ltemp)->prox;
        l = l->prox;

        while (l) {
            if (i % 2 == 0) {
                *ltemp = l;
                ltemp = &((*ltemp)->prox);
            } else {
                *ytemp = l;
                ytemp = &((*ytemp)->prox);
            }
            l = l->prox;
            i++;
        }
        *ltemp = *ytemp = NULL;
    }
    return y;
}

/* Árvores Binárias */

// Exercicio 28
int altura(ABin a) {
    if (!a)
        return 0;
    int left = altura(a->esq);
    int right = altura(a->dir);

    return 1 + ((left > right) ? left : right);
}

// Exercicio 29
ABin cloneAB(ABin a) {
    ABin new = NULL;
    if (a) {
        new = (ABin)malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneAB(a->esq);
        new->dir = cloneAB(a->dir);
    }
    return new;
}

// Exercicio 30
void mirror(ABin *a) {
    if (*a) {
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

void inorderAUX(ABin a, LInt *l) {
    if (a) {
        inorderAUX(a->dir, l);
        LInt new = (LInt)malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
        inorderAUX(a->esq, l);
    }
}

// Exercicio 31
void inorder(ABin a, LInt *l) {
    *l = NULL;
    inorderAUX(a, l);
}

void preorderAUX(ABin a, LInt *l) {
    if (a) {
        preorderAUX(a->dir, l);
        preorderAUX(a->esq, l);
        LInt new = (LInt)malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
    }
}

// Exercicio 32
void preorder(ABin a, LInt *l) {
    *l = NULL;
    preorderAUX(a, l);
}

void posorderAUX(ABin a, LInt *l) {
    if (a) {
        LInt new = (LInt)malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
        posorderAUX(a->dir, l);
        posorderAUX(a->esq, l);
    }
}

// Exercicio 33
void posorder(ABin a, LInt *l) {
    *l = NULL;
    posorderAUX(a, l);
}

// Exercicio 34
int depth(ABin a, int x) {
    if (!a)
        return -1;
    if (a->valor == x)
        return 1;
    int left = depth(a->esq, x), right = depth(a->dir, x);
    if (left == -1 && right == -1)
        return -1;
    if (left == -1)
        return 1 + right;
    if (right == -1)
        return 1 + left;
    else
        return 1 + (left > right) ? right : left;
}

// Exercicio 35
int freeAB(ABin a) {
    if (a) {
        ABin left = a->esq, right = a->dir;
        free(a);
        return 1 + freeAB(left) + freeAB(right);
    }
    return 0;
}

// Exercicio 36
int pruneAB(ABin *a, int l) {
    if (l == 0) {
        int count = freeAB(*a);
        *a = NULL;
        return count;
    }
    if (l == 1) {
        ABin left = (*a)->esq, right = (*a)->dir;
        (*a)->esq = (*a)->dir = NULL;
        return freeAB(left) + freeAB(right);
    }
    return pruneAB((*a)->esq, l - 1) + pruneAB((*a)->dir, l - 1);
}

// Exercicio 37
int iguaisAB(ABin a, ABin b) {
    if (!a && !b)
        return 1;
    if (!a || !b)
        return 0;
    if (a->valor == a->valor)
        return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    return 0;
}

void nivelLAUX(ABin a, LInt *l, int n) {
    if (a && n > 0) {
        if (n == 1) {
            LInt new = newLInt(a->valor, *l);
            *l = new;
        } else {
            nivelLAUX(a->dir, l, n - 1);
            nivelLAUX(a->esq, l, n - 1);
        }
    }
}

// Exercicio 38
LInt nivelL(ABin a, int n) {
    LInt l = NULL;
    if (n > 0)
        nivelLAUX(a, &l, n);
    return l;
}

// Exercicio 39
int nivelV(ABin a, int n, int v[]) {
    if (!a || n < 1)
        return 0;
    if (n == 1) {
        *v = a->valor;
        return 1;
    }
    int left = nivelV(a->esq, n - 1, v);
    return left + nivelV(a->dir, n - 1, v + left);
}

// Exercicio 40
int dumpAbin(ABin a, int v[], int N) {
    if (!a || N < 1)
        return 0;
    int left = dumpAbin(a->esq, v, N);
    if (left < N) {
        v[left] = a->valor;
        return 1 + left + dumpAbin(a->dir, v + left + 1, N - left - 1);
    }
    return N;
}

// Exercicio 41
ABin somasAcA(ABin a) {
    if (!a)
        return NULL;
    if (!a->dir && !a->esq) {
        ABin new = newABin(a->valor, NULL, NULL);
        return new;
    }
    ABin new = (ABin)malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    if (new->esq &&new->dir)
        new->valor = a->valor + new->esq->valor + new->dir->valor;
    else if (new->esq)
        new->valor = a->valor + new->esq->valor;
    else if (new->dir)
        new->valor = a->valor + new->dir->valor;
    return new;
}

// Exercicio 42
int contafolhas(ABin a) {
    if (!a)
        return 0;
    if (!a->esq && !a->dir)
        return 1;
    return contafolhas(a->esq) + contafolhas(a->dir);
}

// Exercicio 43
ABin cloneMirror(ABin a) {
    ABin new = NULL;
    if (a) {
        new = (ABin)malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneMirror(a->dir);
        new->dir = cloneMirror(a->esq);
    }
    return new;
}

// Exercicio 44
int addOrd(ABin *a, int x) {
    ABin anterior = NULL, temp = *a;
    while (temp && temp->valor != x) {
        anterior = temp;
        temp = (temp->valor < x) ? temp->dir : temp->esq;
    }

    if (temp)
        return 1;

    ABin new = (ABin)malloc(sizeof(struct nodo));
    new->valor = x;
    new->dir = new->esq = NULL;
    if (anterior->valor > x)
        anterior->esq = new;
    else
        anterior->dir = new;

    return 0;
}

// Exercicio 45
int lookupAB(ABin a, int x) {
    while (a && a->valor != x)
        a = (a->valor < x) ? a->dir : a->esq;

    return a ? 1 : 0;
}

// Exercicio 46
int depthOrd(ABin a, int x) {
    int count = 1;
    while (a && a->valor != x) {
        a = (a->valor < x) ? a->dir : a->esq;
        count++;
    }

    return a ? count : -1;
}

// Exercicio 47
int maiorAB(ABin a) {
    while (a->dir)
        a = a->dir;

    return a->valor;
}

// Exercicio 48
void removeMaiorAB(ABin *a) {
    if (*a) {
        while ((*a)->dir)
            a = &((*a)->dir);

        ABin temp = (*a)->esq;
        free(*a);
        *a = temp;
    }
}

// Exercicio 49
int quantosMaiores(ABin a, int x) {
    if (!a)
        return 0;
    if (a->valor <= x)
        return quantosMaiores(a->dir, x);
    else
        return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->esq, x);
}

void listToBTreeAUX(LInt l, ABin *a) {
    if (l) {
        LInt e = parteAmeio(&l);

        *a = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = (*a)->dir = NULL;

        LInt temp = l->prox;
        free(l);
        l = temp;

        LTBTAux(e, &(*a)->esq);
        LTBTAux(l, &(*a)->dir);
    }
}

// Exercicio 50
void listToBTree(LInt l, ABin *a) {
    *a = NULL;
    listToBTreeAUX(l, a);
}

int menores(ABin a, int x) {
    if (!a)
        return 1;
    return (x < a->valor) && menores(a->esq, x) && menores(a->dir, x);
}

int maiores(ABin a, int x) {
    if (!a)
        return 1;
    return (x > a->valor) && maiores(a->esq, x) && maiores(a->dir, x);
}

// Exercicio 51
int deProcura(ABin a) {
    if (!a)
        return 1;
    return maiores(a->esq, a->valor) && menores(a->dir, a->valor) &&
           deProcura(a->dir) && deProcura(a->esq);
}
