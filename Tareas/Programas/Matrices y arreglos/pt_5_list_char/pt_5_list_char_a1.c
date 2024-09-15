/*
Alumnos: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 15/09/24
Fecha de actualización: 15/09/24

Características del programa: 
Construir una lista ligada que acepte caracteres y realizar lo siguiente:
1. Llenar la lista con al menos 10 caracteres.  
2. Usar 4 funciones para insertar `A,W,T,M` en cualquier parte de la estructura.
3. Usar 4 funciones para eliminar cuatro elementos distintos de la estructura. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "list.h"

void *nuevoData(char c){
	//Función para crear datos
	char *data;
	data = (char *)malloc(sizeof(char));
	if(data==NULL)
		exit(1);
	*data=c;
	return data;
}

static void print_list (const List *list) {
	// Imprimir lista
    ListNode *node;
    char *data;
	int i;

    fprintf(stdout, "El tamaño de la lista es: %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    setlocale(LC_ALL,"spanish");
	List list;
    ListNode *node;
    char *data, c;
    int i;

    // Inicializar la lista
    list_init(&list, free);

    // 1. LLenar la lista
    node = list_head(&list);
    for (c = ' '; c <= '6'; c+=2){
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = c;

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

	node = list_head(&list);
    fprintf(stdout, "\nAgregando A en la cabeza de la lista.\n");
    if (list_ins_next(&list, NULL, nuevoData('A')) != 0)
        return 1;
    print_list(&list);
    for (i = 1; i < (list_size(&list)-1)/2-1; ++i)
        node = list_next(node);

    fprintf(stdout, "\nAgregando W a mitad de la lista.\n");
    if (list_ins_next(&list, node, nuevoData('W')) != 0)
        return 1;
    print_list(&list);
	
	node = list_next(node);
	node = list_next(node);
	data = list_data(node);
	
	fprintf(stdout, "\nAgregando T después del nodo \"%c\".\n", *data);
    if (list_ins_next(&list, node, nuevoData('T')) != 0)
        return 1;
    print_list(&list);
	
	node = list_head(&list);
	for (i = 1; i < 5; ++i)
        node = list_next(node);
	
	data = list_data(node);
    fprintf(stdout, "\nAgregando M después del nodo \"%c\".\n", *data);
    if (list_ins_next(&list, node, nuevoData('M')) != 0)
        return 1;
    print_list(&list);    
    
    node=list_head(&list);
    for (i = 0; i < list_size(&list)-2; ++i)
        node = list_next(node);
        
    data=list_data(node);
    fprintf(stdout, "\nQuitando el nodo de la cola.\n");
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    print_list(&list);
	
	node=list_head(&list);
    for (i = 0; i < 3; ++i)
        node = list_next(node);
        
    data=list_data(node);
    fprintf(stdout, "\nQuitando el nodo siguiente a \"%c\"\n", *data);
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    print_list(&list);
    
    for (i; i < 7; ++i)
        node = list_next(node);
        
    data=list_data(node);
    fprintf(stdout, "\nQuitando el nodo siguiente a \"%c\"\n", *data);
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    print_list(&list);
    
    data=list_data(list_head(&list));
    fprintf(stdout, "\nQuitando la cabeza de la lista.\n");
    if (list_rem_next(&list, NULL, (void **)&data) != 0)
        return 1;
    print_list(&list);
    
    // Destroying the list
    fprintf(stdout, "\nDestruyendo lista.\n");
    list_destroy(&list);
	
	system("pause");
    return 0;
}
