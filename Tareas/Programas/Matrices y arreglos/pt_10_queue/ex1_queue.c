//Archivo main de queue
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
//#include "queue.c"

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
		
        if (queue_enqueue(&list, data) != 0)
            return 1;
        fprintf(stdout, "\n Se ha agregado el elemento %03d\n", *data);
    }
	
	queue_dequeue(&list, data);
	data=queue_peek(&list);
    fprintf(stdout, "\nRemoviendo la cabeza, nueva cabeza: %03d\n", *data);
	

    
    
    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    queue_destroy(&list);

    return 0;
}
