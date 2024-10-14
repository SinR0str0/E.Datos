//EJERCICIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "queue.h"

/*
   Print queue
*/

static void print_queue(const Queue *list) {
	ListNode *node;
	int size, i;
	char **data;
	fprintf(stdout, "Queue size is %d\n", size = queue_size(list));

	i = 0;
	node = list_head(list);

	while (i < size) {
		*data = list_data(node);
		fprintf(stdout, "queue[%03d]=%s, %p -> %p\n", i, *data, node, node->next);
		node = list_next(node);
	 	i++;
	}
	return;
}

int main(int argc, char const *argv[]) {
	Queue queue;
	int i;
	char **data;

	// Initialize the queue
	queue_init(&queue, free);

	for (i = 1; i < argc; i++) {
		if ((data = (char **)malloc(sizeof(char*))) == NULL)
	    	return 1;

	   	*data = argv[i];
		printf("\n Dato es: %s", *data);
		if (queue_enqueue(&queue, *data) != 0)
	    	return 1;
	}
	print_queue(&queue);

	fprintf(stdout, "\nPopping 2 elements\n");
	for (i = 0; i < 2; i++) {
		if(queue_dequeue(&queue, (void **)&data) == 0)
			free(data);
		else
			return 1;
	}
	print_queue(&queue);

	fprintf(stdout, "\nPushing \"Hola\" and \"*133\"\n");
	if ((data = (char **)malloc(sizeof(char *))) == NULL)
		return 1;
	*data = "Hola";
	if (queue_enqueue(&queue, data) != 0)
		return 1;

	if ((data = (char **)malloc(sizeof(char*))) == NULL)
		return 1;
	*data = "*133";
	if (queue_enqueue(&queue, data) != 0)
		return 1;
	print_queue(&queue);

	if ((data = queue_peek(&queue)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%s\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_queue(&queue);

	fprintf(stdout, "\nPopping all elements\n");
	while (queue_size(&queue) > 0) {
		if (queue_dequeue(&queue, (void **)&data) == 0)
			free(data);
	}
	if ((data = queue_peek(&queue)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%.5lf\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_queue(&queue);

	fprintf(stdout, "\nDestroying the queue\n");
	queue_destroy(&queue);
	return 0;
	
}
