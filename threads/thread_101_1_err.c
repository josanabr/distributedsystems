/**

Este programa evidencia que cuando se trabaja con hilos, y en este caso 
particular, existen al menos dos hilos de ejecucion: el del 'main' y el que se
crea para ejecutar la funcion 'inc_x'.

Que se observa que sucede? Que estuvo mal? Como corregir el problema?

Author: John Sanabria - john.sanabria@correounivalle.edu.co
Date: 2019-09-17

*/
#include <pthread.h>
#include <stdio.h>

#define MAX 10000

void *inc_x(void *x_void_ptr);

int main() {
	int x = 0,
	    y = 0;
	printf("x: %d, y: %d\n", x, y);
	pthread_t inc_x_thread;
	if (pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread\n");
		return 2;
	}
	while (++y < MAX);
	printf("y increment finished\n");
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

void *inc_x(void *x_void_ptr) {
	int *x_ptr = (int *)x_void_ptr;
	while (++(*x_ptr) < MAX);
	printf("x increment finished\n");
	return NULL;
}
