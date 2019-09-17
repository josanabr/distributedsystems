/**
Este programa muestra algunos elementos basicos para la programacion de hilos en
el lenguaje C.

- Inclusion del archivo de cabecera 'pthread.h'
- Prototipo de la funcion que puede ser usada dentro de un hilo de ejecucion
- Inclusion del tipo de dato 'pthread_t'
- Uso de las funciones 'pthread_create' y 'pthread_join'
- Paso de argumentos a la funcion que correra el hilo de ejecucion

Author: John Sanabria - john.sanabria@correounivalle.edu.co
Date: 2019-09-17

*/

#include <pthread.h>
#include <stdio.h>

#define MAX 100

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
	if (pthread_join(inc_x_thread, NULL)) {
		fprintf(stderr, "Error joining thread\n");
		return 2;
	}
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

void *inc_x(void *x_void_ptr) {
	int *x_ptr = (int *)x_void_ptr;
	while (++(*x_ptr) < MAX);
	printf("x increment finished\n");
	return NULL;
}
