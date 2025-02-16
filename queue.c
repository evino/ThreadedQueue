#include "queue.h"

struct queue {
    int *arr;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
};

