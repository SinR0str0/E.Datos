#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "archivo.h"

typedef enum menu{
	salir,
	principal,
	secundaria
}menu;

int main(){
	configuraIdioma();
	ele *Px, *PPx;
	int len, totales, total2, i, *A, t, m, opcional, tec=1, op;
	char *cadena;
	do{
		printf("\n Seleccione la funci�n que quiere utilizar:"
				"\n %d. De un conjunto arrojar las topolog�as."
				"\n %d. Comprobar topolog�a "
				"\n %d. Salir"
				"\n Escriba el n�mero de la opci�n deseada: ", principal, secundaria, salir);
		m=escanerInt(salir,secundaria);
		if(m){
			printf("\n Escriba la cantidad de elementos de A: ");
			len=escanerInt(1,4);
			
			printf("\n Escriba el conjunto A de naturales separado por espacios o comas:\n A={");
			cadena=(char *)malloc(sizeof(char));
			if (cadena == NULL) {
		        printf("Error en la asignaci�n de memoria.\n");
		        return 1;
		    }
			string(cadena,1000);
			system("cls");
			
			A=(int *)calloc(25,sizeof(int));
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
					"\n A={",len);
			for(i=0; i<len; i++){
				printf(" %d", A[i]);
				if(i!=len-1){
					printf(",");
				}
			}
			printf("}\n");
			Px = potenciaInt(A, len, &totales);
			/*
			printf("\n P(A)=");
			imprimirConjuntoPotencia(Px, totales);
			*/
			
			//PPx = potenciaEle(Px,totales, &total2);
			
			/*
			printf("\n P(P(A))=");
			imprimirConjuntoPotencia2(PPx,total2);
			*/
			t=0;
			printf("\n 1. Ver las topolog�as.");
			printf("\n 2. Ver todas las candidatas a topolog�a.");
			printf("\n Escriba el n�mero de la opci�n deseada: ");
			opcional = escanerInt(1,2);
			
			int total = pow(2,totales),i,j,k;
			//printf("\n TOTAL %d", total);
			// Asignar memoria para un subconjunto
		    ele *potencia = (ele *)malloc(sizeof(ele));
		    if (!potencia) {
		        fprintf(stderr, "Error al asignar memoria\n");
		        return 1;
		    }
			
		    // Generar y mostrar todos los subconjuntos
		    for (i = 0; i < total; i++) {
		        int tam = 0;
		
		        // Contar el n�mero de elementos en el subconjunto
		        for (j = 0; j < totales; j++) {
		            if (i & (1 << j)) {
		                tam++;
		            }
		        }
			
		        // Reasignar memoria para el subconjunto actual
		        potencia->t = conjunto;
		        potencia->data.set2.len = tam;
		        potencia->data.set2.arr = (ele *)malloc(tam * sizeof(ele));
		        if (!potencia->data.set2.arr) {
		            free(potencia);
		            printf("Error al asignar memoria\n");
		            return 1;
		        }
		
		        // Copiar elementos en el subconjunto
		        int pos = 0;
		        for (k = 0; k < totales; k++) {
		            if (i & (1 << k)) {
		                potencia->data.set2.arr[pos] = Px[k];  // Copiar elemento del arreglo original
		                pos++;
		            }
		        }
		        
		        //imprimirEle2(potencia[0]);
				
				int esX=0, es;
				for(es=0;es<tam;es++){
					if(isX(potencia->data.set2.arr[es],A,len)){
						esX=1;
						break;
					}
					
				}
				if(opcional==1){
					if(potencia->data.set2.arr[0].data.set2.len == 0 &&
					unionBarbara(potencia->data.set2.arr,tam,0) &&
					interBarbara(potencia->data.set2.arr,tam,0) &&
					isX(potencia->data.set2.arr[es],A,len)){
						printf("\n T=");
						imprimirEle2(potencia[0]);
						printf("\n Si es topolog�a ya que:");
						printf("\n El vac�o es elemento de T.");
						printf("\n El conjunto A es elemento de T.");
						printf("\n La uni�n barbara de elementos de T son elementos de T.");
						printf("\n La intersecci�n arbitraria de elementos de T son elementos de T.");
					}
					else
						continue;
				}
				else{
					printf("\n T=");
					imprimirEle2(potencia[0]);
					
					if(potencia->data.set2.arr[0].data.set2.len != 0){
						printf("\n T no tiene al conjunto vac�o como elemento.");
					}
					else{
						if(!isX(potencia->data.set2.arr[es],A,len)){
							printf("\n T no tiene al conjunto A como elemento.");
						}
						else{
							if(!unionBarbara(potencia->data.set2.arr,tam,1)){
								printf("\n Por lo tanto T no es topolog�a.");
							}
							else{
								if(!interBarbara(potencia->data.set2.arr,tam,1)){
									printf("\n Por lo tanto T no es topolog�a.");
								}
								else{
									printf("\n El vac�o es elemento de la topolog�a.");
									printf("\n El conjunto A es elemento de la topolog�a.");
									printf("\n La uni�n arbitraria son elementos de la topolog�a.");
									printf("\n La intersecci�n finita de elementos en T son elementos de T.");
									printf("\n Por lo tanto T SI es topolog�a.");
								}
							}
						}
					}
				}
				
		        // Liberar memoria para el subconjunto actual
		        free(potencia->data.set2.arr);
		        printf("\n\n 1. Ver siguiente candidato. \n 0. Salir. \n Escriba el n�mero de la opci�n deseada: ");
		        op=escanerInt(0,1);
		        if(op){
		        	system("cls");
				}
		        else
		        	break;
		    }
			
		    // Liberar memoria para el puntero
		    free(potencia);

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
					"\n 3. Todo elemento de la topolog�a debe ser un subconjunto de los n�meros naturales."
					"\n T={ ", cadena);
			string(cadena2,1000);
			system("cls");
			printf("\n Cantidad de elementos: %d"
					"\n A={ ",len);
			for(i=0; i<len; i++){
				printf("%d ", A[i]);
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
		        	if(isX(t[i],A,len)){
		        		x=1;
		        		printf("\n - Tiene al conjunto A como elemento de T.");
					}
					else if(t[i].data.set2.len==0){
						printf("\n - Tiene al conjunto vac�o como elemento de T.");
						v=2;
					}
				}
				if(unionBarbara(t, total,1) && interBarbara(t, total,1)){
					printf("\n - La uni�n arbitraria de elementos de P(P(A)) son elementos de P(P(A))");
					printf("\n - La intersecci�n arbitraria de elementos de P(P(A)) son elementos de P(P(A))");
					u=3;
				}
				else{
					printf("\n Alg�n elemento con la uni�n o intersecci�n de otros elementos no es un elemento de A.");
					printf("\n Por lo tanto, T NO es topolog�a de A.\n");
					n=0;
					continue;
				}
				
				if(!v || !x){
					if(!x)
						printf("\n El conjunto A no est� en T.");
					else
						printf("\n El vac�o no est� en T.");
					printf("\n Por lo tanto, T NO es topolog�a de A.\n");
					//printf("\n v_%d | n_%d | u_%d | x_%d",v,n,u,x);
					continue;
				}
		        
			}
			//printf("\n v_%d | n_%d | u_%d | x_%d",v,n,u,x);
			if(v && !n && u && x){
				printf("\n Por lo tanto, T es topolog�a de A.");
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
