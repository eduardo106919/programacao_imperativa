#ifndef __STORAGE_H__
#define __STORAGE_H__

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l);
int quantasP (Palavras l);
void listaPal (Palavras l);
char * ultima (Palavras l);
Palavras acrescentaInicio (Palavras l, char *p);
Palavras acrescentaFim (Palavras l, char *p);
Palavras acrescentaInit (Palavras l, char *p);
Palavras acrescentaOrd (Palavras l, char *p);
struct celula * maisFreq (Palavras l);

#endif