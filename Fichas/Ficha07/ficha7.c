#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void libertaLista(Palavras l) {
    while (l) {
        Palavras temp = l->prox;
        free(l->palavra);
        free(l);
        l = temp;
    }
}

int quantasP(Palavras l) {
    int total = 0;
    for (; l; l = l->prox, total++)
        ;
    return total;
}

void listaPal(Palavras l) {
    for (; l; l = l->prox)
        printf("str: %s\tnº: %d\n", l->palavra, l->ocorr);
}

char *ultima(Palavras l) {
    if (!l)
        return NULL;

    while (l->prox)
        l = l->prox;
    return l->palavra;
}

Palavras acrescentaInicio(Palavras l, char *p) {
    Palavras new = (Palavras)malloc(sizeof(struct celula));
    assert(new);

    // duplica uma string e devolve um endereço gerado por malloc(), logo pode
    // ser limpo com free()
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = l;
    l = new;

    return l;
}

Palavras acrescentaFim(Palavras l, char *p) {
    Palavras end = acrescentaInicio(NULL, p);
    if (!l)
        return end;

    Palavras temp = l;
    while (temp->prox)
        temp = temp->prox;

    temp->prox = end;
    return l;
}

/**
 * Função acrescenta(), mas insere a nova célula no inicio
 */
Palavras acrescentaInit(Palavras l, char *p) {
    Palavras aux = l;

    while (aux && strcmp(p, aux->palavra))
        aux = aux->prox;

    if (!aux)
        l = acrescentaInicio(l, p);
    else
        aux->ocorr++;

    return l;
}

/**
 * Função acrescenta(), mas insere uma nova célula ordenadamente
 */
Palavras acrescentaOrd(Palavras l, char *p) {
    Palavras new = acrescentaInicio(NULL, p);
    if (l == NULL)
        return new;

    Palavras *temp = &l;
    while (*temp && strcmp(p, (*temp)->palavra) < 0)
        temp = &((*temp)->prox);

    if (!strcmp((*temp)->palavra, p))
        (*temp)->ocorr++;
    else {
        new->prox = *temp;
        *temp = new;
    }
    return l;
}

struct celula *maisFreq(Palavras l) {
    if (!l)
        return NULL;
    Palavras mais = l;
    l = l->prox;
    while (l) {
        if (l->ocorr > mais->ocorr)
            mais = l;
        l = l->prox;
    }

    return mais;
}
