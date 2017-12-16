/* =========================================================================
 * First Come First Serve Scheduling
 * =========================================================================
 */

#include <string.h>
#include "queue.h"

//void fcfs(int);                /* to implement first come first serve scheduling */
//void turn_around(int, int [], int []);        /* to calculate turn around time */
void read_file(char *filename);
void update_states();
void check_running_state();
void update_blocking(minHeap *hp);
void update_queue(minHeap *hp);
int sort_queue();

minHeap processes_heap;
minHeap finished_heap;
minHeap blocked_heap;
queue ready_queue;
int simulation_time = 0;
int busy_cycles = 0;
int count = 0;


int main() {


    read_file("/Users/macpro/Downloads/Assignmet_4/sample/sample");
    //display_blocked_states(&processes_heap);

//    display(&ready_queue);
//    for (int j = 0; j < count; ++j) {
//        printf("%d \n", blocked_heap[j].pid);
//    }
    //display(&blocked_heap);
    while(viewMinimum(&processes_heap).arrival_time > simulation_time){
        printf("%d:\n",simulation_time);
        simulation_time++;
    }

    update_queue(&processes_heap);

    while(!isEmpty(&ready_queue) || !isEmptyHeap(&processes_heap) || !isEmptyHeap(&blocked_heap)){
        update_blocking(&blocked_heap);
        update_states();
        check_running_state();
        if(!isEmpty(&ready_queue) || !isEmptyHeap(&blocked_heap)){
            printf("%d: ",simulation_time);
            busy_cycles += display_states(&ready_queue);
            display_blocked_states(&blocked_heap);
            simulation_time++;
            printf("\n");
        }
        update_queue(&processes_heap);
    }

    printf("Finishing Time: %d\n", simulation_time-1);
    printf("CPU Utilization: %.2f\n", (1.0*busy_cycles)/(1.0*simulation_time));
//    for (int i = 0; i < finished_heap.size; i++)
//        printf("Turnaround Time of Process: %d: %d\n", finished_heap.elem[i].pid, finished_heap.elem[i].turnaround_time);

    return 0;
}

void update_states(){

    if (!isEmpty(&ready_queue)){
        //if(ready_queue.queue_array[ready_queue.front].arrival_time <= simulation_time)
        if(!isEmpty(&ready_queue) && ready_queue.queue_array[ready_queue.front].arrival_time <= simulation_time)
            ready_queue.queue_array[ready_queue.front].state = 'R';
    }
}

void check_running_state(){
    if (!isEmpty(&ready_queue)){
        if(((ready_queue.queue_array[ready_queue.front].time_taken < ready_queue.queue_array[ready_queue.front].burst_time)
                && ready_queue.queue_array[ready_queue.front].state == 'R') ||
                (ready_queue.queue_array[ready_queue.front].blocked &&
                        ready_queue.queue_array[ready_queue.front].time_taken <
                                ready_queue.queue_array[ready_queue.front].burst_time + ready_queue.queue_array[ready_queue.front].io_time))
            ready_queue.queue_array[ready_queue.front].time_taken ++;
        else{
            if(ready_queue.queue_array[ready_queue.front].io_time != 0){
                node temp = getNext(&ready_queue);
                temp.turnaround_time = simulation_time - temp.turnaround_time +1;
                insertNode(&finished_heap,temp.arrival_time,temp.burst_time,temp.io_time,temp.pid,temp.time_taken,
                           temp.state,temp.blocked,temp.turnaround_time);
//                if(isEmpty(&ready_queue) && isEmptyHeap(&processes_heap) && isEmptyHeap(&blocked_heap))
//                    printf("%d: process: %d --> %c\n",simulation_time,temp.pid,temp.state);
                if(temp.time_taken == temp.burst_time+temp.io_time)
                    ready_queue.queue_array[ready_queue.front].time_taken++;
                if(!temp.blocked){
                    temp.blocked = true;
                    temp.state = 'B';
                    temp.arrival_time = simulation_time + temp.io_time;
                    insertNode(&blocked_heap,temp.arrival_time,temp.burst_time,temp.io_time,temp.pid,temp.time_taken,
                               temp.state,temp.blocked,temp.turnaround_time);
                }
            }else if(ready_queue.queue_array[ready_queue.front].io_time == 0 &&
                    ready_queue.queue_array[ready_queue.front].time_taken > ready_queue.queue_array[ready_queue.front].burst_time*2){
                getNext(&ready_queue);
                ready_queue.queue_array[ready_queue.front].time_taken++;
            }
            else
                ready_queue.queue_array[ready_queue.front].time_taken++;
            if(!isEmpty(&ready_queue) && ready_queue.queue_array[ready_queue.front].arrival_time <= simulation_time)
                ready_queue.queue_array[ready_queue.front].state = 'R';
        }
    }
}

void update_blocking(minHeap *hp){
    if(!isEmptyHeap(&blocked_heap)) {
        if (hp->elem[0].arrival_time <= simulation_time) {
            node temp = getMinimum(&blocked_heap);
            temp.state = 'Y';
            insert(&ready_queue, temp);
            if(!sort_queue())
                ready_queue.queue_array[ready_queue.front].time_taken++;
        } else
            hp->elem[0].time_taken++;
    }
}

void update_queue(minHeap *hp){
    if(!isEmptyHeap(&processes_heap)){
        node next = viewMinimum(hp);
        for (int i = 0; i < hp->size; i++) {
            if(next.arrival_time <= simulation_time) {
                next.state = 'Y';
                next.turnaround_time = next.arrival_time;
                insert(&ready_queue, next);
                getMinimum(hp);
            }
            next = viewMinimum(hp);
        }
    }
}

int sort_queue(){
    node temp;
    int flag = 0;
    if (!isEmpty(&ready_queue)){
        for (int i = ready_queue.front; i <= ready_queue.rear; i++)
            if(ready_queue.queue_array[i].state == 'Y')
                flag ++;
    }

    if (!isEmpty(&ready_queue) && flag >= 2 && ready_queue.queue_array[ready_queue.front].state!= 'R'){
        for(int i = ready_queue.front ; i < ready_queue.rear ; i++) {
            for(int j = i+1 ; j < ready_queue.rear +1 ; j++) {
                if(ready_queue.queue_array[i].pid > ready_queue.queue_array[j].pid) {
                    temp = ready_queue.queue_array[i] ;
                    ready_queue.queue_array[i]  = ready_queue.queue_array[j];
                    ready_queue.queue_array[j] = temp;
                }
            }
        }
        return 1;
    }
    return 0;
}

void read_file(char *filename) {
    FILE *fp;
    char *line = NULL, *times[4];
    size_t len = 0;
    int heap_size = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while (getline(&line, &len, fp) != -1) {
        heap_size++;
    }
    fclose(fp);

    processes_heap = initMinHeap(heap_size);
    finished_heap = initMinHeap(heap_size);
    blocked_heap = initMinHeap(heap_size);
    ready_queue = initQueue(heap_size);

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while (getline(&line, &len, fp) != -1) {
        int i = 0;
        char *pch;
        pch = strtok(line, "  \n");
        while (pch != NULL) {
            times[i++] = pch;
            pch = strtok(NULL, "  \n");
        }
        insertNode(&processes_heap, atoi(times[3]), atoi(times[1]), atoi(times[2]), atoi(times[0]),0,NULL,false,0);
    }
    fclose(fp);
    if (line)
        free(line);

}




///* fcfs : to implement first come first serve scheduling */
////void fcfs(int size) {
////    int i, j, result;
////    int arrival[size], burst[size], waiting[size];
////
////    for (i = 0; i < size; ++i)
////        waiting[i] = 0;    /* initialize all values with 0 */
////
////    /* input the arrival time and burst time for each process */
////    for (i = 0; i < size; ++i) {
////        printf("\nEnter arrival time for process %d : ", i + 1);
////        scanf("%d", &arrival[i]);
////
////        printf("Enter burst time for process %d : ", i + 1);
////        scanf("%d", &burst[i]);
////    }
////
////    /* first come first serve */
////    for (i = 1; i < size; ++i) {
////        result = 0;
////        for (j = 0; j < i; ++j)
////            result += burst[j];
////        waiting[i] = result - arrival[i];    /* waiting time = starting time - arrival time */
////    }
////
////    /* print the waiting time */
////    printf("\nWaiting Time:\t");
////    for (i = 0; i < size; ++i)
////        printf("%d\t", waiting[i]);
////
////    /* average waiting time */
////    for (i = 0; i < size; ++i) result += waiting[i];
////
////    result /= size;
////
////    printf("\nAverage Waiting Time:\t%d", result);
////
////    /* turn around time */
////    turn_around(size, burst, waiting);
////
////    printf("\n");
////}
////
/////* turn_around : to calculate turn around time for each process */
////void turn_around(int size, int burst[], int waiting[]) {
////    int i;
////    int turn_around_time[size];
////
////    for (i = 0; i < size; ++i)
////        turn_around_time[i] = burst[i] + waiting[i];    /* turn around time = burst time + waiting time */
////
////    printf("\nTurn Around Time:\t");
////    for (i = 0; i < size; ++i)
////        printf("%d\t", turn_around_time[i]);
////}