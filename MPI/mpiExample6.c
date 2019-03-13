// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 20
#define imprimirvector(V,MA) int __i__; for (__i__ = 0; __i__ < MA; __i__++) printf("%d ",V[__i__]);

int main(int argc, char** argv) {
  int a[MAXARRAY];
  int *b;
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int posxnode = MAXARRAY/world_size;
  

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int number;
  if (world_rank == 0) {
    // We initialize vector
    int i;
    for (i = 0; i < MAXARRAY; i++) a[i] = i;
  }
  b = (int*) malloc(sizeof(int)*posxnode);
  if (b == 0) {
   perror("Error al alojar memoria");
   MPI_Abort(MPI_COMM_WORLD, 1);
  }
  MPI_Scatter(
    a, posxnode, MPI_INT,
    b, posxnode, MPI_INT, 
    0,
    MPI_COMM_WORLD);
  printf("[R] Vector recibido\n");
  imprimirvector(b,posxnode);
  MPI_Finalize();
}

