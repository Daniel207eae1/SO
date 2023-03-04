#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FILOSOFOS 5
//Dos opciones, Usar un vector de semaforos o usar un vector de cubiertos.

sem_t cubiertos[NUM_FILOSOFOS];
sem_t filosofos;

void *Filosofo(void *args){
    char num = *(int *)args;
    while(1){
        printf("Filosofo[%d] piensa...\n",num);
        usleep(1000000);
        sem_wait(&filosofos);
        Comer(num);
        sem_post(&filosofos);
    }
}

void Comer(int num){    
    if(num==0){
        //Preguntar por tenedores en sus laterales.
        sem_wait(&cubiertos[0]);
        sem_wait(&cubiertos[NUM_FILOSOFOS-1]);
        printf("Filosofo[%d] comiendo con cubiertos (%d,%d)\n",0,0,NUM_FILOSOFOS-1);
        usleep(1000000);
        printf("Filosofo[%d] regresa los cubiertos (%d,%d)\n",0,0,NUM_FILOSOFOS-1);
        sem_post(&cubiertos[0]);
        sem_post(&cubiertos[NUM_FILOSOFOS-1]);
    }
    else{
        sem_wait(&cubiertos[num]);
        sem_wait(&cubiertos[num-1]);
        printf("Filosofo[%d] comiendo con cubiertos (%d,%d)\n",num,num,num-1);
        usleep(1000000);
        printf("Filosofo[%d] regresa los cubiertos (%d,%d)\n",num,num,num-1);
        sem_post(&cubiertos[num]);
        sem_post(&cubiertos[num-1]);
    }
}

int main(){
    int fi = NUM_FILOSOFOS/2;
    pthread_t thread[NUM_FILOSOFOS];
    sem_init(&filosofos,0,fi);
    int ids[NUM_FILOSOFOS];

    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        sem_init(&cubiertos[i], 0, 1);
    }
    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        ids[i] = i;
        pthread_create(&thread[i],NULL,Filosofo, &ids[i]);
        //usleep(1000);
    }
    for(int i = 0; i < NUM_FILOSOFOS;i++){
        pthread_join(thread[i],NULL);
    }

    for (int i = 0; i < NUM_FILOSOFOS; i++)
        sem_destroy(&cubiertos[i]);

    sem_destroy(&filosofos);
    
    return 0;
}