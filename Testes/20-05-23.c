#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Ponto;

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} * ABin;

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} * LInt;

void showPontos(Ponto pos[], int N) {
    for (int i = 0; i < N; i++)
        printf("x: %d\ty: %d\n", pos[i].x, pos[i].y);
}

void showListFormat(LInt l, int n) {
    while (n > 0) {
        printf("%d -> ", l->valor);
        l = l->prox;
        n--;
    }
    puts("NULL");
}

// Questão 1
int perfeito(int x) {
    int half = x / 2, store[half];
    for (int i = 1; i < half + 1; i++) {
        store[i - 1] = (x % i == 0) ? 1 : 0;
    }

    int sum = 0;
    for (int j = 0; j < half; j++) {
        sum += store[j] * (j + 1);
    }
    return sum == x;
}

// Questão 2
int dist(Ponto p) { return p.x * p.x + p.y * p.y; }

void swap(Ponto pos[], int distancias[], int i, int j) {
    Ponto temp1 = pos[i];
    pos[i] = pos[j];
    pos[j] = temp1;
    int temp2 = distancias[i];
    distancias[i] = distancias[j];
    distancias[j] = temp2;
}

void ordenaAUX(Ponto pos[], int N, int distancias[]) {
    for (int i = N; i > 0; i--) {
        for (int j = 1; j < i; j++)
            if (distancias[j - 1] > distancias[j])
                swap(pos, distancias, j - 1, j);
    }
}

void ordena(Ponto pos[], int N) {
    int distancias[N];
    for (int i = 0; i < N; i++)
        distancias[i] = dist(pos[i]);
    ordenaAUX(pos, N, distancias);
}

// Questão 3
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

// Questão 4
int wordle(char secreta[], char tentativa[]) {
    int count = 0, aux = 0;
    for (int i = 0; secreta[i]; i++) {
        if (secreta[i] == tentativa[i]) {
            tentativa[i] = tentativa[i] - ('a' - 'A');
            count++;
        } else {
            for (int j = 0; secreta[j] && aux == 0; j++) {
                if (tentativa[i] == secreta[j] && tentativa[j] != secreta[j])
                    aux = 1;
            }
            if (!aux)
                tentativa[i] = '*';
            else
                aux = 0;
        }
    }
    return count;
}

// Questão 5
LInt periodica(char s[]) {
    LInt final = NULL;
    if (s[0]) {
        LInt *temp = &final, rep = NULL;
        int first = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(')
                first = 1;
            else {
                if (s[i] == ')')
                    *temp = rep;
                else {
                    *temp = (LInt)malloc(sizeof(struct lint_nodo));
                    (*temp)->valor = s[i] - '0';
                    if (first) {
                        rep = *temp;
                        first = 0;
                    }
                    temp = &((*temp)->prox);
                }
            }
        }
    }
    return final;
}

int main() {

    assert(perfeito(28));
    assert(!perfeito(15));
    assert(!perfeito(100));

    Ponto pos1[] = {{3, 3}, {2, 1}, {-1, 0}},
          pos2[] = {{9, 5}, {2, 6}, {1, 1}, {4, 0}, {3, 3}, {0, 0}, {0, 2}};
    ordena(pos1, 3);
    // showPontos(pos1, 3);
    ordena(pos2, 7);
    // showPontos(pos2,7);

    /* a função depth funciona, testes estão na pasta Questoes */

    char secreta1[10] = "laranja", tentativa1[10] = "cerejas",
         tentativa2[10] = "bananas";
    assert(wordle(secreta1, tentativa1) == 1);
    // printf("tentativa 1: %s\n", tentativa1);
    assert(wordle(secreta1, tentativa2) == 3);
    // printf("tentativa 2: %s\n", tentativa2);

    char s1[10] = "34(56)", s2[10] = "9(234)", s3[10] = "9875(1)";
    LInt result1 = periodica(s1);
    // showListFormat(result1, 8);
    LInt result2 = periodica(s2);
    // showListFormat(result2, 6);
    LInt result3 = periodica(s3);
    // showListFormat(result3, 8);

    return 0;
}