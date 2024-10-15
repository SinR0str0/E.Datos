//Actividad de int a char para DList
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/*
   Print DList
*/

static void print_dlist (const DList *list) {
    DListNode *node;
    char *data; int i;

    fprintf(stdout, "List size is %d\n", dlist_size(list));

    i = 0;
    node = dlist_head(list);

    while (1) {
        data = dlist_data(node);
        fprintf(stdout, "dlist.node[%03d]=%c, %p -> %p -> %p \n", i, *data, node->prev, node, node->next);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    DList list;
    DListNode *node;

    char *data; int i;
	
    // Initialize the linked list
    dlist_init(&list, free);
	
    // Fill the linked list
    node = dlist_head(&list);
    for (i = 1; i < argc; i++) {
		
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;
		*data = argv[i][0];
        //*data = 92+i;
		
        if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
            return 1;
        
    }

    print_dlist(&list);

    node = dlist_head(&list);
    for (i = 0; i < argc/2; ++i)
        node = dlist_next(node);
    data = dlist_data(node);
    
    fprintf(stdout, "\nRemoving the node containing %c\n", *data);

    if (dlist_remove(&list, node, (void**)&data) != 0)
        return 1;

    print_dlist(&list);

    fprintf(stdout, "\nInserting \"a\" at the tail of the list\n");
    *data = 'a';
    if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
        return 1;

    print_dlist(&list);

    fprintf(stdout, "\nRemoving the head.\n");
    if (dlist_remove(&list, dlist_head(&list), (void**)&data) != 0)
        return 1;
    print_dlist(&list);

    fprintf(stdout, "\nRemoving the tail node.\n");
    if (dlist_remove(&list, dlist_tail(&list), (void**)&data) != 0)
        return 1;
    print_dlist(&list);    
    
    fprintf(stdout, "\nInsert \"?\" at the next to the head of the list\n");
    *data = '?';
    if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
        return 1;
    print_dlist(&list);    
	if(dlist_size(&list)>=3){
	
    	fprintf(stdout, "\nIterating and removing the third node\n");

	    node = dlist_head(&list);
    	node = dlist_next(node);
    	node = dlist_next(node);

    	if (dlist_remove(&list, node, (void **)&data) != 0)
        	return 1;

    	print_dlist(&list);
	}
    fprintf(stdout, "\nInserting \"0\" after the first node\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
    	return 1;
	*data = '0';
    if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
        return 1;
    print_dlist(&list);

    i = dlist_is_head(dlist_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&list);

    return 0;
}
