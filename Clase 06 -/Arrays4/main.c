#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int numeros[TAM] = {87,113,87,113,9};
    int mayor;
    //cual es mayor

    for(int i=0; i<TAM; i++)
    {
        if(i==0 || numeros[i]>mayor)
        {
            mayor=numeros[i];
        }
    }

    printf("El mayor numero es: %d y se encuentra en la/s posicion/es ", mayor);

    for(int i=0; i<TAM; i++)
    {
        if(numeros[i]==mayor)
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    return 0;
}
