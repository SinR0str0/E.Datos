/*
Alumno: Hern�ndez Pe�a Angel Adrian, Gil de Gaona Jazm�n
Grupo: 1301
Programaci�n II. Facultad de Estudios Superiores Acatl�n
Fecha de realizaci�n: 09/08/24
Fecha de actualizaci�n: 28/08/24

Caracter�sticas del programa: 
Se desea un programa que construya arreglos din�micos de tama�o bidimensional de acuerdo a su n�mero 
de cuenta, adem�s, este arreglo se llenar� con los n�meros de la cuenta por el anterior.
Ejemplo:
No. Cuenta: 410592683
| 4 | 4 | 4 | 4 | 
| 1 |
(NULL)
| 5 | 5 | 5 | 5 | 5 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 2 | 2 |
| 6 | 6 | 6 | 6 | 6 | 6 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 3 | 3 | 3 |
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define n 9 
// n son los d�gitos del n�mero de cuenta
int leerUsuario(int **valor);
int copiarCadena(int **numero, char *cadena);
int copiarElementos(int **numero, char *cadena[]);
void liberarMemoria(int **num);
void imprimirArreglo(int **num);
int escanerChar();

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"spanish");
	int **NoCuenta, var;
	
	NoCuenta = (int **) calloc (n, sizeof(int *));
	if(NoCuenta==NULL)
		return -1;
	
	if (argc>1 && strlen(argv[1])==n)
		var = copiarCadena(NoCuenta, argv[1]);
	else if(argc==n+1)
		var = copiarElementos(NoCuenta, argv);
	else{
		(argc>1)?printf("\n Lo siento, pero el n�mero ingresado no es un n�mero de cuenta v�lido."):printf("");
		leerUsuario(NoCuenta);
	}
	
	imprimirArreglo(NoCuenta);
	liberarMemoria(NoCuenta);
	return 0;
}
int copiarElementos(int **numero, char *cadena[]){
	int i,j, valor;
	for(i=1; i<=n; i++){
		valor=cadena[i][0]-'0';
		if(valor>=0 && valor<10){
			numero[i-1] = (int *) calloc (valor?valor:1, sizeof(int));
			if(numero[i-1]==NULL)
				return -1;
			numero[i-1][0]=valor;
			for(j=0; j<valor; j++)
				numero[i-1][j]=valor;
		}
		else
			return 0;
	}
	return 1;
}

int copiarCadena(int **numero, char *cadena){
	//Copiar en el apuntador desde consola
	int i, j, valor;
	for(i=0; i<n; i++){
		valor = cadena[i]-'0';
		if(valor>=0 && valor<10){
			numero[i] = (int *) calloc (valor?valor:1, sizeof(int));
			if(numero[i]==NULL)
				return -1;
				
			numero[i][0]=valor;
			for(j=0; j<valor; j++)
				numero[i][j]=valor;
		}
		else
			return 0;
	}
	return 1;
}

int leerUsuario(int **valor){
	//Solicitar de nuevo su n�mero al usuario
	char cadena[n];
	printf("\n Por favor, ingrese su n�mero de cuenta, debe contar con %d d�gitos: ", n);
	fflush(stdin);
	scanf("%s", &cadena);
	
	return copiarCadena(valor, cadena);
}

void liberarMemoria(int **num){
	//Limpiar y liberar memoria
	int i,j;
	for(i=n-1; i>=0; i--)
		free(num[i]);
	free(num);
}

void imprimirArreglo(int **num){
	//Imprimir el arreglo
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<num[i][0];j++)
			printf("| %3d ", num[i][j]);
		num[i][0]?printf("|\n"):printf("(NULL)\n");
	}
}

int escanerChar(){
	//Funci�n para leer caracteres sin errores
	char var;
	fflush(stdin);
	while(scanf("%c", &var) != 1 || var-'0'<0 || var-'0'>10){
		printf("\n Lo siento, ingrese un n�mero, no una letra: ");
	}
	return var-'0';
}
