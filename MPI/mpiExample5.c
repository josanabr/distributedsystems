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
#define imprimirvector(V,MA) for (i = 0; i < MA; i++) printf("%d ",V[i]);

int main(int argc, char** argv) {
  int a[MAXARRAY];
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int number;
  if (world_rank == 0) {
    int i;
    // We initialize vector
    for (i = 0; i < MAXARRAY; i++) a[i] = i;
    MPI_Send(
      /* data         = */ &a, 
      /* count        = */ MAXARRAY, 
      /* datatype     = */ MPI_INT, 
      /* destination  = */ 1, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    printf("[R] Vector inicial\n");
    int i;
    imprimirvector(a,MAXARRAY);
    printf("[R] Recibiendo el vector\n");
    MPI_Recv(
      /* data         = */ &a, 
      /* count        = */ MAXARRAY, 
      /* datatype     = */ MPI_INT, 
      /* source       = */ 0, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
    printf("[R] Vector recibido\n");
    imprimirvector(a,MAXARRAY);
  }
  MPI_Finalize();
}

