#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100

int main() {
    srand(time(0));
    int i = 0, temp = 0;

    printf("-------- STACKS --------\n");

    Stack stack;
    initStack(&stack);
    printf("stack is empty: '%s'\n", SisEmpty(stack) == 0 ? "false" : "true");

    for (i = 0; i < 10; i++) {
        temp = rand() % MAX_VALUE;
        printf("push %*d\n", 2, temp);
        push(&stack, temp);
    }
    printf("stack is empty: '%s'\n", SisEmpty(stack) == 0 ? "false" : "true");

    printf("--------\nStack:\n");
    printStack(stack);
    top(stack, &temp);
    printf("top %*d\n----------\n", 2, temp);

    for (i = 0; i < 3; i++) {
        pop(&stack, &temp);
        printf("pop %*d\n", 2, temp);
    }

    printf("--------\nStack:\n");
    printStack(stack);
    top(stack, &temp);
    printf("top %*d\n----------\n", 2, temp);

    printf("Cleaning up:\n");
    while (SisEmpty(stack) == 0) {
        pop(&stack, &temp);
        printf("pop %*d\n", 2, temp);
    }
    printf("stack is empty: '%s'\n", SisEmpty(stack) == 0 ? "false" : "true");

    printf("-------- QUEUES --------\n");

    Queue queue;
    initQueue(&queue);
    printf("queue is empty: '%s'\n", QisEmpty(queue) == 0 ? "false" : "true");

    for (i = 0; i < 10; i++) {
        temp = rand() % MAX_VALUE;
        printf("enqueue %*d\n", 2, temp);
        enqueue(&queue, temp);
    }

    printf("--------\nQueue:\n");
    printQueue(queue);
    front(queue, &temp);
    printf("front %*d\n", 2, temp);
    printf("queue is empty: '%s'\n", QisEmpty(queue) == 0 ? "false" : "true");

    for (i = 0; i < 4; i++) {
        dequeue(&queue, &temp);
        printf("dequeue %*d\n", 2, temp);
    }

    printf("--------\nQueue:\n");
    printQueue(queue);
    front(queue, &temp);
    printf("front %*d\n", 2, temp);

    printf("Cleaning up:\n");
    while (QisEmpty(queue) == 0) {
        dequeue(&queue, &temp);
        printf("dequeue %*d\n", 2, temp);
    }
    printf("queue is empty: '%s'\n", QisEmpty(queue) == 0 ? "false" : "true");

    printf("-------- CIRCULAR QUEUES --------\n");
    
    QueueC cq;
    initQueueC(&cq);
    printf("circular queue is empty: '%s'\n", QisEmptyC(cq) == 0 ? "false" : "true");

    for (i = 0; i < 10; i++) {
        temp = rand() % MAX_VALUE;
        printf("enqueue %*d\n", 2, temp);
        enqueueC(&cq, temp);
    }

    printf("--------\nCircular Queue:\n");
    printQueueC(cq);
    frontC(cq, &temp);
    printf("front %*d\n", 2, temp);
    printf("circular queue is empty: '%s'\n", QisEmptyC(cq) == 0 ? "false" : "true");

    for (i = 0; i < 4; i++) {
        dequeueC(&cq, &temp);
        printf("dequeue %*d\n", 2, temp);
    }

    printf("--------\nCircular Queue:\n");
    printQueueC(cq);
    frontC(cq, &temp);
    printf("front %*d\n", 2, temp);

    printf("Cleaning up:\n");
    while (QisEmptyC(cq) == 0) {
        dequeueC(&cq, &temp);
        printf("dequeue %*d\n", 2, temp);
    }
    printf("queue is empty: '%s'\n", QisEmptyC(cq) == 0 ? "false" : "true");

    printf("-------- DOUBLE ENDED QUEUES --------\n");

    Deque deque;
    initDeque(&deque);
    printf("deque is empty: '%s'\n", DisEmpty(deque) == 0 ? "false" : "true");

    for (i = 0; i < 5; i++) {
        temp = rand() % MAX_VALUE;
        printf("push front %*d\n", 2, temp);
        pushFront(&deque, temp);
    }

    printf("--------\nDouble Ended Queue:\n");
    printDeque(deque);
    DQfront(deque, &temp);
    printf("front %*d\n", 2, temp);
    back(deque, &temp);
    printf("back %*d\n", 2, temp);
    printf("deque is empty: '%s'\n", DisEmpty(deque) == 0 ? "false" : "true");

    for (i = 0; i < 5; i++) {
        temp = rand() % MAX_VALUE;
        printf("push back %*d\n", 2, temp);
        pushBack(&deque, temp);
    }

    printf("--------\nDouble Ended Queue:\n");
    printDeque(deque);
    DQfront(deque, &temp);
    printf("front %*d\n", 2, temp);
    back(deque, &temp);
    printf("back %*d\n", 2, temp);
    printf("deque is empty: '%s'\n", DisEmpty(deque) == 0 ? "false" : "true");

    printf("Pop Max\n");
    popMax(&deque, &temp);
    printf("max %*d\n", 2, temp);
    printDeque(deque);

    for (i = 0; i < 3; i++) {
        popFront(&deque, &temp);
        printf("pop front %*d\n", 2, temp);
    }
    printf("--------\nDouble Ended Queue:\n");
    printDeque(deque);

    for (i = 0; i < 3; i++) {
        popBack(&deque, &temp);
        printf("pop back %*d\n", 2, temp);
    }
    printf("--------\nDouble Ended Queue:\n");
    printDeque(deque);

    DQfront(deque, &temp);
    printf("front %*d\n", 2, temp);
    back(deque, &temp);
    printf("back %*d\n", 2, temp);

    printf("Cleaning up:\n");
    while (DisEmpty(deque) == 0) {
        popBack(&deque, &temp);
        printf("pop back %*d\n", 2, temp);
    }
    printf("deque is empty: '%s'\n", DisEmpty(deque) == 0 ? "false" : "true");






    printf("-------- DOUBLE ENDED CIRCULAR QUEUES --------\n");
    
    DequeC dequeC;
    initDequeC(&dequeC);
    printf("circular deque is empty: '%s'\n", DisEmptyC(dequeC) == 0 ? "false" : "true");

    for (i = 0; i < 5; i++) {
        temp = rand() % MAX_VALUE;
        printf("push front %*d\n", 2, temp);
        pushFrontC(&dequeC, temp);
    }

    printf("--------\nDouble Ended Circular Queue:\n");
    printDequeC(dequeC);
    DQfrontC(dequeC, &temp);
    printf("front %*d\n", 2, temp);
    backC(dequeC, &temp);
    printf("back %*d\n", 2, temp);
    printf("circular deque is empty: '%s'\n", DisEmptyC(dequeC) == 0 ? "false" : "true");
    for (i = 0; i < 5; i++) {
        temp = rand() % MAX_VALUE;
        printf("push back %*d\n", 2, temp);
        pushBackC(&dequeC, temp);
    }

    printf("--------\nDouble Ended Circular Queue:\n");
    printDequeC(dequeC);
    DQfrontC(dequeC, &temp);
    printf("front %*d\n", 2, temp);
    backC(dequeC, &temp);
    printf("back %*d\n", 2, temp);
    printf("circular deque is empty: '%s'\n", DisEmptyC(dequeC) == 0 ? "false" : "true");

    printf("Pop Max\n");
    popMaxC(&dequeC, &temp);
    printf("max %*d\n", 2, temp);
    printDequeC(dequeC);

    for (i = 0; i < 3; i++) {
        popFrontC(&dequeC, &temp);
        printf("pop front %*d\n", 2, temp);
    }
    printf("--------\nDouble Ended Circular Queue:\n");
    printDequeC(dequeC);

    for (i = 0; i < 3; i++) {
        popBackC(&dequeC, &temp);
        printf("pop back %*d\n", 2, temp);
    }
    printf("--------\nDouble Ended Circular Queue:\n");
    printDequeC(dequeC);

    DQfrontC(dequeC, &temp);
    printf("front %*d\n", 2, temp);
    backC(dequeC, &temp);
    printf("back %*d\n", 2, temp);

    printf("Cleaning up:\n");
    while (DisEmptyC(dequeC) == 0) {
        popBackC(&dequeC, &temp);
        printf("pop back %*d\n", 2, temp);
    }
    printf("circular deque is empty: '%s'\n", DisEmptyC(dequeC) == 0 ? "false" : "true");

    return 0;
}