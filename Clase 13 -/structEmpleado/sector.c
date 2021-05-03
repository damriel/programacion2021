#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "empleado.h"
#include "dam.h"

//PARA EL VIERNES
//REFACTORIZAR EL ABM PARA LOS EMPLEADOS CON LOS SECTORES INCLUIDOS

int mostrarSectores(eSector arraySectores[], int tamSec)
{
    printf("\n Listado de Sectores\n");
    printf("  ID    Descripcion\n");
    for(int i=0; i<tamSec; i++)
    {
        mostrarUnSector(arraySectores[i]);
    }
    printf("\n\n");
    return 0;
}

int mostrarUnSector(eSector unSector)
{
    printf(" %d    %10s\n",unSector.id, unSector.descripcion);
    return 0;
}

int cargarDescripcionSector(int id, eSector arraySectores[], int tamSec, char descripcion[])
{
    int retorno=0;
    if(id>0 && arraySectores!=NULL && tamSec>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamSec; i++)
        {
            if(arraySectores[i].id==id)
            {
                strcpy(descripcion, arraySectores[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
