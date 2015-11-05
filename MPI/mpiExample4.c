#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sumTotal, upToVal;
	int start, end, size, rank;

	upToVal = 10000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	start = rank*(upToVal/size) + 1;
    	if(rank==(size-1)){
    		end = upToVal;
    	}else{
    		end = start + (upToVal/size)-1;
    	}
    	sum = 0;
    	sumTotal=0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
    	// insert your code here

    	printf("\nRank: %d, sum: %d, sumTotal: %d, start: %d, end: %d\n", rank, sum, sumTotal, start, end);
	
	MPI_Finalize();
	
	return 0;
}



