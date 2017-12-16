//
// Created by MacPro on 12/11/17.
//

#ifndef FSCHEDULER_HEAP_H
#define FSCHEDULER_HEAP_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node {
    int arrival_time, burst_time, pid, io_time, time_taken, turnaround_time;
    bool blocked;
    char state;
} node;

typedef struct minHeap {
    int size;
    node *elem;
} minHeap;

minHeap initMinHeap(int size);

void swap(node *n1, node *n2);

void heapify(minHeap *hp, int i);

void buildMinHeap(minHeap *hp, int *arr, int size);

void insertNode(minHeap *hp, int a_time, int b_time, int io_time, int pid, int time_taken, char state, bool blocked, int turn_time);

node getMinimum(minHeap *hp);

node viewMinimum(minHeap *hp);

void deleteMinHeap(minHeap *hp);

int isEmptyHeap(minHeap *hp);

void display_blocked_states(minHeap *hp);

#endif //FSCHEDULER_HEAP_H
