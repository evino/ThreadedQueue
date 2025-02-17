#include "queue.h"


struct queue {
    size_t capacity;  // Maximum Capacity of Queue
    size_t frontPos;     // Front position in Queue
    size_t size;      // Current size of Queue
    int *arr;         // Array holding ints for Queue
    pthread_mutex_t lock;
    pthread_cond_t enqueueCV;
    pthread_cond_t dequeueCV;
};

queue_t *NewQueue(size_t capacity) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->arr = malloc(sizeof(int) * capacity);
    queue->frontPos = 0;
    queue->size = 0;
    if (pthread_mutex_init(&(queue->lock), NULL) != 0) {
        printf("Error initializing mutex\n");
    }

    if (pthread_cond_init(&(queue->enqueueCV), NULL) != 0) {
        printf("Error with CV init for enqueue\n");
    }

    if (pthread_cond_init(&(queue->dequeueCV), NULL) != 0) {
        printf("Error with CV init for dequeue\n");
    }

    return queue;
}

// Make sure to destroy mutex here
void DeleteQueue(queue_t **queue) {
    if (queue != NULL && *queue != NULL) {
        pthread_cond_destroy(&((*queue)->enqueueCV));
        pthread_cond_destroy(&((*queue)->dequeueCV));
        pthread_mutex_destroy(&((*queue)->lock));

        free((*queue)->arr);
        (*queue)->arr = NULL;
        free(*queue);
        *queue = NULL;
    }


    
    return;
}

int GetFront(queue_t *queue) {
    if (queue->size == 0) {
        return -999;
    }

    int frontValue = queue->arr[queue->frontPos];
    return frontValue;
}

bool Enqueue(queue_t* queue, int value) {
    fprintf(stdout, "Enqueue() called\n");
    pthread_mutex_lock(&(queue->lock));
    fprintf(stdout, "After mutex lock in Enqueue()\n");



    if (queue->size == queue->capacity) {
        printf("waiting on CV in Enqueue()\n");
        pthread_cond_wait(&(queue->enqueueCV), &(queue->lock));
        
        printf("After cv signal sent\n");
        // return false;
    }

    fprintf(stdout, "Starting enqueue operation\n");
    size_t rearPos = (queue->frontPos + queue->size) % queue->capacity;
    queue->arr[rearPos] = value;
    queue->size++;
    pthread_mutex_unlock(&(queue->lock));
    pthread_cond_signal(&(queue->dequeueCV));
    fprintf(stdout, "Enque of %d done\n", value);
    return true;
}


int Dequeue(queue_t* queue) {
    pthread_mutex_lock(&(queue->lock));

    if (queue->size == 0) {
        pthread_cond_wait(&(queue->dequeueCV), &(queue->lock));
        fprintf(stdout, "Waiting on CV in Dequeue()\n");
        // return -999;
    }

    fprintf(stdout, "Starting dequeue operation\n");
    int frontVal = queue->arr[queue->frontPos];
    queue->frontPos = (queue->frontPos + 1) % queue->capacity;
    queue->size--;
    pthread_mutex_unlock(&(queue->lock));
    pthread_cond_signal(&(queue->enqueueCV));

    fprintf(stdout, "Done dequeuing %d\n", frontVal);
    return frontVal;
}

size_t GetSize(queue_t* queue) {
    return queue->size;
}

