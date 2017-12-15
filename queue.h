//
// Created by MacPro on 12/11/17.
//

#ifndef FSCHEDULER_QUEUE_H
#define FSCHEDULER_QUEUE_H

#include "minHeap.h"

#define MAX 50

typedef struct queue {
    int size, rear, front;
    node queue_array[20];
} queue;


queue initQueue(int size);

void insert(queue *q, node item);

node getNext(queue *q);

node viewNext(queue *q);

int isEmpty(queue *q);

void update_arrival_time(node *nd);

void display(queue *q);

void display_states(queue *q);

#endif //FSCHEDULER_QUEUE_H
