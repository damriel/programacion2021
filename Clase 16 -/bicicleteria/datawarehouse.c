#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

/**DATOS PARA ENTIDAD TIPOS*/

int idTipos[4]={
    1000,
    1001,
    1002,
    1003
};

char descripcionTipos[4][20]={
    "Rutera",
    "Carrera",
    "Mountain",
    "BMX"
};

int hardcodearTipos(eTipo aTipos[], int tamTipo)
{
    int retorno=0;

    if(aTipos!=NULL && tamTipo>0)
    {
        retorno=1;
        for(int i=0; i<tamTipo; i++)
        {
            aTipos[i].id=idTipos[i];
            strcpy(aTipos[i].descripcion, descripcionTipos[i]);
        }
    }
    return retorno;
}

/**DATOS PARA ENTIDAD COLOR*/

int idColores[5]={
    5000,
    5001,
    5002,
    5003,
    5004
};

char descripcionColores[5][20]={
    "Gris",
    "Negro",
    "Blanco",
    "Azul",
    "Rojo"
};

int hardcodearColores(eColor aColores[], int tamCol)
{
    int retorno=0;

    if(aColores!=NULL && tamCol>0)
    {
        retorno=1;
        for(int i=0; i<tamCol; i++)
        {
            aColores[i].id=idColores[i];
            strcpy(aColores[i].nombreColor, descripcionColores[i]);
        }
    }
    return retorno;
}

/**DATOS PARA ENTIDAD SERVICIOS*/

int idServicios[4]={
    20000,
    20001,
    20002,
    20003
};

char descripcionServicios[4][20]={
    "Limpieza",
    "Parche",
    "Centrado",
    "Cadena"
};

float preciosServicios[4]={
    250,
    300,
    400,
    350
};

int hardcodearServicios(eServicio aServicios[], int tamSer)
{
    int retorno=0;

    if(aServicios!=NULL && tamSer>0)
    {
        retorno=1;
        for(int i=0; i<tamSer; i++)
        {
            aServicios[i].id=idServicios[i];
            strcpy(aServicios[i].descripcion, descripcionServicios[i]);
            aServicios[i].precio=preciosServicios[i];
        }
    }
    return retorno;
}
