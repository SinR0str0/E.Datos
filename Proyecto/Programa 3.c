//Librerías básicas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"


int palindromo(const DList *palabra){
	//Comprueba si la palabra es palíndroma
	/*
	Iniciamos variables, dos nodos y dos datas para
	recorrer la palabra de extremos a centro
	*/
	DListNode *derecha, *izquierda;
	char *dataD, *dataI;
	//Iniciamos en los extremos
	derecha = dlist_head(palabra);
	izquierda = dlist_tail(palabra);
	
	while(derecha!=izquierda && izquierda->next!=derecha){	
		//Configuramos los datas de los extremos
		dataD = dlist_data(derecha);
		dataI = dlist_data(izquierda);
		
		/*
			Comprobamos, si la letra del data es la misma
			Se continua con el siguiente nodo y reinicia el bucle hasta
			que se llegue al centro de la palabra 
			(mismo nodo o el siguiente de alguno de ellos es en el que estamos)
			Si no, se acaba el proceso y regresa falso.
		*/
		if((*dataI)!=(*dataD))
			return 0; //Termina si son diferentes letras
			
		//Movemos los nodos una posición:
		derecha = dlist_prev(derecha);
		izquierda = dlist_next(izquierda);
	}
	return 1;
}

static void print_dlist (const DList *list, int num) {
	//Imprime cada palabra palíndroma, primero el renglon, luego la palabra
    DListNode *node;
    char *data;
    node = dlist_head(list);
    fprintf(stdout,"%d. ",num);
    while (1) {
        data = dlist_data(node);
        fprintf(stdout, "%c", *data);

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }
    fprintf(stdout, "\n");
   return;
}

void leer(char **palabra){
	//Para leer la ruta del archivo desde el programa.
	/*
	Leerá cada caracter que ingrese el usuario al programa
	hasta que este sea un salto de linea y lo guarda en la ruta.
	*/
	char c;
	int tam=1;
	
	*palabra=(char *) malloc(sizeof(char));
	if (*palabra == NULL)
		return;
	while(1){
		c=getchar();
		if(c!='\n'){
			tam++;
			*palabra = realloc(*palabra, tam*sizeof(char));
			if(*palabra == NULL)
				return;
			(*palabra)[tam-2]=c;
			(*palabra)[tam-1]='\0';
		}
		else{
			break;
		}
	}
}

int main(int argc, char **argv){
	/*Inicializamos las variables:
	1. Ruta: Ruta del archivo .txt.
	2. caracter: Letra que se está iterando.
	3. data: Data de cada letra.
	4. archivo: Para leer un archivo.
	5. renglon: Contador de renglones \n.
	6. palabra: Dlist de palabra. Junto a su nodo.
	*/
	char *ruta, caracter, *data;
	FILE *archivo;
	int renglon=1;
	DList palabra;
    DListNode *node;
    
    //Comrpobamos la información que recibimos desde la consola:
	//printf("\n Argc: %d", argc);
	if(argc<2){
		//Número de parámetros correctos:
		printf("\n No se ha proporcionado una ruta del archivo.");
		printf("\n Escriba la ruta del archivo: ");
		leer(&ruta);
		//printf("La ruta proporcionada es: %s", ruta);
	}
	else if(strlen(argv[1])<=4){
		//Comprueba la longitud de la ruta:
		printf("\n La ruta del archivo es invalida.");
		printf("\n Escriba la ruta del archivo: ");
		leer(&ruta);
		//printf("La ruta proporcionada es: %s", ruta);
	}
	else{
		//Si existe una ruta, se copia a la variable correcta:
		ruta = (char *)calloc(strlen(argv[1]),sizeof(char));
		if(ruta==NULL)
			return 1;
		strcpy(ruta,argv[1]);
	}
	//Se lee el archivo como solo lectura.
	archivo = fopen(ruta,"r");
	if(archivo==NULL){
		//Si no se puede abrir, la ruta es incorrecta.
		printf("\n El archivo no fue encontrado.\n Saliendo.");
		fclose(archivo);
		return 3;
	}
	
	//Iniciamos la lista palabra que contendrá la palabra:
	dlist_init(&palabra, free);
	//Si el archivo se puede abrir, se itera por cada letra de este:
	while(!feof(archivo)){
		
		caracter = fgetc(archivo);
		
		//Si la letra es un corte de palabra:
		if(caracter=='\n'||caracter==' '||caracter==EOF){
			//Verificamos que la palabra almacenada sea un palíndromo:
			
			if(dlist_size(&palabra)>5 && palindromo(&palabra)==1)
			//Si es palíndroma, imprime la palabra y su renglón
				print_dlist(&palabra, renglon);
			
			//Creamos una nueva lista para la siguiente palabra:	
			dlist_destroy(&palabra);
			dlist_init(&palabra, free);
		}
		else if((caracter)>='a' && (caracter)<='z'){
			//Si el caracter es una letra normal, se agrega a la lista
			if ((data = (char *)malloc(sizeof(char))) == NULL)
			//Crea un nodo nuevo con la letra del texto
	            return -1;
	        *data = caracter;
			
	        if (dlist_ins_next(&palabra, dlist_tail(&palabra), data) != 0)
	        	//Inserta en la lista
	            return -1;
		}
		if(caracter=='\n')
			renglon++;
	}
	
	free(ruta);
	dlist_destroy(&palabra);
	fclose(archivo);
	return 0;
}
