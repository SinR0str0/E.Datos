#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cdlist.h"

enum sentido{
	izquierda=0,
	derecha
};

static void print_cdlist (const CDList *list) {
	//Función para imprimir la lista
    CDListNode *node;
    int *data, i;

    fprintf(stdout, "\n List size is %d\n", cdlist_size(list));

    i = 0;
    node = cdlist_head(list);

    while (1) {
        data = cdlist_data(node);
        fprintf(stdout, "%03d, ", *data);

        i++;

        if (i>=list->size)
            break;
        else
            node = cdlist_next(node);
    }
	printf("\n");
   	return;
}

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "spanish"); //Idioma español
	/* Se crean 4 variables: 
		- La primera dirá el número de concursantes.
		- La segunda dirá el sentido (1 derecha, 0 izquierda).
		- La tercera dirá cada cuantos hay que sacar.
		- La cuarta dirá el número del concursante que desea ganar.
	*/
	int tam = 1, rotar=2, ganso=3, salvar=4;
	
	if(argc!=salvar+1){
		//Valida que solo pasen los argumentos necesarios.
		printf("\n Lo siento, debe ingresar solo %d parámetros.", salvar+1);
		return 1;
	}
	tam = atoi(argv[tam]);
	rotar = atoi(argv[rotar]);
	ganso = atoi(argv[ganso]);
	salvar = atoi(argv[salvar]);
	
	//Verificamos que los datos ingresados sean válidos
	if(tam<=0){
		printf("\n Lo siento, ingrese un número de prisioneros válido (positivo).");
		return 2;
	}
	if(rotar!=izquierda && rotar != derecha){
		printf("\n Lo siento, solo puede girar a la derecha (%d) o a la izquierda (%d).", derecha, izquierda);
		return 2;
	}
	if(ganso<=0){
		printf("\n Lo siento, ingrese un número valido de cada cuantos eliminar.");
		return 2;
	}
	if(salvar < 1 || salvar > tam){
		printf("\n El jugador a salvar no existe.");
		return 2;
	}
	
	//Si todo es correcto, comenzamos el juego:
	//Creamos e iniciamos la lista circular de participantes, del 1 al tam.	
	CDList patos; //Lista
    CDListNode *node; //Nodo auxiliar

    int *data, i, inicio; //Contenido auxiliar, iterador y ronda de inicio.
	
    cdlist_init(&patos, free); //Iniciación de lista vacía
    node = cdlist_head(&patos); //Iniciamos en la cabeza de la lista
    for (i = 1; i <= tam; i++) {
    	//Llenamos la lista con los participantes
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;
		
        if (cdlist_ins_prev(&patos, cdlist_head(&patos), data) != 0)
            return 3; //La memoria se llenó
        
    }
	//print_cdlist(&patos); //Imprime la lista circular.
	
	/* Este juego pedecirá quien será el ganador, y después se jugará para ayudar a los amigos.
		Para el juego, se seguirá el siguiente algoritmo:
		1. Iniciar con el concursante 1 (cabeza).
		2. Jugar pato pato ganso:
			- Si el concursante es pato, se salva. Es pato si
				es menor al número fijo "ganso".
			- Si el concursante es ganso, se elimina de la lista
				ya que no puede seguir jugando.
		3. Repetir desde el paso 2 hasta que solo quede un jugador
			(size == 1).
		NOTA: (rotar==derecha)? expresa el sentido al que apunta el juego.
	*/
	
	node = cdlist_head(&patos); //Iniciamos el juego
	while(cdlist_size(&patos)>1){ //Repetir mientra haya más de un jugador.
		for(i=1; i<=ganso; i++)
			node = (rotar==derecha)? cdlist_next(node) : cdlist_prev(node); //Avanzamos, es pato
		
		//En este punto, ya tenemos al jugador "ganso". Lo eliminamos.
		data = (rotar==derecha)? cdlist_data(node->prev) : cdlist_data(node->next);
		//printf("\n El jugador #%d es ganso!", *data); //Imprime el ganso
		if (cdlist_remove(&patos, (rotar==derecha)?node->prev:node->next, (void**)&data) != 0)
        	return 4; //Un eror más
        
        //print_cdlist(&patos); //Se imprimen los sobrevivientes
	}
	
	//El nodo que sale de este while es el único sobreviviente.
	data = cdlist_data(node);
	inicio = salvar-*data;
	printf("\n El juego de prueba a terminado.");
	
	//Ya sabiendo el resultado del juego, podemos jugar de verdad
	//Reiniciamos el juego:
	cdlist_destroy(&patos);
	cdlist_init(&patos, free); //Iniciación de lista vacía
    node = cdlist_head(&patos); //Iniciamos en la cabeza de la lista
    for (i = 1; i <= tam; i++) {
    	//Llenamos la lista con los participantes
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;
		
        if (cdlist_ins_prev(&patos, cdlist_head(&patos), data) != 0)
            return 3; //La memoria se llenó
    }
    node = cdlist_head(&patos); //Iniciamos el juego
    //Pero ahora lo iniciamos en el nodo correcto:
    
	if(inicio>0)
    	for(i=0;i<inicio;i++) node = cdlist_next(node);
    else
    	for(i=0;i>inicio;i--) node = cdlist_prev(node);
    
    data=cdlist_data(node);
    printf("\n Iniciando el juego con el jugador: %d", *data);
    print_cdlist(&patos);
	while(cdlist_size(&patos)>1){ //Repetir mientra haya más de un jugador.
		for(i=1; i<=ganso; i++)
			node = (rotar==derecha)? cdlist_next(node) : cdlist_prev(node); //Avanzamos, es pato
		
		//En este punto, ya tenemos al jugador "ganso". Lo eliminamos.
		data = (rotar==derecha)? cdlist_data(node->prev) : cdlist_data(node->next);
		printf("\n El jugador #%d es ganso!", *data); //Imprime el ganso
		if (cdlist_remove(&patos, (rotar==derecha)?node->prev:node->next, (void**)&data) != 0)
        	return 4; //Un eror más
        
        print_cdlist(&patos); //Se imprimen los sobrevivientes
	}
	
	//Se dice quien es el ganador
	data = cdlist_data(node);
	printf("\n El ganador del juego es: %d",*data);
	
	//Se borra lo construido:
	cdlist_destroy(&patos);
	return 0;
}
