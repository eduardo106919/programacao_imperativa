#ifndef __STORAGE_H__
#define __STORAGE_H__

#define COUNT 10

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d);
ABin RandArvFromArray (int v[], int N);
void dumpABin (ABin a);
void freeABin (ABin a);

int altura (ABin a);
int nFolhas (ABin a);
ABin maisEsquerda (ABin a);
void imprimeNivel (ABin a, int l);
int procuraE (ABin a, int x);

struct nodo *procura (ABin a, int x);
int nivel (ABin a, int x);
void imprimeAte (ABin a, int x);

#endif