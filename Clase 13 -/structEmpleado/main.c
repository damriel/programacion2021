#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "empleado.h"
#include "sector.h"
#define TAM 11
#define TAMSEC 4

void actualizarSueldosXSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void aPonerla(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);

int main()
{
    eSector sectores[TAMSEC]={
        {500,"Sistemas"},
        {501,"RRHH"},
        {502,"Cobranzas"},
        {503,"Legales"}
    };
    //HARDCODEAR VECTOR EMPLEADOS
    eEmpleado nomina[TAM];

    char exitConfirm='n';
    int nextId=20000;
    inicializarEmpleados(nomina, TAM);
    hardcodearEmpleados(nomina,TAM,10,&nextId);

    do{
        switch(menuOpciones())
        {
        case 1:
            //ALTA DE EMPLEADO
            if(!altaEmpleado(nomina, TAM, &nextId, sectores, TAMSEC))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            system("pause");
            break;
        case 2:
            modificarEmpleado(nomina, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 3:
            //BAJA DE EMPLEADO
            if(!bajaEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Hubo un problema. Baja cancelada.\n");
            }
            system("pause");
            break;
        case 4:
            //LISTAR EMPLEADOS
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);
            break;
        case 5:
            //ORDENAR EMPLEADOS
            ordenarEmpleados(nomina,TAM, sectores, TAMSEC);
            break;
        case 6:
            //MOSTRAR SECTORES
            mostrarSectores(sectores, TAMSEC);
            system("pause");
            break;
        case 7:
            //INFORMES
            empleadosSector(nomina,TAM,sectores,TAMSEC);
            break;
        case 8:
            //AUMENTO DE SUELDO
            actualizarSueldosXSector(nomina,TAM,sectores,TAMSEC);
            break;
        case 9:
            //AUMENTO DE SUELDO
            aPonerla(nomina,TAM,sectores,TAMSEC);
            break;
        case 12:
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
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
