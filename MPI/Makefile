run: compile
	mpirun -np 8 --hostfile machinefile ./openmpi_demo
compile:
	mpicc openmpi_demo.c -o ./openmpi_demo
clean:
	rm -rf ./openmpi_demo
ex1: example1
	mpirun -np 2 --hostfile machinefile ./ex1
example1:
	mpicc mpiExample1.c -o ./ex1
ex2: example2
	mpirun -np 8 --hostfile machinefile ./ex2
example2:
	mpicc mpiExample2.c -o ./ex2
ex3: example3
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile ./ex3
example3:
	mpicc mpiExample3.c -o ./ex3
ex4: example4
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile ./ex4
example4:
	mpicc mpiExample4.c -o ./ex4
ex5: example5
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile ./ex5
example5:
	mpicc mpiExample5.c -o ./ex5
