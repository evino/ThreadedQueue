#include "queue.h"

struct queue {
    size_t capacity;  // Maximum Capacity of Queue
    int *arr;         // Array holding ints for Queue
    size_t front;     // Front position in Queue
    // size_t back;
    size_t size;      // Current size of Queue
};

queue_t *NewQueue(size_t capacity) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->arr = malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->size = 0;

    return queue;
}

void DeleteQueue(queue_t **queue) {
    if (queue != NULL && *queue != NULL) {
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

    int frontValue = queue->arr[queue->front];
    return frontValue;
}


