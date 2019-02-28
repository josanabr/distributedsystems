
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

## Una breve introduccion al `fork()`

	#include <stdio.h>
	#include <unistd.h>

	int main(int argc, char **argv) {
		pid_t pid;
		pid_t mypid;
		if (pid = fork()) {
			printf("Soy el padre y mi id es %d y el id de mi hijo es %d\n",getpid(), pid);
		} else {
			printf("Soy el hijo y mi id es %d\n", getpid());
		}
		fflush(stdout);
	}

En el codigo anterior note que hay una linea que tiene estas instrucciones `pid = fork()` esto quiere decir que se invoca el metodo `fork()` y se asigna el valor retornado por `fork()` a la variable `pid`. 
Aqui es donde llega la magia. 

Despues de invocado el `fork()` se crean dos procesos exactamente iguales en el sistema operativo **con espacios de direcciones diferentes**. Un proceso tendra en su variable `pid` el valor de `0` (el hijo) y otro tendra un valor diferente de `0` (el padre). 
De esta manera el padre podra saber cual es el identificador de proceso (`pid`) de su hijo.

Corte y pegue ese codigo en un archivo .c, ejemplo `fork_101.c` y ejecutelo

	gcc fork_101.c -o fork_101
	./fork_101

Interesante, no?

## Ejecutando el codigo
### fork\_00

Este codigo pretende mostrar que una vez un programa en C invoca la funcion `fork()` esto causa que dos procesos "iguales" se encuentren ahora en el sistema y ejecutandose de forma independiente.
El estudiante debera ejecutar los siguientes pasos:
- Compilar el codigo y luego ejecutarlo
	- Ejecute el comando `make all`
	- Ejecute el comando `./run.sh fork_00`
	- Explique lo que observa

- Edite el archivo `fork_00.c` y encuentre un comentario en el  codigo numerado
con el valor `1.`. Proceda a descomentar las lineas y repita los pasos del item
1- en este documento

- Edite el archivo `fork_00.c` y encuentre un comentario en el codigo numerado
con el valor `2.`. Proceda a descomentar las lineas y repita los pasos del item
1- en este documento

### fork\_01
Este codigo muestra como procesos creados con la instruccion `fork()` **NO 
comparten variables**. El estudiante debera 
- Compilar el programa `fork_01.c`, `make fork_01`
- Ejecutar el programa `fork_01`, `./fork_01`
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
