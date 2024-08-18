/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 14/08/24

Características del programa: 
Se desea construir un programa que cuenta con las siguientes funciones de lectura de matrices estáticas:
1) Dada una matriz 6x4, leer los elementos de la matriz en forma de "S" invertida.
2) Dada una matriz 6x6, leer los elementos de la matriz en forma de "Z".
3) Dada una matriz 6x6, leer los elementos de la matriz en forma de "Z" de abajo hacia arriba.
4) Dada una matriz 3x4, leer los elementos de la matriz en forma "invertida", es decir, 
	de derecha a izquierda y de abajo hacia arriba.
*/

#include <stdio.h>
#include <locale.h>
#define n 4
#define m 6
#define x 3

void configuraIdioma();
void leerS(int mat[m][n]);
void leerZ(int mat[m][m]);
void leerZ2(int mat[m][m]);
void leerA(int mat[x][n]);

int main(){
	int matS[m][n]={{1,2,3,4}, {10,12,5,6}, {6,7,8,9}, {0,13,10,7}, {2,3,5,4}, {9,7,4,6}};
	int matZ[m][m]={{1,2,3,4,5,6}, {7,8,9,10,11,12}, {13,14,15,16,17,18}, {19,20,21,22,23,24},
	{25,26,27,28,29,30}, {31,32,33,34,35,36}};
	int matA[x][n]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	
	//leerS(matS);
	//leerZ(matZ);
	//leerZ2(matZ);
	leerA(matA);
	
	return 0;
}

void leerS(int mat[m][n]){
	//FUNCIÓN LECTURA "S" INVERTIDA
	/*
	Ejemplo:
	1   2 3 4 
	10 12 5 6 
	6  7  8 9
	0 13 10 7
	2  3  5 4
	9  7  4 6
	Resultado: 1,2,3,4,6,5,12,10,6,7,8,9,7,10,13,0,2,3,5,4,6,4,7,9. 
	*/
	int i,j=0;
	
	for(i=0; i<m; i++){
		if(i%2==0){
			for(j=j; j<n; j++){
				printf(" %d ", mat[i][j]);
			}
			j--;
		}
		else{
			for(j=j; j>=0; j--){
				printf(" %d ", mat[i][j]);	
			}
			j++;
		}
	}
}

void leerZ(int mat[m][m]){
	//FUNCIÓN LECTURA "Z"
	/*
	Ejemplo:
	1   2  3  4  5  6
	7   8  9 10 11 12
	13 14 15 16 17 18
	19 20 21 22 23 24
	25 26 27 28 29 30
	31 32 33 34 35 36
	Resultado: 1,2,3,4,5,6,11,16,21,26,31,32,33,34,35,36. 
	*/
	int i, j;
	for(i=0; i<m; i++){
		if(i==0 || i==m-1){
			for(j=0; j<m; j++){
				printf(" %d ", mat[i][j]);
			}
			j--;
		}
		else{
			j--;
			printf(" %d ", mat[i][j]);
		}
		
	}
}

void leerZ2(int mat[m][m]){
	//FUNCIÓN LECTURA "Z" DE ABAJO HACIA ARRIBA
	/*
	Ejemplo:
	1   2  3  4  5  6
	7   8  9 10 11 12
	13 14 15 16 17 18
	19 20 21 22 23 24
	25 26 27 28 29 30
	31 32 33 34 35 36
	Resultado: 36,35,34,33,32,31,26,21,16,11,6,5,4,3,2,1. 
	*/
	int i, j;
	for(i=m-1; i>=0; i--){
		if(i==0 || i==m-1){
			for(j=m-1; j>=0; j--){
				printf(" %d ", mat[i][j]);
			}
			j++;
		}
		else{
			j++;
			printf(" %d ", mat[i][j]);
		}
		
	}
}

void leerA(int mat[x][n]){
	//FUNCIÓN LECTURA INVERTIDA
	/*
	{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	Ejemplo:
	1  2  3  4
	5  6  7  8
	9 10 11 12
	Resultado: 12,11,10,9,8,7,6,5,4,3,2,1.
	*/
	
	int i,j;
	for(i=x-1; i>=0; i--){
		for(j=n-1; j>=0; j--){
			printf(" %d ", mat[i][j]);
		}
	}
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

