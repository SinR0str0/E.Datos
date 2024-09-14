/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 18/08/24
Fecha de actualización: 22/08/24

Características del programa: 
Dado un arreglo unidemsional de 12 elementos, se desea transformar el arreglo en una matriz de tamaño 4x3
con los elementos del arreglo original.

*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#define n 12
#define m 4

void llenarM(int mat[n]);
int numAMat(int mat[n], char cadena[12]);
void separarM(int mat[n], int seg[3][m]);
void leerM(int mat[3][m]);
void configuraIdioma();
int escanerInt(int min, int max);


int main(int argc, char *argv[]){
	configuraIdioma();
	int matriz[n]={1,2,3,4,5,6,7,8,9,10,11,21}, bidi[3][m];
	
	
	if(argv[1]&&strlen(argv[1])==n){
		if(!numAMat(matriz,argv[1])){
			llenarM(matriz);
		}
	}
	else{
		llenarM(matriz);
	}
	
	separarM(matriz, bidi);
	leerM(bidi);
	return 0;
}

void leerM(int mat[3][m]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<m;j++){
			printf(" %d", mat[i][j]);
		}
		printf("\n");
	}
}

void separarM(int mat[n], int seg[3][m]){
	int i, j=0, k=0;
	
	for(i=0; i<n;i++){
		if(i%4==0 && i!=0){
			k++;
			j=0;
		}
		seg[k][j]=mat[i];
		j++;
	}
}

int numAMat(int mat[n], char cadena[n]){
	int i;
	for(i=0; i<n; i++){
		if(cadena[i]-'0'<=9 && cadena[i]-'0' >=0){
			mat[i]=cadena[i]-'0';
		}
		else{
			return 0;
		}
	}
	return 1;
}

void llenarM(int mat[n]){
	int i;
	for(i=0;i<n;i++){
		printf("\n Digite su valor No. %d: ", i+1);
		mat[i]=escanerInt(0,0);
	}
}

int escanerInt(int min, int max){
	//Función para leer números int sin errores
	int var;
	if(min || max){
		while(scanf("%d", &var) != 1 || var < min || var > max){
			fflush(stdin);
			printf("\n Lo siento, ingrese un número entre %d y %d: ", min, max);
		}
	}
	else{
		while(scanf("%d", &var) != 1){
			fflush(stdin);
			printf("\n Lo siento, ingrese un número válido: ");
		}
	}
	
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
