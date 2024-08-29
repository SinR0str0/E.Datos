# Pt4. Memoria Dinámica

## Créditos
Elaborado por Hernández Peña Angel Adrian y Gil De Gaona Jazmín.  
Materia: Estructura de Datos.  
Escuela: Facultad de Estudios Superiores Acatlán.  
Entrega: 30 de agosto de 2024.  

## Objetivos

- Aprender a usar memoria dinámica para la creación de matrices.  
- Manejo y manipulación de matrices unidimensionales y bidimensionales.  
- Comprender el uso de los apuntadores.  

## Problemas

### Arreglos Unidimensionales
**ACTIVIDAD:** Realice un programa en lenguaje C que genere una lista de los primeros 10 números pares, luego, imprimirlos en orden inverso.  
Posteriormente deberá modificar el valor almacenado en el índice correspondiente al último dígito de su número cuenta por -1.  
*Por ejemplo:*  

```
| 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 |
```
Número de cuenta `410092686`
```
| 2 | 4 | 6 | 8 | 10 | 12 | -1 | 16 | 18 | 20 |
```

### Arreglos bidimensionales
**ACTIVIDAD 1:** Considerando el siguiente arreglo matricial: 
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

**ACTIVIDAD 2:** Genere un arreglo dinámico variable bidimensional de acuerdo a su número de cuenta y será rellenado con los dígitos correspondientes a su cuenta. Por ejemplo para el número de cuenta `410592683`:  
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