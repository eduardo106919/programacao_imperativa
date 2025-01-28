#include "Questoes1.h"
#include "Questoes2.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showArray(int array[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void showMatrix(int N, float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", m[i][j]);
        }
        putchar('\n');
    }
}

void showMatrixInt(int N1, int N2, int m[N1][N2]) {
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            printf("%d ", m[i][j]);
        }
        putchar('\n');
    }
}

int main() {

    //              Questões 1

    // Exercicio 1
    // maior();

    // Exercicio 2
    // media();

    // Exercicio 3
    // segundoMaior();

    // Exercicio 4
    // assert(bitsUm(57394) == 6);
    // assert(bitsUm(10000) == 5);
    // assert(bitsUm(64) == 1);
    // assert(bitsUm(0) == 0);
    // // assert(bitsUm(-34) == 2);

    // // Exercicio 5
    // assert(trailingZ(67) == 0);
    // assert(trailingZ(64) == 6);
    // assert(trailingZ(12) == 2);
    // assert(trailingZ(0) == 8);

    // // Exercicio 6
    // assert(qDig(2390341) == 7);
    // assert(qDig(0) == 1);
    // assert(qDig(90) == 2);
    // assert(qDig(10) == 2);

    // // Exercicio 7
    // char concat1[] = "hello ", concat2[] = "world!", concat3[] = "i am a
    // software enginner student ", concat4[] = ":)", concat5[] = "";
    // assert(strcatM(concat1, concat2) != NULL);
    // // printf("concat1: %s\n", concat1);
    // assert(strcatM(concat3, concat4) != NULL);
    // // printf("concat3: %s\n", concat3);
    // assert(strcatM(concat5, concat3) != NULL);
    // // printf("concat5: %s\n", concat5);

    // // Exercicio 8
    // char copy1[] = "copy", copy2[] = "paste", copy3[] = "", copy4[] =
    // "23456kfdl", copy5[] = "password :> ;|"; assert(strcpyM(copy1, copy2) !=
    // NULL);
    // // printf("copy1: %s\n", copy1);
    // assert(strcpyM(copy3, copy4) != NULL);
    // // printf("copy3: %s\n", copy3);
    // assert(strcpyM(copy2, copy5) != NULL);
    // // printf("copy2: %s\n", copy2);
    // assert(strcpyM(copy4, copy4) != NULL);
    // // printf("copy4: %s\n", copy4);

    // // Exercicio 9
    // char comp1[] = "texto ", comp2[] = "texto", comp3[] = "", comp4[] =
    // "partial", comp5[] = "texto"; assert(strcmpM(comp2, comp5) == 0);
    // assert(strcmpM(comp1, comp2) > 0);
    // assert(strcmpM(comp3, comp2) < 0);
    // assert(strcmpM(comp4, comp1) < 0);
    // assert(strcmpM(comp1, comp4) > 0);

    // // Exercicio 10
    // char ocor1[] = "ocorrencia", ocor2[] = "rren", ocor3[] = "kkk", ocor4[] =
    // ""; char ocor5[] = "encA", ocor6[] = "ciaK", ocor7[] = "cia";
    // assert(strstrM(ocor1, ocor2) == &(ocor1[3]));
    // assert(strstrM(ocor1, ocor3) == NULL);
    // assert(strstrM(ocor4, ocor3) == NULL);
    // assert(strstrM(ocor1, ocor5) == NULL);
    // assert(strstrM(ocor1, ocor6) == NULL);
    // assert(strstrM(ocor1, ocor7) == &(ocor1[7]));
    // assert(strstrM(ocor6, ocor1) == NULL);

    // // Exercicio 11
    // char inv1[] = "inverte texto! .)", inv2[] = "", inv3[] = "yadot";
    // strrevM(inv1);
    // // printf("inv1: %s\n", inv1);
    // strrevM(inv2);
    // // printf("inv2: %s(check)\n", inv2);
    // strrevM(inv3);
    // // printf("inv3: %s\n", inv3);

    // // Exercicio 12
    // char vog1[] = "txt wTht Vgl", vog2[] = "textO com vogAis", vog3[] = "",
    // vog4[] = "Aeiio uu E A A I"; strnoV(vog1);
    // // printf("vog1: %s\n", vog1);
    // strnoV(vog2);
    // // printf("vog2: %s\n", vog2);
    // strnoV(vog3);
    // // printf("vog3: %s(check)\n", vog3);
    // strnoV(vog4);
    // // printf("vog4: %s(check)\n", vog4);

    // // Exercicio 13
    // char trunc1[] = "liberdade, igualdade e fraternidade", trunc2[] = "",
    // trunc3[] = "exi  gen kk, l erty", trunc4[] = "eduardo frei fernandes hoje
    // vai festejar"; truncW(trunc1, 4);
    // // printf("trunc1: %s\n", trunc1);
    // truncW(trunc2, 5);
    // // printf("trunc2: %s\n", trunc2);
    // truncW(trunc3, 7);
    // // printf("trunc3: %s\n", trunc3);
    // truncW(trunc4, 5);
    // // printf("trunc4: %s\n", trunc4);

    // // Exercicio 14
    // char chfreq1[] = "ola o meu nome_eduardo", chfreq2[] = "llkjhdsvllmn",
    // chfreq3[] = ""; assert(charMaisfreq(chfreq1) == 'o');
    // assert(charMaisfreq(chfreq2) == 'l');
    // assert(charMaisfreq(chfreq3) == 0);

    // // Exercicio 15
    // char igcon1[] = "aabcccaac", igcon2[] = "", igcon3[] = "lkjhgfd dfsre
    // bnm", igcon4[] = "llllll"; assert(iguaisConsecutivos(igcon1) == 3);
    // assert(iguaisConsecutivos(igcon2) == 0);
    // assert(iguaisConsecutivos(igcon3) == 1);
    // assert(iguaisConsecutivos(igcon4) == 6);

    // // Exercicio 16
    // assert(difConsecutivos(igcon1) == 3);
    // assert(difConsecutivos(igcon2) == 0);
    // assert(difConsecutivos(igcon3) == 17);
    // assert(difConsecutivos(igcon4) == 0);

    // // Exercicio 17
    // char pref1[] = "geekforce", pref2[] = "geek", pref3[] = "hello", pref4[]
    // = "", pref5[] = "h ello"; assert(maiorPrefixo(pref1, pref2) == 4);
    // assert(maiorPrefixo(pref1, pref3) == 0);
    // assert(maiorPrefixo(pref3, pref4) == 0);
    // assert(maiorPrefixo(pref3, pref5) == 1);

    // // Exercicio 18
    // char suf1[] = "today cinema", suf2[] = "cinema", suf3[] = "goodbye",
    // suf4[] = "", suf5[] = "ye"; assert(maiorSufixo(suf1, suf2) == 6);
    // assert(maiorSufixo(suf1, suf3) == 0);
    // assert(maiorSufixo(suf3, suf4) == 0);
    // assert(maiorSufixo(suf3, suf5) == 2);

    // // Exercicio 19
    // char prefsuf1[] = "batota", prefsuf2[] = "totalidade", prefsuf3[] = "",
    // prefsuf4[] = "hetotalk", prefsuf5[] = "agua";
    // assert(sufPref(prefsuf1,prefsuf2) == 4);
    // assert(sufPref(prefsuf1,prefsuf3) == 0);
    // assert(sufPref(prefsuf1,prefsuf4) == 0);
    // assert(sufPref(prefsuf4,prefsuf2) == 0);
    // assert(sufPref(prefsuf1,prefsuf5) == 1);

    // // Exercicio 20
    // char pal1[] = "a a bb a", pal2[] = "hoje e dia de festa", pal3[] =
    // "aniversario", pal4[] = ""; assert(contaPal(pal1) == 4);
    // assert(contaPal(pal2) == 5);
    // assert(contaPal(pal3) == 1);
    // assert(contaPal(pal4) == 0);

    // // Exercicio 21
    // char cVog1[] = "II OO eagg skit", cVog2[] = "kbnm g rtr qw !!";
    // assert(contaVogais(pal1) == 3);
    // assert(contaVogais(cVog1) == 7);
    // assert(contaVogais(cVog1) == 7);
    // assert(contaVogais(cVog2) == 0);

    // // Exercicio 22
    // char cont1[] = "braga", cont2[] = "bracarence agunca", cont3[] = "",
    // cont4[] = "portuagl"; assert(contida(cont1, cont2));
    // assert(contida(cont1, cont3) == 0);
    // assert(contida(cont1, cont4) == 0);

    // // Exercicio 23
    // char palin1[] = "hellolleh", palin2[] = "lkanlav alkaknvbkabvk", palin3[]
    // = "", palin4[] = "ll"; assert(palindorome(palin1));
    // assert(palindorome(palin2) == 0);
    // assert(palindorome(palin3));                // a string vazia é
    // considerada palindrome???? assert(palindorome(palin4));

    // // Exercicio 24
    // char rep1[] = "aaabaaabbbaaa", rep2[] = "lkvaksoi als sadn !! sdc :)",
    // rep3[] = "", rep4[] = "llkllkllpAA"; assert(remRep(rep1) == 5);
    // // printf("rep1: %s\n", rep1);
    // assert(remRep(rep2) == 26);
    // // printf("rep2: %s\n", rep2);
    // assert(remRep(rep3) == 0);
    // // printf("rep3: %s(check)\n", rep3);
    // assert(remRep(rep4) == 7);
    // // printf("rep4: %s\n", rep4);

    // // Exercicio 25
    // char esp1[] = "akdfkd   aaf   a asdjaa", esp2[] = "", esp3[] = "hoje nao
    // ha festa ca por casa", esp4[] = "portugal   vai    ganhar  o euro";
    // assert(limpaEspacos(esp1) == 19);
    // // printf("esp1: %s\n", esp1);
    // assert(limpaEspacos(esp2) == 0);
    // // printf("esp2: %s\n", esp2);
    // assert(limpaEspacos(esp3) == 29);
    // // printf("esp3: %s\n", esp3);
    // assert(limpaEspacos(esp4) == 26);
    // // printf("esp4: %s\n", esp4);

    // // Exercicio 26
    // int ins1[7] = {1,2,3,5,6,7}, ins2[] = {9}, ins3[] = {3,8,10,11,20}; //
    // como testo para o array vazio insere(ins1, 6, 4);
    // // showArray(ins1, 7);
    // insere(ins2, 1, 7);
    // // showArray(ins2, 2);
    // insere(ins3, 5, 21);
    // // showArray(ins3, 6);

    // // Exercicio 27
    // int merg1[] = {3,6,9,12,15}, merg2[] = {2,4,6,8,20}, res1[10];
    // int merg3[] = {1,1,1,5,90,92}, merg4[] = {-5,-1,0,1,2}, res2[11];
    // merge(res1,merg1,merg2,5,5);
    // // showArray(res1,10);
    // merge(res2,merg3,merg4,6,5);
    // // showArray(res2,11);

    // // Exercicio 28
    // int cres1[] = {1,2,3,4,5,6}, cres2[] = {0,6,9,2,12,5}, cres3[] = {1};
    // assert(crescente(cres1, 1, 4));
    // assert(crescente(cres2, 0, 2));
    // assert(crescente(cres2, 1, 4) == 0);
    // assert(crescente(cres3, 0, 0));

    // // Exercicio 29
    // int neg1[] = {5,8,-1,0,-3,-5,-10}, neg2[] = {0,0,0,9,1}, neg3[] =
    // {-3,-6,-8,-1}; assert(retiraNeg(neg1, 7) == 3); assert(retiraNeg(neg2, 5)
    // == 5); assert(retiraNeg(neg3, 4) == 0);

    // // Exercicio 30
    // int freq1[] = {1,1,2,3,4,4,4,7}, freq2[] = {4,4,4,6,6,8,8,8,9}, freq3[] =
    // {6,6,6,8}; assert(menosFreq(freq1, 7) == 2); assert(menosFreq(freq2, 9)
    // == 9); assert(menosFreq(freq3, 4) == 8);

    // // Exercicio 31
    // int maisfr1[] = {1,7,9,13,55,55,55}, maisfr2[] = {0,0,0,0,8,56,56,56},
    // maisfr3[] = {1,2,3,4,5,6,7,8}; assert(maisFreq(maisfr1, 7) == 55);
    // assert(maisFreq(maisfr2, 8) == 0);
    // assert(maisFreq(maisfr3, 8) == 1);

    // // Exercicio 32
    // int maxcr1[] = {1,2,3,2,9,9,1,2,3,4}, maxcr2[] = {4,3,1,0,-4}, maxcr3[] =
    // {1,2,3,4,5,6,8,0}; assert(maxCresc(maxcr1, 10) == 4);
    // assert(maxCresc(maxcr2, 5) == 1);
    // assert(maxCresc(maxcr3, 8) == 7);

    // // Exercicio 33
    // int elRep1[] = {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}, elRep2[] = {9,45,12,6,4},
    // elRep3[] = {1,1,1,1,1,1}; assert(elimRep(elRep1, 10) == 5);
    // // showArray(elRep1, 5);
    // assert(elimRep(elRep2, 5) == 5);
    // // showArray(elRep2, 5);
    // assert(elimRep(elRep3, 6) == 1);
    // // showArray(elRep1, 1);

    // // Exercicio 34
    // int repOrd1[] = {1,1,1,2,4,5,6,6,6}, repOrd2[] = {6,7,8,9,20,30},
    // repOrd3[] = {9,9,9,9,9,9,9}; assert(elimRepOrd(repOrd1, 9) == 5);
    // // showArray(repOrd1, 5);
    // assert(elimRepOrd(repOrd2, 6) == 6);
    // // showArray(repOrd2, 6);
    // assert(elimRepOrd(repOrd3, 7) == 1);
    // // showArray(repOrd1, 1);

    // // Exercicio 35
    // int comOrd1[] = {1,2,3,4,5,6,7}, comOrd2[] = {2,4,6,8,10}, comOrd3[] =
    // {10,20,67,98}; int comOrd4[] = {2,2,2,9,10}; assert(comunsOrd(comOrd1, 7,
    // comOrd2, 5) == 3); assert(comunsOrd(comOrd1, 7, comOrd3, 3) == 0);
    // assert(comunsOrd(comOrd2, 5, comOrd3, 3) == 1);
    // assert(comunsOrd(comOrd1, 7, comOrd4, 5) == 1);

    // // Exercicio 36
    // int com1[] = {4,8,2,6,8,3,5,74,4,23}, com2[] = {1,4,8,0,4,2,5,3,3,1},
    // com3[] = {-4,-6,-1,0}; assert(comuns(com1, 10, com2, 10) == 5);
    // assert(comuns(com3, 4, com1, 10) == 0);
    // assert(comuns(com3, 4, com2, 10) == 1);

    // // Exercicio 37
    // int menorInd1[] = {6,3,8,1,9}, menorInd2[] = {1,2,3,4,0}, menorInd3[] =
    // {9,8,7,6,-1,10,-1}; assert(minInd(menorInd1, 5) == 3);
    // assert(minInd(menorInd2, 5) == 4);
    // assert(minInd(menorInd3, 7) == 4);

    // // Exercicio 38
    // int somas1[] = {1,2,3,4,5}, somasRes1[5], somas2[] = {0,0,4,12,6,-3},
    // somasRes2[6]; somasAc(somas1, somasRes1, 5);
    // // showArray(somasRes1, 5);
    // somasAc(somas2, somasRes2, 6);
    // // showArray(somasRes2, 6);

    // // Exercicio 39
    // float mat1[][3] = {{1,2,3},{4,5,6},{7,8,9}}, mat2[][4] =
    // {{1,2,3,4},{0,5,6,7},{0,0,8,9},{0,0,0,10}}; float mat3[][3] =
    // {{0,0,0},{0,0,0},{0,1,0}}, mat4[][2] = {{1,2},{0,3}}; assert(triSup(3,
    // mat1) == 0); assert(triSup(4, mat2)); assert(triSup(3, mat3) == 0);
    // assert(triSup(2, mat4));

    // // Exercicio 40
    // // transposta(3, mat1);
    // // showMatrix(3, mat1);
    // // transposta(4, mat2);
    // // showMatrix(4, mat2);

    // // Exercicio 41
    // int matT1[][3] = {{1,2,3},{4,5,6},{7,8,9}}, matT2[][3] =
    // {{3,2,1},{6,5,4},{9,8,7}}; int matT3[][1] = {{1},{2},{3},{4}}, matT4[][1]
    // = {{0},{4},{-5},{9}}; addTo(3,3, matT1, matT2);
    // // showMatrixInt(3, 3, matT1);
    // addTo(4, 1, matT3, matT4);
    // // showMatrixInt(4, 1, matT3);

    // // Exercicio 42
    // int conj1[] = {0,1,0,0,1,0,0,1}, conj2[] = {1,0,0,1,1,0,1,0}, result1[8];
    // int conj3[] = {1,1,0,1}, conj4[] = {0,1,0,1}, result2[8];
    // unionSet(8, conj1, conj2, result1);
    // // showArray(result1, 8);
    // unionSet(4, conj3, conj4, result2);
    // // showArray(result2, 4);

    // // Exercicio 43
    // // intersectSet(8, conj1, conj2, result1);
    // // showArray(result1, 8);
    // // intersectSet(3, conj3, conj4, result2);
    // // showArray(result2, 4);

    // // Exercicio 44
    // int conjM1[] = {0,2,0,0,1,0,0,3}, conjM2[] = {1,5,3,0,0,7,0,1}, resM1[8];
    // int conjM3[] = {5,6,7,8,9}, conjM4[] = {6,3,0,8,7}, resM2[5];
    // intersectMSet(8, conjM1, conjM2, resM1);
    // // showArray(resM1, 8);
    // intersectMSet(5, conjM3, conjM4, resM2);
    // showArray(resM2, 5);

    // Exercicio 45
    // unionMSet(8, conjM1, conjM2, resM1);
    // showArray(resM1, 8);
    // unionMSet(5, conjM3, conjM4, resM2);
    // showArray(resM2, 5);

    // Exercicio 46
    // int conjM5[] = {0,0,0,0};
    // assert(cardinalMSet(8, conjM1) == 6);
    // assert(cardinalMSet(8, conjM2) == 17);
    // assert(cardinalMSet(5, conjM3) == 35);
    // assert(cardinalMSet(5, conjM4) == 24);
    // assert(cardinalMSet(4, conjM5) == 0);

    //              Questões 2

    srand(time(0));
    LInt listaA = NULL, listaB = NULL, listaC = NULL, listaD = NULL,
         empty = NULL;

    listaA = listaPares(10, 1);
    listaB = listaNorm(20);
    listaC = listaPares(15, 0);
    listaD = listaRandom(10);

    // imprimeL(listaA);
    // imprimeL(listaB);
    // imprimeL(listaC);
    // imprimeL(listaD);
    // imprimeL(empty);
    assert(length(listaA) == 5);
    assert(length(listaB) == 20);
    assert(length(listaC) == 7);
    assert(length(empty) == 0);

    // reverseL(listaA);       // FIX ME
    // printList(listaA);

    // printList(listaC);
    insertOrd(&listaC, 9);
    assert(length(listaC) == 8);
    // printList(listaC);
    insertOrd(&listaC, 1);
    assert(length(listaC) == 9);
    // printList(listaC);
    insertOrd(&listaC, 19);
    assert(length(listaC) == 10);
    // printList(listaC);

    // printList(listaB);
    assert(removeOneOrd(&listaB, 17) == 0);
    assert(length(listaB) == 19);
    // printList(listaB);
    assert(removeOneOrd(&listaB, 1) == 0);
    assert(length(listaB) == 18);
    // printList(listaB);
    assert(removeOneOrd(&listaB, 20) == 0);
    assert(length(listaB) == 17);
    // printList(listaB);
    assert(removeOneOrd(&listaB, 5) == 0);
    assert(length(listaB) == 16);
    // printList(listaB);
    assert(removeOneOrd(&listaB, 5) == 1);
    assert(length(listaB) == 16);

    LInt result1 = NULL;
    // puts("Lista B:");
    // printList(listaB);
    // puts("Lista C:");
    // printList(listaC);
    mergeLInt(&result1, listaB, listaC);
    // puts("Result 1:");
    // printList(result1);

    // puts("Lista D:");
    // printList(listaD);
    LInt result2 = NULL, result3 = NULL;
    splitQS(listaD, 5, &result2, &result3);
    // puts("Result 2:");
    // printList(result2);
    // puts("Result 3:");
    // printList(result3);

    freeL(result1);

    // puts("Lista A:");
    // printList(listaA);
    result1 = parteAmeio(&listaA);
    // puts("Lista A:");
    // printList(listaA);
    // puts("Result 1:");
    // printList(result1);

    LInt listaE = listaRandom(20);

    // puts("Lista E:");
    // printList(listaE);
    removeAll(&listaE, rand() % 20 + 1);
    // printList(listaE);

    // printList(listaE);
    assert(removeDups(&listaE));
    // printList(listaE);
    // printList(listaA);
    assert(!removeDups(&listaA));
    // printList(listaA);

    // printList(listaE);
    removeMaiorL(&listaE);
    // printList(listaE);

    LInt listaF = listaRandom(20);

    // puts("Lista F:");
    // printList(listaF);
    init(&listaF);
    // printList(listaF);

    // printList(listaF);
    appendL(&listaF, 35);
    // printList(listaF);

    // printList(empty);
    // appendL(&empty, 100);
    // printList(empty);

    // puts("Lista F:");
    // printList(listaF);
    // puts("Lista A:");
    // printList(listaA);
    concatL(&listaF, listaA);
    // puts("Lista F:");
    // printList(listaF);
    // puts("Lista A:");
    // printList(listaA);
    // concatL(&empty, listaA);
    // puts("empty:");
    // printList(empty);

    // puts("Lista F:");
    // printList(listaF);
    result1 = cloneL(listaF);
    // puts("result 1:");
    // printList(result1);

    freeL(result1);

    // puts("Lista F:");
    // printList(listaF);
    result1 = cloneRev(listaF);
    // puts("result 1:");
    // printList(result1);

    // puts("Lista F:");
    // printList(listaF);
    // printf("maximo: %d\n", maximo(listaF));

    LInt listaG = listaRandom(15), listaH = listaPares(10, 1);

    // puts("Lista G:");
    // printList(listaG);
    assert(take(9, &listaG) == 9);
    // printList(listaG);

    // puts("Lista H:");
    // printList(listaH);
    assert(take(7, &listaH) == 5);
    // printList(listaH);

    // puts("Lista H:");
    // printList(listaH);
    assert(drop(3, &listaH) == 3);
    // printList(listaH);

    // puts("Lista G:");
    // printList(listaG);
    assert(drop(11, &listaG) == 9);
    // printList(listaG);

    int *array1 = (int *)malloc(6 * sizeof(int)),
        array2[] = {5, 1, 8, 10, 89, 0, 4};

    // puts("Lista F:");
    // printList(listaF);
    assert(listToArray(listaF, array1, 6) == 6);
    // showArray(array1, 6);

    LInt listaJ = arrayToList(array2, 7);
    // puts("Lista J:");
    // printList(listaJ);

    free(result1);

    // puts("Lista J:");
    // printList(listaJ);
    result1 = somasAcL(listaJ);
    // puts("result 1:");
    // printList(result1);

    LInt listaK = listaPares(20, 0);
    insertOrd(&listaK, 6);
    insertOrd(&listaK, 12);
    insertOrd(&listaK, 10);
    insertOrd(&listaK, 2);
    insertOrd(&listaK, 2);
    insertOrd(&listaK, 2);
    insertOrd(&listaK, 12);
    insertOrd(&listaK, 12);
    // puts("Lista K:");
    // printList(listaK);
    remreps(listaK);
    // puts("Lista K:");
    // printList(listaK);

    // puts("Lista A:");
    // printList(listaA);
    listaA = rotateL(listaA);
    // puts("Lista A:");
    // printList(listaA);
    empty = rotateL(empty);
    // printList(empty);

    freeL(result1);

    LInt listaL = listaRandom(30);

    // puts("Lista L:");
    // printList(listaL);
    result1 = parte(listaL);
    // puts("Lista L:");
    // printList(listaL);
    // puts("result 1:");
    // printList(result1);

    /* Àrvores Binárias */

    ABin arvore1 = newABin(7,
                           newABin(2, newABin(8, NULL, NULL),
                                   newABin(3, NULL, newABin(0, NULL, NULL))),
                           newABin(4, NULL, newABin(1, NULL, NULL)));
    ABin arvVazia = NULL, arvore3 = newABin(5, NULL, NULL);

    // showABin(arvore1);
    // showABin(arvore2);
    // showABin(arvore3);

    assert(altura(arvore1) == 4);
    assert(altura(arvVazia) == 0);
    assert(altura(arvore3) == 1);

    ABin arvore4 = cloneAB(arvore1);
    // puts("Arvore 1:");
    // showABin(arvore1);
    // puts("Arvore 4:");
    // showABin(arvore4);

    mirror(&arvore4);
    // puts("Arvore 4:");
    // showABin(arvore4);
    mirror(&arvVazia);

    ABin arvore5 = cloneAB(arvore1), arvore6 = cloneAB(arvore4);
    LInt aux1 = NULL;

    // puts("Arvore 4:");
    // showABin(arvore4);
    inorder(arvore4, &aux1);
    // puts("InOrder:");
    // printList(aux1);
    freeL(aux1);
    aux1 = NULL;

    // puts("Arvore 5:");
    // showABin(arvore5);
    preorder(arvore5, &aux1);
    // puts("PreOrder:");
    // printList(aux1);
    freeL(aux1);
    aux1 = NULL;

    // puts("Arvore 6:");
    // showABin(arvore6);
    posorder(arvore6, &aux1);
    // puts("PosOrder:");
    // printList(aux1);
    freeL(aux1);
    aux1 = NULL;

    assert(depth(arvore1, 8) == 3);
    assert(depth(arvore1, 7) == 1);
    assert(depth(arvore1, 6) == -1);
    assert(depth(arvVazia, 9) == -1);

    assert(freeAB(arvore1) == 7);

    return 0;
}