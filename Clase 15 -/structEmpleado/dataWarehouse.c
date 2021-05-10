#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"

char nombres[10][20]={
    "Donato",
    "German",
    "Gunda",
    "Carmen",
    "Daniela",
    "Maria",
    "Alex",
    "Damian",
    "Gaston",
    "Santiago"
};

char sexos[10]={'m','m','f','f','f','f','m','m','m','m'};

int edades[10]={56,53,58,71,38,47,30,46,29,40};

float sueldos[10]={200,12000,11000,12500,13700,11800,10300,13100,14700,12400};

eFecha fechas[10]={
    {2,3,2001},
    {21,5,2018},
    {10,8,2004},
    {12,8,2017},
    {23,1,2015},
    {13,10,2021},
    {6,7,2011},
    {16,12,2017},
    {8,4,2002},
    {29,2,2020}
};

int idSectores[10]={500,500,502,504,503,501,501,501,502,504};

int legEmpleados[20]={20000,20000,20001,20002,20005,20003,20001,20007,20005,20006,20004,20009,20007,20005,20000,20001,20002,20005,20007,20003};
int idComidasA[20]={1000,1004,1002,1000,1000,1000,1003,1004,1003,1000,1001,1002,1001,1003,1004,1001,1001,1003,1002,1004};
eFecha fechas2[20]={
    {2,3,2021},
    {21,5,2021},
    {10,4,2021},
    {2,3,2021},
    {21,11,2021},
    {10,8,2021},
    {2,3,2021},
    {21,5,2021},
    {10,8,2021},
    {7,3,2021},
    {21,5,2021},
    {10,12,2021},
    {12,5,2017},
    {23,1,2021},
    {12,3,2001},
    {21,5,2014},
    {10,12,2003},
    {22,2,2013},
    {23,1,2011},
    {26,3,2021}
};

int hardcodearEmpleados(eEmpleado arrayEmpleados[], int tam, int cant, int* pLegajo)
{
    int retorno=0;
    if(arrayEmpleados!=NULL && tam>0 && cant>=0 && cant<=tam && pLegajo!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            arrayEmpleados[i].legajo=*pLegajo;
            (*pLegajo)++;
            strcpy(arrayEmpleados[i].nombre, nombres[i]);
            arrayEmpleados[i].edad=edades[i];
            arrayEmpleados[i].sexo=sexos[i];
            arrayEmpleados[i].sueldo=sueldos[i];
            arrayEmpleados[i].fechaIngreso=fechas[i];
            arrayEmpleados[i].idSector=idSectores[i];
            arrayEmpleados[i].isEmpty=0;
        }
    }
    return retorno;
}

int hardcodearAlmuerzos(eAlmuerzo aAlmuerzos[], int tamAlm, int cant, int* pId)
{
    int retorno=0;
    if(aAlmuerzos!=NULL && tamAlm>0 && cant>=0 && cant<=tamAlm && pId!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            aAlmuerzos[i].id=*pId;
            (*pId)++;
            aAlmuerzos[i].legEmpleado=legEmpleados[i];
            aAlmuerzos[i].idComida=idComidasA[i];
            aAlmuerzos[i].fecha=fechas2[i];
            aAlmuerzos[i].isEmpty=0;
        }
    }
    return retorno;
}
