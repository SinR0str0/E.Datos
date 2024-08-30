/*
Alumno: Hernández Peña Angel Adrian, Gil de Gaona Jazmín
Grupo: 1301
Programación II. Facultad de Estudios Superiores Acatlán
Fecha de realización: 29/08/24
Fecha de actualización: 29/08/24

Características del programa: 
Realizar un programa con memoria dinámica que acepte una lista de n estudiante con los datos:
- Nombre del alumno (Hasta 25 caracteres)
- Calificación
- Edad
Además, deberá mostrar el promedio de edad y de calificaciones del grupo, junto con la impresión de los
nombres de alumnos en sentido inverso al ingresado.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void configuraIdioma();
int escanerInt(int min, int max);
void imprimirNombres(char ***tabla, int max);
void imprimir(char ***tabla, int max);
float promedioEdad(char ***tabla, int max);
float promedioCal(char ***tabla, int max);

int main(int argc, char *argv[]){
	configuraIdioma();
	int n, i, max=25;
	char ***tabla;
	
	printf("\n Ingrese el número de alumnos a promediar: ");
	n = escanerInt(0,0);
	tabla = (char ***) calloc (n, sizeof(char**));
	
	if(tabla==NULL)
		return -1;
		
	for(i=0; i<n; i++){
		tabla[i]=(char **) calloc(3, sizeof(char*));
		if(tabla[i]==NULL)
			return -1;
		
		printf("\n Ingrese el nombre %d: ", i+1);
		tabla[i][0]=(char *) calloc(25, sizeof(char ));
		if(tabla[i][0]==NULL)
			return -1;
		fflush(stdin);
		fgets(tabla[i][0], max, stdin);
		fflush(stdin);
		tabla[i][0][strcspn(tabla[i][0], "\n")] = 0;
		
		tabla[i][1] = (char *) calloc(3, sizeof(char));
        if(tabla[i][1] == NULL)
            return -1;
        printf(" Ingrese la edad %d: ", i + 1);
        sprintf(tabla[i][1], "%d", escanerInt(1, 150));

        tabla[i][2] = (char *) calloc(2, sizeof(char));
        if(tabla[i][2] == NULL)
            return -1;
        printf(" Ingrese la calificación %d: ", i + 1);
        sprintf(tabla[i][2], "%d", escanerInt(0, 10));
	}
	
	imprimir(tabla, n);
	
	printf("\n El promedio de edad es: %.2f", promedioEdad(tabla, n));
    printf("\n El promedio de calificaciones es: %.2f", promedioCal(tabla, n));

	imprimirNombres(tabla, n);
	
	for(i=n-1;i>=0; i--)
		free(tabla[i]);
	free(tabla);
	
	return 0;
}

float promedioCal(char ***tabla, int max){
	//Obtiene el promedio de calificaciones de los estudiantes
	int i, valor=0;
	for(i=0; i<max; i++)
		valor+=atoi(tabla[i][2]);
	
	return (float)valor/max;
}

float promedioEdad(char ***tabla, int max){
	//Obtiene el promedio de la edad de los estudiantes
	int i, valor=0;
	for(i=0; i<max; i++)
		valor+=atoi(tabla[i][1]);
	
	return (float)valor/max;
}

void imprimir(char ***tabla, int max){
	//Imprimir tabla
    int i;
    printf("\n\n            Nombre         | Edad  | Calificación");
    printf("\n -------------------------------------------------");
    for(i=0; i<max; i++)
        printf("\n %-25s | %5d | %6d", tabla[i][0], atoi(tabla[i][1]), atoi(tabla[i][2]));
    printf("\n");
}

void imprimirNombres(char ***tabla, int max){
	//Imprimir solo los nombres en sentido opuesto
    int i, x=1;
    printf("\n Listado de nombres:");
    for(i=max-1; i>=0; i--){
        printf("\n %d. %-25s",x, tabla[i][0]);
        x++;
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
