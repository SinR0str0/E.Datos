/*
    queue.c
*/
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "list.h"

/*
    Insert next node at the queue
*/
int queue_enqueue (Queue *queue, const void *data) {
    list_ins_next(queue,NULL,data);
    return 0;
}

/*
    Remove node at the queue
*/
int queue_dequeue (Queue *queue, void **data) {
	list_rem_next(queue, NULL, data);
	
    return 0;
}

