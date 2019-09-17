/**

En este programa se incorpora la invocacion del metodo correspondiente a la
espera de la terminacion de la ejecucion de los hilos creados en este programa.
---
NOTA AL MARGEN:
Si usted esta usando el editor 'vi' y se encuentra en modo de comando ejecutar
la siguiente secuencia de teclas ':set number'
---
Esta espera se hace a traves de la funcion 'pthread_join()' y se encuentra en
las lineas 103-113.

Que problema presenta esta solucion ahora?

Author: John Sanabria - john.sanabria@correounivalle.edu.co
Date: 2019-09-17
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THREADS 8
#define VECTOR_SIZE 100000000

// Vector de identificadores de hilos
pthread_t tid[MAX_THREADS];

// Un apuntador a un vector de enteros
int *array;
// Maxima longitud del vector
int length = VECTOR_SIZE;
int count = 0;
int double_count = 0;
int max_threads = 0;

void *count3s_thread(void *arg) {
	int i;
	int length_per_thread = length/max_threads;
	// Cast -> http://stackoverflow.com/questions/1640423/error-cast-from-void-to-int-loses-precision
	int id = (int)arg;
	int start = id * length_per_thread;
	printf("\tThread [%d] starts [%d] length [%d]\n",id, start, length_per_thread);
	for (i = start; i < start + length_per_thread; i++) {
		if (array[i] == 3) {
			count++;
		}
	}
	return NULL;
}


void initialize_vector() {
	int i = 0;
	array = (int*) malloc(sizeof(int) * VECTOR_SIZE);
	if (array == NULL) {
		printf("Allocation memory failed!\n");
		exit(-1);
	}
	for (; i < VECTOR_SIZE; i++) {
		array[i] = rand() % 20;
		if (array[i] == 3)
			double_count++;
	}
}

int main(int argc, char* argv[]) {
	int i = 0;
	int err;
	clock_t t1, t2;

	if (argc == 2) {
		max_threads = atoi(argv[1]);
		if (max_threads > MAX_THREADS)
			max_threads = MAX_THREADS;
	} else {
		max_threads = MAX_THREADS;
	}
	printf("[3s-02] Using %d threads\n",max_threads);
	// random seed
	// http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	printf("*** 3s-02 ***\n");
	srand(time(NULL));
	printf("Initializing vector... ");
	fflush(stdout);
	initialize_vector();
	printf("Vector initialized!\n");
	fflush(stdout);
	// Se comienza a contabilizar el tiempo transcurrido
	t1 = clock();
	// Bucle para crear hilos
	while (i < max_threads) {
		err = pthread_create(&tid[i], NULL, &count3s_thread, (void*)i);
		if (err != 0) 
			printf("[3s-02] Can't create a thread: [%d]\n", i);
		else
			printf("[3s-02] Thread created!\n");
		i++;
	}
	// https://computing.llnl.gov/tutorials/pthreads/#Joining
	i = 0;
	// Bucle para esperar por la terminacion de los hilos
	for (; i < max_threads; i++) {
		void *status;
		int rc;
		rc = pthread_join(tid[i], &status);
		if (rc) {
			printf("ERROR; retrun code from pthread_join() is %d\n", rc);
			exit(-1);
		}  else {
			printf("Thread [%d] exited with status [%ld]\n", i, (long)status);
		}
	}
	t2 = clock();
	printf("[3s-02] Count by threads %d\n", count);
	printf("[3s-02] Double check %d\n", double_count);
	printf("[[3s-02] Elapsed time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);
	return 0;
}

