/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 14/08/24

Características del programa: 
Se desea construir un programa que lea los elementos de una matriz estática de tamaño 4x6 tal que:
se impriman los valores al leer la matriz en forma de "S" invertida.

Ejemplo:
1 2 3 4 5 6
6 7 8 9 10 7
2 3 5 4 8 8
9 7 4 6 3 9
Resultado: 1,2,3,4,5,6,7,10,9,8,7,6,2,3,5,4,8,8,9,3,6,4,7,9. 
*/

//PROYECTO LECTURA "S"
#include <stdio.h>
#include <locale.h>
#define n 4
#define m 6
void configuraIdioma();
void leerS(int mat[n][m]);


int main(){
	int mat[n][m]={{1,2,3,4,5,6},{6,7,8,9,10,7},{2,3,5,4,8,8},{9,7,4,6,3,9}};
	leerS(mat);
	
	return 0;
}

void leerS(int mat[n][m]){
	//Vamos a considerar que la posición está dada por (i,j)
	int i,j=0;
	
	/*1. Estar en 0,0 **
	  2. j++ y i=i -> j++, (i=i) '' *j.3* / *i.2*
	  3. i++, j=j  -> j=j'', (i++) ''
	  4. j--, i=i  -> j--, i=i
	  5. i++, j=j  -> j=j, i++
	*/
	
	for(i=0; i<n; i++){
		if(i%2==0){
			for(j=j; j<m; j++){
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

void configuraIdioma(){
	//Cambiar idioma a español (acepta ñ y acentos)
	struct lconv *lcptr;
	setlocale(LC_ALL,"spanish");
	lcptr=localeconv();
	lcptr->decimal_point=".";
	lcptr->thousands_sep=",";
	lcptr->grouping="3";
}

