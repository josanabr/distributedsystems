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

* **MPI_Comm_rank** esta funcion indica que identificador tiene este proceso en 

* as
