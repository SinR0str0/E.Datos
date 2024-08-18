/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 14/08/24
Fecha de actualización: 17/08/24

Características del programa: 
Se desea construir un programa que cuenta con las siguientes funciones de lectura de matrices estáticas:
1) Dada una matriz 6x4, leer los elementos de la matriz en forma de "S" invertida.
2) Dada una matriz 6x6, leer los elementos de la matriz en forma de "Z".
3) Dada una matriz 6x6, leer los elementos de la matriz en forma de "Z" de abajo hacia arriba.
4) Dada una matriz 3x4, leer los elementos de la matriz en forma "invertida", es decir, 
	de derecha a izquierda y de abajo hacia arriba.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 4
#define m 6
#define x 3

enum menu{
	salir,
	mS,
	mZ,
	mZ2,
	mA,
	cambiar
};

void configuraIdioma();
int escanerInt(int min, int max);
void llenarM(int a, int b, int mat[a][b]);
void leerM(int fil, int col, int mat[fil][col]);
void cambiarM(int matS[m][n], int matZ[m][m], int matA[x][n]);
void leerS(int mat[m][n]);
void leerZ(int mat[m][m]);
void leerZ2(int mat[m][m]);
void leerA(int mat[x][n]);

int main(){
	configuraIdioma();
	int matS[m][n]={{1,2,3,4}, {10,12,5,6}, {6,7,8,9}, {0,13,10,7}, {2,3,5,4}, {9,7,4,6}};
	int matZ[m][m]={{1,2,3,4,5,6}, {7,8,9,10,11,12}, {13,14,15,16,17,18}, {19,20,21,22,23,24},
	{25,26,27,28,29,30}, {31,32,33,34,35,36}};
	int matA[x][n]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	
	int uso;
	
	printf("\n 1. Llenar matrices.\n 2. Usar matrices predeterminadas. \n 0. Salir."
			"\n Seleccione el número de la opción de su agrado: ");
	uso=escanerInt(0,2);
	if(uso==1){
		cambiarM(matS, matZ, matA);	
	}
	else if(!uso){
		return 1;
	}
	
	do{
		system("cls");
		printf("\n %d. Leer matriz en forma de \"S\" invertida. "
				"\n %d. Leer matriz en forma de \"Z\"."
				"\n %d. Leer matriz en forma de \"Z\" de abajo hacia arriba."
				"\n %d. Leer matriz en forma de forma invertida (abajo hacia arriba)."
				"\n %d. Cambiar matriz."
				"\n %d. Salir."
				"\n Seleccione el número de la opción deseada: ", mS, mZ, mZ2, mA, cambiar, salir);
		uso=escanerInt(salir, cambiar);
		switch(uso){
			case mS: //Leer en S
				leerM(m,n,matS);
				printf("\n Resultado:");
				leerS(matS);
				break;
			case mZ: //Leer en Z
				leerM(m,m, matZ);
				printf("\n Resultado:");
				leerZ(matZ);
				break;
			case mZ2: //Leer en Z inversa
				leerM(m,m, matZ);
				printf("\n Resultado:");
				leerZ2(matZ);
				break;
			case mA: //Leer inverso
				leerM(x,n, matA);
				printf("\n Resultado:");
				leerA(matA);
				break;
			case salir: //Salir
				printf("\n Hasta luego!");
				break;
			case cambiar: //cambiar Matrices
				cambiarM(matS, matZ, matA);
				break;
			default: 
				printf("\n Ha ocurrido un error extraño, vuelva a intenterlo.");
		}
		printf("\n");
		system("pause");	
	}while(uso);
	return 0;
}

void cambiarM(int matS[m][n], int matZ[m][m], int matA[x][n]){
	//Llenar matrices:
	int uso;
	printf("\n 1. Llenar matriz 6x4. \n 2. Llenar matriz 6x6. \n 3. Llenar matriz 3x4. \n 0. Salir."
			"\n Seleccione el número de la opción deseada: ");
	uso=escanerInt(0,3);
	switch(uso){
		case 1: //Llenar 6x4
			llenarM(m,n, matS);
			break;
		case 2: //Llenar 6x6
			llenarM(m,m, matZ);
			break;
		case 3: //Llenar 3x4
			llenarM(x,n, matA);
			break;
		case 0: //Salir
			exit(1);
		default: 
			printf("\n Ha ocurrido un error inesperado.");
	}
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
		for(j; !(i%2)?j<n:j>=0; !(i%2)?j++:j--){
			printf(" %d ", mat[i][j]);
		}
		!(i%2)?j--:j++;
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

void llenarM(int a, int b, int mat[a][b]){
	//Función para mostrar los datos de la matriz
	int i,j;
	
	for(i=0; i<a;i++){
		for(j=0; j<b; j++){
			printf("\n Ingrese valor de (%d,%d): ", i+1,j+1);
			mat[i][j] = escanerInt(0,0);
		}
	}
}

void leerM(int fil, int col, int mat[fil][col]){
	//Función para mostrar los datos de la matriz
	int i,j;
	
	for(i=0; i<fil;i++){
		for(j=0; j<col; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
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

