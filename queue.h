#pragma once
#include <stdlib.h>

typedef struct queue queue_t;

/**
 * @brief Get front value from queue
 * 
 * @param queue_t* Pointer to the queue
 * 
 * @return int Value at front of queue
 */
int GetFront();

/**
 * @brief Get back value from queue
 * 
 * @param queue_t* Pointer to the queue
 * 
 * @return int Value at back of queue
 */
int GetBack();
