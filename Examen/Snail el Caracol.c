#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "stack.h"
#include "list.h"

//Definimos cuanto va a avanzar el caracol según cada caso.
const short int l = -1; //Lluvia
const short int h = 1; //Humedo
const short int s = 2; //Seco

enum clima{
	//Un enum para definir si el día está lloviendo, seco o húmedo.
	secar=0,
	humedecer,
	llover
};

static void print_stack(const Stack *stack, int n, int pos) {
	ListNode *node;
	int *data, size=stack_size(stack), i;
	//system("cls");
	i = 0;
	node = list_head(stack);
	printf("\n|______|\n");
	while (i < size) {
		data = list_data(node);
		if(i == pos)
			fprintf(stdout, "  | @ |\n");
		else
			fprintf(stdout, "  | %d |\n",i);
		node = list_next(node);
		if(i==n) fprintf(stdout, "  ----\n");
		
	 	i++;
	}
	return;
}

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "spanish"); //Idioma a Español
	if(argc!=2){
		//Error de número de parámetros
		printf("\n Lo siento, solo requiere ingresar el tamaño del pozo.");
		return 1;
	}
	
	//Crearemos las variables necesarias:
	Stack pozo; //Pozo
	//Auxiliar de contenido, iterador, días transcurridos, estado del pozo, profundidad
	int *data, i, dias=0, estado=secar, profundidad=atoi(argv[1]); 
	
	if(profundidad<=0){
		//Error si la profundidad está mal
		printf("\n La profundidad del pozo debe ser un número válido. >:(");
		return 1;
	}
	
	stack_init(&pozo, free); //Iniciar el pozo
	for (i=profundidad; i>=0; i--) {
		//Llenando el pozo de n-0 elementos
		if ((data = (int *)malloc(sizeof(int))) == NULL)
	    	return 2;
	   		*data = i;
		if (stack_push(&pozo, data) != 0)
	    	return 3;
	}
	
	int paro=0, value=profundidad; //Solo como auxiliar
	char op; //Llueve o no
	
	//Un poco de historia
	printf("\n\n Es un día tranquilo en el bosque, y nuestro amigo \"Snail\" va caminando. \n \t\t @");
	printf("\n ¡¿Pero que pasó?!");
	printf("\n Snail ha caido por un pozo de %d metros de profundidad.", profundidad);
	printf("\n ¿Cuántos días tardará en salir del pozo?");
	
	//Ejecutar lo siguiente mientras el caracol esté en el pozo
	print_stack(&pozo, profundidad, profundidad);
	while(stack_size(&pozo)>1){
		dias++;
		//Pregunta al usuario si llueve o no
		printf("\n Es el día %d, ¿Hoy llueve?", dias);
		printf("\n [S/N] \n Escriba su respuesta: ");
		fflush(stdin);
		while(scanf("%c", &op) && op!='n' && op!='N' && op!='S' && op!='s'){
			//O es si, o es no.
			printf("\n Solo puede decir, \"S\" o \"N\": ");
			fflush(stdin);
		}
		
		//Esto es adicional
		data = stack_peek(&pozo);
		if(*data == 0) paro++;
		else paro=0;
		
		//Según la respuesta, se cambia el estado a humedo, seco o mojado
		if(op=='S' || op=='s') estado = llover;
		else estado--;
		if(estado<0) estado = secar;
		
		//Gracias al estado del suelo, el caracol sube o baja
		switch(estado){
			case secar:
				for(i=0;i<s;i++){
					///Sube (elimina) s escalones
					if(stack_size(&pozo)>1)
						if (stack_pop(&pozo, (void **)&data) == 0)
							free(data);
				}
				break;
			case humedecer:
				for(i=0;i<h;i++){
					//Sube (elimina) s escalones
					if(stack_size(&pozo)>1)
						if (stack_pop(&pozo, (void **)&data) == 0)
							free(data);
				}
				break;
			case llover:
				//Agregará l escalones (baja)
				for(i=0;i>l;i--){
					if(stack_size(&pozo)<=profundidad){
						value = *data - 1;
						if ((data = (int *)malloc(sizeof(int))) == NULL)
					    	return 2;
					   		*data = value;
						if (stack_push(&pozo, data) != 0)
					    	return 3;
					}
				}
				break;				
		}
		data = stack_peek(&pozo);
		system("cls");
		print_stack(&pozo, profundidad, profundidad-*data);
		if(paro>4 && (op=='s' || op=='S') && *data == 0) 
			printf("\n Oye ya, pobre Snail, nunca saldrá del pozo.");
	}
	
	printf("\n Al final, Sanil tardó %d días en salir de ahí.", dias);
	
	//Eliminamos la lista y se acaba el programa
	stack_destroy(&pozo);
	return 0;
}
