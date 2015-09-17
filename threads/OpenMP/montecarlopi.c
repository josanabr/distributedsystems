#include <stdio.h>   
#include <omp.h>   
   
static long MULTIPLIER  = 1366;   
static long ADDEND      = 150889;   
static long PMOD        = 714025;   
long random_last = 0.0;   
double random_low, random_hi;   

/*
Functions used to generate random numbers
*/
   
double random()   
{   
    long random_next;   
    double ret_val;   
   
    random_next = (MULTIPLIER  * random_last + ADDEND)% PMOD;   
    random_last = random_next;   
   
    ret_val = ((double)random_next/(double)PMOD)*(random_hi-random_low)+random_low;   
    return ret_val;   
}   

void seed(double low_in, double hi_in)   
{   
   if(low_in < hi_in)   
   {    
      random_low = low_in;   
      random_hi  = hi_in;   
   }   
   else   
   {   
      random_low = hi_in;   
      random_hi  = low_in;   
   }   
   random_last = PMOD/ADDEND; 
   
}   
   
//    
// The monte carlo pi program   
// Include the OpenMP directives to transform this sequential program in  a
// parallel one
//   
   
static long num_trials = 100000;   
   
int main ()   
{   
   long i;  long Ncirc = 0;   
   double pi, x, y, test;   
   double r = 1.0;   // radius of circle. Side of squrare is 2*r    
   
   seed(-r, r);  // The circle and square are centered at the origin   
   
   for(i=0;i<num_trials; i++)   
   {   
      x = random();    
      y = random();   
   
      test = x*x + y*y;   
   
      if (test <= r*r) Ncirc++;   
    }   
   
    pi = 4.0 * ((double)Ncirc/(double)num_trials);   
   
    printf("\n %d trials, pi is %f \n",num_trials, pi);   
   
    return 0;   
}   
