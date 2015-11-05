#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int i,rank,size;
    int root,count;
    int buffer[5];
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    root=0;
    count=5;
    if(rank== root){
      for(i=0;i<count;i++){
        buffer[i]=i;
      }
    }

    // insert your code here


    printf("Rank is: %d, Value at buffer[%d] is: %d\n ",rank, count-1, buffer[count-1]);

    printf("\n");
    MPI_Finalize();
    return 0;
}


