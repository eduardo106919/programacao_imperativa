#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>


int nota(Aluno a) {
    int mediaMtestes = 0;
    for (int i = 0; i < 5; i++)
        mediaMtestes += a.miniT[i];

    if (mediaMtestes < 3)
        return 0;

    float miniTestes = mediaMtestes * 2 * 0.2;
    float teste = a.teste * 0.8;
    float notaFinal = teste + miniTestes + 0.5;

    return (notaFinal < 10) ? 0 : notaFinal;
}

int procuraNum(int num, Aluno t[], int N) {
    int i, l = 0, u = N - 1;
    while (l <= u) {
        i = (l + u) / 2;
        if (t[i].numero == num)
            return i;
        if (t[i].numero < num)
            l = i + 1;
        else
            u = i - 1;
    }
    return -1;
}

void swapAluno(Aluno turma[], int i, int j) {
    Aluno temp = turma[i];
    turma[i] = turma[j];
    turma[j] = temp;
}

int partitionAluno(Aluno turma[], int N, int x) {
    int i, a;
    for (i = a = 0; i < N; i++)
        if (turma[i].numero <= x)
            swapAluno(turma, i, a++);
    return a;
}

void ordenaPorNum(Aluno t[], int N) {
    if (N > 1) {
        int p;
        p = partitionAluno(t, N - 1, t[N - 1].numero);
        swapAluno(t, p, N - 1);
        ordenaPorNum(t, p);
        ordenaPorNum(t + p + 1, N - p - 1);
    }
}

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i, j, min;
    for (int i = 0; i < N; i++)
        ind[i] = i;

    // selection sort
    for (i = 0; i < N; i++) {
        min = i;
        for (j = i; j < N; j++)
            if (t[ind[j]].numero < t[ind[min]].numero)
                min = j;
        swap(ind, i, min);
    }
}

void imprimeTurma(int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        printf("Número: %d\n", t[ind[i]].numero);
        printf("Nome: %s\n", t[ind[i]].nome);
        printf("Nota: %d\n", nota(t[ind[i]]));
    }
}

int procuraNumADP(int num, int ind[], Aluno turma[], int N) {
    int i, l = 0, u = N - 1;
    while (l <= u) {
        i = (l + u) / 2;
        if (turma[ind[i]].numero == num)
            return ind[i];
        if (turma[ind[i]].numero < num)
            l = i + 1;
        else
            u = i - 1;
    }
    return -1;
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i, j, min;
    for (i = 0; i < N; i++)
        ind[i] = i;

    // selection sort
    for (i = 0; i < N; i++) {
        min = i;
        for (j = i; j < N; j++)
            if (strcmp(t[ind[j]].nome, t[ind[min]].nome) < 0)
                min = j;
        swap(ind, i, min);
    }
}


// shows an array of integers through stdout
void showArray(int v[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

// shows a Aluno through stdout
void showAluno(Aluno *stu) {
    printf("Número: %d\n", stu->numero);
    printf("Nome: %s\n", stu->nome);
    printf("Mini Testes: ");
    showArray(stu->miniT, NUM_MTESTES);
    printf("Teste: %.2f\n", stu->teste);
}

// shows an array of students
void showTurma(Aluno turma[], int N) {
    for (int i = 0; i < N; i++) {
        printf("Aluno %d:\n", i + 1);
        showAluno(turma + i);
    }
}

int main() {
    Aluno aluno1 = {136, "eduardo", {2, 1, 2, 0, 1}, 16.5};
    Aluno aluno2 = {270, "maria", {0, 2, 1, 0, 1}, 10};
    Aluno aluno3 = {300, "joao", {1, 2, 2, 2, 1}, 19};
    Aluno aluno4 = {348, "silvino", {2, 0, 0, 0, 2}, 7.3};
    Aluno aluno5 = {491, "arnaldo", {0, 2, 0, 2, 1}, 11.7};

    assert(nota(aluno1) == 16);
    assert(nota(aluno2) == 10);
    assert(nota(aluno3) == 18);
    assert(nota(aluno4) == 0);
    assert(nota(aluno5) == 11);

    Aluno turma1[] = {aluno1, aluno2, aluno3, aluno4},
          turma2[] = {aluno2, aluno4, aluno5},
          turma3[] = {aluno1, aluno2, aluno3, aluno4, aluno5},
          turma4[] = {aluno3, aluno2, aluno5, aluno1}, turma5[] = {aluno2},
          turma6[] = {aluno5, aluno4, aluno3, aluno2, aluno1},
          turma7[] = {{4444, "André", {2, 1, 0, 2, 2}, 10.5},
                      {2222, "Joana", {2, 2, 2, 1, 0}, 14.5},
                      {7777, "Maria", {2, 2, 2, 2, 2}, 18.5},
                      {3333, "Paulo", {0, 0, 2, 2, 2}, 8.7}};

    assert(procuraNum(250, turma1, 4) == -1);
    assert(procuraNum(491, turma2, 3) == 2);
    assert(procuraNum(270, turma3, 5) == 1);

    // ordenaPorNum(turma3, 5);
    // showTurma(turma3, 5);
    // ordenaPorNum(turma4, 4);
    // showTurma(turma4, 4);
    // ordenaPorNum(turma5, 1);
    // showTurma(turma5, 1);
    // ordenaPorNum(turma6, 5);
    // showTurma(turma6, 5);

    int indices1[4], indices2[5], indices3[4];
    criaIndPorNum(turma7, 4, indices1);
    // showArray(indices1, 4);
    criaIndPorNum(turma6, 5, indices2);
    // showArray(indices2, 5);
    criaIndPorNum(turma4, 4, indices3);
    // showArray(indices3, 4);

    // imprimeTurma(indices1, turma7, 4);
    // imprimeTurma(indices2, turma6, 5);
    // imprimeTurma(indices3, turma4, 4);

    assert(procuraNumADP(250, indices1, turma7, 4) == -1);
    assert(procuraNumADP(491, indices2, turma6, 5) == 0);
    assert(procuraNumADP(3333, indices1, turma7, 4) == 3);

    // criaIndPorNome(turma7, 4, indices1);
    // showArray(indices1, 4);
    // criaIndPorNome(turma6, 5, indices2);
    // showArray(indices2, 5);
    // criaIndPorNome(turma4, 4, indices3);
    // showArray(indices3, 4);

    return 0;
}
