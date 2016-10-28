#include <stdio.h>
#include <omp.h>
int main(int argc, char** argv) {
#pragma omp parallel 
	{
		int id;
		id = omp_get_thread_num();
		printf("hello %d", id);
		printf("world %d\n", id);
	}
}
