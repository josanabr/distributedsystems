#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/*
Copia un archivo llamado 'from' a otro archivo llamado 'to'. Devuelve un valor
entero el cual es 0 si todo salio bien, de lo contrario retorna un valor 
distinto de 0*/

int copyFromTo(char *from, char *to);

int main(int argc, char** argv) {
	int result = 0;
	char *archivo0 = "output_00.dat";
	char *archivo1 = "output_01.dat";
	char *archivo2 = "output_02.dat";

	if ((result = copyFromTo(archivo0,"/tmp/demo00")) == 0) {
		printf("%s OK\n", archivo0); 
	}
	if ((result = copyFromTo(archivo1,"/tmp/demo00")) == 0) {
		printf("%s OK\n", archivo1); 
	}
	if ((result = copyFromTo(archivo2,"/tmp/demo00")) == 0) {
		printf("%s OK\n", archivo2); 
	}
}

int copyFromTo(char *from, char *to) {
    int fd_to, fd_from;
    char buf[4096];
    ssize_t nread;
    int saved_errno;

    fd_from = open(from, O_RDONLY);
    if (fd_from < 0)
        return -1;

    fd_to = open(to, O_WRONLY | O_CREAT, 0666);
    if (fd_to < 0)
        goto out_error;

    while (nread = read(fd_from, buf, sizeof buf), nread > 0)
    {
        char *out_ptr = buf;
        ssize_t nwritten;

        do {
            nwritten = write(fd_to, out_ptr, nread);

            if (nwritten >= 0)
            {
                nread -= nwritten;
                out_ptr += nwritten;
            }
            else if (errno != EINTR)
            {
                goto out_error;
            }
        } while (nread > 0);
    }

    if (nread == 0)
    {
        if (close(fd_to) < 0)
        {
            fd_to = -1;
            goto out_error;
        }
        close(fd_from);

        /* Success! */
        return 0;
    }

  out_error:
    saved_errno = errno;

    close(fd_from);
    if (fd_to >= 0)
        close(fd_to);

    errno = saved_errno;
    return -1;
}
