#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define initrandomico() srand(time(NULL))
#define randomico(n) rand() % n

#define MAXARRAY 1000000

int main(int argc, char** argv) {
	int i;
	int maxi;
	int temp;
	int x[] = 
		{ 
		  12, 36, 24, 15, 55, 13, 79, 82, 47, 66,  
		  32, 26, 38, 75, 95, 43, 29, 62, 57, 16,  
		  54, 42, 21, 46, 85, 79, 81, 95, 28, 43,  
		  94, 12, 71, 36, 15, 69, 31, 75, 98, 23,  
		  64, 72, 91, 86, 45, 29, 51, 15, 68, 93,  
		  74, 52, 61, 66, 25, 89, 11, 55, 38, 63,
		  17, 31, 57, 93
		};  
	int cont;
	
	maxi = 0;
	for (i = 0; i < MAXARRAY; i++) {
		temp = x[i];
		if (temp > maxi)
			maxi = temp;
	}
	printf("%d\n",maxi); 
	return 0;
}
