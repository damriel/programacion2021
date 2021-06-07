#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main()
{
    int tam = 3;
    int indice;
    eEmpleado* auxEmpleado = NULL;
    eEmpleado** lista = (eEmpleado**)malloc(sizeof(eEmpleado*)*tam);

    if(inicializarEmpleados(lista,tam))
    {
        printf("Empleados inicializados con exito!!\n");
    }
    else
    {
        printf("Ocurrio un problema al inicializar los empleados.\n");
        exit(EXIT_FAILURE);
    }

    buscarLibreEmpleado(lista,tam,&indice);
    if(indice!=-1)
    {
        auxEmpleado=newEmpleadoParam(1234, "Juan", "Perez", 'f', 5000);
        if(auxEmpleado!=NULL)
        {
            *(lista+indice)=auxEmpleado;
            printf("Alta Juan Exitosa!\n");
        }
        else
        {
            printf("No se pudo crear el empleado.\n");
        }
    }
    else
    {
        printf("No se consiguio lugar.\n");
    }

    buscarLibreEmpleado(lista,tam,&indice);
    if(indice!=-1)
    {
        *(lista+indice)=newEmpleadoParam(4524, "Ana", "Gomez", 'm', 3000);
        printf("Alta Ana Exitosa!\n");
    }
    else
    {
        printf("No se consiguio lugar.\n");
    }

    buscarLibreEmpleado(lista,tam,&indice);
    if(indice!=-1)
    {
        *(lista+indice)=newEmpleadoParam(2314, "Miguel", "Sanchez", 'f', 7600);
        printf("Alta Miguel Exitosa!\n");
    }
    else
    {
        printf("No se consiguio lugar.\n");
    }

    buscarLibreEmpleado(lista,tam,&indice);
    if(indice!=-1)
    {
        *(lista+indice)=newEmpleadoParam(3974, "Carolina", "Garcia", 'f', 6000);
        printf("Alta Carolina Exitosa!\n");
    }
    else
    {
        printf("No consegui lugar para carolina, voy a tratar de agrandar el array.\n");
        if(agrandarArray(&lista,&tam))
        {
            buscarLibreEmpleado(lista,tam,&indice);
            if(indice!=-1)
            {
                *(lista+indice)=newEmpleadoParam(3941, "Carolina", "Garcia", 'f', 6000);
                printf("Alta Carolina Exitosa!\n");
            }
        }
        else
        {
            printf("No hay caso, el array no se agranda.\n");
        }
    }

    mostrarEmpleados(lista,tam);

    ordenarEmpleadosPorLegajo(lista,tam);

    mostrarEmpleados(lista,tam);

    ordenarEmpleadosPorApellido(lista,tam);

    mostrarEmpleados(lista,tam);

    free(lista);

    return 0;
}

/*****************************************************************************/


