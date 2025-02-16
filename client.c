#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv) {
    printf("Hello world!\n");

    // Create new queue
    queue_t *q = NewQueue(10);

    for (int i = 1; i <= 11; i++) {
        printf("Trying to queue %d. ", i);
        if (Enqueue(q, i)) {
            printf("%d queued\n", i);
        } else {
            printf("Can't enqueue %d, queue is full\n", i);
        }
    }
    int q_FrontVal = GetFront(q);

    
    for (int i = 1; i <= 11; i++) {
        printf("Trying to dequeue %d. ", i);
        if (Dequeue(q) != -999) {
            printf("%d queued\n", i);
        } else {
            printf("Can't dequeue since queue is empty\n");
        }
    }

    printf("Val at front of q is %d\n", q_FrontVal);

    DeleteQueue(&q);

    return 0;
}
