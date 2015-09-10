# Fork()
Este directorio contiene algunos programas en C que muestran el uso de la
funcion `fork()`.

Estos son los archivos que contiene el presente directorio

- `makefile`: archivo usado para compilar los programas en este directorio
- `run.sh`: un script en bash que le permitira ejecutar un programa un numero 
determinado de veces
- `fork_00.c`: programa en C que pretende mostrar como un padre y un hijo corren 
de forma simultanea
- `fork_01.c`: programa en C que muestra como las variables de un padre y un hijo
no se comparten 
- `README.md`: este archivo
- `fork.c`, `forfork.c` algunos codigos para evaluar que tanto entendiste la funcion `fork()`.

## Una breve introduccion al `fork()`
#include "fork\_101.c"

## Ejecutando el codigo
### fork\_00

Este codigo pretende mostrar que una vez un programa en C invoca la funcion `fork()` esto causa que dos procesos "iguales" se encuentren ahora en el sistema y ejecutandose de forma independiente.
El estudiante debera ejecutar los siguientes pasos:
- Compilar el codigo y luego ejecutarlo
	- Ejecute el comando `make all`
	- Ejecute el comando `./run.sh fork\_00`
	- Explique lo que observa

- Edite el archivo `fork\_00.c` y encuentre un comentario en el  codigo numerado
con el valor `1.`. Proceda a descomentar las lineas y repita los pasos del item
1- en este documento

- Edite el archivo `fork\_00.c` y encuentre un comentario en el codigo numerado
con el valor `2.`. Proceda a descomentar las lineas y repita los pasos del item
1- en este documento

### fork\_01
Este codigo muestra como procesos creados con la instruccion `fork()` **NO 
comparten variables**. El estudiante debera 
- Compilar el programa `fork_01.c`, `make fork_01`
- Ejecutar el programa `fork\_01`, `./fork\_01`
- Que observa?

## Tarea
Modifique su programa en C de modo que el padre sea quien imprima la respuesta 
correcta PERO el padre debera sumar el valor de `a` (comun a los dos procesos) 
con el valor de `b` que le asigno el hijo a dicha variable. El programa al final
debera imprimir `La suma es: 6`.

## Que tanto dominas el tema?
Sin compilar los codigos indique la salida de los siguientes programas
- `fork.c`
- `forfork.c`
