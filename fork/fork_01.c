#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
 int a,b;
 pid_t pid;
 a = 2;
 b = 3;
 pid = fork();
 if (pid == 0) {
  b = 4;
 }
 printf("La suma es: %d\n",a + b);
}
