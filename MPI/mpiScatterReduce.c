#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 20

int iniarray(int n, int *array) {
	int i;
	for (i = 0; i < n; i++) 
		array[i] = i;
	return i;
}

void printarray(int n, int *array) {
	int i = 0;
	printf("[ ");
	for (; i < n; i++) {
		if (i == n - 1) 
			printf("%d ", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("]\n");
}
int main(int argc, char** argv) {
	int arreglo[MAXARRAY];
	int *myArreglo;
	int myN;
	int rank;
	int size;
	int subtotal, total;
	int i;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if (rank == 0) {
		iniarray(MAXARRAY, arreglo);
		printf("Arreglo\n");
		printarray(MAXARRAY,arreglo);
		printf("\n-=*=-=*=-=*=-=*=-=*=-=*=-\n\n");
	} 	
	myN = MAXARRAY/size;
	myArreglo = (int*)malloc(sizeof(int)*myN);
	if (myArreglo == 0) {
		printf("Error en la asignacion de memoria\n"); exit(-1);
	}
	// Aqui hay un error, se envia es de bloques de tamano 'myN'
	// Fuente: http://mpi-forum.org/docs/mpi-1.1/mpi-11-html/node72.html
	MPI_Scatter(&arreglo,MAXARRAY,MPI_INT,myArreglo,myN,MPI_INT,0,MPI_COMM_WORLD);
	// Que error encuentra aqui?
	for (i = 0, subtotal = 0; i < myN; i++) 
		subtotal += myArreglo[i];
	printf("[%d] Mi subtotal es %d\n",rank, subtotal);
	total = 0;
	MPI_Reduce(&subtotal, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
		printf("El total es %d\n",total);
	MPI_Finalize();
}
