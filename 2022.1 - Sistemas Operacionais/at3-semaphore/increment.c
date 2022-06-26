/*------ INCLUDES -----------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h> 

/*------ GLOBALS -----------------------*/

#define N 3             // ? number of threads
#define MAX 10          // ? max number of increments
int GLOBAL = 0;         // ! critical location
pthread_t threads[N];   // ! array of threads
sem_t semaphore[N];     // ! array of semaphores



/*------ FUNCTIONS -----------------------*/
void *thread(void *data);


int main(void) {

    sem_init(&semaphore[0],0,1);                                        // ! initialize semaphore 0 w/ value 1

    for (int x = 1; x < N; x++) {
        sem_init(&semaphore[x],0,0);                                    // ! initialize semaphore x w/ value 0
    }

    for(int i = 0; i < N; i++) {

        int *j = malloc(sizeof(int));                                   // ! allocate memory for <j>
        *j = i;                                                         // ! set <j> to <i>
        pthread_create(&threads[i], NULL, thread, (void *)j);           // ! create thread <i>

    }

    for(int c=0; c<N; c++) {

      pthread_join(threads[c], NULL);                                   // ! join thread <c>
      printf("Thread %ld retornou\n", threads[c]);                      // ! print return of thread <c>

    }

    return(1);

}


/**
 * @brief -> function that increments GLOBAL variable by 1
 * 
 * @param data -> pointer to integer that represents the thread number
 */
void *thread(void *data) {
    int id;                                                             // ! the thread number
    id = *((int *) data);                                               // ! set <id> to <data>
    free((int *)data);                                                  // ! free memory <data>

    while (true) {

        sem_wait(&semaphore[id]);                                       // ! wait for semaphore <id> to be available
        
        if (GLOBAL >= MAX) {

            for (int x = 0; x < N; x++) {
                sem_post(&semaphore[x]);                                // ! liberate semaphore <x>
            }

            pthread_exit(NULL);                                         // ! exit thread
        }
        GLOBAL++;                                                       // ! increment GLOBAL variable by 1

        printf("Thread %d: global = %d\n", id, GLOBAL);                 // ! print GLOBAL variable and thread number
        sem_post(&semaphore[(id+1)%N]);                                 // ! liberate semaphore <(id+1)%N> | next thread     
        sleep(2);
    }
}
