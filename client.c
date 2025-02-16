#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv) {
    printf("Hello world!\n");

    // Create new queue
    queue_t *q = NewQueue(10);
    int q_FrontVal = GetFront(q);
    printf("Val at front of q is %d\n", q_FrontVal);

    DeleteQueue(&q);

    return 0;
}
