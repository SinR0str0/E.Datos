/*
archivo.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

typedef enum simbolo{
	entero,
	conjunto
}tipo;

typedef struct e1{
	//Estructura de enteros, letras y cadenas.
	tipo t;
	union{
		int i;
		struct{
			int *arr;
			int len;
		}set;
		struct{
			struct e1 *arr;
			int len;
		}set2;
	} data;
}ele;

int sonIguales(ele a, ele b) {
	int i;
    if (a.t == conjunto && b.t == conjunto) {
        if (a.data.set.len != b.data.set.len) {
            return 0;  // Diferente longitud
        }
        for (i = 0; i < a.data.set.len; i++) {
            if (a.data.set.arr[i] != b.data.set.arr[i]) {
                return 0;  // Diferentes elementos
            }
        }
        return 1;  // Son iguales
    }
    return 0;
}

ele *eliminarDuplicados(ele *arr, int *total) {
	int i,j;
    int len = *total;
    ele *unicos = (ele *)malloc(len * sizeof(ele));
    if (!unicos) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    int unicosLen = 0;
    for (i = 0; i < len; i++) {
        int esDuplicado = 0;
        for (j = 0; j < unicosLen; j++) {
            if (sonIguales(arr[i], unicos[j])) {
                esDuplicado = 1;
                break;
            }
        }
        if (!esDuplicado) {
            unicos[unicosLen++] = arr[i];
        }
    }

    *total = unicosLen;
    return unicos;
}

void imprimirEle(ele e) {
	int i;
    if (e.t == entero) {
        printf("%d", e.data.i);
    } else if (e.t == conjunto) {
        if (e.data.set.len == 0) {
            printf("{}"); // Conjunto vacío
        } else {
            printf("{");
            for (i = 0; i < e.data.set.len; i++) {
                printf("%d", e.data.set.arr[i]);
                if (i < e.data.set.len - 1) {
                    printf(", ");
                }
            }
            printf("}");
        }
    }
}

void imprimirEle2(ele e) {
	int i;
    if (e.t == entero) {
        printf("%d", e.data.i);
    } else if (e.t == conjunto) {
        if (e.data.set2.len == 0) {
            printf("{}");  // Conjunto vacío
        } else {
            printf("{");
            for (i = 0; i < e.data.set2.len; i++) {
                imprimirEle(e.data.set2.arr[i]);  // Imprimir subconjunto de elementos tipo ele
                if (i < e.data.set2.len - 1) {
                    printf(", ");
                }
            }
            printf("}");
        }
    }
}

int compararEnteros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

ele unionConjuntos(ele a, ele b) {
	int i,j;
    ele result;
    result.t = conjunto;
    
    // Crear un arreglo temporal para almacenar la unión
    int tempLen = a.data.set.len + b.data.set.len;
    int *tempArr = (int *)malloc(tempLen * sizeof(int));
    
    int pos = 0;

    // Copiar los elementos de 'a'
    for (i = 0; i < a.data.set.len; i++) {
        tempArr[pos++] = a.data.set.arr[i];
    }

    // Añadir los elementos de 'b' si no están en 'a'
    for (i = 0; i < b.data.set.len; i++) {
        int found = 0;
        for (j = 0; j < a.data.set.len; j++) {
            if (b.data.set.arr[i] == a.data.set.arr[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            tempArr[pos++] = b.data.set.arr[i];
        }
    }

    // Ordenar el arreglo resultante
    qsort(tempArr, pos, sizeof(int), compararEnteros);

    // Asignar el tamaño real de la unión
    result.data.set.len = pos;
    result.data.set.arr = (int *)malloc(pos * sizeof(int));
    for (i = 0; i < pos; i++) {
        result.data.set.arr[i] = tempArr[i];
    }

    free(tempArr);
    return result;
}

ele interConjuntos(ele a, ele b) {
	int i,j;
    ele result;
    result.t = conjunto;
    
    // Crear un arreglo temporal para almacenar la intersección
    int tempLen = (a.data.set.len < b.data.set.len) ? a.data.set.len : b.data.set.len;
    int *tempArr = (int *)malloc(tempLen * sizeof(int));
    
    int pos = 0;

    // Añadir los elementos de 'b' si están en 'a'
    for (i = 0; i < a.data.set.len; i++) {
        for (j = 0; j < b.data.set.len; j++) {
            if (a.data.set.arr[i] == b.data.set.arr[j]) {
                tempArr[pos++] = a.data.set.arr[i];
                break;
            }
        }
    }

    // Ordenar el arreglo resultante
    qsort(tempArr, pos, sizeof(int), compararEnteros);

    // Asignar el tamaño real de la intersección
    result.data.set.len = pos;
    result.data.set.arr = (int *)malloc(pos * sizeof(int));
    for (i = 0; i < pos; i++) {
        result.data.set.arr[i] = tempArr[i];
    }

    free(tempArr);
    return result;
}

int unionBarbara(ele *PPx, int totalSubconjuntos, int ver) {
	int i,j,k,bandera=0;

    for (i = 0; i < totalSubconjuntos; i++) {
        for (j = i + 1; j < totalSubconjuntos; j++) {
            // Realizar la unión de PPx[i] y PPx[j]
            ele unionResult = unionConjuntos(PPx[i], PPx[j]);
            
            /*
            printf("\n La union de: ");
            imprimirEle(PPx[i]);
            printf(" con ");
            imprimirEle(PPx[j]);
            printf(" es ");
            imprimirEle(unionResult);
            */
            
            // Verificar si la unión está en PPx
            for (k = 0; k < totalSubconjuntos; k++) {
                if (sonIguales(unionResult, PPx[k])) {
                    free(unionResult.data.set.arr);  // Liberar memoria
                    bandera=1;
					break;  // La unión está en PPx
                }
                bandera=0;
            }
            if(!bandera){
            	if(ver){
	            	printf("\n ");
	               	imprimirEle(PPx[i]);
	               	printf(" U ");
	               	imprimirEle(PPx[j]);
	               	printf(" = ");
	                imprimirEle(unionResult);
	                printf(" y no es elemento de P(P(A))");
	            }
            	free(unionResult.data.set.arr);
            	return 0;
			}
            
            free(unionResult.data.set.arr);  // Liberar memoria
        }
    }
    if(bandera)
    	return 1;
    else
    	return 0;
}

int interBarbara(ele *PPx, int totalSubconjuntos, int ver) {
	int i,j,k;

    for (i = 0; i < totalSubconjuntos; i++) {
        for (j = i + 1; j < totalSubconjuntos; j++) {
            // Realizar la intersección de PPx[i] y PPx[j]
            ele interResult = interConjuntos(PPx[i], PPx[j]);
            
            /*
            printf("\n La inter de: ");
            imprimirEle(PPx[i]);
            printf(" con ");
            imprimirEle(PPx[j]);
            printf(" es ");
            imprimirEle(interResult);
            */
            
            // Verificar si la intersección está en PPx
            int found = 0;
            for (k = 0; k < totalSubconjuntos; k++) {
                if (sonIguales(interResult, PPx[k])) {
                    free(interResult.data.set.arr);  // Liberar memoria
                    found = 1;
                    break;  // La intersección está en PPx
                }
            }
            if (!found) {
            	if(ver){
            		printf("\n ");
	               	imprimirEle(PPx[i]);
	               	printf(" n ");
	               	imprimirEle(PPx[j]);
	               	printf(" = ");
	                imprimirEle(interResult);
	                printf(" y no es elemento de P(P(A))");
				}
                free(interResult.data.set.arr);
                return 0;  // La intersección no está en PPx
            }
            free(interResult.data.set.arr);  // Liberar memoria
        }
    }
    return 1; 
}

int isX(ele x, int *X, int max) {
	int i;
    if (x.t == conjunto) {
    	//printf("\n A: ");
		//imprimirEle(x);
		//printf("len: %d vs %d", x.data.set.len, max);
        if (x.data.set.len == max) {
            for (i = 0; i < max; i++) {
            	//printf("%d vs %d",x.data.set.arr[i] , X[i] );
                if (x.data.set.arr[i] != X[i]) {
					return 0;
                }
            }
            return 1;
        }
    }
    return 0; 
}

void agregarConjuntoVacio(ele *p, int *size){
	//Agregar al vacío
	p[*size].t = conjunto;
    p[*size].data.set.arr = NULL; // Conjunto vacío
    p[*size].data.set.len = 0;
    (*size)++;
}

void agregarConjuntoVacio2(ele *p, int *size){
	//Agregar al vacío
	p[*size].t = conjunto;
    p[*size].data.set2.arr = NULL; // Conjunto vacío
    p[*size].data.set2.len = 0;
    (*size)++;
}

ele *potenciaInt(int *arr, int len, int *totales){
	//Crear conjunto potencia
    int total = pow(2,len);  // 2^len subconjuntos
    ele *potencia = (ele *)malloc(total * sizeof(ele));
    if (!potencia) {
        // Error al asignar memoria
        return NULL;
    }
    
	int index = 0, i,j,k;

    // Agregar el conjunto vacío
    agregarConjuntoVacio(potencia, &index);

    // Generar todos los subconjuntos
    for(i = 1; i < total; i++){
        int tam = 0;

        // Contar el número de elementos en el subconjunto
        for (j = 0; j < len; j++){
            if (i & (1 << j)) {
                tam++;
            }
        }

        // Asignar memoria para el subconjunto
        potencia[index].t = conjunto;
        potencia[index].data.set.arr = (int *)malloc(tam * sizeof(int));
        if (!potencia[index].data.set.arr) {
            // Error al asignar memoria
            free(potencia);
            return NULL;
        }
		potencia[index].data.set.len = tam;
        

        int pos = 0;
        for (k = 0; k < len; k++){
            if (i & (1 << k)) {
                potencia[index].data.set.arr[pos] = arr[k];
                pos++;
            }
        }
        index++;
    }

    *totales = total;
    return potencia;
}

ele *potenciaEle(ele *arr, int len, int *totales) {
    // Crear conjunto potencia
    int total = pow(2, len);  // 2^len subconjuntos
    ele *potencia = (ele *)malloc(total * sizeof(ele));
    if (!potencia) {
        // Error al asignar memoria
        return NULL;
    }

    int index = 0, i, j, k;

    // Agregar el conjunto vacío
    agregarConjuntoVacio2(potencia, &index);

    // Generar todos los subconjuntos
    for (i = 1; i < total; i++) {
        int tam = 0;

        // Contar el número de elementos en el subconjunto
        for (j = 0; j < len; j++) {
            if (i & (1 << j)) {
                tam++;
            }
        }

        // Asignar memoria para el subconjunto
        potencia[index].t = conjunto;
        potencia[index].data.set2.arr = (ele *)malloc(tam * sizeof(ele));
        if (!potencia[index].data.set2.arr) {
            // Error al asignar memoria
            free(potencia);
            return NULL;
        }
        potencia[index].data.set2.len = tam;

        int pos = 0;
        for (k = 0; k < len; k++) {
            if (i & (1 << k)) {
                potencia[index].data.set2.arr[pos] = arr[k];  // Copiar elemento tipo ele
                pos++;
            }
        }
        index++;
    }

    *totales = total;
    return potencia;
}

// Función para procesar la entrada y convertirla en la estructura ele
ele *procesarEntrada(char *input, int *total) {
    ele *result = (ele *)malloc(100 * sizeof(ele)); // Capacidad inicial arbitraria
    if (!result) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    int resultLen = 0;
    int len = strlen(input);
    char *p = input;

    while (*p) {
        if (*p == '{') {
            p++; // Avanzar al siguiente carácter
            if (*p == '}') {
                agregarConjuntoVacio2(result, &resultLen);
                p++;
            } else {
                // Leer los elementos del conjunto
                int *tempArr = (int *)malloc(10 * sizeof(int)); // Capacidad inicial arbitraria
                int tempLen = 0;
                while (*p != '}' && *p) {
                    if (isdigit(*p)) {
                        int val = 0;
                        while (isdigit(*p)) {
                            val = val * 10 + (*p - '0');
                            p++;
                        }
                        tempArr[tempLen++] = val;
                    } else if (*p == ',') {
                        p++; // Ignorar coma
                    } else {
                        p++;
                    }
                }
                
                result[resultLen].t = conjunto;
                result[resultLen].data.set2.arr = (ele *)malloc(tempLen * sizeof(ele));
                if (!result[resultLen].data.set2.arr) {
                    printf("Error al asignar memoria.\n");
                    return NULL;
                }
                memcpy(result[resultLen].data.set2.arr, tempArr, tempLen * sizeof(int));
                result[resultLen].data.set2.len = tempLen;
                resultLen++;
                p++; // Avanzar al siguiente carácter
                free(tempArr);
            }
        } else {
            p++;
        }
    }

    *total = resultLen;
    return result;
}

void imprimirConjuntoPotencia2(ele *potencia, int total) {
    int i;
	printf("{ ");
    for (i = 0; i < total; i++) {
        imprimirEle2(potencia[i]);
        if (i < total - 1) {
            printf(", ");
        }
    }
    printf(" }\n TOTAL: %d\n",total);
}

void imprimirConjuntoPotencia(ele *potencia, int total) {
    int i;
	printf("{ ");
    for (i = 0; i < total; i++) {
        imprimirEle(potencia[i]);
        if (i < total - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void imprimirNum(int *C, int len){
	//Imprime numeros en un conjunto de numeros
	int i;
	for(i=0; i<len; i++)
		printf("%d ", C[i]);
}

int convertir(char *cadena, int *C, int max){
	//Pasar letras a números:
	int i=0,j=0, count=0;
	int *auxiliar = (int *)malloc(max * sizeof(int));
	char *token = strtok(cadena, " ");
    while (token != NULL && i<max) {
        C[i] = atoi(token);
        i++;
        // Obtener el siguiente token
        token = strtok(NULL, " ");
    }
    
     for (i = 0; i < max; i++) {
        int esRepetido = 0;
        
        // Comprobar si el elemento ya ha sido contado
        for (j = 0; j < i; j++) {
            if (C[i] == C[j]) {
                esRepetido = 1;  // Marcamos que el elemento es repetido
                break;
            }
        }

        if (!esRepetido) {
            count++;  // Incrementamos el contador de elementos distintos
        } else {
            // Si es repetido, desplazamos los elementos a la izquierda
            for (j = i; j < max - 1; j++) {
                C[j] = C[j + 1];
            }
            max--;  // Reducimos el tamaño del arreglo
            i--;          // Retrocedemos un paso en el índice para revisar el nuevo valor en la posición
        }
    }

    return count;
}

void string(char *cadena, int max){
	//Leer string
	int i;
	
    fflush(stdin);
    fgets(cadena, max, stdin);
    
    // Eliminar el salto de línea si está presente
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
    
    for(i=0; i<strlen(cadena); i++){
    	if(cadena[i]==','){
    		if (cadena[i+1]!=' ' || cadena[i-1]!=' '){
    			cadena[i]=' ';
			}
			else if(cadena[i+1]==' ' && cadena[i-1]==' '){
				cadena[i]=' ';
			}
			else if(cadena[i]=='}'){
				cadena[i]='\0';
			}
		}
	}
	/*
	printf("\n La cadena es: %s", cadena);
	system("pause");
	*/
}
int tienePunto(const char *cadena) {
    while (*cadena) {
        if (*cadena == '.') {
            return 1;
        }
        cadena++;
    }
    return 0;
}
int esNumero(const char *cadena) {
    while (*cadena) {
        if (!isdigit(*cadena)) {
            return 0;
        }
        cadena++;
    }
    return 1;
}

int esN(const char *cadena) {
    while (*cadena!=EOF && *cadena !='\n' && *cadena!='\0') {
    	//printf("\n Comprobando: %c", *cadena);
        if (!isdigit(*cadena) && *cadena != ',' && *cadena != ' ' && *cadena!='\0' && *cadena!='{' && *cadena!='}') {
            //printf("\"%c\" no es nada :)",*cadena);
			return 0;
        }
        cadena++;
    }
    return 1;
}

int escanerInt(int min, int max){
	//Función para leer números int sin errores
	
    int var;
    fflush(stdin);
    while(1){
    	char *cadena = NULL;
	    char c='\n';
	    size_t tamano = 0;
	    size_t capacidad = 0;
	    while ((c = getchar()) != '\n' && c != EOF) {
	        // Asegurar que hay suficiente espacio
	        if (tamano + 1 >= capacidad) {
	            capacidad += 1;
	            cadena = (char*)realloc(cadena, capacidad * sizeof(char));
	            if (cadena == NULL) {
	                printf("Error de asignación de memoria\n");
	                return 1;
	            }
	        }
	        cadena[tamano++] = c;
	    }
	    if(cadena==NULL){
			continue;
		}
	    cadena[tamano] = '\0';  // Finalizamos la cadena
	    fflush(stdin);   
		//printf("\n Cadena es: %s | %d", cadena, strlen(cadena));
	    
	    //printf("\n La cadena es: %s", cadena);
	    if(tienePunto(cadena)){
	    	printf("\n Ay si, ahora resulta que el 0 no puede ser natural, pero ese número es un entero.");
	    	printf("\n Ingrese un número natural: ");
			free(cadena);
			continue;
		}
		if(!esNumero(cadena)){
			printf("\n Lo siento, pero %s no es un entero.");
			printf("\n Ingrese un número natural: ");
	    	free(cadena);
	    	continue;
		}
		var = atoi(cadena);
		//printf("\n La cadena es: %s>%d", cadena, var);
		if(min||max){
			if(var>4 && max==4){
				printf("\n No se pase profesor, mi RAM no aguantará tanto cálculo :(.");
				printf("\n Ingrese un número natural menor a 5: ");
				free(cadena);
				continue;
			}
			else if (var <(float)min || var > (float)max){
				printf("\n Lo siento, ingrese un número entre %d y %d: ", min, max);
				free(cadena);
				continue;
			}
		}
		else{
			if(var<=0){
				fflush(stdin);
				printf("\n Lo siento, ingrese un número natural válido: ");
				continue;
			}
		}
		break;
	}
		
	fflush(stdin);
	return var;
}

void configuraIdioma(){
	//Cambiar idioma a español (acepta ñ y acentos)
	struct lconv *lcPtr;
	setlocale(LC_ALL,"spanish");
	lcPtr = localeconv();
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";	
}
