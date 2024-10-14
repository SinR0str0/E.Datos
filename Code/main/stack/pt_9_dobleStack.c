#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "stack.h"

/*
   Print stack
*/

static void print_stack(const Stack *stack) {
	ListNode *node;
	int size, i;
	double *data;
	fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));

	i = 0;
	node = list_head(stack);

	while (i < size) {
		data = list_data(node);
		fprintf(stdout, "stack[%03d]=%lf, %p -> %p\n", i, *data, node, node->next);
		node = list_next(node);
	 	i++;
	}
	return;
}

int main(int argc, char const *argv[]) {
	Stack stack;
	int i;
	double *data;

	// Initialize the stack
	stack_init(&stack, free);

	for (i = 1; i < argc; i++) {
		if ((data = (double *)malloc(sizeof(double))) == NULL)
	    	return 1;

	   		*data = atof(argv[i]);

		if (stack_push(&stack, data) != 0)
	    	return 1;
	}
	print_stack(&stack);

	fprintf(stdout, "\nPopping 2 elements\n");
	for (i = 0; i < 2; i++) {
		if(stack_pop(&stack, (void **)&data) == 0)
			free(data);
		else
			return 1;
	}
	print_stack(&stack);

	fprintf(stdout, "\nPushing 9.75 and 3.141516\n");
	if ((data = (double *)malloc(sizeof(double))) == NULL)
		return 1;
	*data = 9.75;
	if (stack_push(&stack, data) != 0)
		return 1;

	if ((data = (double *)malloc(sizeof(double))) == NULL)
		return 1;
	*data = 3.141516;
	if (stack_push(&stack, data) != 0)
		return 1;
	print_stack(&stack);

	if ((data = stack_peek(&stack)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%.5lf\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_stack(&stack);

	fprintf(stdout, "\nPopping all elements\n");
	while (stack_size(&stack) > 0) {
		if (stack_pop(&stack, (void **)&data) == 0)
			free(data);
	}
	if ((data = stack_peek(&stack)) != NULL)
		fprintf(stdout, "\nPeeking at the top element [value]=%.5lf\n", *data);
	else
		fprintf(stdout, "\nPeeking at the top element [value]=NULL\n");
	print_stack(&stack);

	fprintf(stdout, "\nDestroying the stack\n");
	stack_destroy(&stack);
	return 0;
	
}
