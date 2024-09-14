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
		printf("\n Seleccione la función que quiere utilizar:"
				"\n %d. De un conjunto arrojar las topologías."
				"\n %d. Comprobar topología "
				"\n %d. Salir"
				"\n Escriba el número de la opción deseada: ", principal, secundaria, salir);
		m=escanerInt(salir,secundaria);
		if(m){
			printf("\n Escriba la cantidad de elementos de X: ");
			len=escanerInt(1,10);
			
			printf("\n Escriba el conjunto XCN separado por espacios o comas:\n X={");
			cadena=(char *)malloc(sizeof(char));
			if (cadena == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			string(cadena,1000);
			system("cls");
			
			A=(int *)calloc(10,sizeof(int));
			if (A == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			convertir(cadena, A, len);
			//printf("\n CADENA: %s", cadena);
		}
		if(m==1){
			//Construir topologías
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
			printf("\n 1. Ver las topologías.");
			printf("\n 2. Ver las NO topologías.");
			printf("\n Escriba el número de la opción deseada: ");
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
							printf(" es topología de X.\n");
							printf(" Ya que {} es elemento de T.");
							printf("\n X es elemento de T.");
							printf("\n La unión arbitraria de elementos de T son elementos de P(P(X)).");
							printf("\n La intersección finita de elementos de T son elementos de P(P(X)).");
							t++;
							printf("\n 1. Ver la siguiente opción. \n 2. Salir.\n Seleccione el número de la opción deseada: ");
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
									printf(" por lo cual no es topología de X.");
							}
							else{
								printf("\n Lo siento, pero el conjunto X no está en la topología.");
							}
						}
						else{
							printf("\n No tiene al vació como elemento de la topología.");
						}
						
					
						printf("\n 1. Ver la siguiente opción. \n 2. Salir.\n Seleccione el número de la opción deseada: ");
						tec=escanerInt(1,2);
						if (tec==2) break;
					}
					else{
						printf("\n No tiene suficientes elementos para ser topología.");
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
			//Verificar topología
			char *cadena2;
			ele *t;
			int total, ap=0, x=0, v=0,u=0,n=0;
			cadena2=(char *)malloc(sizeof(char));
			if (cadena2 == NULL) {
		        printf("Error en la asignación de memoria.\n");
		        return 1;
		    }
			printf("\n Ingrese una topología."
					"\n 1. Todos los elementos de la topología deben estar separados por comas o espacios."
					"\n 2. Para el conjunto vacío usar {}."
					"\n 3. Todo elemento de la topología debe ser un subconjunto de los números reales."
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
						printf("\n - Tiene al conjunto vacío como elemento de T.");
						v=2;
						continue;
					}
				}
				if(unionBarbara(t, total,1) && interBarbara(t, total,1)){
					printf("\n - La unión arbitraria de elementos de P(P(X)) son elementos de P(P(X))");
					printf("\n - La intersección arbitraria de elementos de P(P(X)) son elementos de P(P(X))");
					u=3;
				}
				else{
					printf("\n Algún elemento con la unión o intersección de otros elementos no es un elemento de T.");
					printf("\n Por lo tanto, T NO es topología de X.\n");
					n=0;
					continue;
				}
				
				if(!v || !x){
					printf("\n El vacío o el conjunto X no está en T.");
					printf("\n Por lo tanto, T NO es topología de X.\n");
					continue;
				}
		        
			}
			if(v && n && u && x){
				printf("\n Por lo tanto, T es topología de X.");
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
