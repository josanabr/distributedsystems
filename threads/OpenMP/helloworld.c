/**
En el código ud. encontrara algunas lineas con comentarios y al final de la
linea una expresion similar a //[n] o //[n-].
Cuando ud. encuentre la expresion //[n] eso quiere decir que ese comentario solo debe ser visible durante la interaccion 'n'. En otras palabras si ud. esta en la interaccion 'n' esa linea deberia ser descomentada. En otra interaccion la linea debe permanecer comentada.
La expresion //[n-] indica que ese comentario tiene sentido desde la interaccion 'n' en adelante. Esto quiere decir que en cualquier interaccion por debajo de 'n' esta linea debe permanecer comentada. De la interaccion 'n' en adelante el comentario debe ser removido.

En este ejemplo se tienen interacciones 0, 1 y 2. La interaccion 0 es el programa sin modificaciones.
*/
#include <stdio.h>
//#include <omp.h> //[1-]

int main(int argc, char** argv) {
	//#pragma omp parallel //[1] 
	//#pragma omp parallel num_threads(5) //[2-]
	//{ //[1-]
	int id = 0; // [0]
	//int id = omp_get_thread_num(); //[1-]
	printf("hello (%d)", id);
	printf(" world (%d)\n", id);
	//} //[1-]
}
