#include "storage.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//* Helpfull functions
void printStack(Stack s) {
    Stack aux;

    printf("Stack:");
    for (aux = s; aux; aux = aux->prox) {
        printf(" %d", aux->valor);
    }
    printf("\n");
}

void printQueue(Queue q) {
    LInt aux;

    printf("Queue:");
    for (aux = q.inicio; aux; aux = aux->prox) {
        printf(" %d", aux->valor);
    }
    printf("\n");
}

// void printLQC(QueueC q){
//     LInt aux;
//     printf("QueueC:");
//     if(!LQCisEmpty(q)){
//         for (aux = q.fim->prox; aux != q.fim; aux = aux->prox){
//             printf(" %d", aux->valor);
//         }printf(" %d",aux->valor);
//     }printf("\n");
// }

// void printDeque(Deque d){
//     DList aux;

//     printf("Deque: ");
//     for (aux = d.back; aux; aux = aux->prox){
//         printf(" %d", aux->valor);
//     }printf("\n");
// }

// void printDequeC(DequeC d){
//     DList aux;

//     printf("DequeC:");
//     if(!isEmptyDequeC(d)){
//         for (aux = d.front->prox; aux != d.front; aux = aux->prox){
//             printf(" %d", aux->valor);
//         }printf(" %d",aux->valor);
//     }printf("\n");
// }

LInt newLInt(int x, LInt xs) {
    LInt r = (LInt)malloc(sizeof(struct slist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

DList newDList(int x, DList xs) {
    DList r = (DList)malloc(sizeof(struct dlist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
        r->ant = NULL;
    }
    return r;
}

/* Stacks */

void initStack(Stack *s) { *s = NULL; }

int SisEmpty(Stack s) { return s == NULL; }

int push(Stack *s, int x) {
    Stack new = newLInt(x, *s);
    *s = new;
    return 0;
}

int pop(Stack *s, int *x) {
    if (*s == NULL)
        return 1;

    Stack temp = (*s)->prox;
    *x = (*s)->valor;
    free(*s);
    (*s) = temp;

    return 0;
}

int top(Stack s, int *x) {
    if (s == NULL)
        return 1;

    *x = s->valor;
    return 0;
}

/* Queues */

void initQueue(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q) { return q.inicio == NULL; }

int enqueue(Queue *q, int x) {
    LInt new = newLInt(x, NULL);
    if (!new)
        return 1;
    if (QisEmpty(*q)) {
        q->inicio = new;
        q->fim = new;
    } else {
        (q->fim)->prox = new;
        q->fim = new;
    }
    return 0;
}

int dequeue(Queue *q, int *x) {
    if (QisEmpty(*q))
        return 1;

    LInt temp = (q->inicio)->prox;
    *x = (q->inicio)->valor;
    free(q->inicio);
    q->inicio = temp;

    return 0;
}

int front(Queue q, int *x) {
    if (QisEmpty(q))
        return 1;

    *x = (q.inicio)->valor;

    return 0;
}

/* Circular Queue */

void initQueueC(QueueC *q) { *q = NULL; }

int QisEmptyC(QueueC q) { return q == NULL; }

int enqueueC(QueueC *q, int x) {
    QueueC new = newLInt(x, NULL);
    if (!new)
        return 1;

    if (QisEmptyC(*q)) {
        *q = new;
        (*q)->prox = *q;
    } else {
        QueueC temp = (*q)->prox;
        (*q)->prox = new;
        *q = new;
        (*q)->prox = temp;
    }
    return 0;
}

int dequeueC(QueueC *q, int *x) {
    if (QisEmptyC(*q))
        return 1;

    // poderá ser desnecessário
    // se só tiver um elemento na queue
    if (*q == (*q)->prox)
        free(*q);
    else {
        QueueC temp = (*q)->prox->prox;
        *x = (*q)->prox->valor;
        free((*q)->prox);
        (*q)->prox = temp;
    }
    return 0;
}

int frontC(QueueC q, int *x) {
    if (QisEmptyC(q))
        return 1;

    *x = q->prox->valor;
    return 0;
}

/* Double ended Queue */

void initDeque(Deque *q) { q->front = q->back = NULL; }

int DisEmpty(Deque q) { return q.front == NULL && q.back == NULL; }

int pushBack(Deque *q, int x) {
    DList new = newDList(x, NULL);
    if (!new)
        return 1;

    if (DisEmpty(*q)) {
        q->front = new;
    }

    new->ant = q->back;
    q->back = new;
    return 0;
}

int pushFront(Deque *q, int x) {
    DList new = newDList(x, q->front);
    if (!new)
        return 1;

    if (DisEmpty(*q)) {
        q->back = new;
    }

    q->front = new;
    return 0;
}

int popBack(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 1;

    DList ultimo = q->back;
    *x = ultimo->valor;

    q->back = ultimo->ant;

    // se a queue só tiver um elemento
    if (q->front == ultimo)
        q->front = NULL;

    free(ultimo);
    return 0;
}

int popFront(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 1;

    DList cabeca = q->front;
    *x = cabeca->valor;

    q->front = cabeca->prox;

    // se a queue só tiver um elemento
    if (q->back == cabeca)
        q->back = NULL;

    free(cabeca);
    return 0;
}

int popMax(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 1;

    DList reference = q->front;
    DList tempFront = q->front->prox;
    DList tempBack = q->back;

    while (tempFront && tempFront != tempBack) {
        if (reference->valor < tempFront->valor)
            reference = tempFront;
        if (reference->valor < tempBack->valor)
            reference = tempBack;

        tempFront = tempFront->prox;
        tempBack = tempBack->prox;
    }

    // se o maior for a cabeca
    if (reference->ant == NULL)
        q->front = reference->prox;
    else
        reference->ant->prox = reference->prox;

    // se o maior for o ultimo
    if (reference->prox == NULL)
        q->back = reference->ant;
    else
        reference->prox->ant = reference->ant;

    *x = reference->valor;
    free(reference);
    return 0;
}

int back(Deque q, int *x) {
    if (DisEmpty(q))
        return 1;

    *x = q.back->valor;
    return 0;
}

int DQfront(Deque q, int *x) {
    if (DisEmpty(q))
        return 1;

    *x = q.front->valor;
    return 0;
}

/* Double Ended Circular Queue */

void initDequeC(DequeC *q) { *q = NULL; }

int DisEmptyC(DequeC q) { return q == NULL; }

int pushBackC(DequeC *q, int x) {
    DList new = newDList(x, NULL);
    if (!new)
        return 1;

    if (DisEmptyC(*q)) {
        *q = new;
        (*q)->prox = new;
        (*q)->ant = new;
    } else {
        new->prox = (*q)->prox;
        (*q)->prox = new;
        new->ant = *q;
    }

    return 0;
}

int pushFrontC(DequeC *q, int x) {
    DList new = newDList(x, NULL);
    if (!new)
        return 1;

    if (DisEmptyC(*q)) {
        *q = new;
        (*q)->prox = new;
        (*q)->ant = new;
    } else {
        new->prox = (*q)->prox;
        (*q)->prox = new;
        new->ant = *q;
    }

    return 0;
}

int popBackC(DequeC *q, int *x) {
    if (DisEmptyC(*q))
        return 1;

    *x = (*q)->valor;
    // liga o penultimo à cabeca
    (*q)->ant->prox = (*q)->prox;

    // liga a cabeca ao penultimo
    (*q)->prox->ant = (*q)->ant;

    free(*q);
    return 0;
}

int popFrontC(DequeC *q, int *x) {
    if (DisEmptyC(*q))
        return 1;

    DList cabeca = (*q)->prox;
    *x = cabeca->valor;

    // liga o ultimo ao segundo elemento
    (*q)->prox = cabeca->prox;

    // liga o segundo ao ultimo
    cabeca->prox->ant = *q;

    free(cabeca);
    return 0;
}

int popMaxC(DequeC *q, int *x) {
    if (DisEmptyC(*q))
        return 1;

    DList reference = (*q)->prox;
    DList tempFront = (*q)->prox->prox;
    DList tempBack = *q;

    while (tempFront && tempFront != tempBack) {
        if (tempBack->valor > reference->valor)
            reference = tempBack;
        if (tempFront->valor > reference->valor)
            reference = tempFront;

        tempBack = tempBack->ant;
        tempFront = tempFront->prox;
    }

    *x = reference->valor;
    // ligo os elementos que estao e depois do reference
    reference->ant->prox = reference->prox;
    reference->prox->ant = reference->ant;

    free(reference);
    return 0;
}

int backC(DequeC q, int *x) {
    if (DisEmptyC(q))
        return 1;

    *x = q->valor;
    return 0;
}

int DQfrontC(DequeC q, int *x) {
    if (DisEmptyC(q))
        return 1;

    *x = q->prox->valor;
    return 0;
}
