#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *x, y, i,t,d;
	x = (int*) calloc (1,sizeof (int));
	printf("\nTamano del arreglo: ");
	scanf ("%d",&y);
	
	x = (int*) realloc(x, y * sizeof(int));
	for(i=0; i<y; i++){
		 printf("Ingresa los datos:" );
		 scanf("%d",&x[i]);//Guarda los datos.
	}
	for (i=0; i<y; i++){
		printf("\n%d",x[i]); //Recoge el dato.
	}
	
	printf("Ingresa un numero negativo");
	scanf("%d",&t);
	d = y + t + 1; 
	
	printf("\n Valor de la posicion: %d", x[d]);
	
	free(x);
	
	return 0; 
}

