CC=gcc

%.o: %.c
	$(CC) -c -o $@ $<
all: fork_00 fork_01

fork_00: fork_00.o
	gcc -o fork_00 fork_00.o
fork_01: fork_01.o
	gcc -o fork_01 fork_01.o
tar:
	tar cf ../fork.tar . 
	mv ../fork.tar .
	
clean:
	rm -f *.o fork_00 fork_01
