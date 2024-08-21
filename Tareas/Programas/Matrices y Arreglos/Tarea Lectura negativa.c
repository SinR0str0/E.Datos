/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 20/08/24
Fecha de actualización: 20/08/24

Características del programa: 
Dada una matriz dinámica de n elementos (con n ingresado por el usuario).
Se le solicitará un valor x al usuario tal que -n<x<n para acceder a un elemento específico de una lista,
aceptando índices negativos y positivos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirA(int tam, int *mat);
void leerA(int tam, int *mat);
int escanerInt(int min, int max);
void configuraIdioma();

int main(int argc, char *argv[]){
	configuraIdioma();
	int *x, y, t, i;
	
	x = (int*) calloc (1,sizeof (int));
	
	printf("\n Tamano del arreglo: ");
	y=escanerInt(1,0);
	
	x = (int*) realloc(x, y * sizeof(int));
	
	printf("\n 1. Llenar datos manualmente. \n 2. Llenar los datos automaticamente."
			"\n Seleccione el número de la opción deseada: ");
	t=escanerInt(1,2);
	
	if(t==1)
		leerA(y, x);
	else
		for(i=0;i<y;i++)
			x[i]=i;
	
	printf("\n Tu matriz es: ");
	imprimirA(y, x);
	
	printf("\n Ingresa el índice a revisar: ");
	t=escanerInt(-y,y);
	
	if(t<0)
		printf("\n Valor de la posicion %d : %d", t, x[y+t]);
	else
		printf("\n Valor de la posicion %d: %d", t, x[t]);
		
	free(x);
	printf("\n ");
	system("pause");
	return 0; 
}

void leerA(int tam, int *mat){
	//Función para guardar datos en el arreglo.
	int i;
	
	for(i=0; i<tam; i++){
		printf("\n Ingresa el dato No. %d: ", i+1);
		scanf("%d",&mat[i]);
	}
	
}

void imprimirA(int tam, int *mat){
	//Función para imprimir datos en el arreglo.
	int i;
	printf("|");
	for(i=0; i<tam; i++)
		printf(" %d |", mat[i]);
}

int escanerInt(int min, int max){
	//Función para leer números int sin errores
	fflush(stdin);
	int var;
	if(max>=min){
		while(scanf("%d", &var) != 1 || var < min || var > max){
			printf("\n Lo siento, ingrese un número entre %d y %d: ", min, max);
		}
	}
	else{
		while(scanf("%d", &var) != 1 || var<0){
			printf("\n Lo siento, ingrese un número válido: ");
		}
	}
	fflush(stdin);
	return var;
}

void configuraIdioma(){
	//Cambiar idioma a español (acepta ñ y acentos)
	struct lconv *lcptr;
	setlocale(LC_ALL,"spanish");
	lcptr=localeconv();
	lcptr->decimal_point=".";
	lcptr->thousands_sep=",";
	lcptr->grouping="3";
}
