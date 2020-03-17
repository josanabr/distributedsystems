all: 3s-00 3s-01 3s-02 3s-03 3s-04 3s-05

3s-00:
	gcc -pthread 3s-00.c -o 3s-00
3s-01:
	gcc -pthread 3s-01.c -o 3s-01
3s-02:
	gcc -pthread 3s-02.c -o 3s-02
3s-03:
	gcc -pthread 3s-03.c -o 3s-03
3s-04:
	gcc -pthread 3s-04.c -o 3s-04
3s-05:
	gcc -pthread 3s-05.c -o 3s-05
te-00:
	gcc -pthread thread_exit.c -o thread_exit
te-01:
	gcc -pthread -D__SLEEP__ thread_exit.c -o thread_exit
te-02:
	gcc -pthread -D__SLEEP__ -D__NO_MAIN_EXIT__ thread_exit.c -o thread_exit
clean:
	rm -f 3s-00 3s-01 3s-02 3s-03 3s-04 3s-05 thread_exit
