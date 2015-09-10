#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;
	pid_t mypid;
	if (pid = fork()) {
		printf("Soy el padre y mi id es %d y el id de mi hijo es %d\n",getpid(), pid);
	} else {
		printf("Soy el hijo y mi id es %d\n", getpid());
	}
	fflush(stdout);
}
