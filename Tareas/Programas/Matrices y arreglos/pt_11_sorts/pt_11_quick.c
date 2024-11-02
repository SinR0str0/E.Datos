/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 01/11/24
Fecha de actualización: 01/11/24

Características del programa: 
Se desea construir un programa que dada una lista de número enteros, esta se ordene
usando el método de quick sort. Versión 2: Recursivo.
*/

//Quick sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

static void print_dlist (const DList *list) {
	//Impresion de lista
	if(dlist_size(list)<1) return;
    DListNode *node;
    float *data; int i;

    i = 0;
    node = dlist_head(list);
	fprintf(stdout, "\n");
    while (1) {
        data = dlist_data(node);
        fprintf(stdout, "| %.3f ", *data);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }
	fprintf(stdout, "|\n");
   return;
}

int quick(DList *lista){
	if(dlist_size(lista)<=1) return 1;
	// Función recursiva
	// Si hay 1 o menos elementos, se regresa
	
	DList derecha, izquierda;
	DListNode *pivote, *node, *nodeL;
	float *datap, *data, *data2;
	int i;
	
	pivote = dlist_head(lista);
	datap = dlist_data(pivote);
	
	dlist_init(&derecha, free);
	dlist_init(&izquierda, free);
	
	node = dlist_head(lista);
	node = dlist_next(node);
	
	// Llena la lista de menores o mayores al pivote
	for(i=1;i<dlist_size(lista);i++){
		data = dlist_data(node);
		if ((data2 = (float *)malloc(sizeof(float))) == NULL)
        	return 2;
        (*data2) = (*data);
		if((*data)<=(*datap)){
			if (dlist_ins_next(&izquierda, dlist_tail(&izquierda), data) != 0)
	            return 3;
		}
		else{
			if (dlist_ins_next(&derecha, dlist_tail(&derecha), data2) != 0)
	            return 3;
		}
		node = dlist_next(node);
	}
	
	/* Verificar listas: 
	
	printf("\n Lista de menores: %d para pivote: %f", dlist_size(&izquierda), (*datap));
	print_dlist(&izquierda);
	printf("\n Lista de mayores: %d para pivote: %f", dlist_size(&derecha), *datap);
	print_dlist(&derecha);
	*/
	
	// Recursión: 
	quick(&derecha);
	quick(&izquierda);
	
	/*
	printf("\n Lista de menores: %d para el pivote %f", list_size(&izquierda), (*datap));
	print_dlist(&izquierda);
	printf("\n Lista de mayores: %d para el pivote %f", list_size(&derecha), (*datap));
	print_dlist(&derecha);
	*/
	
	//Re-construir la lista:
	node = dlist_head(&izquierda);
	nodeL = dlist_head(lista);
	while(node!=NULL){
		data = dlist_data(node);
		data2 = dlist_data(nodeL);
		printf("\n Para:");
		print_dlist(lista);
		printf("\n Con:");
		print_dlist(&izquierda);
		printf("\n Corrigiendo: %f -> %f", *data, *data2);
		(*data2) = (*data);
		node = dlist_next(node);
		nodeL= dlist_next(nodeL);
	}

	data2 = dlist_data(nodeL);
	(*data2) = (*datap);
	node = dlist_head(&derecha);
	nodeL= dlist_next(nodeL);
	
	while(node!=NULL){
		data = dlist_data(node);
		data2 = dlist_data(nodeL);
		
		(*data2) = (*data);
		node = dlist_next(node);
		nodeL= dlist_next(nodeL);
	}
	
	printf("\n Para el pivote %f:", (*datap));
	print_dlist(lista);
	
	dlist_destroy(&izquierda);
	dlist_destroy(&derecha);
	return 0;
}

int main(int argc, char *argv[]){
	if(argc<=1){
		printf("\n Lo siento, ingrese una lista de enteros valida.");
		return 1;
	}
	
	float var;
	int i;
	DList ordenado;
	DListNode *node;
	float *data;
	
	//Lista con la que se trabajará
	dlist_init(&ordenado, free);
	
	for(i=1;i<argc;i++){
		var = atof(argv[i]);
		if ((data = (float *)malloc(sizeof(float))) == NULL)
        	return 1;

        (*data) = var;
		if (dlist_ins_next(&ordenado, dlist_head(&ordenado), data) != 0)
            return 3;
	}
	
	print_dlist(&ordenado);
	i=quick(&ordenado);
	print_dlist(&ordenado);
	
	dlist_destroy(&ordenado);
	printf("\n Todo salio perfecto! : %d",i);
	return i;
}
