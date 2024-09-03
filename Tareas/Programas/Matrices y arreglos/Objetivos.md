# Programas Tareas
En este apartado se muestran todos los aprendizajes esperados y programas a realizar en la materia de Estructura de Datos.  

## Créditos
Elaborado por Hernández Peña Angel Adrian y Gil De Gaona Jazmín.  
Materia: Estructura de Datos.  
Escuela: Facultad de Estudios Superiores Acatlán.  
Ultima actualización: 02 de septiembre de 2024.  

## Pt3. Lectura de Matrices

### Fecha de entrega
19 de agosto de 2024.  

### Objetivos

- Comprender el funcionamiento de los bucles y bucles anidados.  
- Aprender diferentes formas de recorrer una matriz estática.  
- Utilizar GitHub para subir archivos de código.  

### Actividades

Se requiere desarrollar un programa que implemente funciones para leer matrices estáticas de diferentes formas:  

1. **Matriz 6x4**: Leer los elementos en forma de "S" invertida.  
2. **Matriz 6x6**: Leer los elementos en forma de "Z".  
3. **Matriz 6x6**: Leer los elementos en forma de "Z", pero de abajo hacia arriba.  
4. **Matriz 3x4**: Leer los elementos en forma "invertida", es decir, de derecha a izquierda y de abajo hacia arriba.  
Para desarrollar mejor esto, se anexa la imagen usada como referencia de los programas:  

![Diagrama de Matrices](https://github.com/SinR0str0/E.Datos/raw/main/Tareas/Diagramas/pt_3_diagram.png)

## Pt4. Memoria Dinámica

### Fecha de entrega
19 de agosto de 2024.  

### Objetivos

- Aprender a usar memoria dinámica para la creación de matrices.  
- Manejo y manipulación de matrices unidimensionales y bidimensionales.  
- Comprender el uso de los apuntadores.  

### Problemas

#### Arreglos Unidimensionales
**ACTIVIDAD 1:** Realice un programa en lenguaje C que genere una lista de los primeros 10 números pares, luego, imprimirlos en orden inverso.  
Posteriormente deberá modificar el valor almacenado en el índice correspondiente al último dígito de su número cuenta por -1.  
*Por ejemplo:*  

```
| 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 |
```
Número de cuenta `410092686`
```
| 2 | 4 | 6 | 8 | 10 | 12 | -1 | 16 | 18 | 20 |
```

#### Arreglos bidimensionales
**ACTIVIDAD 2:** Considerando el siguiente arreglo matricial: 
| Nombre   | Edad | Calificación |
|----------|------|--------------|
| Alberto  | 22   | 9            |
| Fernando | 19   | 4            |
| ...  	   | ...  | ...          |
| Brenda   | 34   | 7            |

Realice un programa que acepte una lista de `n` alumnos, el arreglo deberá ser de `nx3`, la primera columna deberá tener un espacio de 25 caracteres, la segunda y tercera deberá aceptar números enteros.  

El programa después de capturar los datos, deberá devolver el promedio de edad y de calificación grupal.  
El programa deberá imprimir los nombres de los alumnos en sentido inverso al que fueron ingresados o se encuentran almacenados.  
Puede ser del tipo char todo el arreglo, solo recuerde hacer el "casteo" para los elementos numéricos.  

**ACTIVIDAD 3:** Genere un arreglo dinámico variable bidimensional de acuerdo a su número de cuenta y será rellenado con los dígitos correspondientes a su cuenta. Por ejemplo para el número de cuenta `410592683`:  
```
| 4 | 4 | 4 | 4 | 
| 1 |
| 5 | 5 | 5 | 5 | 5 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 2 | 2 |
| 6 | 6 | 6 | 6 | 6 | 6 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 3 | 3 | 3 |
```
Además, el programa deberá solicitar el número de cuenta al usuario.  

## Pt4. Listas de Caracteres

### Fecha de entrega
18 de septiembre de 2024.  

### Objetivos

- Entender el uso de listas ligadas.  
- Utilización de librerias para las actividades.  
- Comprender el uso de los apuntadores.  

### Problemas
PENDIENTES DE ESCRIBIR.  





## Actividades Extras.
Los siguientes programas ya han sido terminados, sin embargo, no se ha especificado fecha de entrega para estos, por lo cual tendrán una nomenclatura diferete a la usual, pero en cuanto se soliciten, esta nomenclatura cambiará.

### Matrices Unidimensionales y Bidimensionales

### Objetivo

- Entender como los lenguajes de programación actuales permiten matrices bidimensionales.  
- Utilizar argc y argv para leer datos desde la ejecución del archivo.  
- Comprender el recorrido de matrices.  

### Problema

Se necesita un programa capaz de transformar un arreglo unidimensional de 12 datos a uno bidimensional de tamaño 4x3.  

### EJEMPLO:
`A={1,2,3,4,5,6,7,8,9,10,11,12}`  
Resultado:  
```
1  2  3  
4  5  6  
7  8  9  
10 11 12  
```

### Índices Negativos

### Objetivos

- Acceder a elementos en un arreglo a través de un recorrido inverso de la matriz.  
- Comprender como otros lenguajes de programación aceptan entradas negativas para obtener datos.  
- Crear una nueva forma de acceder a datos en el arreglo.  

### Problema

Se requiere un programa que, dado un arreglo unidimensional de `n` elementos, si ingreso un índice válido positivo o negativo, este me imprimirá el valor que se almacena en dicho índice del arreglo.

#### EJEMPLO:
`arreglo = {0,1,3,5,8};`  
`print(arreglo[-3]) -> 3`  
`print(arreglo[-2]) -> 5`  