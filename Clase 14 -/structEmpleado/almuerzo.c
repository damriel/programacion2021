#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "dam.h"
#include "empleado.h"

void inicializarAlmuerzos(eAlmuerzo aAlmuerzos[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        aAlmuerzos[i].isEmpty=1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo aAlmuerzos[], int tam)
{
    int indice=-1;
    if(aAlmuerzos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(aAlmuerzos[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int cargarUnAlmuerzo(eAlmuerzo* unAlmuerzo)
{
    int retorno=-1;
    if(!dam_getNumero(&(*unAlmuerzo).legEmpleado,"Ingrese legajo del empleado: ","Error.\n",1,999999,10)&&
       !dam_getNumero(&(*unAlmuerzo).idComida,"Ingrese ID de la comida: ","Error.\n",1,999999,10)&&
       !dam_getNumero(&(*unAlmuerzo).fecha.dia,"Ingrese dia: ","Error.\n",1,31,10)&&
       !dam_getNumero(&(*unAlmuerzo).fecha.mes,"Ingrese mes: ","Error.\n",1,12,10)&&
       !dam_getNumero(&(*unAlmuerzo).fecha.anio,"Ingrese anio: ","Error.\n",1950,2021,10))
    {
        retorno=0;
    }
    return retorno;
}


int altaAlmuerzo(eAlmuerzo aAlmuerzos[], int tamAlm,
                 eEmpleado aEmpleados[], int tamEmp,
                 eSector aSectores[], int tamSec,
                 eComida aComidas[], int tamCom,
                 int* pIdAlmuerzo)
{
    int retorno=-1;
    int indice;
    int legajo;
    int idComida;
    eAlmuerzo nuevoAlmuerzo;
    if(aEmpleados!=NULL && tamAlm>0 && pIdAlmuerzo!=NULL)
    {
        system("cls");
        printf("      Alta Almuerzo\n\n");
        printf("ID Almuerzo: %d\n",*pIdAlmuerzo);
        indice = buscarLibreAlmuerzo(aAlmuerzos,tamAlm);

        if(indice!=-1)
        {
            /**ASIGNO ID Almuerzo*/
            nuevoAlmuerzo.id = *pIdAlmuerzo;

            mostrarEmpleados(aEmpleados, tamEmp, aSectores, tamSec);
            dam_getNumero(&legajo,"Ingrese legajo del empleado: ","ERROR. ", 20000,30000,0);
            while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajo)==-1)
            {
                printf("No es un empleado valido...\n");
                dam_getNumero(&legajo,"Reingrese legajo: ","ERROR. ", 20000,30000,0);
            }
            /**ASIGNO Legajo Empleado*/
            nuevoAlmuerzo.legEmpleado=legajo;
            printf("\n");

            mostrarComidas(aComidas,tamCom);
            dam_getNumero(&idComida,"Ingrese ID de la comida: ","ERROR. ", 1,5000,0);
            while(buscarComida(aComidas,tamCom,idComida)==-1)
            {
                printf("No es una comida valida...\n");
                dam_getNumero(&idComida,"Reingrese ID: ","ERROR. ", 1,5000,0);
            }
            /**ASIGNO ID Comida*/
            nuevoAlmuerzo.idComida=idComida;

            /**ASIGNO Fecha*/
            dam_getNumero(&nuevoAlmuerzo.fecha.dia,"Ingrese dia (1-31): ","ERROR. ",1,31,10);
            dam_getNumero(&nuevoAlmuerzo.fecha.mes,"Ingrese mes (1-12): ","ERROR. ",1,12,10);
            dam_getNumero(&nuevoAlmuerzo.fecha.anio,"Ingrese anio (1999-2021): ","ERROR. ",1999,2021,10);
            /**Otra Forma...
            printf("Ingrese fecha dd/mm/aaa: ");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia,
                              &nuevoAlmuerzo.fecha.mes,
                              &nuevoAlmuerzo.fecha.anio);*/

            /**ASIGNO 0 a isEmpty*/
            nuevoAlmuerzo.isEmpty=0;

            /**Copio los valores de la variable auxiliar al vector de almuerzos*/
            aAlmuerzos[indice]=nuevoAlmuerzo;
            (*pIdAlmuerzo)++;
            retorno=0;
        }
        else
        {
            printf("No hay lugar para cargar mas almuerzos.\n");
        }
    }
    return retorno;
}

int mostrarAlmuerzos(eAlmuerzo aAlmuerzos[], int tam, eComida aComidas[], int tamCom, eEmpleado aEmpleados[], int tamEmp)
{
    int retorno=-1;
    int flag=0;
    if(aAlmuerzos!=NULL && tam>0)
    {
        retorno=0;
        printf("      LISTA DE ALMUERZOS\n");
        printf(" ID     Legajo     Empleado      Comida        Fecha\n");
        for(int i=0; i<tam; i++)
        {
            if(!aAlmuerzos[i].isEmpty)
            {
                mostrarUnAlmuerzo(aAlmuerzos[i],aComidas,tamCom,aEmpleados,tamEmp);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay almuerzos cargados.\n");
        }
    }
    system("pause");
    return retorno;
}

void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, eComida aComidas[], int tamCom, eEmpleado aEmpleados[], int tamEmp)
{
    char descricpcion[20];
    char nombre[20];
    if(cargarDescripcionComida(unAlmuerzo.idComida,aComidas,tamCom,descricpcion)&&
       cargarNombreEmpleado(unAlmuerzo.legEmpleado,aEmpleados,tamEmp,nombre))
    {
        printf("%5d    %5d    %10s    %10s   %02d/%02d/%4d\n",unAlmuerzo.id,
                                                    unAlmuerzo.legEmpleado,
                                                    nombre,
                                                    descricpcion,
                                                    unAlmuerzo.fecha.dia,
                                                    unAlmuerzo.fecha.mes,
                                                    unAlmuerzo.fecha.anio);
    }
    else
    {
        printf("Hubo un problema al cargar la descripcion de la comida\n");
    }
}
