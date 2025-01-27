#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char strings[20][100] = {"apple",      "banana",    "cherry", "date",
                             "eberry",     "fig",       "grape",  "honeydew",
                             "kiwi",       "lemon",     "mango",  "nectarine",
                             "orange",     "pineapple", "quince", "raspberry",
                             "strawberry", "tangerine", "ugli",   "watermelon"};

    Palavras lista = NULL;

    for (int i = 0; i < 15; i++)
        lista = acrescentaInicio(lista, strings[i]);
    listaPal(lista);
    assert(quantasP(lista) == 15);

    printf("Ultima: %s\n", ultima(lista));
    printf("---\n");

    for (int i = 15; i < 20; i++)
        lista = acrescentaFim(lista, strings[i]);
    listaPal(lista);
    assert(quantasP(lista) == 20);

    printf("---\n");

    libertaLista(lista);
    lista = NULL;
    assert(quantasP(lista) == 0);

    listaPal(lista);
    for (int i = 0; i < 10; i++)
        lista = acrescentaInicio(lista, strings[i]);
    listaPal(lista);
    assert(quantasP(lista) == 10);
    printf("---\n");

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            // lista = acrescentaInit(lista, strings[i]);
            lista = acrescentaOrd(lista, strings[i]);
        }
    }
    listaPal(lista);
    assert(quantasP(lista) == 10);
    printf("---\n");

    for (int i = 0; i < 3; i++)
        lista = acrescentaOrd(lista, strings[8]);
    listaPal(lista);

    struct celula * freq = maisFreq(lista);
    printf("+freq: %s\n", freq->palavra);

    return 0;
}
