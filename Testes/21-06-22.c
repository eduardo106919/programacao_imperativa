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

// Questão 1
int pesquisa(int a[], int N, int x) {
    int start = 0, end = N - 1, middle;
    while (start <= end) {
        middle = (start + end) / 2;
        if (a[middle] == x)
            return middle;
        if (a[middle] > x)
            end = middle - 1;
        else
            start = middle + 1;
    }
    return -1;
}

// Questão 2

void roda(LInt *l) {
    if (*l) {
        LInt cabeca = *l, anterior = NULL;
        while ((*l)->prox) {
            anterior = *l;
            l = &((*l)->prox);
        }
        anterior->prox = NULL;
        (*l)->prox = cabeca;
    }
}

// Questão 3

int apaga(ABin a, int n) {
    if (!a)
        return 0;
    if (!a->esq && !a->dir) {
        free(a);
        return 1;
    }
    int left = apaga(a->esq, n);
    if (left == n)
        return n;
    left += apaga(a->dir, n - left);
    if (left < n) {
        free(a);
        return 1 + left;
    }
    return left;
}

// Questão 4

void checksum(char s[]) {
    int len = 0;
    for (; s[len]; len++)
        ;
    int store[len];
    for (int i = 0; i < len; i++)
        store[i] = s[i] - '0';
    int par = 1, sum = 0;
    for (int j = len - 1; j >= 0; j--) {
        if (!par) {
            sum += store[j];
            par = 1;
        } else {
            int temp = 2 * store[j];
            sum += (temp >= 10) ? 1 + (temp % 10) : temp;
            par = 0;
        }
    }
    int controle = sum % 10;
    s[len] = controle + '0';
    s[len + 1] = '\0';
}

// Questão 5

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// ordena do maior para o menor
void ordenaRevInd(int v[], int N, int ind[]) {
    for (int i = N; i > 0; i--) {
        for (int j = 1; j < i; j++)
            if (v[j - 1] < v[j])
                swap(ind, j - 1, j);
    }
}

int escolhe(int N, int valor[], int peso[], int C, int quant[]) {
    int ind[N];
    for (int i = 0; i < N; i++)
        ind[i] = i;
    ordenaRevInd(valor, N, ind);
    int preco = 0, totalP = 0;
    for (int i = 0; i < N; i++) {
        quant[ind[i]] = C / peso[ind[i]];
        C %= peso[ind[i]];
        preco += quant[ind[i]] * valor[ind[i]];
    }
    return preco;
}

int main() {

    // LInt list1 = listaNorm(10);
    // puts("Lista 1:");
    // printList(list1);
    // roda(&list1);
    // printList(list1);

    ABin arvore = newABin(7,
                          newABin(4, newABin(1, NULL, newABin(2, NULL, NULL)),
                                  newABin(6, NULL, NULL)),
                          newABin(9, newABin(8, NULL, NULL),
                                  newABin(13, NULL, newABin(15, NULL, NULL))));

    showABin(arvore);
    apaga(arvore, 3);
    showABin(arvore);

    char test1[10] = "9871", test2[10] = "807941";
    checksum(test1);
    // printf("teste 1: %s\n", test1);
    checksum(test2);
    // printf("teste 2: %s\n", test2);

    return 0;
}