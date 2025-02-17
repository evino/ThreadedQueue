#include <stdio.h>
#include "queue.h"

struct Pop_Args {
    queue_t *q;
};

struct Push_Args {
    queue_t *q;
    int val;
};

void *Pop(void *args) {
    struct Pop_Args *popArgs = (struct Pop_Args *) args;
    // popArgs->q = args->q;
    Dequeue(popArgs->q);

    return NULL;
}

void *Push(void *args) {
    struct Push_Args *pushArgs = (struct Push_Args *) args;
    // popArgs->q = args->q;
    Enqueue(pushArgs->q, pushArgs->val);

    return NULL;
}

int main(int argc, char **argv) {

    printf("Hello world!\n");

    // Create new queue
    queue_t *q = NewQueue(10);

    int testVal = 1;
    pthread_t t2;
    struct Push_Args *thread2Args = malloc(sizeof(thread2Args));
    thread2Args->q = q;
    thread2Args->val = testVal;
    pthread_create(&t2, NULL, Push, (void *) thread2Args);
    void *returnVal2;

    pthread_t t3;
    struct Pop_Args *thread3Args = malloc(sizeof(thread3Args));
    thread3Args->q = q;
    pthread_create(&t3, NULL, Pop, (void *) thread3Args);
    void *returnVal3;

    fprintf(stdout, "Before enqueue test\n");
    // Enqueue Test
    // for (int i = 1; i <= 11; i++) {
    //     fprintf(stdout, "db\n");
    //     printf("Trying to queue %d. ", i);
    //     thread2Args->val = i;
    //     pthread_join(t2, &returnVal2);
    //     // if (Enqueue(q, i)) {
    //     //     printf("%d queued\n", i);
    //     // } else {
    //     //     printf("Can't enqueue %d, queue is full\n", i);
    //     // }
    // }

    fprintf(stdout, "db\n");
    fprintf(stdout, "Trying to queue %d\n", testVal);
    pthread_join(t3, &returnVal3);
    pthread_join(t2, &returnVal2);

    // int q_FrontVal = GetFront(q);




    // Dequeue(q);
    
    // Dequeue Test
    // for (int i = 1; i <= 11; i++) {
    //     printf("Trying to dequeue %d. ", i);
    //     if (Dequeue(q) != -999) {
    //         printf("%d queued\n", i);
    //     } else {
    //         printf("Can't dequeue since queue is empty\n");
    //     }
    // }

    // printf("Val at front of q is %d\n", q_FrontVal);

    DeleteQueue(&q);

    return 0;
}
