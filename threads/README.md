# Principles of Parallel Programming - Chapter One
## Threads in C

### A gentle introduction

The first example is `thread_101_1.c`. This program exhibits how interact with pthread methods such as `pthread_create` and `pthread_join`.

In order to compile the program run the following command
`gcc -pthread thread_101_1.c -o thread_101_1`

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
