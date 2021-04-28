#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "empleado.h"
#include "dam.h"

//PARA EL VIERNES
//REFACTORIZAR EL ABM PARA LOS EMPLEADOS CON LOS SECTORES INCLUIDOS

void mostrarSectores(eSector arraySectores[], int tam)
{
    printf("\n Listado de Sectores\n");
    printf("  ID    Descripcion\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnSector(arraySectores[i]);
    }
    printf("\n\n");
}

void mostrarUnSector(eSector unSector)
{
    printf(" %d    %10s\n",unSector.id, unSector.descripcion);
}
