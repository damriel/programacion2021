#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "empleado.h"
#include "sector.h"
#include "dam.h"

void empleadosSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    int auxIdSector;
    int contador=0;
    char descripcion[20];
    system("cls");
    printf("   INFORME EMPLEADOS POR SECTOR\n");
    mostrarSectores(arraySectores, tamSec);
    if(arrayEmpleados!=NULL && tam>0 && arraySectores!=NULL && tamSec>0 && !dam_getNumero(&auxIdSector, "Ingrese el ID del sector: ","ERROR. ", 500,503,10))
    {
        cargarDescripcionSector(auxIdSector, arraySectores, tamSec, descripcion);
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].idSector==auxIdSector && !arrayEmpleados[i].isEmpty)
            {
                mostrarUnEmpleado(arrayEmpleados[i],arraySectores,tamSec);
                contador++;
            }
        }
        if(!contador)
        {
            printf("No hay empleados en el sector %s.\n",descripcion);
        }
        else
        {
            printf("Hay %d empleados en el sector %s.\n",contador,descripcion);
        }
        system("pause");
    }
}

void actualizarSueldosXSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    int auxAumento;
    int auxIdSector;
    char descripcion[20];

    system("cls");
    printf("     ACTUALIZAR SUELDOS POR SECTOR");
    mostrarSectores(arraySectores, tamSec);
    if(!dam_getNumero(&auxIdSector, "Ingrese el ID del sector: ", "ERROR. ",500,503,10) &&
       !dam_getNumero(&auxAumento, "Ingrese el porcentaje de aumento: ", "ERROR. ",1,99,10) &&
       cargarDescripcionSector(auxIdSector,arraySectores,tamSec,descripcion))
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].idSector==auxIdSector && !arrayEmpleados[i].isEmpty)
            {
                arrayEmpleados[i].sueldo+=(arrayEmpleados[i].sueldo*auxAumento/100);
            }
        }
        printf("Se han actualizado los sueldos del sector %s\n",descripcion);
    }
}

void aPonerla(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    float totalSector;
    float total=0;

    system("cls");
    printf("  INFORME SUELDOS POR SECTOR Y TOTAL\n\n");
    for(int i=0; i<tamSec; i++)
    {
        totalSector=0;
        printf("Sector: %s\n",arraySectores[i].descripcion);
        for(int j=0; j<tam; j++)
        {
            if(!arrayEmpleados[j].isEmpty && arrayEmpleados[j].idSector==arraySectores[i].id)
            {
                totalSector+=arrayEmpleados[j].sueldo;
            }
        }
        printf("Total: %.2f\n\n",totalSector);
        total+=totalSector;
    }
    printf("Total de todos los sueldos: %.2f\n",total);
    system("pause");
}

