/*
    clist.c
*/
#include <stdlib.h>
#include <string.h>

#include "clist.h"

/*
    Initialize the clist
*/
void clist_init (CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;    
}

/*
    Destroying the clist
*/
void clist_destroy (CList *list) {
    void *data;

    while (clist_size(list) > 0) {
        if (clist_rem_next(list, clist_head(list), (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }    
    memset(list, 0, sizeof(CList));
    return;
}

/*
    Insert next node at the clist
*/
int clist_ins_next (CList *list, CListNode *node, const void *data ) {
    CListNode    *new_node;

    // Do not allow a NULL node unless the list is empty
    if (node == NULL && clist_size(list) != 0)
        return -1;

    if ((new_node = (CListNode *)malloc(sizeof(CListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    // The list is empty, insert at the head
    if (clist_size(list) == 0){
        new_node->next = new_node;
        list->head = new_node;
        
    } else {
        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;

    return 0;
}

/*
    Remove node at the List
*/
int clist_rem_next (CList *list, CListNode *node, void **data) {
	CListNode *old_node;

    // Check if is not empty the list
    if (clist_size(list) == 0)
        return -1;
    
    // Handle removal from head of the list 
    if (node->next == node) {
        *data = list->head->data;
        old_node = node;
        list->head = NULL;

    } else {
        // Handle removal from somewhere other than at the 

        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;

    }

    free(old_node);
    list->size--;

    return 0;
}

