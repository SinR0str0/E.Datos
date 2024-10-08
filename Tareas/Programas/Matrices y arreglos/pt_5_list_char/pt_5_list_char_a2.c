/*
Alumnos: Hern�ndez Pe�a Angel Adrian, Gil de Gaona Jazm�n
Grupo: 1301
Programaci�n II. Facultad de Estudios Superiores Acatl�n
Fecha de realizaci�n: 15/09/24
Fecha de actualizaci�n: 15/09/24

Caracter�sticas del programa: 
Desde la consola CMD, el programa recibir� par�metros y crear� una lista con ellos, luego:
1. Usar 4 funciones para insertar `D,R,o,9` en cualquier parte de la estructura.
2. Usar 4 funciones para eliminar cuatro elementos distintos de la estructura. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "list.h"

void *nuevoData(char c){
	//Funci�n para crear datos
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

    fprintf(stdout, "El tama�o de la lista es: %d\n", list_size(list));
	if (list_size(list)>0){
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
	}

   return;
}


int main (int argc, char **argv){
    setlocale(LC_ALL,"spanish");
	List list;
    ListNode *node;
    char *data, c;
    int i;
    
    list_init(&list, free);
    if(argc>1){
    	for(i=1; i<argc; i++){
    		if (list_ins_next(&list, NULL, nuevoData(argv[i][0])) != 0)
        		return 1;
		}
		print_list(&list);
	}
	else
		printf("\nLa lista se crear� vac�a.");

	//1. Agregar D,R,o,9.
	fprintf(stdout, "\nAgregando D al final de la lista.\n");
	if (list_ins_next(&list, list_tail(&list), nuevoData('D')) != 0)
        return 1;
    print_list(&list);
    
    node = list_head(&list);
    for(i=0;i<list_size(&list)-3; ++i)
    	node = list_next(node);
    data = list_data(node);
    if(list_size(&list)>2)
    	fprintf(stdout, "\nAgregando R en la antepen�ltima posici�n de la lista.\n");
    else
    	fprintf(stdout, "\nAgregando R en despu�s de %c.\n", *data);
    if (list_ins_next(&list, node, nuevoData('R')) != 0)
        return 1;
    print_list(&list);
    
    fprintf(stdout, "\nAgregando o en la cabeza de la lista.\n");
    if (list_ins_next(&list, NULL, nuevoData('o')) != 0)
        return 1;
    print_list(&list);
    
    node = list_head(&list);
    for(i=0;i<(list_size(&list)-1)/4;i++)
    	node = list_next(node);
    	
    data = list_data(node);
    
    fprintf(stdout, "\nAgregando 9 despu�s del nodo %c.\n", *data);
    if (list_ins_next(&list, node, nuevoData('9')) != 0)
        return 1;
    print_list(&list);
    
    //2. Eliminar 4 elementos
    data = list_data(list_head(&list));
    fprintf(stdout, "\nQuitando el nodo de la cabeza.\n");
    if (list_rem_next(&list, NULL, (void **)&data) != 0)
        return 1;
    print_list(&list);
    
    node = list_head(&list);
    node = list_next(node);
    
    data = list_data(node);
    fprintf(stdout, "\nQuitando el nodo siguiente a %c.\n",*data);
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    print_list(&list);
	
	node = list_head(&list);
	for(i=0;i<(list_size(&list)-1)/2;i++){
		node = list_next(node);
	}
	data = list_data(node);
	fprintf(stdout, "\nQuitando el nodo n�mero %d.\n",i+1);
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    print_list(&list);
    
    node = list_head(&list);
    for(i=0;i<list_size(&list)-3;++i)
    	node = list_next(node);
    data = list_data(node);
    if(!i){
    	fprintf(stdout, "\nQuitando el �ltimo elemento.\n");
    	if (list_rem_next(&list, NULL, (void **)&data) != 0)
        	return 1;
	}
    else{
    	fprintf(stdout, "\nQuitando el nodo siguiente a %c.\n",*data);
    	if (list_rem_next(&list, node, (void **)&data) != 0)
        	return 1;
        
    }
    print_list(&list);
    
	
    // Borrando lista
    fprintf(stdout, "\nDestruyendo lista.\n");
    list_destroy(&list);
	
	system("pause");
    return 0;
}
