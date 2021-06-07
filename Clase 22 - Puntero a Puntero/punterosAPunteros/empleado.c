#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int inicializarEmpleados(eEmpleado** emp, int sizeEmp)
{
    int retorno=0;
    if(emp!=NULL && sizeEmp>0)
    {
        for(int i=0; i<sizeEmp; i++)
        {
            *(emp+i)=NULL;
        }
        retorno=1;
    }
    return retorno;
}

int mostrarEmpleado(eEmpleado* emp)
{
    int retorno = 0;
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    if(emp!=NULL &&
       empleadoGetLegajo(emp, &legajo) &&
       empleadoGetNombre(emp, nombre) &&
       empleadoGetApellido(emp, apellido) &&
       empleadoGetSexo(emp, &sexo) &&
       empleadoGetSueldo(emp, &sueldo))
    {
        printf(" %d   %10s  %10s    %c  %9.2f\n",legajo,nombre,apellido,sexo,sueldo);
        retorno=1;
    }
    return retorno;
}

int mostrarEmpleados(eEmpleado** emp, int sizeEmp)
{
    int retorno=0;
    if(emp!=NULL && sizeEmp>0)
    {
        printf("Legajo     Nombre    Apellido   Sexo   Sueldo\n");
        for(int i=0; i<sizeEmp; i++)
        {
            mostrarEmpleado(*(emp+i));
        }
        printf("\n\n");
        retorno=1;
    }
    return retorno;
}

int buscarLibreEmpleado(eEmpleado** emp, int sizeEmp, int* pIndice)
{
    int retorno=0;
    *pIndice = -1;
    if(emp!=NULL && sizeEmp>0 && pIndice!=NULL)
    {
        for(int i=0; i<sizeEmp; i++)
        {
            if(*(emp+i)==NULL)
            {
                *pIndice=i;
                break;
            }
        }
        retorno=1;
    }
    return retorno;
}

int agrandarArray(eEmpleado*** pEmp, int* pTam)
{
    int retorno=0;
    eEmpleado** aux;

    aux=(eEmpleado**)realloc(*pEmp, sizeof(eEmpleado*)*(*pTam+1));
    if(aux!=NULL)
    {
        printf("Se agrando el array\n");
        *(aux + *pTam) = NULL;
        *pEmp=aux;
        *pTam=*pTam+1;
        retorno=1;
    }
    return retorno;
}

int ordenarEmpleadosPorLegajo(eEmpleado** emp, int sizeEmp)
{
    int retorno=0;
    eEmpleado* aux;
    if(emp!=NULL && sizeEmp>0)
    {
        for(int i=0; i<sizeEmp-1; i++)
        {
            for(int j=i+1; j<sizeEmp; j++)
            if((*(emp+i))->legajo > (*(emp+j))->legajo)
            {
                aux=*(emp+i);
                *(emp+i)=*(emp+j);
                *(emp+j)=aux;
            }
        }
        printf("\n\nLista ordenada por legajo...\n");
        retorno=1;
    }
    return retorno;
}

int ordenarEmpleadosPorApellido(eEmpleado** emp, int sizeEmp)
{
    int retorno=0;
    eEmpleado* aux;
    if(emp!=NULL && sizeEmp>0)
    {
        for(int i=0; i<sizeEmp-1; i++)
        {
            for(int j=i+1; j<sizeEmp; j++)
            if(strcmp((*(emp+i))->apellido,(*(emp+j))->apellido)>0)
            {
                aux=*(emp+i);
                *(emp+i)=*(emp+j);
                *(emp+j)=aux;
            }
        }
        printf("\n\nLista ordenada por apellido...\n");
        retorno=1;
    }
    return retorno;
}

/*****************************************************************************/
/********                 FUNCIONES CONSTRUCTORAS               **************/
/*****************************************************************************/

eEmpleado* newEmpleado()
{
    eEmpleado* nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->legajo=0;
        strcpy(nuevoEmpleado->nombre,"");
        strcpy(nuevoEmpleado->apellido,"");
        nuevoEmpleado->sexo=' ';
        nuevoEmpleado->sueldo=0;
    }
    return nuevoEmpleado;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado = newEmpleado();
    if(nuevoEmpleado!=NULL)
    {
        if(!(empleadoSetLegajo(nuevoEmpleado,legajo) &&
           empleadoSetNombre(nuevoEmpleado,nombre) &&
           empleadoSetApellido(nuevoEmpleado,apellido) &&
           empleadoSetSexo(nuevoEmpleado,sexo) &&
           empleadoSetSueldo(nuevoEmpleado,sueldo)))
        {
            destroyEmpleado(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }
    }
    return nuevoEmpleado;
}

/******************************************************************************
******************                 SETTERS                    *****************
******************************************************************************/

int empleadoSetLegajo(eEmpleado* emp, int legajo)
{
    int retorno=0;
    if(emp!=NULL && legajo>0)
    {
        emp->legajo=legajo;
        retorno=1;
    }
    return retorno;
}

int empleadoSetNombre(eEmpleado* emp, char* nombre)
{
    int retorno=0;
    if(emp!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<20)
    {
        strcpy(emp->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int empleadoSetApellido(eEmpleado* emp, char* apellido)
{
    int retorno=0;
    if(emp!=NULL && apellido!=NULL && strlen(apellido)>1 && strlen(apellido)<20)
    {
        strcpy(emp->apellido,apellido);
        retorno=1;
    }
    return retorno;
}

int empleadoSetSexo(eEmpleado* emp, char sexo)
{
    int retorno=0;
    if(emp!=NULL && (sexo=='m'||sexo=='f'))
    {
        emp->sexo=sexo;
        retorno=1;
    }
    return retorno;
}

int empleadoSetSueldo(eEmpleado* emp, int sueldo)
{
    int retorno=0;
    if(emp!=NULL && sueldo>=0)
    {
        emp->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

/******************************************************************************
******************                 GETTERS                    *****************
******************************************************************************/

int empleadoGetLegajo(eEmpleado* emp, int* pLegajo)
{
    int retorno=0;
    if(emp!=NULL && pLegajo!=NULL)
    {
        *pLegajo=emp->legajo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetNombre(eEmpleado* emp, char* pNombre)
{
    int retorno=0;
    if(emp!=NULL && pNombre!=NULL)
    {
        strcpy(pNombre,emp->nombre);
        retorno=1;
    }
    return retorno;
}

int empleadoGetApellido(eEmpleado* emp, char* pApellido)
{
    int retorno=0;
    if(emp!=NULL && pApellido!=NULL)
    {
        strcpy(pApellido,emp->apellido);
        retorno=1;
    }
    return retorno;
}

int empleadoGetSexo(eEmpleado* emp, char* pSexo)
{
    int retorno=0;
    if(emp!=NULL && pSexo!=NULL)
    {
        *pSexo=emp->sexo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetSueldo(eEmpleado* emp, float* pSueldo)
{
    int retorno=0;
    if(emp!=NULL && pSueldo!=NULL)
    {
        *pSueldo=emp->sueldo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetNombreCompleto(eEmpleado* emp, char* pNombreCompleto)
{
    int retorno=0;
    if(emp!=NULL && pNombreCompleto!=NULL)
    {
        strcpy(pNombreCompleto,emp->nombre);
        strcat(pNombreCompleto," ");
        strcat(pNombreCompleto,emp->apellido);
        retorno=1;
    }
    return retorno;
}

/******************************************************************************
******************                 DESTROYER                  *****************
******************************************************************************/

int destroyEmpleado(eEmpleado* emp)
{
    int retorno=0;
    if(emp!=NULL)
    {
        free(emp);
        retorno=1;
    }
    return retorno;
}
