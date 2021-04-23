#include <stdio.h>
#include <stdlib.h>
#include "dam.h"



void dam_cargarVectorEnteros(int vec[], int tam)
{
    for(int i = 0; i < tam; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&vec[i]);
    }
}

int dam_mostrarVectorEnteros(int vec[], int tam)
{
    int retorno = 0;

    if(vec!=NULL && tam>0)
    {
        for(int i = 0; i < tam; i++){
            printf("%d ", vec[i]);

        }
        retorno=1;
    }
    return retorno;
}
