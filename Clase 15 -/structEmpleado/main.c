#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "dataWarehouse.h"

#define TAM 10
#define TAMSEC 5
#define TAMCOM 5
#define TAMALM 30

/**
TAREA PARA 10/05
1) Elegir un sector y haga la sumatorias de todas los almuerzos de ese sector.
2) Cual es la comida preferida de un sector.
3) Cual es el sector que más comio de una comida.
4) Elegir un empleado o varios, una vez que calcula el costo de la comida que se lo descuente del sueldo.
   Que salte una alarma si los gastos de los almuerzos son más grandes que los sueldos (es porque no tiene dinero para pagar).
*/

void sectorQueMasCobra(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec);
void mostrarAlmuerzosEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void totalGastoAlmuerzo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);

int main()
{
    eSector sectores[TAMSEC]={
        {500,"Sistemas"},
        {501,"RRHH"},
        {502,"Cobranzas"},
        {503,"Legales"},
        {504,"Ventas"}
    };

    eComida comidas[TAMCOM]={
        {1000,"Milanesa", 100},
        {1001,"Fideos", 120},
        {1002,"Churrasco", 140},
        {1003,"Ensalada", 160},
        {1004,"Pescado", 110}
    };

    char exitConfirm='n';
    int nextId=20000;
    int nextIdAlmuerzo=50000;
    eAlmuerzo almuerzos[TAMALM];
    eEmpleado nomina[TAM];
    inicializarEmpleados(nomina, TAM);
    inicializarAlmuerzos(almuerzos,TAMALM);
    hardcodearEmpleados(nomina,TAM,10,&nextId);
    hardcodearAlmuerzos(almuerzos,TAMALM,20,&nextIdAlmuerzo);

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
            system("pause");
            break;
        case 5:
            //ORDENAR EMPLEADOS
            ordenarEmpleados(nomina,TAM, sectores, TAMSEC);
            system("pause");
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
        case 10:
            system("cls");
            mostrarComidas(comidas, TAMCOM);
            break;
        case 11:
            altaAlmuerzo(almuerzos,TAMALM,nomina,TAM,sectores,TAMSEC,comidas,TAMCOM,&nextIdAlmuerzo);
            break;
        case 12:
            mostrarAlmuerzos(almuerzos,TAMALM,comidas,TAMCOM,nomina,TAM);
            break;
        case 13:
            sectorQueMasCobra(nomina, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 14:
            mostrarAlmuerzosEmpleado(nomina,TAM,sectores,TAMSEC,comidas,TAMCOM,almuerzos,TAMALM);
            system("pause");
            break;
        case 15:
            totalGastoAlmuerzo(nomina,TAM,sectores,TAMSEC,comidas,TAMCOM,almuerzos,TAMALM);
            system("pause");
            break;
        case 20:
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}


void sectorQueMasCobra(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    float totales[tamSec];
    float auxFloat;
    int idSector;
    int mayor;
    for(int i=0; i<tamSec; i++)
    {
        auxFloat=0;
        idSector=aSectores[i].id;
        for(int j=0; j<tam; j++)
        {
            if(aEmpleados[j].isEmpty==0 && aEmpleados[j].idSector==idSector)
            {
                auxFloat+=aEmpleados[j].sueldo;
            }
        }
        totales[i]=auxFloat;
    }
    mayor=totales[0];
    for(int i=1; i<tamSec; i++)
    {
        if(totales[i]>mayor)
        {
            mayor=totales[i];
        }
    }

    printf("Sectores que mas cobran:\n");
    for(int i=0; i<tamSec; i++)
    {
        if(totales[i]==mayor)
        {
            printf(" %s ", aSectores[i].descripcion);
        }
    }
    printf("\n\n");
}

void mostrarAlmuerzosEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajo;
    int flag=0;
    printf("       Almuerzos Empleado \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajo,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajo)==-1)
    {
        dam_getNumero(&legajo,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(aAlmuerzos[i].legEmpleado == legajo && !aAlmuerzos[i].isEmpty)
        {
            mostrarUnAlmuerzo(aAlmuerzos[i],aComidas,tamCom,aEmpleados,tamEmp);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n",legajo);
    }
}

void totalGastoAlmuerzo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajoBuscado;
    int flag=0;
    float gastoTotal=0;
    printf("       Total Gasto Almuerzo \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajoBuscado,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado)==-1)
    {
        dam_getNumero(&legajoBuscado,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(aAlmuerzos[i].legEmpleado == legajoBuscado && !aAlmuerzos[i].isEmpty)
        {
            for(int j=0; j<tamCom; j++)
            {
                if(aAlmuerzos[i].idComida==aComidas[j].id)
                {
                    gastoTotal+=aComidas[j].precio;
                    flag=1;
                }
            }
        }
    }

    if(!flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n",legajoBuscado);
    }
    else
    {
        printf("Total a pagar $ %.2f\n",gastoTotal);
    }
}
