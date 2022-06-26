/*------ INCLUDES -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h> 

/*------ GLOBAIS -----------------------*/
#define N 5
#define LEFT ((i+N-1)%N)
#define RIGHT ((i+1)%N)
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
pthread_t filosofos[N];
sem_t mutex;
sem_t semaphore[N];

/*------ FUNÇÕES -----------------------*/
void *philosopher(void *data);
void test(int i);
void take_forks(int i);
void put_forks(int i);

/*------ MAIN -----------------------*/
int main(void) {

    sem_init(&mutex,0,1); // inicializa mutex para controlar a região crítica

    for(int i = 0; i < N; i++) {

        sem_init(&semaphore[i], 0, 0);                                  // inicializa o semaforo de cada filosofo
        state[i] = THINKING;                                            // inicializa o estado de cada filosofo
        int *j = malloc(sizeof(int));                                   // aloca memória para o ponteiro do filosofo
        *j = i;                                                         // atribui o valor do filosofo ao ponteiro
        pthread_create(&filosofos[i], NULL, philosopher, (void *)j);    // cria o filosofo

    }

    for(int c=0; c<N; c++) {

      pthread_join(filosofos[c], NULL);                                 // espera o fim do filosofo
      printf("Filosofo %ld retornou\n", filosofos[c]);                  // imprime o retorno do filosofo
    }

    return(1);
}

/*------ FUNÇÕES -----------------------*/
/**
 * @brief -> Função que pega os garfos para o filosofo
 * 
 * @param i -> identificador do filosofo
 */
void take_forks(int i) {

    sem_wait(&mutex);           // operação down(&mutex);
    state[i] = HUNGRY;          // altera o estado do filosofo para HUNGRY
    test(i);                    // testa se o filosofo pode pegar os garfos
    sem_post(&mutex);           // operação up(&mutex);
    sem_wait(&semaphore[i]);    // operação down(&s[i]);
    
}

/**
 * @brief -> Função que libera os garfos do filosofo
 * 
 * @param i -> identificador do filosofo
 */
void put_forks(int i) {

    sem_wait(&mutex);           // operação down(&mutex);
    state[i] = THINKING;        // altera o estado do filosofo para THINKING
    test(LEFT);                 // testa se o filosofo da esquerda quer pegar os garfos
    test(RIGHT);                // testa se o filosofo da direita quer pegar os garfos
    sem_post(&mutex);           // operação up(&mutex);

}

/**
 * @brief -> Função que testa se o filosofo pode pegar os garfos
 * 
 * @param i -> identificador do filosofo
 */
void test(int i) {

    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) { // se o filosofo está com fome e os garfos da esquerda e da direita não estão comendo então pode pegar os garfos
        state[i] = EATING;                                                  // altera o estado do filosofo para EATING
        sem_post(&semaphore[i]); // up(&semaphore[i]);
    }
}

/**
 * @brief -> Função que executa o filosofo - a thread
 * 
 * @param data -> ponteiro para o identificador do filosofo
 */
void *philosopher(void *data) {
    int id;                                                 // identificador do filosofo
    id = *((int *) data);                                   // atribui o valor do filosofo ao ponteiro
    free((int *)data);                                      // libera a memória do ponteiro

    while (true) {

        //1 segundo = 1 000 000 microsegundos
        usleep(rand()%5000000);                         // faz o filosofo pensar
        take_forks(id);                                 // tenta pegar os garfos
        printf("\nPhilosopher %d is eating! \n", id);   // imprime que o filosofo está comendo
        put_forks(id);                                  // libera os garfos
    }
}