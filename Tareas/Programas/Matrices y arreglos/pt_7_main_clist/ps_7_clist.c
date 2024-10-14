//Archivo main de CList
#include <stdio.h>
#include <stdlib.h>

#include "clist.h"

/*
   Print List
*/

static void print_clist (const CList *list) {
    CListNode *node;
    float *data; int i;

    fprintf(stdout, "List size is %d\n", clist_size(list));

    i = 0;
    node = clist_head(list);

    while (1) {
        data = (float*)clist_data(node);
        fprintf(stdout, "clist.node[%03d]=%.5f, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (i>=list->size)
            break;
        else
            node = clist_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    CList list;
    CListNode *node;

    float *data; int i; 
	
    // Initialize the linked list
    clist_init(&list, free);
	
    // Fill the linked list
    node = clist_head(&list);
    for (i = 1; i < argc; i++) {
		
        if ((data = (float *)malloc(sizeof(float))) == NULL)
            return 1;

        *data = (float) atof(argv[i]);
		
        if (clist_ins_next(&list, clist_head(&list), data) != 0)
            return 1;
        
    }

    print_clist(&list);

    node = clist_head(&list);

    for (i = 0; i < 3; ++i)
        node = clist_next(node);

    data = (float*)clist_data(node);
    fprintf(stdout, "\nRemoving the node containing %.5f\n", *data);

    if (clist_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_clist(&list);

    fprintf(stdout, "\nInserting 0.12 at next of the head of the list\n");
    if ((data = (float *)malloc(sizeof(float))) == NULL)
            return 1;
    *data=0.12;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;

    print_clist(&list);

    fprintf(stdout, "\nRemoving the next head.\n");
    if (clist_rem_next(&list, clist_head(&list), (void**)&data) != 0)
        return 1;
    print_clist(&list);

	node = clist_head(&list);
	for(i=0;i<4;i++){
		node = clist_next(node);
	}
    fprintf(stdout, "\nRemoving the 5th node.\n");
    if (clist_rem_next(&list, node, (void**)&data) != 0)
        return 1;
    print_clist(&list);    
    
    fprintf(stdout, "\nInsert 9.75 at the next to the head of the list\n");
    if ((data = (float *)malloc(sizeof(float))) == NULL)
            return 1;
    *data=9.75;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;
    print_clist(&list);    

    fprintf(stdout, "\nIterating and removing the third node\n");

    node = clist_head(&list);
    node = clist_next(node);
    node = clist_next(node);

    if (clist_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_clist(&list);

    fprintf(stdout, "\nInserting 0 after the first node\n");
    if ((data = (float *)malloc(sizeof(float))) == NULL)
            return 1;
    *data = 0;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;
    print_clist(&list);
    
    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    clist_destroy(&list);

    return 0;
}
