#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
 printf("hola\n");
 fork();
 printf("mundo\n");
 printf("world\n");
}
