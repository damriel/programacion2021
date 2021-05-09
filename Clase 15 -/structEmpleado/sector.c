#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "dam.h"

//PARA EL VIERNES
//REFACTORIZAR EL ABM PARA LOS EMPLEADOS CON LOS SECTORES INCLUIDOS

int mostrarSectores(eSector aSectores[], int tamSec)
{
    printf("\n Listado de Sectores\n");
    printf("  ID    Descripcion\n");
    for(int i=0; i<tamSec; i++)
    {
        mostrarUnSector(aSectores[i]);
    }
    printf("\n\n");
    return 0;
}

int mostrarUnSector(eSector unSector)
{
    printf(" %d    %10s\n",unSector.id, unSector.descripcion);
    return 0;
}

int cargarDescripcionSector(int id, eSector aSectores[], int tamSec, char descripcion[])
{
    int retorno=0;
    if(id>=500 && id<=504 && aSectores!=NULL && tamSec>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamSec; i++)
        {
            if(aSectores[i].id==id)
            {
                strcpy(descripcion, aSectores[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
