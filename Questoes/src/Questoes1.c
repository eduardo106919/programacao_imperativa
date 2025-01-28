#include "Questoes1.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercicio 1
void maior() {
    int largest = INT_MIN, num = INT_MIN;
    printf("Maior Valor de uma Sequência\nInsira uma lista de valores (0 para "
           "parar)\n");
    while (num != 0) {
        assert(scanf("%d", &num) == 1);
        if (num > largest)
            largest = num;
    }
    printf("Maior valor inserido: %d\n", largest);
}

// Exercicio 2
void media() {
    int total = 0, num = 1, i;
    float med;
    printf(
        "Media de uma Sequência\nInsira uma lista de valores (0 para parar)\n");

    for (i = 0; num != 0; i++, total += num)
        assert(scanf("%d", &num) == 1);
    med = (float)total / (i - 1);
    printf("Media da sequência: %.2f\n", med);
}

// Exercicio 3
void segundoMaior() {
    int bigger = INT_MIN, second = INT_MIN, num;
    printf("Segundo Maior Valor de uma Sequência\nInsira uma lista de valores "
           "(0 para parar)\n");

    while (1) {
        assert(scanf("%d", &num) == 1);
        if (num == 0)
            break;
        if (num > bigger) {
            second = bigger;
            bigger = num;
        } else if (num > second)
            second = num;
    }
    printf("Segundo Maior Valor: %d\n", second);
}

// Exercicio 4
int bitsUm(unsigned int n) {
    if (n > 0)
        return (n & 1) + bitsUm(n >> 1);
    else
        return 0;
}

// Exercicio 5
int trailingZ(unsigned int n) { // número de 0 à direita (10010100 == 2)
    if (n == 0)
        return 8; // 8 por ser 8 bits
    if (n & 1)
        return 0;
    else
        return 1 + trailingZ(n >> 1);
}

// Exercicio 6
int qDig(unsigned int n) {
    if (n == 0)
        return 1;
    int i = 0;
    for (; n > 0; i++, n /= 10)
        ;
    return i;
}

// Exercicio 7
char *strcatM(char s1[], char s2[]) {
    int i, j;
    for (j = 0; s1[j] != '\0'; j++)
        ;
    for (i = 0; s2[i] != '\0'; i++, j++)
        s1[j] = s2[i];
    s1[j] = '\0';
    return s1;
}

// Exercicio 8
char *strcpyM(char *dest, char source[]) {
    char *aux;
    for (aux = source; *aux != '\0'; dest++, aux++)
        *dest = *aux;
    *dest = '\0';
    return dest;
}

// Exercicio 9
int strcmpM(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
        ;
    return (s1[i] - s2[i]);
}

// Exercicio 10
char *strstrM(char s1[], char s2[]) {
    int i = 0, j = 0, m = 0;
    char *pos = NULL;
    for (; s2[m] != '\0'; m++)
        ;
    for (; s1[i] != '\0' && s2[j] != '\0'; i++) {
        if (s1[i] == s2[j]) {
            if (j == 0)
                pos = s1 + i;
            j++;
        } else
            j = 0;
    }
    return (j == m) ? pos : NULL;
}

// AUXILIAR
void swapChar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Exercicio 11
void strrevM(char s[]) {
    int m = 0;
    for (; s[m] != '\0'; m++)
        ;
    m--;
    int i = 0;
    for (; i < m; i++, m--)
        swapChar(s + i, s + m);
}

// AUXILIAR
int isvogal(int c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Exercicio 12
void strnoV(char s[]) {
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (!isvogal(s[i])) {
            s[j] = s[i];
            j++;
        }
    s[j] = '\0';
}

// Exercicio 13
void truncW(char t[], int n) {
    int i, j = 0, m = 0;
    for (i = 0; t[i] != '\0'; i++)
        if (j < n || isspace(t[i])) {
            t[m] = t[i];
            j++;
            m++;
            if (isspace(t[i]))
                j = 0;
        }
    t[m] = '\0';
}

// AUXILIAR
int countChar(char s[], char x) {
    int i, c = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == x)
            c++;
    return c;
}

// Exercicio 14
char charMaisfreq(char s[]) {
    if (s[0] == '\0')
        return 0;
    int freq = countChar(s, s[0]), i;
    char acc = s[0];
    for (i = 0; s[i] != '\0'; i++)
        if (freq < countChar(s, s[i])) {
            freq = countChar(s, s[i]);
            acc = s[i];
        }
    return acc;
}

// Exercicio 15
int iguaisConsecutivos(char s[]) {
    if (s[0] == '\0')
        return 0;
    int cont = 1, i, acc = 1;
    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1])
            cont++;
        else
            cont = 1;
        if (cont > acc)
            acc = cont;
    }
    return acc;
}

// Exercicio 16
int difConsecutivos(char s[]) {
    if (s[0] == '\0')
        return 0;
    int cont = 1, i, acc = 1;
    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[i - 1])
            cont++;
        else
            cont = 1;
        if (cont > acc)
            acc = cont;
    }
    return (acc == 1 && i > 1) ? 0 : acc;
}

// Exercicio 17
int maiorPrefixo(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
        ;
    return i;
}

// Exercicio 18
int maiorSufixo(char s1[], char s2[]) {
    int n1 = strlen(s1) - 1, n2 = strlen(s2) - 1, cont = 0;
    for (; s1[n1] == s2[n2] && n1 >= 0 && n2 >= 0; cont++, n1--, n2--)
        ;
    return cont;
}

// Exercicio 19
int sufPref(char s1[], char s2[]) {
    int i, j;
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[j])
            j++;
        else
            j = 0;
    }
    return j;
}

// Exercicio 20
int contaPal(char s[]) {
    int cont = 0, i, pal = 1;
    /*
    pal == 1 -> esta em palavra mas nao contou
    pal == -1 -> esta em palavra e ja contou
    pal == 0 -> nao esta em palavra
    */
    for (i = 0; s[i] != '\0'; i++) {
        if (isspace(s[i]))
            pal = 0;
        else if (pal == 0)
            pal = 1;
        if (pal > 0) {
            cont++;
            pal = -1;
        }
    }
    return cont;
}

// Exercicio 21
int contaVogais(char s[]) {
    int cont = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (isvogal(s[i]))
            cont++;
    return cont;
}

// AUXILIAR
int pertence(char x, char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == x)
            return 1;
    return 0;
}

// Exercicio 22
int contida(char a[], char b[]) {
    for (int i = 0; a[i] != '\0'; i++)
        if (!pertence(a[i], b))
            return 0;
    return 1;
}

// Exercicio 23
int palindorome(char s[]) {
    int j = strlen(s) - 1;
    int n = strlen(s) / 2;
    for (int i = 0; i < n; i++, j--)
        if (s[i] != s[j])
            return 0;
    return 1;
}

// Exercicio 24
int remRep(char x[]) {
    if (strlen(x) == 0)
        return 0;
    int i, j;
    for (i = 1, j = 1; x[i] != '\0'; i++)
        if (x[i] != x[i - 1]) {
            x[j] = x[i];
            j++;
        }
    x[j] = '\0';
    return j;
}

// Exercicio 25
int limpaEspacos(char t[]) {
    if (!(*t))
        return 0;
    int i, j;
    for (i = 1, j = 1; t[i] != '\0'; i++)
        if (!(isspace(t[i]) && isspace(t[i - 1]))) {
            t[j] = t[i];
            j++;
        }
    t[j] = '\0';
    return j;
}

// Exercicio 26
void insere(int v[], int N, int x) {
    for (; N > 0 && v[N - 1] > x; N--)
        v[N] = v[N - 1];
    v[N] = x;
}

// Exercicio 27
void merge(int r[], int a[], int b[], int na, int nb) {
    int i, j, k;
    i = j = k = 0;
    for (; i < na && j < nb; k++)
        r[k] = (a[i] <= b[j]) ? a[i++] : b[j++];
    for (; i < na; k++)
        r[k] = a[i++];
    for (; j < nb; k++)
        r[k] = b[j++];
}

// Exercicio 28
int crescente(int a[], int i, int j) {
    for (; i < j && a[i] <= a[i + 1]; i++)
        ;
    return (j - i) ? 0 : 1;
}

// Exercicio 29
int retiraNeg(int v[], int N) {
    int i, j;
    for (i = 0, j = 0; i < N; i++)
        if (v[i] >= 0) {
            v[j] = v[i];
            j++;
        }
    return j;
}

// Exercicio 30
int menosFreq(int v[], int N) {
    int i = 1, out = v[0], freq = 1, freqMin = 1;
    for (; i < N && v[i] == v[0]; i++, freqMin++)
        ;
    for (; i < N - 1; i++) {
        if (v[i] == v[i + 1])
            freq++;
        else {
            if (freq < freqMin) {
                freqMin = freq;
                out = v[i];
            }
            freq = 1;
        }
    }
    return (v[i] != v[i - 1] && freqMin > 1) ? v[i] : out;
}

// Exercicio 31
int maisFreq(int v[], int N) {
    int i, freq = 1, acc = v[0], freqMax = 1;
    for (i = 1; i < N; i++) {
        if (v[i] == v[i - 1])
            freq++;
        else {
            if (freq > freqMax) {
                freqMax = freq;
                acc = v[i - 1];
            }
            freq = 1;
        }
    }
    return (freq > freqMax) ? v[i - 1] : acc;
}

// Exercicio 32
int maxCresc(int v[], int N) {
    if (N == 0)
        return 0;
    int i, freq = 1, freqMax = 1;
    for (i = 1; i < N; i++) {
        if (v[i] > v[i - 1])
            freq++;
        else {
            if (freq > freqMax)
                freqMax = freq;
            freq = 1;
        }
    }
    return (freq > freqMax) ? freq : freqMax;
}

// AUXILIAR
int elem(int v[], int N, int x) {
    for (int i = 0; i < N; i++)
        if (v[i] == x)
            return 1;
    return 0;
}

// Exercicio 33
int elimRep(int v[], int n) {
    int i, j;
    for (i = 1, j = 1; i < n; i++)
        if (!elem(v, i, v[i])) {
            v[j] = v[i];
            j++;
        }
    return j;
}

// Exercicio 34
int elimRepOrd(int v[], int n) {
    int i, j;
    for (i = 1, j = 1; i < n; i++)
        if (v[i] != v[i - 1]) {
            v[j] = v[i];
            j++;
        }
    return j;
}

// Exercicio 35
int comunsOrd(int a[], int na, int b[], int nb) {
    int i, j, cont = 0;
    for (i = 0, j = 0; i < na && j < nb;) {
        if (a[i] == b[j]) {
            i++;
            j++;
            cont++;
        } else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    return cont;
}

// Exercicio 36
int comuns(int a[], int na, int b[], int nb) {
    int i, cont = 0;
    for (i = 0; i < na; i++)
        if (!elem(a, i, a[i]) && elem(b, nb, a[i]))
            cont++;
    return cont;
}

// Exercicio 37
int minInd(int v[], int n) {
    int i, ind = 0;
    for (i = 1; i < n; i++)
        if (v[i] < v[ind])
            ind = i;
    return ind;
}

// Exercicio 38
void somasAc(int v[], int Ac[], int N) {
    Ac[0] = v[0];
    for (int i = 1; i < N; i++) {
        Ac[i] = v[i] + Ac[i - 1];
    }
}

// Exercicio 39
int triSup(int N, float m[N][N]) {
    int i, j;
    for (i = 1; i < N; i++)
        for (j = 0; j < i; j++)
            if (m[i][j] != 0)
                return 0;
    return 1;
}

// AUXILIAR
void swapFlt(float *x, float *y) {
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Exercicio 40
void transposta(int N, float m[N][N]) {
    int i, j;
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
            swapFlt(&(m[i][j]), &(m[j][i]));
}

// Exercicio 41
void addTo(int N, int M, int a[N][M], int b[N][M]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] += b[i][j];
}

// Exercicio 42
int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        r[i] = (v1[i] || v2[i]);
        cont += r[i];
    }
    return cont;
}

// Exercicio 43
int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        r[i] = (v1[i] && v2[i]);
        cont += r[i];
    }
    return cont;
}

// Exercicio 44
int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        r[i] = (v1[i] <= v2[i]) ? v1[i] : v2[i];
        cont += r[i];
    }
    return cont;
}

// Exercicio 45
int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        r[i] = (v1[i] <= v2[i]) ? v2[i] : v1[i];
        cont += r[i];
    }
    return cont;
}

// Exercicio 46
int cardinalMSet(int N, int v[N]) {
    int cont = 0;
    for (int i = 0; i < N; i++)
        cont += v[i];
    return cont;
}

// Exercicio 47
Posicao posFinal(Posicao inicial, Movimento mov[], int N) {
    for (int i = 0; i < N; i++) {
        switch (mov[i]) {
            case Norte:
                inicial.y++;
                break;
            case Sul:
                inicial.y--;
                break;
            case Oeste:
                inicial.x--;
                break;
            case Este:
                inicial.x++;
                break;
            default:
                break;
        }
    }
    return inicial;
}

// Exercicio 48
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i;
    for (i = 0; i < N && (inicial.x != final.x || inicial.y != final.y); i++) {
        if (inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
        } else if (inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
        } else if (inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
        } else {
            mov[i] = Norte;
            inicial.y--;
        }
    }
    return (inicial.x != final.x || inicial.y != final.y) ? -1 : i;
}

// AUXILIAR
float dist(Posicao pos) { return sqrt(pow(pos.x, 2) + pow(pos.y, 2)); }

// Exercicio 49
int maisCentral(Posicao pos[], int N) {
    int i = 1, acc = 0, d = dist(pos[0]);
    for (; i < N; i++)
        if (dist(pos[i]) < d) {
            d = dist(pos[i]);
            acc = i;
        }
    return acc;
}

// AUXILIAR
int manDist(int x, int y, int x0, int y0) { return abs(x - x0) + abs(y - y0); }

// Exercicio 50
int vizinhos(Posicao p, Posicao pos[], int N) {
    int i = 0, cont = 0;
    for (; i < N; i++)
        if (manDist(pos[i].x, pos[i].y, p.x, p.y) == 1)
            cont++;
    return cont;
}
