#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 4
#define m 3

void matrizDinamica(int **matriz){
	int i, j, max=10;
	char noCuenta[max];
	printf("\n Escriba su numero de cuenta: ");
	gets(noCuenta);
	
	matriz = (int **) calloc (max, sizeof(int));
	
	if(matriz==NULL){
		printf("\n Memoria no asignada, saliendo.");
		exit(1);
	}
	
	for (i=0; i<max-1; i++){
		int numero = noCuenta[i]-'0';
		matriz[i] = (int *) calloc (numero, sizeof(int));
		
		if(matriz[i]==NULL){
			printf("\n Ha ocurrido un error inesperado. \n\t Saliendo.");
			exit(1);
		}
		
		for(j=0; j<numero; j++){
			matriz[i][j]=numero;
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<max-1; i++){
		free(matriz[i]);
	}
	free(matriz);
}

void xd(int matriz[n][m]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void buscarArreglo1(int matriz[n][m]){
	int i, j, bandera=0;
	xd(matriz);
	for(j=0; j<m; j++){
		if(i%2==0){
			bandera=1;
		}
		if(j==0 || j%2==0){
			for(i=n-1; i>=0; i--){
				printf(" %d ", matriz[i][j]);
			}
		}
		else{
			for(i=0; i<n; i++){
				printf(" %d ", matriz[i][j]);
			}
		}
	}	
}

void buscarArreglo2(int matriz[n][m]){
	xd(matriz);
	int i,j;
	if(n-m>0){
		for(i=n-1; i>=n-m; i--){
			if(i==n-m||i==n-1){
				for(j=m-1; j>=0; j--){
					printf(" %d ", matriz[i][j]);
				}
				j=1;
			}
			else{
				printf(" %d ", matriz[i][j]);
				j++;
			}
		}
	}
	else{
		for(i=n-1; i>=0; i--){
			if(i==n-1){
				for(j=m-1; j>=0; j--){
					printf(" %d ", matriz[i][j]);
				}
				j=1;
			}
			else if(i==0){
				for(1; j>=0; j--){
					printf(" %d ", matriz[i][j]);
				}
				j=1;
			}
			else{
				printf(" %d ", matriz[i][j]);
				j++;
			}
		}
	}
}

int main(){
	int aux[4][3]={{1,2,3},{4,5,6},{7,8,9}, {1,2,3}};
	
	buscarArreglo2(aux);
	return 0;
}
