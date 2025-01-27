#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// AUXILIAR
// Determina se uma letra é vogal
int isvogal(int ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int contaVogais(char *s) {
    int total = 0;
    for (int i = 0; s[i]; i++)
        total += isvogal(s[i]);
    return total;
}

int retiraVogaisRep1(char *s) {
    char aux[strlen(s) + 1];
    aux[0] = s[0];
    int j, i;
    for (i = j = 0; s[i]; i++)
        if (!isvogal(s[i]) || s[i] != s[i + 1])
            aux[j++] = s[i];
    aux[j] = '\0';
    strcpy(s, aux);
    return i - j;
}

int retiraVogaisRep2(char *s) {
    int j, i;
    for (i = j = 0; s[i]; i++)
        if (!isvogal(s[i]) || s[i] != s[i + 1])
            s[j++] = s[i];
    s[j] = '\0';
    return i - j;
}

int duplicaVogais1(char *s) {
    char aux[strlen(s) + contaVogais(s) + 1];
    int i, j;
    for (i = j = 0; s[i]; i++) {
        aux[j++] = s[i];
        if (isvogal(s[i]))
            aux[j++] = s[i];
    }
    aux[j] = '\0';
    strcpy(s, aux);
    return j - i;
}

int duplicaVogais2(char *s) {
    int i = strlen(s), c = contaVogais(s), j = i + c;
    s[j--] = '\0';
    for (i--; i >= 0; i--) {
        s[j--] = s[i];
        if (isvogal(s[i]))
            s[j--] = s[i];
    }
    return c;
}

// 1 -> true
// 0 -> false
int ordenado(int v[], int N) {
    for (int i = 1; i < N; i++)
        if (v[i] < v[i - 1])
            return 0;
    return 1;
}

void merge(int a[], int na, int b[], int nb, int r[]) {
    int k, i, j;
    for (k = i = j = 0; i < na && j < nb; k++)
        r[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    for (; i < na; k++)
        r[k] = a[i++];
    for (; j < nb; k++)
        r[k] = b[j++];
}

int partition1(int v[], int N, int x) {
    int aux[N], i, j, m;
    for (i = j = 0, m = N - 1; i < N && j <= m; i++) {
        if (v[i] <= x)
            aux[j++] = v[i];
        else
            aux[m--] = v[i];
    }
    for (j = 0; j < N; j++)
        v[j] = aux[j];
    return i;
}

// AUXILIAR
// Troca duas posições de um array
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int partition2(int v[], int N, int x) {
    int a, b;
    for (a = b = 0; b < N; b++)
        if (v[b] <= x)
            swap(v, b, a++);
    return a;
}


void showArray(int v[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

int main() {

    char texto1[] =
        "i Am studying Software Engenering in universidade do MinhO.";
    char texto2[30] = "ghjkgbdsc --lswq++345b b b!";
    assert(contaVogais(texto1) == 21);
    assert(contaVogais(texto2) == 0);

    char vogrep[] = "Estaa e umaa string coom duuuplicadoos";
    char vogrep2[] = "ola o meu nome e eduardo 567";
    assert(retiraVogaisRep1(vogrep) == 6);
    // printf("vogrep: %s\n", vogrep);
    assert(retiraVogaisRep1(vogrep2) == 0);
    // printf("vogrep2: %s\n", vogrep2);

    char frase1[] = "Estaa e umaa string coom duuuplicadoos";
    char frase2[] = "234 hg ef kk LL MM eeEAAC";

    assert(retiraVogaisRep2(frase1) == 6);
    // printf("frase1: %s\n", frase1);
    assert(retiraVogaisRep2(frase2) == 2);
    // printf("frase2: %s\n", frase2);

    char bla[] = "texto aletorio que eu escrevi";
    char bla2[] = "txt wth vgl";
    assert(duplicaVogais1(bla) == 14);
    // printf("bla: %s\n", bla);
    assert(duplicaVogais1(bla2) == 0);
    // printf("bla2: %s\n", bla2);

    char test1[11 * 2] = "Hello world", test2[16 * 2] = "kjhgfd mnbck pyt",
                    test3[15 * 2] = "aaiouee oioo uu";
    assert(duplicaVogais2(test1) == 3);
    // printf("test1: %s\n", test1);
    assert(duplicaVogais2(test2) == 0);
    // printf("test2: %s\n", test2);
    assert(duplicaVogais2(test3) == 13);
    // printf("test2: %s\n", test3);

    int list[] = {1, 2, 3, 4, 5, 6}, list2[] = {4, 8, 9, 0, 10, 14},
        list3[] = {1, 2, 3, 4, 5, 0};
    assert(ordenado(list, 6));
    assert(!ordenado(list2, 6));
    assert(!ordenado(list3, 6));

    int list5[] = {1, 2, 7, 20, 21, 30}, list4[] = {3, 6, 9, 12, 15},
        result[30];
    int list6[] = {1, 2, 3, 4};
    int result2[30];

    merge(list4, 5, list5, 6, result);
    // showArray(result, 11);
    merge(list6, 4, list, 6, result2);
    // showArray(result2, 10);

    int part1[] = {9, 4, 8, 20, 21, 0},
        part2[] = {100, 5, 23, 89, 0, 12, 444, 66, 3, 56, -23, 6},
        part3[] = {9, 7, 30, 0, 67, 68, 45, 3, 7};
    // partition1(part1, 6, 10);
    // showArray(part1, 6);
    // partition1(part2, 12, 15);
    // showArray(part2, 12);

    assert(partition2(part1, 6, 5) == 2);
    // showArray(part1, 6);
    assert(partition2(part2, 12, 5) == 4);
    // showArray(part2, 12);
    assert(partition2(part3, 9, 31) == 6);
    // showArray(part3, 9);

    return 0;
}
