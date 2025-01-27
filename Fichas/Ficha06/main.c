#include "storage.h"
#include <assert.h>
#include <stdio.h>

int main() {

    STACK stack1;
    QUEUE queue1;
    DinStack dStack1;
    DinQueue dQueue1;
    int x, i;

    /* Static Stacks */

    SinitStack(&stack1);
    assert(stack1.sp == 0);
    assert(SisEmpty(&stack1));
    assert(!Spush(&stack1, 6));
    assert(!Spush(&stack1, 9));
    assert(!Stop(&stack1, &x));
    assert(x == 9);
    assert(!Spush(&stack1, 2));
    // showStack(&stack1);
    assert(!SisEmpty(&stack1));
    assert(!Spop(&stack1, &x));
    // showStack(&stack1);
    assert(!Spop(&stack1, &x));
    assert(!Spop(&stack1, &x));
    assert(SisEmpty(&stack1));
    assert(Spop(&stack1, &x));
    for (i = 0; i < MAX; i++)
        assert(!Spush(&stack1, i));
    // showStack(&stack1);
    assert(Spush(&stack1, 0));

    /* Static Queues */

    SinitQueue(&queue1);
    assert(queue1.length == 0 && queue1.front == 0);
    assert(SisEmptyQ(&queue1));
    assert(!Senqueue(&queue1, 7));
    assert(!Sfront(&queue1, &x));
    assert(x == 7);
    assert(!Senqueue(&queue1, 1));
    assert(!Senqueue(&queue1, 8));
    // showQueue(&queue1);
    assert(!SisEmptyQ(&queue1));
    assert(!Sdequeue(&queue1, &x));
    // showQueue(&queue1);
    assert(!Sdequeue(&queue1, &x));
    assert(!Sdequeue(&queue1, &x));
    assert(Sdequeue(&queue1, &x));
    assert(SisEmptyQ(&queue1));
    for (i = 0; i < MAX - 1; i++)
        assert(!Senqueue(&queue1, i));
    // showQueue(&queue1);
    assert(!Senqueue(&queue1, 0));
    // showQueue(&queue1);

    /* Dinamic Stacks */

    SinitDStack(&dStack1);
    assert(dStack1.size == MAX && dStack1.sp == 0 && dStack1.values != NULL);
    assert(DSisEmpty(&dStack1));
    assert(!DSpush(&dStack1, 5));
    assert(!DSpush(&dStack1, 3));
    assert(!DStop(&dStack1, &x));
    assert(x == 3);
    assert(!DSpush(&dStack1, 7));
    assert(!DSpush(&dStack1, 1));
    // showDinStack(&dStack1);
    assert(!DSisEmpty(&dStack1));
    assert(!Dpop(&dStack1, &x));
    // showDinStack(&dStack1);
    assert(!Dpop(&dStack1, &x));
    assert(!Dpop(&dStack1, &x));
    assert(!Dpop(&dStack1, &x));
    assert(DSisEmpty(&dStack1));
    assert(Dpop(&dStack1, &x));
    for (i = 0; i < dStack1.size; i++)
        assert(!DSpush(&dStack1, i));
    // showDinStack(&dStack1);
    assert(!DSpush(&dStack1, 0));
    // showDinStack(&dStack1);
    assert(dStack1.size == 2 * MAX);
    assert(!DSpush(&dStack1, 1));
    assert(!DSpush(&dStack1, 3));
    // showDinStack(&dStack1);

    /* Dinamic Queues */

    SinitDQueue(&dQueue1);
    assert(dQueue1.size == MAX && dQueue1.length == 0 && dQueue1.front == 0 &&
           dQueue1.values != NULL);
    assert(SisEmptyDQ(&dQueue1));
    assert(!DSenqueue(&dQueue1, 4));
    assert(!DSenqueue(&dQueue1, 1));
    // showDinQueue(&dQueue1);
    assert(!DSenqueue(&dQueue1, 8));
    assert(!SisEmptyDQ(&dQueue1));
    assert(!DSfront(&dQueue1, &x));
    assert(x == 4);
    // showDinQueue(&dQueue1);
    assert(!DSdequeue(&dQueue1, &x));
    // showDinQueue(&dQueue1);
    assert(!DSdequeue(&dQueue1, &x));
    assert(!DSdequeue(&dQueue1, &x));
    assert(DSdequeue(&dQueue1, &x));
    assert(SisEmptyDQ(&dQueue1));
    for (i = 0; i < dQueue1.size; i++)
        assert(!DSenqueue(&dQueue1, i));
    // showDinQueue(&dQueue1);
    assert(!DSenqueue(&dQueue1, 0));
    assert(!DSenqueue(&dQueue1, 2));
    // showDinQueue(&dQueue1);
    assert(dQueue1.size == 2 * MAX);
    assert(!DSenqueue(&dQueue1, 7));
    // showDinQueue(&dQueue1);

    return 0;
}