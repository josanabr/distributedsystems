# Principles of Parallel Programming - Chapter One
## Threads in C

### A gentle introduction

The first example is `thread_101_1.c`. This program exhibits how interact with fpthread methods such as `pthread_create` and `pthread_join`.

In order to compile the program run the following command
`gcc -pthread thread_101_1.c -o thread_101_1`

#### Assignment

Remove the instructions related to `pthread_join` and explain:

- What is the program's behavior
- If it is unexpected, what did you think that happen?

Try the program several times.

- All the executions were equal?

### Anothe example from Principles of Parallel Programming book

In chapter one of the book "Principles of Parallel Programming", a trivial example using threads is presented. The problem is to count the number of times that the number "3" is in a given array.

In this directory you find different C programs to present the code that should help you on understanding the section "Parallelism Using Multiple Instruction Streams" in the aforementioned chapter. As follows a description of every program is given.

## Important Note

To compile all programs in this directory run

> make clean && make all

**Note:** It is very important to read chapter one of "Principles of Parallel Programming" before to continue with this reading.

**Note:** These programs were run in a computer having 8 GB of RAM

## 3s-00.c

This program presents a sequential solution of the problem stated in chapter one. The code has two principal parts:

- Initialize and populate a large vector with random numbers.
- Count in the initialized vector the number of 3s in it.

### First assignment 

Add the proper code sentences that allow you to determine how much time the program spends during the process of:

- Vector initialization.
- Counting the number of 3s in a given vector.

## 3s-01.c

This program uses threads in order to divide the task of counting 3s in a given vector amongst different "working units", a.k.a. *threads*. 
Read and understand what this program does.

### Second assignment

Include the code sentences used to estimate how much time takes to each thread to count the number of 3s in a given array.  

Answer the following questions

- How many elements the large vector has?
- The program is correct? What is wrong with it? What value the program gets and what is the expected value?

## 3s-02.c

This version of the program is more accurate but it is not completely correct.

### Third assignment

- Include the code sentences used to estimate how much time takes to each thread to count the number of 3s in a given array.
- What is wrong with this code this time?

## 3s-03.c

This time the program is doing what we expect it has to do.

### Fourth assignment

- Include the code sentences used to estimate how much time takes to each thread to count the number of 3s in a segment of the full array.    
- How much time took to obtain the total count of 3s in the whole array.

## 3s-04.c

The program has a little difference with the previous program.

### Fifth assignment

- What is the difference between 3s-03.c and 3s-04.c?
- Compare elapsed time per thread during the counting process **and** the total time that all  threads took for counting the number of 3s in the whole array. Run every program (3s-03 and 3s-04) three times and compute the average time per program. Present your results and explain them.

## 3s-05.c 

This time this solution is correct and exhibits a better performance when it is compared with the previous  programs. 

### Sixth assignment

- Where the success of this program resides?
- Compare this program execution and compare its performance with previous instances and write your observations.

## Big assignment

Implement the **Fourth Solution: Try 4** found in page 20 and compare the performance of your implementation with previous programs.

