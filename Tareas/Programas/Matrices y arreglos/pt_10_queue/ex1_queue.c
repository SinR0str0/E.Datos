//Archivo main de queue
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "queue.c"
/*
   Print List
*/

static void print_queue (const Queue *list) {
	queue_peek(list);
	return;
}


int main (int argc, char **argv) {
    Queue list;

    int *data, i;
	
    // Initialize the linked list
    queue_init(&list, free);
	
    // Fill the linked list
    for (i = 20; i > 10; i--) {
		
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;
		
        if (enqueue(&list, data) != 0)
            return 1;
        fprintf(stdout, "\n Se ha agregado el elemento %03d\n", *data);
    }
	
	
    fprintf(stdout, "\nRemoviendo la cabeza, nueva cabeza:\n", *data);
    print_queue(&list);

    
    
    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    queue_destroy(&list);

    return 0;
}
