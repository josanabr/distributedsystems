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
 
	

## Recursos

La información de los ejemplos en este repositorio se tomaron de diversas fuentes que se listan a continuación.

* [OpenMP by Example](http://people.math.umass.edu/~johnston/PHI_WG_2014/OpenMPSlides_tamu_sc.pdf)
* [Guide Into OpenMP](http://bisqwit.iki.fi/story/howto/openmp/)
* [A "Hands-on" Introduction to OpenMP](http://openmp.org/mp-documents/omp-hands-on-SC08.pdf)
