#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"

int main()
{
    int tam=20;
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    int cant;
    int indice=-1;
    eEmpleado* auxEmpleado=NULL;
    eEmpleado** lista = (eEmpleado**)malloc(sizeof(eEmpleado*)*tam);
    //eEmpleado* emp1 = newEmpleadoParam(1234,"Juan","Perez",'m',200);

    inicializarEmpleados(lista,tam);

    FILE* f = fopen("empleados.csv","r");
    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    fscanf(f,"%s",nombre); ///Lectura fantasma del encabezado

    do{
        cant = fscanf(f,"%d,%[^,],%[^,],%c,%f",&legajo,nombre, apellido,&sexo,&sueldo);
        if(cant<4)
            {
                break;
            }
        buscarLibreEmpleado(lista,tam,&indice);
        if(indice!=-1)
        {
            auxEmpleado=newEmpleadoParam(legajo,nombre,apellido,tolower(sexo),sueldo);
            if(auxEmpleado!=NULL)
            {
                *(lista+indice)=auxEmpleado;
                auxEmpleado=NULL;
            }
        }
    }while(!feof(f));

    fclose(f);

    mostrarEmpleados(lista,tam);

    free(lista);

    return 0;
}

/*****************************************************************************/


