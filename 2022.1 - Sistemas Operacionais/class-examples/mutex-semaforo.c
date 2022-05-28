/* Dica para compilação: 
                         gcc -o test2 MutexESemaforo.c -lpthread */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 


void *mythread(void *data);

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;



#define N 2 // number of threads

sem_t s;


int x = 0; 

int main(void) {
   pthread_t tids[N];
   int i=0;

   sem_init(&s, 0, 1); // inicializa o semáforo com valor 1

   for(i=0; i<N; i++) {
      int *j = malloc(sizeof(int));
      *j = i;
      pthread_create(&tids[i], NULL, mythread, (void *)j);
   }
   /* We will now wait for each thread to<\n>
    * terminate */
   for(i=0; i<N; i++) {
      pthread_join(tids[i], NULL);
      printf("Thread id %ld returned\n", tids[i]);
   }
   return(1);
}


void *mythread(void *data) {
struct timeval tv;
struct timezone tz;
struct tm *tm;
int id;
   id = *((int *) data);
   free((int *)data);

   // demonstração tratamento exclusão mútua utilizando mutex
   while(x < 10) {

      //pthread_mutex_lock(&count_mutex);
      
      x++;
      gettimeofday(&tv, &tz);
      tm=localtime(&tv.tv_sec);
      printf("(USING MUTEX)  Thread ID %d: x is now %d (%d:%02d:%02d:%d).\n",id, x, tm->tm_hour, tm->tm_min, tm->tm_sec, (int)tv.tv_usec);
      /* We will now release the mutex so that
       * another thread gets the chance to run. */
      
      //pthread_mutex_unlock(&count_mutex);

      sleep(1);
   }
    
   // demonstração tratamento exclusão mútua utilizando semáforo
   while(x < 20) {

      sem_wait(&s); // operação DOWN

      x++;
      gettimeofday(&tv, &tz);
      tm=localtime(&tv.tv_sec);
      printf("(USING SEMAFORE) Thread ID %d: x is now %d (%d:%02d:%02d:%d).\n",id, x, tm->tm_hour, tm->tm_min, tm->tm_sec, (int)tv.tv_usec);
      /* We will now release the mutex so that
       * another thread gets the chance to run. */
      
      sem_post(&s); // operação UP
      

      sleep(1);

   }

   /* We can return a pointer. Whatever pointer
    * we return can later be retrieved using the
    * pthread_join function */
   pthread_exit(NULL);
}

