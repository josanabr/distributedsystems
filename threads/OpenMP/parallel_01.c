#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {
	int tid;
	printf("Before parallel block\n");
	#pragma omp parallel private(tid) num_threads(6)
	{ 
		tid = omp_get_thread_num();
		printf("Hello world from thread = %d\n", tid);
	}
	printf("After parallel block\n");
}
