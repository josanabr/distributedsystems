/**
Este programa es una primera aproximacion a la solucion de contar el numero de
apariciones del numero '3' en un arreglo de 100,000,000 de posiciones.

Author: John Sanabria - john.sanabria@correounivalle.edu.co
Date: 2091-09-17
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THREADS 8 // se crearan '8' hilos
#define VECTOR_SIZE 100000000

// Vector de identificadores de hilos
pthread_t tid[MAX_THREADS];

// Un apuntador a un vector de enteros
int *array;
// Maxima longitud del vector
int length = VECTOR_SIZE;
int count = 0;
int double_count = 0;
// Maximo numero de hilos
int max_threads = MAX_THREADS;

// Funcion usada por la funcion 'pthread_create'. 'pthread_create' crea un nuevo
// hilo quien se dedicara a ejecutar esta funcion
// El argumento '*arg' contendra el identificador del hilo o el numero del hilo
// creado. Se comienza en '0' hasta 'MAX_THREADS - 1'.
// '*arg' le permite al hilo saber de que parte del arreglo se debe encargar 
// para contar los '3's que aparezcan en su parte del vector.
//
// Despues del metodo 'main()' se plantean algunas preguntas. 
//
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
}

// Funcion que inicializa los elementos del vector y cuenta cuantas veces se
// genero el numero '3'
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

// Metodo principal
int main(int argc, char* argv[]) {
	int i = 0;
	int err;
	clock_t t1, t2;
	// Se puede pasar por argumentos el numero de hilos que se quiere se
	// invoquen para procesar el vector
	if (argc == 2) {
		max_threads = atoi(argv[1]);
		if (max_threads > MAX_THREADS)
			max_threads = MAX_THREADS;
	} else {
		max_threads = MAX_THREADS;
	}
	printf("[3s-01] Using %d threads\n",max_threads);
	// random seed
	// http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	srand(time(NULL));
	printf("*** 3s-01 ***\n");
	printf("Initializing vector... ");
	fflush(stdout);
	initialize_vector();
	printf("Vector initialized!\n");
	fflush(stdout);
	t1 = clock();
	// ciclo donde se crean 'max_threas' hilos de ejecucion
	while (i < max_threads) {
		err = pthread_create(&tid[i], NULL, &count3s_thread, (void*)i);
		if (err != 0) 
			printf("[3s-01] Can't create a thread: [%d]\n", i);
		else
			printf("[3s-01] Thread created!\n");
		i++;
	}
	t2 = clock();
	printf("[3s-01] Count by threads %d\n", count);
	printf("[3s-01] Double check %d\n", double_count);
	printf("[[3s-01] Elapsed time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);

	return 0;
}

//
// PREGUNTAS
//
// Que le hace falta a este programa?
// Como identificar el numero de hilos que tiene el ordenador? 
// (https://stackoverflow.com/questions/4586405/how-to-get-the-number-of-cpus-in-linux-using-c)
//
