#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindromo(char *palabra){
	int i, var=0;
	
	for(i=strlen(palabra)-1; i>=0; i--,var++){
		if(palabra[i]!=palabra[var])
			return 0;
	}
	return 1;
}

void leer(char **palabra){
	char c;
	int tam=1;
	
	*palabra=(char *) malloc(sizeof(char));
	if (*palabra == NULL)
		return;
	while(1){
		c=getchar();
		if(c!='\n'){
			tam++;
			*palabra = realloc(*palabra, tam*sizeof(char));
			if(*palabra == NULL)
				return;
			(*palabra)[tam-2]=c;
			(*palabra)[tam-1]='\0';
		}
		else{
			break;
		}
	}
}

int main(int argc, char **argv){
	char *ruta, *palabra, c;
	FILE *archivo;
	int renglon=1, len=1;
	//printf("\n Argc: %d", argc);
	if(argc<2){
		printf("\n No se ha proporcionado una ruta del archivo.");
		printf("\n Escriba la ruta del archivo: ");
		leer(&ruta);
		printf("Palabra: %s", ruta);
	
	}
	else if(strlen(argv[2])<=4){
		printf("\n La ruta del archivo es invalida.");
		printf("\n Escriba la ruta del archivo: ");
		leer(&ruta);
	}
	else{
		ruta = (char *)calloc(strlen(argv[2]),sizeof(char));
		if(ruta==NULL)
			return 1;
		strcpy(ruta,argv[2]);
	}
	
	archivo = fopen(ruta,"r");
	if(archivo==NULL){
		printf("\n El archivo no fue encontrado.\n Saliendo.");
		fclose(archivo);
		return 3;
	}
	palabra=(char *)malloc(sizeof(char));
	while(!feof(archivo)){
		c=fgetc(archivo);
		
		if(c=='\n'||c==' '||c==EOF){
			if(palindromo(palabra))
				printf("\n %d | %s", renglon, palabra);
			len=1;
			free(palabra);
			palabra=(char *)calloc(1,sizeof(char));
		}
		else if(c>='a' && c<='z'){
			len++;
			palabra=realloc(palabra,len*sizeof(char));
			palabra[len-2]=c;
			palabra[len-1]='\0';
			
		}
		if(c=='\n')
			renglon++;
	}
	
	free(ruta);
	free(palabra);
	fclose(archivo);
	return 0;
}
