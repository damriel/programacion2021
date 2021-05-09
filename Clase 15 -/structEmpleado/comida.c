#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"
#include "dam.h"

int mostrarComidas(eComida aComidas[], int tamCom)
{
    int retorno=-1;
    if(aComidas!=NULL && tamCom>0)
    {
        retorno=0;
        printf("      LISTA DE COMIDAS\n");
        printf("  ID    Descripcion     Precio\n");
        for(int i=0; i<tamCom; i++)
        {
            mostrarUnaComida(aComidas[i]);
        }
    }
    system("pause");
    return retorno;
}

void mostrarUnaComida(eComida unaComida)
{
    printf("%5d    %10s     %6.2f\n",unaComida.id,
                                     unaComida.descripcion,
                                     unaComida.precio);
}

int buscarComida(eComida aComidas[], int tamCom, int idBuscado)
{
    int indice=-1;
    if(aComidas!=NULL && tamCom>0)
    {
        for(int i=0; i<tamCom; i++)
        {
            if(idBuscado==aComidas[i].id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int cargarDescripcionComida(int id, eComida aComidas[], int tamCom, char descripcion[])
{
    int retorno=0;
    if(id>=1000 && id<=1004 && aComidas!=NULL && tamCom>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamCom; i++)
        {
            if(aComidas[i].id==id)
            {
                strcpy(descripcion, aComidas[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
