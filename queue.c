#include "queue.h"

struct queue {
    size_t capacity;  // Maximum Capacity of Queue
    int *arr;         // Array holding ints for Queue
    size_t frontPos;     // Front position in Queue
    // size_t rear;
    size_t size;      // Current size of Queue
};

queue_t *NewQueue(size_t capacity) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->arr = malloc(sizeof(int) * capacity);
    queue->frontPos = 0;

    // Shouldn't need actually
    // queue->rear = 0;  // Double check that this should be 0, not 1


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

    int frontValue = queue->arr[queue->frontPos];
    return frontValue;
}

bool Enqueue(queue_t* queue, int value) {
    if (queue->size == queue->capacity) {
        return false;
    }

    size_t rearPos = (queue->frontPos + queue->size) % queue->capacity;
    queue->arr[rearPos] = value;
    queue->size++;
    return true;
}


int Dequeue(queue_t* queue) {
    if (queue->size == 0) {
        return -999;
    }

    int frontVal = queue->arr[queue->frontPos];
    queue->frontPos = (queue->frontPos + 1) % queue->capacity;
    queue->size--;
    return frontVal;
}

