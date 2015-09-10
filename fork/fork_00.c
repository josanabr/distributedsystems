#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
 pid_t pid;
 pid_t main_pid;
 int status;
 main_pid = getpid();
 pid = fork();
 if (pid == 0) { // child
  /**
   1. Comment in the following 3 lines, run makefile and then run ./run.sh fork_00
  */
  //printf("Before to sleep\n");
  //fflush(stdout);
  //sleep(2);
  printf("[%d] hello ",main_pid);
 } else { // parent
  pid_t _pid;
  /**
   2. Comment in the following 3 lines, run makefile and then run ./run.sh fork_00
  */
  //printf("Parent is waiting\n");
  //fflush(stdout);
  //_pid = wait(&status);
  printf(" world [%d]\n", main_pid);
  fflush(stdout);
 }
}
