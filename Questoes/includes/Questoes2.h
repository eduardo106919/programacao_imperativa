#ifndef __QUESTOES2_H__
#define __QUESTOES2_H__


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

/* AUXILIARES */

LInt newLInt (int v, LInt t);
void printList(LInt l);
LInt listaPares (int max, int IP);
LInt listaNorm (int max);
LInt listaRandom (int max);
ABin newABin (int r, ABin e, ABin d);
void printBinaryTree(ABin root);
void showABin(ABin a);

/* EXERCICIOS */

int length (LInt l);
void freeL (LInt l);
void imprimeL (LInt l);
LInt reverseL (LInt l);
void insertOrd (LInt * l, int v);
int removeOneOrd (LInt * l, int v);
void mergeLInt (LInt *r, LInt a, LInt b);
void splitQS (LInt l, int x, LInt *mx, LInt *Mx);
LInt parteAmeio (LInt *l);
int removeAll (LInt * l, int x);
int removeDups (LInt * l);
int removeMaiorL (LInt * l);
void init (LInt * l);
void appendL (LInt *, int);
void concatL (LInt *a, LInt b);
LInt cloneL (LInt l);
LInt cloneRev (LInt l);
int maximo (LInt l);
int take (int n, LInt *l);
int drop (int n, LInt *l);
LInt Nforward (LInt l, int N);
int listToArray (LInt l, int v[], int N);
LInt arrayToList (int v[], int N);
LInt somasAcL (LInt l);
void remreps (LInt l);
LInt rotateL (LInt l);
LInt parte (LInt l);

int altura(ABin a);
ABin cloneAB(ABin a);
void mirror(ABin *a);
void inorderAUX(ABin a, LInt *l);       // Auxiliar
void inorder(ABin a, LInt *l);
void preorderAUX(ABin a, LInt *l);      // Auxiliar
void preorder(ABin a, LInt *l);
void posorderAUX(ABin a, LInt *l);      // Auxiliar
void posorder(ABin a, LInt *l);
int depth(ABin a, int x);
int freeAB(ABin a);
int pruneAB(ABin *a, int l);
int iguaisAB(ABin a, ABin b);
LInt nivelL(ABin a, int n);
int nivelV(ABin a, int n, int v[]);
int dumpAbin(ABin a, int v[], int N);
ABin somasAcA(ABin a);
int contafolhas(ABin a);
ABin cloneMirror(ABin a);
int addOrd(ABin *a, int x);
int lookupAB(ABin a, int x);
int depthOrd(ABin a, int x);
int maiorAB(ABin a);
void removeMaiorAB(ABin *a);
int quantosMaiores(ABin a, int x);
void listToBTree(LInt l, ABin *a);
int deProcura(ABin a);

#endif
