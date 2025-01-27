#ifndef __STORAGE_H__
#define __STORAGE_H__

#define MAX 10

/* DATA TYPES */

struct staticStack {
    int sp;         // length of the array
    int values [MAX];
};
typedef struct staticStack STACK;
typedef struct staticStack *SStack;

struct staticQueue {
    int front;      // index of the first value, in the array
    int length;     // number of elements in the queue
    int values [MAX];
};
typedef struct staticQueue QUEUE;
typedef struct staticQueue *SQueue;

struct dinStack {
    int size;       // maximum size of the stack
    int sp;         // number of elements in the stack
    int *values;
};
typedef struct dinStack DinStack;
typedef struct dinStack *DStack;

struct dinQueue {
    int size;       // maximum size of the queue
    int front;      // index of the first element of the queue
    int length;     // number of elements in the queue
    int *values;
};
typedef struct dinQueue DinQueue;
typedef struct dinQueue *DQueue;


/* FUNCTIONS */

/* SHOW BUFFERS */
void showStack(SStack s);
void showQueue(SQueue q);
void showDinStack(DStack s);
void showDinQueue(DQueue q);

/* STACKS */
void SinitStack (SStack s);
int SisEmpty(SStack s);
int Spush(SStack s, int x);
int Spop(SStack s, int *x);
int Stop(SStack s, int *x);

/* QUEUES */
void SinitQueue(SQueue q);
int SisEmptyQ(SQueue q);
int Senqueue(SQueue q, int x);
int Sdequeue(SQueue q, int *x);
int Sfront(SQueue q, int *x);

/* Dinamic STACKS */
void SinitDStack(DStack s);
int DSisEmpty(DStack s);
int DSpush(DStack s, int x);
int Dpop(DStack s, int *x);
int DStop(DStack s, int *x);

/* Dinamic QUEUES */
void SinitDQueue(DQueue q);
int SisEmptyDQ(DQueue q);
int DSenqueue(DQueue q, int x);
int DSdequeue(DQueue q, int *x);
int DSfront(DQueue q, int *x);

#endif