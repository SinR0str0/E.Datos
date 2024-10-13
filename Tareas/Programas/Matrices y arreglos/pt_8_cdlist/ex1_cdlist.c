//Archivo main de CDList
#include <stdio.h>
#include <stdlib.h>

#include "cdlist.h"
//#include "cdlist.c"
/*
   Print List
*/

static void print_cdlist (const CDList *list) {
    CDListNode *node;
    int *data, i;

    fprintf(stdout, "List size is %d\n", cdlist_size(list));

    i = 0;
    node = cdlist_head(list);

    while (1) {
        data = cdlist_data(node);
        fprintf(stdout, "clist.node[%03d]=%03d, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (i>=list->size)
            break;
        else
            node = cdlist_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    CDList list;
    CDListNode *node;

    int *data, i;
	
    // Initialize the linked list
    cdlist_init(&list, free);
	
    // Fill the linked list
    node = cdlist_head(&list);
    for (i = 20; i > 10; i--) {
		
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;
		
        if (cdlist_ins_next(&list, cdlist_head(&list), data) != 0)
            return 1;
        
    }

    print_cdlist(&list);

    node = cdlist_head(&list);

    for (i = 0; i < 7; ++i)
        node = cdlist_next(node);

    data = cdlist_data(node);
    fprintf(stdout, "\nRemoving the node containing %03d\n", *data);

    if (cdlist_remove(&list, node, (void**)&data) != 0)
        return 1;

    print_cdlist(&list);

    fprintf(stdout, "\nInserting 187 at before of the head of the list\n");
    *data = 187;
    if (cdlist_ins_prev(&list, cdlist_head(&list), data) != 0)
        return 1;

    print_cdlist(&list);

    fprintf(stdout, "\nRemoving the head.\n");
    if (cdlist_remove(&list, cdlist_head(&list), (void**)&data) != 0)
        return 1;
    print_cdlist(&list);

	node = cdlist_head(&list);
	for(i=0;i<5;i++){
		node = cdlist_next(node);
	}
    fprintf(stdout, "\nRemoving the 5th node.\n");
    if (cdlist_remove(&list, node, (void**)&data) != 0)
        return 1;
    print_cdlist(&list);    
    
    fprintf(stdout, "\nInsert 975 at the next to the head of the list\n");
    *data = 975;
    if (cdlist_ins_next(&list, cdlist_head(&list), data) != 0)
        return 1;
    print_cdlist(&list);    

    fprintf(stdout, "\nIterating and removing the second node\n");

    node = cdlist_head(&list);
    node = cdlist_next(node);
    node = cdlist_next(node);

    if (cdlist_remove(&list, node, (void **)&data) != 0)
        return 1;

    print_cdlist(&list);

    fprintf(stdout, "\nInserting 607 after the first node\n");
    *data = 607;
    if (cdlist_ins_next(&list, cdlist_head(&list), data) != 0)
        return 1;
    print_cdlist(&list);
    
    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    cdlist_destroy(&list);

    return 0;
}
