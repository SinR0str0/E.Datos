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
	int len, totales, total2, i, *A, t, m, opcional, tec=1;
	char *cadena;
	do{
		printf("\n Seleccione la funci�n que quiere utilizar:"
				"\n %d. De un conjunto arrojar las topolog�as."
				"\n %d. Comprobar topolog�a "
				"\n %d. Salir"
				"\n Escriba el n�mero de la opci�n deseada: ", principal, secundaria, salir);
		m=escanerInt(salir,secundaria);
		if(m){
			printf("\n Escriba la cantidad de elementos de X: ");
			len=escanerInt(1,10);
			
			printf("\n Escriba el conjunto XCN separado por espacios o comas:\n X={");
			cadena=(char *)malloc(sizeof(char));
			if (cadena == NULL) {
		        printf("Error en la asignaci�n de memoria.\n");
		        return 1;
		    }
			string(cadena,1000);
			system("cls");
			
			A=(int *)calloc(10,sizeof(int));
			if (A == NULL) {
		        printf("Error en la asignaci�n de memoria.\n");
		        return 1;
		    }
			convertir(cadena, A, len);
			//printf("\n CADENA: %s", cadena);
		}
		if(m==1){
			//Construir topolog�as
			printf("\n Cantidad de elementos: %d"
					"\n X={",len);
			for(i=0; i<len; i++){
				printf(" %d", A[i]);
				if(i!=len-1){
					printf(",");
				}
			}
			printf("}\n");
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
			printf("\n 1. Ver las topolog�as.");
			printf("\n 2. Ver las NO topolog�as.");
			printf("\n Escriba el n�mero de la opci�n deseada: ");
			opcional = escanerInt(1,2);
			
			/*
			printf("\n %d P(P(X))=", opcional);
			imprimirConjuntoPotencia2(PPx,total2);
			*/
			for(i=0; i<total2; i++){
				if(opcional==1){
					//AQUI
					if(PPx[i].t==conjunto && PPx[i].data.set2.len>=2 
					&& PPx[i].data.set2.arr[0].data.set.len==0 && isX(PPx[i].data.set2.arr[PPx[i].data.set2.len-1],A,len)){
						
						/*
						printf("\n Elemento: ");
						imprimirEle2(PPx[i]);
						*/
						if(unionBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len,0) 
						&& interBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len,0)){
							/*
							printf("\n Elemento: ");
							imprimirEle2(PPx[i]);
							printf("\n T: %d", t+1);
							*/
							printf(" %d. ", t+1);
							imprimirEle2(PPx[i]);
							printf(" es topolog�a de X.\n");
							printf(" Ya que {} es elemento de T.");
							printf("\n X es elemento de T.");
							printf("\n La uni�n arbitraria de elementos de T son elementos de P(P(X)).");
							printf("\n La intersecci�n finita de elementos de T son elementos de P(P(X)).");
							t++;
							printf("\n 1. Ver la siguiente opci�n. \n 2. Salir.\n Seleccione el n�mero de la opci�n deseada: ");
							tec=escanerInt(1,2);
							if (tec==2) break;
						}
					}
				}
				else if(opcional==2){
					imprimirEle2(PPx[i]);
					if(PPx[i].t==conjunto && PPx[i].data.set2.len>=2){
						if(PPx[i].data.set2.arr[0].data.set.len==0){
							if(isX(PPx[i].data.set2.arr[PPx[i].data.set2.len-1],A,len)){
								if(!unionBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len,1) || !interBarbara(PPx[i].data.set2.arr, PPx[i].data.set2.len,0))
									printf(" por lo cual no es topolog�a de X.");
							}
							else{
								printf("\n Lo siento, pero el conjunto X no est� en la topolog�a.");
							}
						}
						else{
							printf("\n No tiene al vaci� como elemento de la topolog�a.");
						}
						
					
						printf("\n 1. Ver la siguiente opci�n. \n 2. Salir.\n Seleccione el n�mero de la opci�n deseada: ");
						tec=escanerInt(1,2);
						if (tec==2) break;
					}
					else{
						printf("\n No tiene suficientes elementos para ser topolog�a.");
					}
				}
				
			}
			//printf("\n El resultado es: %d", t);
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
			//Verificar topolog�a
			char *cadena2;
			ele *t;
			int total, ap=0, x=0, v=0,u=0,n=0;
			cadena2=(char *)malloc(sizeof(char));
			if (cadena2 == NULL) {
		        printf("Error en la asignaci�n de memoria.\n");
		        return 1;
		    }
			printf("\n Ingrese una topolog�a."
					"\n 1. Todos los elementos de la topolog�a deben estar separados por comas o espacios."
					"\n 2. Para el conjunto vac�o usar {}."
					"\n 3. Todo elemento de la topolog�a debe ser un subconjunto de los n�meros reales."
					"\n T={ ", cadena);
			string(cadena2,1000);
			system("cls");
			printf("\n Cantidad de elementos: %d"
					"\n X={",len);
			for(i=0; i<len; i++){
				printf(" %d", A[i]);
				if(i!=len-1){
					printf(",");
				}
			}
			printf("}\n T={%s} \n",cadena2);
			t = procesarEntrada(cadena2, &total);
			if (t) {
		        // Eliminar conjuntos duplicados
		        t = eliminarDuplicados(t, &total);
		        for(i=0; i<total; i++){
		        	if(isX(t[i],A,total)){
		        		x=1;
		        		printf("\n - Tiene al conjunto X como elemento de T.");
					}
					else if(t[i].data.set2.len==0){
						printf("\n - Tiene al conjunto vac�o como elemento de T.");
						v=2;
						continue;
					}
				}
				if(unionBarbara(t, total,1) && interBarbara(t, total,1)){
					printf("\n - La uni�n arbitraria de elementos de P(P(X)) son elementos de P(P(X))");
					printf("\n - La intersecci�n arbitraria de elementos de P(P(X)) son elementos de P(P(X))");
					u=3;
				}
				else{
					printf("\n Alg�n elemento con la uni�n o intersecci�n de otros elementos no es un elemento de T.");
					printf("\n Por lo tanto, T NO es topolog�a de X.\n");
					n=0;
					continue;
				}
				
				if(!v || !x){
					printf("\n El vac�o o el conjunto X no est� en T.");
					printf("\n Por lo tanto, T NO es topolog�a de X.\n");
					continue;
				}
		        
			}
			if(v && n && u && x){
				printf("\n Por lo tanto, T es topolog�a de X.");
			}
			free(cadena2);
			free(t);
			printf("\n ");
			system("pause");
			system("cls");
		}
	}while(m!=0);
	
	printf("\n Hasta luego!");
	free(cadena);
	free(A);
	return 0;
}
