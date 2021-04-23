#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorEnteros(int vec[], int tam);

int main()
{
    int numeros[TAM];
    numeros[4]=0;
    for(int i=0; i<TAM-1; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numeros[i]);
        numeros[4]+=numeros[i];
    }

    mostrarVectorEnteros(numeros, TAM);

    //pedir 4 numeros y en la quinta posicion se guarde la suma de todos
    return 0;
}

void mostrarVectorEnteros(int vec[], int tam)
{
    for(int i=0; i<TAM; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
