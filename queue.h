#pragma once
#include <stdlib.h>

typedef struct queue queue_t;

/**
 * @brief Constructor for a new circular queue
 * 
 * @param size_t Maximum capacity of queue
 * 
 * @return queue_t* Pointer to new queue
 */
queue_t *NewQueue(size_t capacity);

/**
 * @brief Destructor for circular queue
 * 
 * @param queue_t** Address of queue_t* to delete
 * 
 * @return void
 */
void DeleteQueue(queue_t **q);

/**
 * @brief Get front value from queue
 * 
 * @param queue_t* Pointer to the queue
 * 
 * @return size_t Value at front of queue
 */
int GetFront(queue_t* queue);

/**
 * @brief Get back value from queue
 * 
 * @param queue_t* Pointer to the queue
 * 
 * @return int Value at back of queue
 */
int GetBack();
