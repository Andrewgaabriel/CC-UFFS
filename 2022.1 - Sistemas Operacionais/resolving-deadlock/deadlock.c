#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread1(void *data);
void *thread2(void *data);



pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER, mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_t Thread1, Thread2;

int main(void) {


    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);

    //now join them
    pthread_join(Thread1, NULL);
    printf("Thread id %ld returned\n", Thread1);
    pthread_join(Thread2, NULL);
    printf("Thread id %ld returned\n", Thread2);


    return 1;
    

}

void *thread1(void *data){

    unsigned long i,j;

    int flag = 0;

    while (flag != 2) {

        if (pthread_mutex_trylock(&mutex1) == 0) {

            printf("Thread 1: mutex 1 foi acessado (ID:%ld)\n",pthread_self());

            for(i=0; i< 15000000; ++i); // just for wasting some time

            if(pthread_mutex_trylock(&mutex2) == 0) {
                

                printf("Thread 1: mutex 2 foi acessado (ID:%ld)\n",pthread_self());

                for(i=0; i< 10000000; ++i); // just for wasting some time

                pthread_mutex_unlock(&mutex2);

                printf("Thread 1: processo concluido, ambos mutexes foram acessados com sucesso! (ID:%ld)\n",pthread_self());
                
                flag = 2; 

            } else {

                printf("Thread 1: mutex 2 nao foi acessado (ID:%ld)\n",pthread_self());

                pthread_mutex_unlock(&mutex2);
            }

        } else {

            printf("Thread 1: mutex 1 nao foi acessado (ID:%ld)\n",pthread_self());

            pthread_mutex_unlock(&mutex1);
        }
   }

   pthread_exit(NULL);

}



void *thread2(void *data){

    unsigned long i,j;

    int flag1 = 0;

   while (flag1 != 2) {

        if(pthread_mutex_trylock(&mutex2) == 0){

            printf("Thread 2: mutex 2 foi acessado (ID:%ld)\n", pthread_self());

            for(i=0; i< 10000000; ++i); // just for wasting some time

            //e se eu desbloquear o mutex2 antes de bloquear o mutex1?

            if(pthread_mutex_trylock(&mutex1)==0){

                printf("Thread 2: mutex 1 foi acessado (ID:%ld)\n", pthread_self()); 

                for(i=0; i< 15000000; ++i); // just for wasting some time

                pthread_mutex_unlock(&mutex1);   

                printf("Thread 2: processo concluido, ambos mutexes foram acessados com sucesso! (ID:%ld)\n",pthread_self());

                flag1 = 2;

            } else {

                printf("Thread 2: mutex 1 nao foi acessado (ID:%ld)\n",pthread_self());

                pthread_mutex_unlock(&mutex1);
            }

            pthread_mutex_unlock(&mutex2);
        } else {

            printf("Thread 2: mutex 2 nao foi acessado (ID:%ld)\n",pthread_self());

            pthread_mutex_unlock(&mutex2);
        }
   }
   
   pthread_exit(NULL);

}






