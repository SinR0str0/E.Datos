/*
    cdlist.h
*/
#ifndef CDLIST_H
#define CDLIST_H

#include <stdlib.h>

/*
    Doubled linked list node
*/
typedef struct CDListNode_ {
    void *data;
    struct CDListNode_ *next;
    struct CDListNode_ *prev;
} CDListNode;

/*
    Struct for doubled linked list nodes
*/
typedef struct CDList_ {
    int size;
    void (*destroy) (void *data);
    CDListNode *head;
} CDList;

/*
    Public Interfaces
*/
void cdlist_init (CDList *list, void (*detroy)(void *data));
void cdlist_destroy (CDList *list);

int cdlist_ins_next (CDList *list, CDListNode *node, const void *data);
int cdlist_ins_prev (CDList *list, CDListNode *node, const void *data);
int cdlist_remove (CDList *list, CDListNode *node, void **data);

/*
    Macros
*/
#define cdlist_size(list) ((list)->size)
#define cdlist_head(list) ((list)->head)

#define cdlist_data(node) ((node)->data)
#define cdlist_next(node) ((node)->next)
#define cdlist_prev(node) ((node)->prev)

#endif
    
