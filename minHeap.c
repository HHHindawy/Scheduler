//
// Created by MacPro on 12/11/17.
//

#include "minHeap.h"

minHeap initMinHeap(int size) {
    minHeap hp;
    hp.size = 0;
    return hp;
}

void swap(node *n1, node *n2) {
    node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(minHeap *hp, int i) {
    int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].arrival_time <= hp->elem[i].arrival_time) ? LCHILD(i)
                                                                                                          : i;
    if (RCHILD(i) < hp->size && hp->elem[RCHILD(i)].arrival_time <= hp->elem[smallest].arrival_time) {
        smallest = RCHILD(i);
    }
    if (smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest]));
        heapify(hp, smallest);
    }
}

/*
    Build a Min Heap given an array of numbers
    Instead of using insertNode() function n times for total complexity of O(nlogn),
    we can use the buildMinHeap() function to build the heap in O(n) time
*/
void buildMinHeap(minHeap *hp, int *arr, int size) {
    int i;

    // Insertion into the heap without violating the shape property
    for (i = 0; i < size; i++) {
        if (hp->size) {
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node));
        } else {
            hp->elem = malloc(sizeof(node));
        }
        node nd;
        nd.arrival_time = arr[i];
        hp->elem[(hp->size)++] = nd;
    }

    // Making sure that heap property is also satisfied
    for (i = (hp->size - 1) / 2; i >= 0; i--) {
        heapify(hp, i);
    }
}

void insertNode(minHeap *hp, int a_time, int b_time, int io_time, int pid, int time_taken, char state, bool blocked) {
    if (hp->size) {
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node));
    } else {
        hp->elem = malloc(sizeof(node));
    }

    node nd;
    nd.arrival_time = a_time;
    nd.burst_time = b_time;
    nd.io_time = io_time;
    nd.pid = pid;
    nd.time_taken = time_taken;
    nd.state = state;
    nd.blocked = blocked;

    int i = (hp->size)++;
    while (i && nd.arrival_time < hp->elem[PARENT(i)].arrival_time) {
        hp->elem[i] = hp->elem[PARENT(i)];
        i = PARENT(i);
    }
    hp->elem[i] = nd;
}

node getMinimum(minHeap *hp) {
    if (hp->size) {
        node nd;
        //printf("Process With Minimum Arrival Time %d\n", hp->elem[0].pid) ;
        nd = hp->elem[0];
        hp->elem[0] = hp->elem[--(hp->size)];
        hp->elem = realloc(hp->elem, hp->size * sizeof(node));
        heapify(hp, 0);
        return nd;
    } else {
        //printf("\nMin Heap is empty!\n");
        free(hp->elem);
    }
}

node viewMinimum(minHeap *hp) {
    if (hp->size) {
        node nd;
        //printf("Process With Minimum Arrival Time %d\n", hp->elem[0].pid) ;
        nd = hp->elem[0];
        return nd;
    } else {
        //printf("\nMin Heap is empty!\n");
        free(hp->elem);
    }
}

void deleteMinHeap(minHeap *hp) {
    free(hp->elem);
}

int isEmptyHeap(minHeap *hp) {
    if(!hp->size)
        return 1;
    else return 0;
}

void display_blocked_states(minHeap *hp) {
    for (int i = 0; i < hp->size; i++)
        printf("process: %d --> %c\t", hp->elem[i].pid, hp->elem[i].state);
}