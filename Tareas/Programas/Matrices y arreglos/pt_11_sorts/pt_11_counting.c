/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 01/11/24
Fecha de actualización: 01/11/24

Características del programa: 
Se desea construir un programa que dada una lista de número enteros, esta se ordene
usando el método de counting sort.
*/

//Counting sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Macros
#define Nulidad(ptr) ((ptr) == NULL? 1 : 0)

int CountingArray(int argc, char *argv[]){
	//No lo pidieron, pero aquí esta usando arreglos:
	int i, negativos=0, maxp=0, neg=0;
	int *counting, *ordenado;
	
	//Buscando el mayor
	for(i=1;i<argc;i++){
		if(atoi(argv[i])<0) negativos=1;
		
		if(atoi(argv[i])>maxp){
			maxp = atoi(argv[i]);
		}
		else if(negativos && atoi(argv[i])<neg) neg=atoi(argv[i]);
	}
	
	//Si hay negativos, la operación se ocupará más espacio
	if(negativos) maxp += (-1*neg);
	
	//Creando el arreglo count
	counting = (int *) calloc (maxp,sizeof(int));
	if(Nulidad(counting)) return 2;
	
	//Primer counting (index)
	for(i=1;i<argc;i++){
		int v;
		v = atoi(argv[i]);
		if(negativos) v+=neg;
		
		counting[v]++;
	}
	
	//Segundo counting (suma)
	for(i=1;i<=maxp;i++){
		counting[i]+=counting[i-1];
	}
	
	ordenado = (int*) calloc (counting[maxp],sizeof(int));
	if(Nulidad(ordenado)) return 2;
	
	/* Verificar arreglo counting 
	printf("\n Counting: \n ");
	for(i=0;i<maxp;i++){
		printf(" %d |",counting[i]);
	}
	*/
	
	//Ordenar arreglo
	for(i=1;i<argc;i++){
		int v;
		v = atoi(argv[i]);
		if(negativos) v+=neg;
		counting[v]--;
		ordenado[counting[v]]=v;	
	}
	
	/* Verificar arreglo counting 2
	printf("\n PRIMERO: \n ");
	for(i=0;i<maxp;i++){
		printf(" %d |",counting[i]);
	}
	*/
	
	/* Verificar arreglo ordenado */
	printf("\n ORDENADO: \n ");
	for(i=0;i<argc-1;i++){
		printf(" %d |",ordenado[i]);
	}
	free(counting);
	free(ordenado);
	return 0;
}

static void print_list (const List *list) {
	//Impresion de lista
    ListNode *node;
    int *data, i;

    i = 0;
    node = list_head(list);
	fprintf(stdout, "\n");
    while (1) {
        data = list_data(node);
        fprintf(stdout, "| %d ", *data);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }
	fprintf(stdout, "|\n");
   return;
}

int main(int argc, char *argv[]){
	if(argc<=1){
		printf("\n Lo siento, ingrese una lista de enteros valida.");
		return 1;
	}
	
	List counting, ordenado;
	ListNode *node;
	int *data, i, j, negativos=0, maxp=0, neg=0;
	
	list_init(&counting, free);
	
	//Buscando el mayor
	for(i=1;i<argc;i++){
		if(atoi(argv[i])<0) negativos=1;
		
		if(atoi(argv[i])>maxp) maxp = atoi(argv[i]);
		else if(negativos && atoi(argv[i])<neg) neg=atoi(argv[i]);
	}
	
	//Si hay negativos, la operación se ocupará más espacio
	if(negativos) maxp += (-1*neg);
	
	//Construye el count con ceros
	for(i=0; i<=maxp; i++){
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 2;
        *data = 0;
        if (list_ins_next(&counting, NULL, data) != 0)
            return 3;		
	}
	/* Verificar lista de ceros 
	print_list(&counting);
	*/
	
	//Creando el arreglo count
    for(i=1;i<argc;i++){
    	node = list_head(&counting);
    	for(j=0;j<=maxp;j++){
    		if(j<atoi(argv[i]))
    			node = list_next(node);
    		else{
    			data = list_data(node);
    			(*data)++;
    			node = list_next(node);
			}
		}	
	}
	
	/* Verificar lista counting con index 
	print_list(&counting);
	*/
	
	//Llenar lista ordenada:
	list_init(&ordenado,free);
	
	//Construyo la lista con ceros
	for(i=1; i<argc; i++){
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 2;
        *data = 0;
        if (list_ins_next(&ordenado, NULL, data) != 0)
            return 3;		
	}
	
	/* Verificar lista ordenada con ceros
	print_list(&ordenado);
	*/
	
	//Creo la lista ordenada
	for(i=1;i<argc;i++){
		
		int v, num=atoi(argv[i]);
		node = list_head(&counting);
		for(j=0;j<num;j++){
			node = list_next(node);
		}
		
		data = list_data(node);
		(*data)--;
		v=(*data);
		
		node = list_head(&ordenado);
		for(j=0;j<v;j++){
			node = list_next(node);
		}
		
		data = list_data(node);
		(*data) = num;
	}
	
	//Imprimir lista ordenada:
	print_list(&ordenado);
    
	// Destruyendo la lista
    fprintf(stdout, "\n Listas Destruidas \n");
    list_destroy(&counting);
    list_destroy(&ordenado);
	return 0;
}
