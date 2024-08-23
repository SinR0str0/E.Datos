/*
Alumno: Hern�ndez Pe�a Angel Adrian, Gil de Gaona Jazm�n
Grupo: 1301
Programaci�n II. Facultad de Estudios Superiores Acatl�n
Fecha de realizaci�n: 19/08/24
Fecha de actualizaci�n: 22/08/24

Caracter�sticas del programa: 
Realice un programa en C que genere una lista de los primeros 10 n�meros pares, deber� imprimirlos en orden inverso.
Posteriormente deber� modificar el valor almacenado en el �ndice correspondiente al �ltimo d�gito de su n�mero 
de cuenta por -1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define n 10

void configuraIdioma();
void leerM(int *mat);
int escanerInt(int min, int max);
int leerEntrada();

int main(int argc, char *argv[]){
	configuraIdioma();
	int *mat, i, ult, x;
	mat = (int *) calloc (n, sizeof(int));
	for(i=20; i>=2; i-=2){
		mat[10-(i/2)]=i;
	}
	
	if(argv[1]){
		x=argv[1][8]-'0';
		if(x>=0 && x<9){
			ult=x;
		}
		else{
			ult = leerEntrada();
		}
	}
	else if(argc == 10){
		x=*argv[9]-'0';
		if(x>=0 && x<9){
			ult=x;
		}
		else{
			ult = leerEntrada();
		}
	}
	else{
		ult = leerEntrada();
	}
	
	leerM(mat);
	mat[ult]=-1;
	leerM(mat);
	
	free(mat);
	return 0;
}

int leerEntrada(){
	//Funci�n para leer datos con consola
	char l;
	int i=1, x;
	printf("\n Escriba su n�mero de cuenta (m�ximo 9 d�gitos): ");
	while(scanf("%c", &l)==1 && l!='\n' && l!='\0' && i<=9){
		x=l-'0';
		if(x>=0 && x<9){
			i++;
		}
		
	}
	return x;
}

void leerM(int *mat){
	//Leer matriz de valor n
	int i;
	for(i=0; i<n; i++){
		printf("| %d ", mat[i]);
	}
	printf("|\n");
}

int escanerInt(int min, int max){
	//Funci�n para leer n�meros int sin errores
	int var;
	if(min || max){
		while(scanf("%d", &var) != 1 || var < min || var > max){
			fflush(stdin);
			printf("\n Lo siento, ingrese un n�mero entre %d y %d: ", min, max);
		}
	}
	else{
		while(scanf("%d", &var) != 1){
			fflush(stdin);
			printf("\n Lo siento, ingrese un n�mero v�lido: ");
		}
	}
	
	return var;
}

void configuraIdioma(){
	//Cambiar idioma a espa�ol (acepta � y acentos)
	struct lconv *lcptr;
	setlocale(LC_ALL,"spanish");
	lcptr=localeconv();
	lcptr->decimal_point=".";
	lcptr->thousands_sep=",";
	lcptr->grouping="3";
}

