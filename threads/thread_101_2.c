#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS 5 
 
/* se crea un nuevo tipo de dato para pasar como arg. al hilo */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;
 
/* Datos compartidos entre hilos. Variables por fuera de cualquier funcion */
/* (incluido main()) se reconocen como globales */
double shared_x;
pthread_mutex_t lock_x;
 
void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
 
  printf("hello from thr_func, thread id: %d\n", data->tid);
  /* se obtiene el mutex antes de modificar e imprimir shared_x */
  pthread_mutex_lock(&lock_x);
    shared_x += data->stuff;
    printf("x = %f\n", shared_x);
  pthread_mutex_unlock(&lock_x);
 
  pthread_exit(NULL);
}
 
int main(int argc, char **argv) {
  pthread_t thr[NUM_THREADS];
  int i, rc;
  /* Un arreglo de datos de tipo thread_data_t */
  thread_data_t thr_data[NUM_THREADS];
 
  /* inicializacion de datos compartidos */
  shared_x = 0;
 
  /* inicializacion del pthread mutex para proteger  "shared_x" */
  pthread_mutex_init(&lock_x, NULL);
 
  /* creacion de hilos */
  for (i = 0; i < NUM_THREADS; ++i) {
    thr_data[i].tid = i;
    thr_data[i].stuff = (i + 1) * NUM_THREADS;
    if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  /* se espera por la terminacion de todos los hilos */
  for (i = 0; i < NUM_THREADS; ++i) {
    pthread_join(thr[i], NULL);
  }
 
  printf("shared_x %lf\n",shared_x);
  return EXIT_SUCCESS;
}
