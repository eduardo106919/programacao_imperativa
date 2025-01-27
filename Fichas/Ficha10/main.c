#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100

int main() {
    srand(time(0));

    ABin tree;
    int size = 15;
    int array[size];
    int j = 0;
    for (j = 0; j < size; j++)
        array[j] = j;

    tree = RandArvFromArray(array, size);
    printf("------------- RANDOM BINARY TREE -------------\n");
    showABin(tree);

    int index = rand() % size;

    printf("Remove %*d\n", 2, array[index]);
    removeElem(&tree, array[index]);
    showABin(tree);
    
    index = rand() % size;
    printf("Remove %*d\n", 2, array[index]);
    removeElem(&tree, array[index]);
    showABin(tree);

    printf("------------- Promove Maior -------------\n");
    promoveMaior(&tree);
    showABin(tree);

    printf("------------- Clean Up -------------\n");
    freeABin(tree);
    printf("------------- New Tree -------------\n");
    tree = RandArvFromArray(array, size);
    showABin(tree);

    printf("------------- Remove Menor -------------\n");
    ABin menor = removeMenorAlt(&tree);
    if (menor)
        printf("menor %*d\n", 2, menor->valor);
    showABin(tree);

    printf("------------- Promove Menor -------------\n");
    promoveMenor(&tree);
    showABin(tree);

    printf("------------- Clean Up -------------\n");
    freeABin(tree);
    printf("------------- New Tree -------------\n");
    tree = RandArvFromArray(array, size);
    showABin(tree);

    printf("------------- Equilibra -------------\n");
    equilibra(&tree);
    showABin(tree);

    return 0;
}