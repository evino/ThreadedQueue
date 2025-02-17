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
    queue_t *q = NewQueue(1);

    int testVal1 = 1;
    pthread_t t1;
    struct Push_Args *thread1Args = malloc(sizeof(thread1Args));
    thread1Args->q = q;
    thread1Args->val = testVal1;
    pthread_create(&t1, NULL, Push, (void *) thread1Args);
    void *returnVal1;

    int testVal2 = 2;
    pthread_t t2;
    struct Push_Args *thread2Args = malloc(sizeof(thread2Args));
    thread2Args->q = q;
    thread2Args->val = testVal2;
    pthread_create(&t2, NULL, Push, (void *) thread2Args);
    void *returnVal2;

    pthread_t t3;
    struct Pop_Args *thread3Args = malloc(sizeof(thread3Args));
    thread3Args->q = q;
    pthread_create(&t3, NULL, Pop, (void *) thread3Args);
    void *returnVal3;

    pthread_join(t1, &returnVal1);
    pthread_join(t2, &returnVal2);
    pthread_join(t3, &returnVal3);

    free(thread1Args);
    free(thread2Args);
    free(thread3Args);


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

    printf("Queue size is now %ld\n", GetSize(q));
    DeleteQueue(&q);

    return 0;
}
