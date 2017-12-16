//
// Created by MacPro on 12/11/17.
//

#include "queue.h"

queue initQueue(int size) {
    queue q;
    q.size = size;
    q.front = -1;
    q.rear = -1;
    return q;
}


void insert(queue *q, node item) {
    if (q->rear == MAX - 1)
        printf("Queue Overflow \n");
    else {
        if (q->front == -1)
            /*If queue is initially empty */
            q->front = 0;
        q->rear = q->rear + 1;
        q->queue_array[q->rear] = item;
    }
}

node getNext(queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow \n");
    } else {
        node nd = q->queue_array[q->front];
        //printf("Element deleted from queue is : %d\n", q->queue_array[q->front].pid);
        q->front = q->front + 1;
        return nd;
    }
}

node viewNext(queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow \n");
    } else {
        node nd = q->queue_array[q->front];
        //printf("Element at top of queue is : %d\n", q->queue_array[q->front].pid);
        return nd;
    }
}

int isEmpty(queue *q) {
    if (q->front == -1 || q->front > q->rear)
        return 1;
    else
        return 0;
}

void update_arrival_time(node *nd) {
    nd->arrival_time += (nd->burst_time + nd->io_time);
}

void display(queue *q) {
    if (q->front == -1 || q->front > q->rear)
        printf("Queue is empty \n");
    else {
        printf("Queue is : \n");
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->queue_array[i].pid);
        printf("\n");
    }
}

int display_states(queue *q) {
    if (!isEmpty(q)){
        for (int i = q->front; i <= q->rear; i++){
            if(q->queue_array[i].state != NULL)
                printf("process: %d --> %c\t",q->queue_array[i].pid, q->queue_array[i].state);
            if(q->queue_array[i].state == 'R')
                return 1;
        }
    }
    return 0;
}
