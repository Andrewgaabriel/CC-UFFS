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
    /* 
        0 ->  deu ruim / nada foi feito
        1 ->  primeiro mutex OK
        2 ->  segundo mutex OK
    */
   

    if (pthread_mutex_trylock(&mutex1) == 0) {
        flag = 1; //primeiro mutex foi acessado

        printf("Thread 1: mutex 1 foi acessado\n");

        printf("Thread 1 - ID%ld got mutex1.\n", pthread_self());

        for(i=0; i< 15000000; ++i); // just for wasting some time


        //e se eu desbloquear o mutex1 antes de bloquear o mutex2?
        //pthread_mutex_unlock(&mutex1);





        if(pthread_mutex_trylock(&mutex2) == 0){
            flag = 2; //segundo mutex foi acessado // DEU MUITO BOM

            printf("Thread 1: mutex 2 foi acessado\n");

            printf("Thread 1 - ID%ld got mutex2.\n", pthread_self());          

            for(i=0; i< 10000000; ++i); // just for wasting some time

            pthread_mutex_unlock(&mutex2);

            // e se eu trocar o local de retorno / colocar aqui
            printf("\nThread 1 - ID%ld got all mutexs with sucess.\n", pthread_self());

            printf("Thread 1: processo concluido, ambos mutexes foram acessados com sucesso!\n");

            pthread_exit(NULL);

        } else {

            flag = 0; //segundo mutex nao foi acessado / DEU RUIM

            printf("Thread 1: mutex 2 nao foi acessado\n");

            printf("\nThread 1 - ID%ld failed to get mutex2.\n", pthread_self());

            pthread_mutex_unlock(&mutex2);
        }

        //pthread_mutex_unlock(&mutex1);
    }
    else {

        flag = 0; //primeiro mutex nao foi acessado / DEU RUIM

        printf("Thread 1: mutex 1 nao foi acessado\n");

        printf("\nThread ID%ld failed to get mutex1.\n", pthread_self());

        pthread_mutex_unlock(&mutex1);
    }

    /* if (flag == 2) {
        printf("\nThread ID%ld got all mutexs with sucess.\n", pthread_self());
        pthread_exit(NULL);
    } */


}



void *thread2(void *data){

    unsigned long i,j;

    int flag1 = 0;
    /* 
        0 ->  deu ruim / nada foi feito
        1 ->  segundo mutex OK
        2 ->  primeiro mutex OK
    */

    if(pthread_mutex_trylock(&mutex2) == 0){

        flag1 = 1; //segundo mutex foi acessado

        printf("Thread 2: mutex 2 foi acessado\n");

        printf("Thread 2 - ID%ld got mutex2.\n", pthread_self());

        for(i=0; i< 10000000; ++i); // just for wasting some time

        //e se eu desbloquear o mutex2 antes de bloquear o mutex1?

        if(pthread_mutex_trylock(&mutex1)==0){

            flag1 = 2; //primeiro mutex foi acessado // DEU MUITO BOM

            printf("Thread 2: mutex 1 foi acessado\n");

           printf("Thread 2 - ID%ld got mutex1.\n", pthread_self());  

           for(i=0; i< 15000000; ++i); // just for wasting some time

           pthread_mutex_unlock(&mutex1);   

           // e se eu trocar o local de retorno / colocar aqui
           printf("\nThread 2 - ID%ld got all mutexs with sucess.\n", pthread_self());

            printf("Thread 2: processo concluido, ambos mutexes foram acessados com sucesso!\n");

           pthread_exit(NULL);

        }
        else {

            flag1 = 0; //primeiro mutex nao foi acessado / DEU RUIM

            printf("Thread 2: mutex 1 nao foi acessado\n");

            printf("\nThread ID%ld did not get mutex1.\n", pthread_self());

            pthread_mutex_unlock(&mutex1);
        }

        pthread_mutex_unlock(&mutex2);
    }
    else {

        flag1 = 0; //segundo mutex nao foi acessado / DEU RUIM

        printf("Thread 2: mutex 2 nao foi acessado\n");

        printf("\nThread ID%ld did not get mutex2.\n", pthread_self());

        pthread_mutex_unlock(&mutex2);
    }



    /* if(flag1 == 1){
        printf("\nThread ID%ld got mutex2.\n", pthread_self());
    }
    else if(flag1 == 2){
        printf("\nThread ID%ld got mutex1.\n", pthread_self());
    }
    else{
        printf("\nThread ID%ld did not get mutex1 or mutex2.\n", pthread_self());
    } */

    /* if (flag1 == 2) {
        printf("\nThread ID%ld got all mutexs with sucess.\n", pthread_self());
        pthread_exit(NULL);
    } */

    
}






