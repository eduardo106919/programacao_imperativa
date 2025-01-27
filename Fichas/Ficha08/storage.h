#ifndef __STORAGE_H__
#define __STORAGE_H__

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs);


/* Stack */

typedef LInt Stack;

void initStack (Stack *s);
int SisEmpty (Stack s);
int push (Stack *s, int x);
int pop (Stack *s, int *x);
int top (Stack s, int *x);


/* Queue */

typedef struct {
    LInt inicio, fim;
} Queue;

void initQueue (Queue *q);
int QisEmpty (Queue q);
int enqueue (Queue *q, int x);
int dequeue (Queue *q, int *x);
int front (Queue q, int *x);


/* Circular Queue */

typedef LInt QueueC;

void initQueueC (QueueC *q);
int QisEmptyC (QueueC q);
int enqueueC (QueueC *q, int x);
int dequeueC (QueueC *q, int *x);
int frontC (QueueC q, int *x);


/* Double ended Queue */

typedef struct dlist {
      int valor;
      struct dlist *ant, *prox;
} *DList;

typedef struct {
     DList back, front;
} Deque;

DList newDList (int x, DList xs);

void initDeque (Deque *q);
int DisEmpty (Deque q);
int pushBack (Deque *q, int x);
int pushFront (Deque *q, int x);
int popBack (Deque *q, int *x);
int popFront (Deque *q, int *x);
int popMax (Deque *q, int *x);
int back (Deque q, int *x);
int DQfront (Deque q, int *x);


/* Double ended Circular Queue */

typedef DList DequeC;

void initDequeC (DequeC *q);
int DisEmptyC (DequeC q);
int pushBackC (DequeC *q, int x);
int pushFrontC (DequeC *q, int x);
int popBackC (DequeC *q, int *x);
int popFrontC (DequeC *q, int *x);
int popMaxC (DequeC *q, int *x);
int backC (DequeC q, int *x);
int DQfrontC (DequeC q, int *x);


void printStack(Stack s);
void printQueue(Queue q);

#endif
