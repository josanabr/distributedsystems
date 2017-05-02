# README.md

Este directorio contiene los siguientes archivos

## mpiExample1.c

Este codigo muestra el uso de las funciones `MPI_init` y  `MPI_finalize`.

Para compilar este programa ejecute las siguientes instrucciones

```
mpicc mpiExample1.c -o mpiExample1
```

Para ejecutar el programa, ejecute desde una terminal

```
mpirun --hostfile machinefile -np 2 ./mpiExample1
```

Asegurese de tener el archivo `machinefile` en el directorio de ejecucion del comando `mpirun`. 
Este archivo debe contener la siguiente informacion

```
localhost
```

## mpiExample2.c

En este programa se muestra el uso de las siguientes funciones

* **MPI_Comm_size** esta funcion determina el numero de procesos que forman parte de la ejecucion de la aplicacion MPI

* **MPI_Comm_rank** esta funcion indica que identificador tiene este proceso dentro del conjunto de procesos que forman parte de la ejecucion de esta aplicacion.
El proceso cuyo rango es `0` se identifica como el maestro de la ejecucion de este proceso.

### Ejercicios 

* Cree un repositorio en GitHub llamado, **LS-05-02-2017-<sucodigo>**.

* Cree un directorio en su computador de trabajo llamado *LS-05-02-2017*. 
Inicialize este directorio de modo que pueda ser usado por el comando `git`.

* Cree un archivo `README.md` que contenga su
	* codigo de estudiante
	* descripcion del contenido de este repositorio

* Escriba un programa que imprima un mensaje diciendo
	* En el maestro

```
Yo soy el maestro
```

	* En los otros procesos 

```
Yo soy un nodo de procesamiento con identificador N
```

Donde `N` es el identificador del proceso.
