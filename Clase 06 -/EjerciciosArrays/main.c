#include <stdio.h>
#include <stdlib.h>
#define TAM 5

float calcularPromedio(int vec[], int tam);

int main()
{
    int numeros[TAM] = {4,3,2,7,8};
    printf("El promedio es %.2f.\n", calcularPromedio(numeros, TAM));

    return 0;
}

float calcularPromedio(int vec[], int tam)
{
    int acumulador=0;
    for(int i = 0; i<tam; i++)
    {
        acumulador+=vec[i];
    }
    return (float)acumulador/tam;
}
