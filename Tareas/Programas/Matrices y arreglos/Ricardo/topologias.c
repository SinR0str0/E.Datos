#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"

typedef enum menu{
	salir,
	principal,
	secundaria
}menu;

int main(){
	configuraIdioma();
	ele *Px, *PPx;
	int len, totales, total2, i, *A, t, m;
	char *cadena;
	do{
		printf("\n Seleccione la función que quiere utilizar:"
				"\n %d. De un conjunto arrojar las topologías."
				"\n %d. Comprobar topología "
				"\n %d. Salir"
				"\n Escriba el número de la opción deseada: ", principal, secundaria, salir);
		m=escanerInt(salir,secundaria);
		if(m){
			printf("\n Escriba la cantidad de elementos de X: ");
			len=escanerInt(0,0);
			
			printf("\n Escriba el conjunto XCR separado por espacios o comas:\n X={");
			cadena=(char *)malloc(sizeof(char));
			if (cadena == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			string(cadena,1000);
			system("cls");
			
			A=(int *)calloc(len,sizeof(int));
			if (A == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			convertir(cadena, A, len);
		}
		if(m==1){
			//Construir topologías
			printf("\n Cantidad de elementos: %d"
					"\n X={%s}"
					"\n A lo cual, las posibles topologías son: \n",len, cadena);
			Px = potenciaInt(A, len, &totales);
			/*
			printf("\n P(X)=");
			imprimirConjuntoPotencia(Px, totales);
			*/
			
			PPx = potenciaEle(Px,totales, &total2);
			
			/*
			printf("\n P(P(X))=");
			imprimirConjuntoPotencia2(PPx,total2);
			*/
			t=0;
			for(i=0; i<total2; i++){
				if(PPx[i].t==conjunto && PPx[i].data.set2.len>=2 
				&& PPx[i].data.set2.arr[0].data.set.len==0 && isX(PPx[i].data.set2.arr[PPx[i].data.set2.len-1],A,len)){
					/*
					printf("\n Elemento: ");
					imprimirEle2(PPx[i]);
					*/
					if(unionBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len) 
					&& interBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len)){
						/*
						printf("\n Elemento: ");
						imprimirEle2(PPx[i]);
						printf("\n T: %d", t+1);
						*/
						printf(" %d. ", t+1);
						imprimirEle2(PPx[i]);
						printf("\n");
						t++;
					}
						
				}
			}
			printf("\n El resultado es: %d", t);
			for(i=0;i<total2;i++){
				if(PPx[i].t==conjunto && PPx[i].data.set2.len>0){
					free(Px[i].data.set2.arr);
				}
			}
			free(PPx);
			for (i = 0; i < totales; i++){
		        if (Px[i].t == conjunto && Px[i].data.set.len > 0){
		            free(Px[i].data.set.arr);
		        }
		    }
			free(Px);
			printf("\n ");
			system("pause");
			system("cls");
		}
		else if(m==2){
			//Verificar topología
			char *cadena2;
			ele *t;
			int total;
			cadena=(char *)malloc(sizeof(char));
			if (cadena == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			printf("\n Ingrese una topología."
					"\n 1. Todos los elementos de la topología deben estar separados por comas o espacios."
					"\n 2. Para el conjunto vacío usar {}."
					"\n 3. Todo elemento de la topología debe ser un subconjunto de los números reales."
					"\n T={ ");
			string(cadena2,1000);
			system("cls");
			printf("\n Cantidad de elementos: %d"
					"\n X={%s}"
					"\n T={%s} \n",len, cadena, cadena2);
			t = procesarEntrada(cadena2, &total);
			if (t) {
		        // Eliminar conjuntos duplicados
		        t = eliminarDuplicados(t, &total);
		        
		        for(i=0; i<total; i++){
		        	if(isX(t[i],A,total)){
		        		imprimirEle(t[i]);
		        		
		        		printf("\n SI ESTA X");
					}
					/*
					 if(isX(t[i].data.set2.arr[t[i].data.set2.len-1],A,len)){
					 	printf("\n SI ESTA X");
					 	
						if(unionBarbara(t[i].data.set2.arr, t[i].data.set2.len) 
						&& interBarbara(t[i].data.set2.arr, t[i].data.set2.len)){
							printf("\n Esto si es una topología.");
						}
							
					}
					*/
				}
		        
		        printf("Resultado sin duplicados:\n");
		        for (i = 0; i < total; i++) {
		            imprimirEle(t[i]);
		            printf("\n");
		        }
			}
		}
	}while(m!=0);
	
	printf("\n Hasta luego!");
	free(cadena);
	free(A);
	return 0;
}
