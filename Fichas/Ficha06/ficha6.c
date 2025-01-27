#include "storage.h"
#include <stdio.h>
#include <stdlib.h>

/* SHOW BUFFERS */

void showStack(SStack s) {
    puts("_   _");
    for (int i = s->sp - 1; i >= 0; i--)
        printf("| %d |\n", s->values[i]);
    puts("-----");
}

void showQueue(SQueue q) {
    int i;
    for (i = 0; i < q->length * 2 + 5; i++)
        printf("-");
    putchar('\n');
    printf("<- ");

    for (i = 0; i < q->length; i++)
        printf("%d ", q->values[(q->front + i) % MAX]);
    puts("<-");

    for (i = 0; i < q->length * 2 + 5; i++)
        printf("-");
    putchar('\n');
}

void showDinStack(DStack s) {
    puts("_   _");
    for (int i = s->sp - 1; i >= 0; i--)
        printf("| %d |\n", s->values[i]);
    puts("-----");
}

void showDinQueue(DQueue q) {
    int i;
    for (i = 0; i < q->length * 2 + 5; i++)
        printf("-");
    putchar('\n');
    printf("<- ");

    for (i = 0; i < q->length; i++)
        printf("%d ", q->values[(q->front + i) % q->size]);
    puts("<-");

    for (i = 0; i < q->length * 2 + 5; i++)
        printf("-");
    putchar('\n');
}

/* STACKS */

void SinitStack(SStack s) { s->sp = 0; }

int SisEmpty(SStack s) { return s->sp == 0; }

int Spush(SStack s, int x) {
    if (s->sp >= MAX)
        return 1;

    s->values[s->sp++] = x;
    return 0;
}

int Spop(SStack s, int *x) {
    if (SisEmpty(s))
        return 1;

    *x = s->values[--s->sp];
    return 0;
}

int Stop(SStack s, int *x) {
    if (SisEmpty(s))
        return 1;

    *x = s->values[s->sp - 1];
    return 0;
}

/* QUEUES */

void SinitQueue(SQueue q) {
    q->front = 0;
    q->length = 0;
}

int SisEmptyQ(SQueue q) { return q->length == 0; }

int Senqueue(SQueue q, int x) {
    if (q->length >= MAX)
        return 1;

    q->values[(q->front + q->length++) % MAX] = x;
    return 0;
}

int Sdequeue(SQueue q, int *x) {
    if (SisEmptyQ(q))
        return 1;

    *x = q->values[q->front];
    q->front = (q->front + 1) % MAX;
    q->length--;
    return 0;
}

int Sfront(SQueue q, int *x) {
    if (SisEmptyQ(q))
        return 1;

    *x = q->values[q->front];
    return 0;
}

/* Dinamic Stacks */

void SinitDStack(DStack s) {
    s->size = MAX;
    s->sp = 0;
    s->values = (int *)malloc(sizeof(int) * s->size);
}

int DSisEmpty(DStack s) { return s->sp == 0; }

int DSpush(DStack s, int x) {
    if (s->sp == s->size) {
        int *temp = (int *)malloc(sizeof(int) * s->size * 2);
        for (int i = 0; i < s->size; i++)
            temp[i] = s->values[i];

        free(s->values);
        s->size *= 2;
        s->values = temp;
    }
    s->values[s->sp++] = x;
    return 0;
}

int Dpop(DStack s, int *x) {
    if (DSisEmpty(s))
        return 1;

    *x = s->values[--s->sp];
    return 0;
}

int DStop(DStack s, int *x) {
    if (DSisEmpty(s))
        return 1;

    *x = s->values[s->sp - 1];
    return 0;
}

/* Dinamic Queues */

void SinitDQueue(DQueue q) {
    q->size = MAX;
    q->front = 0;
    q->length = 0;
    q->values = (int *)malloc(sizeof(int) * q->size);
}

int SisEmptyDQ(DQueue q) { return q->length == 0; }

int DSenqueue(DQueue q, int x) {
    if (q->length == q->size) {
        int *temp = (int *)malloc(sizeof(int) * q->size * 2);
        for (int i = 0; i < q->length; i++)
            temp[i] = q->values[(i + q->front) % q->size];

        free(q->values);
        q->values = temp;
        q->size *= 2;
        q->front = 0;
    }
    q->values[(q->front + q->length++) % q->size] = x;
    return 0;
}

int DSdequeue(DQueue q, int *x) {
    if (SisEmptyDQ(q))
        return 1;

    *x = q->values[q->front];
    q->front = (q->front + 1) % q->size;
    q->length--;
    return 0;
}

int DSfront(DQueue q, int *x) {
    if (SisEmptyDQ(q))
        return 1;

    *x = q->values[q->front];
    return 0;
}
