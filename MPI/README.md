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

### Ejercicios

* Cree un repositorio en GitHub llamado, **LS-05-02-2017-<sucodigo>**.

* Cree un directorio en su computador de trabajo llamado *LS-05-02-2017*. 
Inicialize este directorio de modo que pueda ser usado por el comando `git`.

* Cree un archivo `README.md` que contenga su
	* codigo de estudiante
	* descripcion del contenido de este repositorio

* Escriba un programa que imprima un mensaje diciendo
	* En el maestro `Yo soy el maestro y existen N procesos corriendo`
	* En los otros procesos `Yo soy un proceso con identificador M de N procesos en ejecucion`. Donde, `N` es el total de procesos en ejecucion y `M` es el identificador del proceso.
	* Guarde este codigo con el nombre `mpiEx2a.c`. Súbalo a su repositorio.
	* Ejecute este programa con 2, 4 y 8; procesos.

* Escriba un programa en el cual **solo** el maestro imprima el numero total de procesos en ejecucion.
	* Guarde este codigo con el nombre `mpiEx2b.c`. Súbalo a su repositorio.
	* Ejecute este programa con 2, 4 y 8; procesos.

## mpiExample3.c

Este codigo muestra en operacion las funciones `MPI_Send` y `MPI_Recv`.

### Ejercicios

* Compile este programa y luego ejecutelo de modo que **unicamente** dos procesos se ejecuten.

* Modifique el codigo de `mpiExample3.c` y cree un nuevo programa llamado `mpiEx3a.c` de modo que en lugar de intercambiar caracteres, se intercambien enteros. Suba su codigo a su repositorio de GitHub. 
**Hint:** El tipo de dato para enteros en MPI es `MPI_INT`.

* Escriba un programa de MPI que tenga 6 procesos y se comporte como sugiere la siguiente [figura](https://drive.google.com/file/d/0B7n65I8SStKXVlZWaThoWEpYMG8/view?usp=sharing). El proceso 0 debe recibir el valor de 5, el proceso 1 debe recibir el valor de 0 y asi sucesivamente.

## mpiExample4.c

Este programa que busca calcular la suma de los primeros 10000 numeros de forma distribuida. 
La idea es que cada nodo de procesamiento tome un rango de numeros y los procese. 
Suponga que existen 5 procesos, la idea es entonces que

* El proceso 1 calcule del valor 1 - 20000
* El prcoeso 2 calcule del valor 20001 - 40000
* El proceso 3 calcule del valor 40001 - 60000
* El proceso 4 calcule del valor 60001 - 80000
* El proceso 5 calcule del valor 80001 - 100000


### Ejercicios

* Modifique el codigo de modo que se logre llevar a cabo la tarea anteriormente descrita haciendo uso de la funcion `MPI_Reduce`.

* Un metodo para calcular el valor de **pi** es el conocido como Montecarlo. 
Una descripcion del metodo se puede encontrar [aqui](https://helloacm.com/cc-coding-exercise-finding-approximation-of-pi-using-monto-carlo-algorithm/). 
Escriba un programa en C que calcule el valor de **pi** haciendo uso de la funcion `MPI_Reduce`. 

	* Por que piensa que es importante MPI en un problema como el del calculo de **pi** usando la aproximacion Montecarlo?
	* Para que tipo de problemas entonces es apropiado MPI?

