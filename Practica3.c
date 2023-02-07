#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1416

float stck[8];

void imprimir(){
    for (int i = 8; i >= 1; i--)
    {
        printf("%d. %f\n",i , stck[i-1]);
    } 
}
void subirpila(){
    for (int i = 7; i >= 1; i--)
    {
        stck[i] = stck[i-1];
    }
}
void bajarpila(int comienzo){
    for (int i = comienzo; i < 8; i++)
    {
        stck[i] = stck[i+1];
    }
    stck[7]=0.0;
}
void ingresar(float num){
    subirpila();
    stck[0]=num;
}
void operar(char opera){
    short int tf = 1; //1 paso, 0 incorrecto
    switch (opera)
    {
    case '+':
        stck[0] = stck[0]+stck[1];
        break;
    case '-':
        stck[0] = stck[1]-stck[0];
        break;
    case '*':
        stck[0] = stck[0]*stck[1];
        break;
    case '/':
        stck[0] = stck[0]/stck[1];
        break;
    case 'r':
        if(stck[0]<0){
            printf("\nNo se puede sacar raiz cuadrada a un numero menor que cero.\n");
            tf = 0;
        }
        else{
            stck[0] = pow(stck[0],0.5);
            tf = 1;
        }
        break;
    case 's':
        stck[0] = sin(stck[0]*PI/180);
        tf=0;
        break;
    case 'c':
        stck[0] = cos(stck[0]*PI/180);
        tf=0;
        break;
    case 't':
        stck[0] = tan(stck[0]*PI/180);
        tf=0;
        break;
    case 'p':
        double potencia;
        printf("Escriba la potencia a la que desea elevar: \n");
        scanf("%lf",&potencia);
        stck[0] = pow(stck[0],potencia);
        break;
    default:printf("Operando incorrecto.");
        break;
    }
    if(tf == 1){
        bajarpila(1);
    }
}
void limpiar(){
    for (int i = 0; i < 8; i++)
    {
        stck[i] = 0;
    }
    
}

int main(){
    printf("Calculadora RPN, Codigo creado por Daniel Escobar. \n\n");
    int opcion=0;
    do
    {
        imprimir();
        printf("\n1. Ingresar numero  ||  2. Seleccionar operacion  ||  3. Limpiar ultima fila \n 4. Limpiar todo  || 5. Salir\n");
        scanf("%d",&opcion);
        if (opcion<=5 && opcion>=1)
        {
            switch (opcion)
            {
            case 1:
                float numero;
                printf("Ingrese el numero: \n");
                scanf("%f",&numero);
                ingresar(numero);
                break;
            case 2:
                char operacione;
                printf("Seleccione la operacion: \n+  |  -  |  *  |  /  |  r(raiz cuadrada)  |  s(seno)  |  c(coseno)  |  t(tangente)  |  p(potencia)\n");
                scanf(" %c", &operacione);
                operar(operacione);
                break;
            case 3:
                bajarpila(0);
                break;
            case 4:
                limpiar();
                break;
            default:printf("Adios.");
                break;
            }
        }
        printf("\033[2J");
    } while (opcion!=5);

    printf("\nGracias por usar.\n");
}

