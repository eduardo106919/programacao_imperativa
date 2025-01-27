#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float teste, minis;
} Aluno;

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} * LInt;

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} * ABin;

// Ex.1
int isFib(int x) {
    if (x < 0)
        return 0;

    if (x == 0 || x == 1)
        return 1;

    int ant1 = 1, ant2 = 1, fib = ant1 + ant2;
    while (fib < x) {
        ant1 = ant2;
        ant2 = fib;
        fib = ant1 + ant2;
    }
    return fib == x;
}

// Ex.2
int nota(Aluno a) { return (int)(a.teste * 0.8 + a.minis * 0.2); }

int moda(Aluno turma[], int N) {
    /*
        aqui uso um método de contagem, no qual crio um array em que cada indice
        é a nota, e o conteudo é o numero de vezes que essa nota se repete
    */
    int res[21];
    for (int i = 0; i < 21; i++) {
        res[i] = 0;
    }

    int maisfreq = 0;
    for (int i = 0; i < N; i++) {
        res[nota(turma[i])]++;
        if (res[maisfreq] < res[nota(turma[i])])
            maisfreq = nota(turma[i]);
    }

    return (maisfreq < 10) ? 0 : maisfreq;
}

// Ex.3
int freeL(LInt l) {
    int count = 0;
    while (l) {
        LInt temp = l->prox;
        free(l);
        l = temp;
        count++;
    }
    return count;
}

int take(int n, LInt *l) {
    while (*l && n > 0) {
        l = &((*l)->prox);
        n--;
    }

    int count = 0;
    if (*l) {
        count += freeL(*l);
        *l = NULL;
    }
    return count;
}

// Ex.4
int verifica(char frase[], int k) {
    int space = 0, count = 0, before = 0;
    for (int i = 0; frase[i]; i++) {
        if (frase[i] == ' ') {
            space = 1;
            before = count;
            count = 0;
        } else {
            if (space && count == 0 && before < k)
                return 0;
            count++;
            before = 0;
            space = 0;
        }
    }
    return 1;
}

// Ex.5
ABin reconstroi(char s[]) {
    /*
        Esta funcao tem de ser feita recursivamente
        uma forma de a fazer é construir primeiro a parte esquerda da arvore e
        ter em conta quantos caracteres já passou para assim poder "saltar" para
        os valores que vão pertencer à direita da àrvore

        Esta resolução quase de certeza está errada, mas devia dar uns ponticos
    */

    if (s[0] == '*' || s[0] == '\0')
        return NULL;

    ABin new = (ABin)malloc(sizeof(struct abin_nodo));
    new->valor = s[0] - '0';
    s++;
    new->esq = reconstroi(s);
    new->dir = reconstroi(s);
}

int main() {

    assert(isFib(13));
    assert(!isFib(18));
    assert(isFib(144));
    assert(!isFib(145));
    assert(isFib(55));

    Aluno a1 = {16, 16}, a2 = {9, 7}, a3 = {10, 13}, a4 = {19, 18},
          a5 = {18, 10};
    /*
        notas: 16 9 11 19 16
    */

    Aluno test[] = {a1, a2, a3, a4, a5};
    assert(moda(test, 5));

    /*
        a função take() está definida na Questoes2, os testes estão na main
        dessa pasta
    */

    char str1[] = "ola o meu nome é vai te f*der",
         str2[] = "skjds akfhak ajsdgas asdgajs";

    assert(!verifica(str1, 3));
    assert(verifica(str2, 3));

    return 0;
}