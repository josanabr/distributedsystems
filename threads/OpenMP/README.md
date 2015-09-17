# OpenMP una librería para programación en paralelo

En este repositorio encontrará algunos ejemplos sobre OpenMP que se presentaron durante la clase del respectivo tema.

## Contenido de este repositorio

Este repositorio contiene varios ejemplos que le permitirán familiarizarse con OpenMP. 
A continuación se procederá a comentar acerca de cada uno de ellos.

* `helloword.c` Este programa muestra como un programa secuencial se puede transformar fácilmente de modo que al final se transforme en un programa que logra su ejecución de forma paralela a través de hilos de ejecución.
Este programa se ejecuta bajo tres interacciones.
	* **Interacción 0** En esta interacción lo único que debe hacer es compilar el programa `gcc helloworld.c -o helloworld`. **Observe los resultados de la ejecución.**
	* **Interacción 1** En esta interacción ud. debe hacer los ajustes al código fuente de acuerdo a como lo especifican los comentarios en el archivo `.c`. Compile el programa de la siguiente manera `gcc -fopenmp helloworld -o helloworld`. Cuantos hilos se ejecutan?
	* **Interacción 2** Haga los ajustes que correspondan al código fuente de acuerdo con lo especificado en los comentarios del programa `.c`. Compile el programa de la siguiente manera `gcc -fopenmp helloworld -o helloworld`. Cuantos hilos se ejecutan? Difiere el número de hilos con relación al anterior? Por qué?

* `parallel_00.c` En este código se puede ver en acción la invocación en paralelo de un bloque de código en C y como se especifica que una variable sea tomada como una variable privada y accesible solo para un hilo.

* `parallel_01.c` En este programa se muestra como se puede indicar un número diferentes de hilos para llevar a cabo una tarea. 

* `parallel_02.c` En este programa se muestra como se puede paralelizar un ciclo `for`. 

* `parallelblock_00.c` En este programa se muestra como se pueden paralelizar diferentes bloques de código a través de las directivas `sections` y `section`. 

* `parallelfor_00.c` En este programa se muestra la paralelización de un ciclo `for` pero además muestra una directiva de compilación llamada `reduction` que permite consolidar el valor parcial de diferentes hilos en una sola variable.

## Ejercicios propuestos

Ud. encontrará dos programas en C que sirven para calcular el valor de Pi.

* `pi.c` usa una aproximación a través del cálculo del área bajo la curva. La [gráfica](https://drive.google.com/open?id=0B7n65I8SStKXZXRZdnRxMlV2V00) muestra la aproximación que sigue el programa `.c`.

* `montecarlopi.c` usa una aproximación basada en el método Monte Carlo para de forma aleatoria se llegue a la estimación del valor de Pi.

Ud. deberá incluir las instrucciones en OpenMP que transforme estas versiones secuenciales del cálculo de Pi en versiones que se ejecuten en paralelo.

## Recursos

La información de los ejemplos en este repositorio se tomaron de diversas fuentes que se listan a continuación.

* [OpenMP by Example](http://people.math.umass.edu/~johnston/PHI_WG_2014/OpenMPSlides_tamu_sc.pdf)
* [Guide Into OpenMP](http://bisqwit.iki.fi/story/howto/openmp/)
* [A "Hands-on" Introduction to OpenMP](http://openmp.org/mp-documents/omp-hands-on-SC08.pdf)
