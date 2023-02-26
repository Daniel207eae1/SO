#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

#define THREAD_NUM 4

void *acumulado(void *args){
    int b=0;
    char msg = *(int *)args;
    for (int i = 0; i <= 100; i++)
    {    
        b+=i;
        printf("Este es el hilo: %d el valor del acomulado es: %d\n",
        msg,b);
        usleep(1000000);
    }
}

void *productoria(void *args){
    int b=1;
    char msg = *(int *)args;
    for (int i = 1; i <= 33; i++)
    {    
        b*=i;
        printf("Este es el hilo: %d ,el valor de la productoria es: %d\n",
        msg,b);
        usleep(1000000);
    }
}

void *e2n(void *args){
    double elevado;
    char msg = *(int *)args;
    for (double i = 0;i < 30;i++)
    {
        elevado = pow(2.0,i);
        printf("Este es el hilo: %d, el valor de la funcion potencia es: %lf\n",msg,elevado);
        usleep(1000000);
    }
    
}

void *fibonacci(void *args){
    char msg = *(int *)args;
    int a=0,b=1,c;
    for(int i = 0; i < 100;i++){
        c=a+b;
        a=b;
        b=c;
        printf("Este es el hilo: %d, el valor de fibonacci es: %d\n",msg,c);
        usleep(1000000);
    }
}

int main(){

    pthread_t thread[THREAD_NUM];
    int j = 1;
    pthread_create(&thread[0],NULL,acumulado, &j);
    usleep(1000000);
    j++;
    pthread_create(&thread[1],NULL,productoria, &j);
    usleep(1000000);
    j++;
    pthread_create(&thread[2],NULL,e2n, &j);
    usleep(1000000);
    j++;
    pthread_create(&thread[3],NULL,fibonacci, &j);
    usleep(1000000);
    
    printf("funcion principal pid: %d\n",getpid());
    
    for(int i = 0; i < THREAD_NUM;i++){
        pthread_join(thread[i],NULL);
    }
    while(1){

    };
    return 0;
}