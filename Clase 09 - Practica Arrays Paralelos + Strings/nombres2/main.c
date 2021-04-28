#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 20

void mostrarNombres(char names[][20], int tam);
void ordenarNombres(char names[][20], int tam);

int main()
{
    char nombres[FILAS][COLUMNAS] = {{"German"},{"Damo"}, {"Amailia"},{"Donato"},{"Chepi"}};
    /*for(int i=0; i<FILAS; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }*/

    mostrarNombres(nombres, FILAS);
    printf("\n\n\n");
    ordenarNombres(nombres, FILAS);
    mostrarNombres(nombres, FILAS);

    return 0;
}

void mostrarNombres(char names[][20], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%s\n",names[i]);
    }
}

void ordenarNombres(char names[][20], int tam)
{
    char auxCad[20];
    for(int i=0;i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(names[i],names[j])> 0)
            {
                //swap
                strcpy(auxCad,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],auxCad);
            }
        }
    }
}
