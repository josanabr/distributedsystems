#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define initrandomico() srand(time(NULL))
#define randomico(n) rand() % n

#define MAXITER 1000000
#define MAXTHREADS 8

double sumparcial[MAXTHREADS];

int fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void* myfunction(void *data) {
	int id = (int) data;
	int iterxthread = MAXITER/MAXTHREADS;
	int i;
	printf("Hilo %d iteraciones %d\n",id,iterxthread);
	sumparcial[id] = 0;
	for  (i = 0; i < iterxthread; i++) 
		sumparcial[id] += (double)fibonacci(randomico(20));
	return NULL;
}

int main(int argc, char** argv) {
	int i;
	double sum;
	pthread_t threadid[MAXTHREADS];
	
	sum = 0;
	initrandomico();
	for (i = 0 ; i < MAXTHREADS; i++) 
		pthread_create(&threadid[i],NULL, myfunction, (void*)i);

	for (i = 0; i < MAXTHREADS; i++) {
		pthread_join(threadid[i], NULL);
		sum += sumparcial[i];
	}
	printf("%.2lf\n", sum);
	return 0;
}
