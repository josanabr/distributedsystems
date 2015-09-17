#include <omp.h>
#define CHUNKSIZE 100
#define N     1000

int main ()  {
	int i, chunk;
	float a[N], b[N], c[N];

	for (i=0; i < N; i++)
		a[i] = b[i] = i * 1.0;
	chunk = CHUNKSIZE;
	#pragma omp for schedule(dynamic,chunk) nowait
  	for (i=0; i < N; i++) {
    		c[i] = a[i] + b[i];
  	}
}

