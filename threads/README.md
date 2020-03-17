# Principles of Parallel Programming - Chapter One

# Threads in C

## A gentle introduction

The first example is `thread_101_1.c`. This program exhibits how interact with pthread methods such as `pthread_create` and `pthread_join`.

In order to compile the program run the following command
`gcc -pthread thread_101_1.c -o thread_101_1`

## The `thread_exit.c` function

The code [`thread_exit.c`](thread_exit.c) uses some compilation directives in order to show how the use or lack of use of some functions calls affect the performance of a threads-based program. 

The [`thread_exit.c`](thread_exit.c) can be compiled through the `make` command as follows:

* `make te-00` this is a normal compilation of the code.
* `make te-01` enables that during `PrintHello()` execution the `sleep()` function being called
* `make te-02` avoids that `main()` thread invokes `pthread_exit()`


**This code has been taken from [https://computing.llnl.gov/tutorials/pthreads/#CreatingThreads](https://computing.llnl.gov/tutorials/pthreads/#CreatingThreads)**

## Passing arguments 

As follows two examples about passing arguments to a new created thread are shown: 

* [hello_arg1.c](hello_arg1.c) In this example a variable of a basic type is passed as argument

* [hello_arg2.c](hello_arg2.c) In this example a variable of a user defined type is passed as argument

Those codes were taken from [this site](https://computing.llnl.gov/tutorials/pthreads/exercise.html#Exercise1):

* [hello_arg1.c](https://computing.llnl.gov/tutorials/pthreads/samples/hello_arg1.c)

* [hello_arg2.c](https://computing.llnl.gov/tutorials/pthreads/samples/hello_arg2.c)

## Examples of collaborative work

### Scalar product

![](http://hyperphysics.phy-astr.gsu.edu/hbase/imgmec/vsc1a.png)

### Description of 3s-0\*.c

Those programs, having `3s-0` as prefix, are implementations of an example described in chapter one of the Principles of Parallel Programming book.
Please open each program and follow the instructions there. 

## Final assignment

* To implement the **Fourth Solution: Try 4** found in page 20 and compare the performance of your implementation with previous programs.

* To identify a computationally intensive problem. Some trivial examples
  * To calculate Fibonnaci's number of every numer in an array of 100,000 positions. Each position has a value less or equal to 30. Be assure your Fibonacci's implementation is recursive.
  * To calculate the area under the curve following the Riemann's approach.
  * To calculate Pi value following the Monte Carlo's approach.

* Show a graph where your program's behaviour is depicted. Axis X would represent the number of threads in your execution and Axis Y represents the execution time.
