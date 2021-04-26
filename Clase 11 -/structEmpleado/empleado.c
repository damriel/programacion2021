#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#include "empleado.h"
#define POR_EDAD 1
#define POR_NOMBRE 2
#define DOS_CRITERIOS 3

static int buscarLibre(eEmpleado arrayEmpleados[], int tam);
static int buscarEmpleado(eEmpleado arrayEmpleados[], int tam);
static int menuModificaciones();

/*****************************************************************/

void inicializarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        arrayEmpleados[i].isEmpty=1;
    }
}

void cargarEmpleado(eEmpleado unEmpleado)
{
    dam_getNumero(&unEmpleado.legajo,"Ingrese legajo: ","Error.\n",1,999999,10);
    dam_getNombre(unEmpleado.nombre,"Ingrese nombre: ","Error.\n",20,10);
    dam_getNumero(&unEmpleado.edad,"Ingrese edad: ","Error.\n",1,199,10);
    dam_getCaracter(&unEmpleado.sexo,"Ingrese sexo: ","Error.\n",'f','m',10);
    dam_getNumeroFlotante(&unEmpleado.sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10);
    dam_getNumero(&unEmpleado.fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10);
    dam_getNumero(&unEmpleado.fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10);
    dam_getNumero(&unEmpleado.fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10);
}

void cargarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        dam_getNumero(&arrayEmpleados[i].legajo,"Ingrese legajo: ","Error.\n",1,999999,10);
        dam_getNombre(arrayEmpleados[i].nombre,"Ingrese nombre: ","Error.\n",20,10);
        dam_getNumero(&arrayEmpleados[i].edad,"Ingrese edad: ","Error.\n",1,199,10);
        dam_getCaracter(&arrayEmpleados[i].sexo,"Ingrese sexo: ","Error.\n",'f','m',10);
        dam_getNumeroFlotante(&arrayEmpleados[i].sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10);

    }
}

void mostrarUnEmpleado(eEmpleado unEmpleado)
{
    printf("%6d %10s    %2d    %c    %9.2f      %02d/%02d/%d\n",unEmpleado.legajo,
                                                                unEmpleado.nombre,
                                                                unEmpleado.edad,
                                                                unEmpleado.sexo,
                                                                unEmpleado.sueldo,
                                                                unEmpleado.fechaIngreso.dia,
                                                                unEmpleado.fechaIngreso.mes,
                                                                unEmpleado.fechaIngreso.anio);

}

int mostrarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-1;
    int flagEmpleados=0;
    if(arrayEmpleados!=NULL && tam>0)
    {
        retorno=0;
        printf("      LISTA DE EMPLEADOS\n");
        printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso\n");
        for(int i=0; i<tam; i++)
        {
            if(!arrayEmpleados[i].isEmpty)
            {
               mostrarUnEmpleado(arrayEmpleados[i]);
               flagEmpleados=1;
            }
        }
        if(!flagEmpleados)
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
    }
    return retorno;
}

void ordenarEmpleados(eEmpleado arrayEmpleados[], int tam, int criterio)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            switch(criterio)
            {
            case POR_EDAD:
                //por edad descendente
                if(arrayEmpleados[i].edad<arrayEmpleados[j].edad)
                {
                    auxEmpleado = arrayEmpleados[i];
                    arrayEmpleados[i] = arrayEmpleados[j];
                    arrayEmpleados[j] = auxEmpleado;
                }
                break;
            case POR_NOMBRE:
                //por nombre ascendente
                if(strcmp(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre)>0)
                {
                    auxEmpleado = arrayEmpleados[i];
                    arrayEmpleados[i] = arrayEmpleados[j];
                    arrayEmpleados[j] = auxEmpleado;
                }
                break;
            case DOS_CRITERIOS:
                //por sexo descendente (z-a) y luego por legajo ascendente
                if(arrayEmpleados[i].sexo<arrayEmpleados[j].sexo ||
                  (arrayEmpleados[i].sexo==arrayEmpleados[j].sexo&&
                   arrayEmpleados[i].legajo>arrayEmpleados[j].legajo))
                {
                    auxEmpleado = arrayEmpleados[i];
                    arrayEmpleados[i] = arrayEmpleados[j];
                    arrayEmpleados[j] = auxEmpleado;
                }
            }
        }
    }
}

/**********************************************************************************************************************************************************/

int menuOpciones()
{
    int retorno=0;
    printf("      *** ABM DE EMPLEADOS ***\n");
    printf("1) Alta empleado.\n");
    printf("2) Modificar empleado.\n");
    printf("3) Baja empleado.\n");
    printf("4) Listar empleados.\n");
    printf("5) Salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.",1,5,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

static int buscarLibre(eEmpleado arrayEmpleados[], int tam)
{
    int indice=-1;
    if(arrayEmpleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-1;
    int i;
    if(arrayEmpleados!=NULL && tam>0)
    {
        i = buscarLibre(arrayEmpleados,tam);
        if(i!=-1)
        {
            retorno=0;
            arrayEmpleados[i].isEmpty=0;
            /*dam_getNumero(&arrayEmpleados[i].legajo,"Ingrese legajo: ","Error. ",1,999999,10);
            dam_getNombre(arrayEmpleados[i].nombre,"Ingrese nombre: ","Error. ",20,10);
            dam_getNumero(&arrayEmpleados[i].edad,"Ingrese edad: ","Error. ",1,199,10);
            dam_getCaracter(&arrayEmpleados[i].sexo,"Ingrese sexo: ","Error. ",'f','m',10);
            dam_getNumeroFlotante(&arrayEmpleados[i].sueldo,"Ingrese sueldo: ","Error. ",1.00,999999.0,10);
            dam_getNumero(&arrayEmpleados[i].fechaIngreso.dia,"Ingrese dia: ","Error. ",1,31,10);
            dam_getNumero(&arrayEmpleados[i].fechaIngreso.mes,"Ingrese mes: ","Error. ",1,12,10);
            dam_getNumero(&arrayEmpleados[i].fechaIngreso.anio,"Ingrese anio: ","Error. ",1950,2021,10);*/
            cargarEmpleado(arrayEmpleados[i]);
        }
        else
        {
            retorno=-2;
            printf("No hay lugar para cargar mas empleados.\n");
        }
    }
    return retorno;
}

static int buscarEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int indice=-1;
    int legajoBuscado;
    if(arrayEmpleados!=NULL && tam>0 &&
       !mostrarEmpleados(arrayEmpleados,tam) &&
       !dam_getNumero(&legajoBuscado,"\n\nIngrese el legajo del empleado: ","ERROR. Legajo no valido.\n",1,999999,10))
    {
        for(int i=0; i<tam; i++)
        {
            if(legajoBuscado==arrayEmpleados[i].legajo && arrayEmpleados[i].isEmpty==0)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

static int menuModificaciones()
{
    int retorno=0;
    printf("\nMENU DE MODIFICACIONES...\n");
    printf("1) Nombre.\n");
    printf("2) Edad.\n");
    printf("3) Sexo.\n");
    printf("4) Sueldo.\n");
    printf("5) Fecha de ingreso.\n");
    printf("6) Guardar cambios y salir.\n");
    printf("7) Descartar cambios y salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.\n",1,7,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int modificarEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-1;
    int indice = buscarEmpleado(arrayEmpleados,tam);
    int opcion;
    char auxNombre[20];
    int auxEdad;
    char auxSexo;
    float auxSueldo;
    int auxDia;
    int auxMes;
    int auxAnio;
    int flagNombre=1;
    int flagSexo=1;
    int flagEdad=1;
    int flagSueldo=1;
    int flagFecha=1;


    if(arrayEmpleados!=NULL && tam>0)
    {
        while(indice==-1)
        {
            printf("No se encontro ningun empleado con ese legajo.\n");
            indice = buscarEmpleado(arrayEmpleados,tam);
        }
        printf("Empleado encontrado:\n");
        printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso\n");
        mostrarUnEmpleado(arrayEmpleados[indice]);
        retorno=0;

        do{
            opcion = menuModificaciones();
            switch(opcion)
            {
            case 1:
                flagNombre = dam_getNombre(auxNombre,"Ingrese nuevo nombre: ","Error. ",20,10);
                break;
            case 2:
                flagEdad = dam_getNumero(&auxEdad,"Ingrese neuva edad: ","Error. ",1,199,10);
                break;
            case 3:
                flagSexo = dam_getCaracter(&auxSexo,"Ingrese nuevo sexo: ","Error. ",'f','m',10);
                break;
            case 4:
                flagSueldo = dam_getNumeroFlotante(&auxSueldo,"Ingrese neuvo sueldo: ","Error. ",1.00,999999.0,10);
                break;
            case 5:
                if (!dam_getNumero(&auxDia,"Ingrese nuevo dia: ","Error. ",1,31,10) &&
                    !dam_getNumero(&auxMes,"Ingrese nuevo mes: ","Error. ",1,12,10) &&
                    !dam_getNumero(&auxAnio,"Ingrese nuevo anio: ","Error. ",1950,2021,10))
                {
                    flagFecha=0;
                }
                break;
            case 6:
                if(!flagNombre)
                {
                    strcpy(arrayEmpleados[indice].nombre,auxNombre);
                }
                if(!flagEdad)
                {
                    arrayEmpleados[indice].edad=auxEdad;
                }
                if(!flagSexo)
                {
                    arrayEmpleados[indice].sexo=auxSexo;
                }
                if(!flagSueldo)
                {
                    arrayEmpleados[indice].sueldo=auxSueldo;
                }
                if(!flagFecha)
                {
                    arrayEmpleados[indice].fechaIngreso.dia=auxDia;
                    arrayEmpleados[indice].fechaIngreso.mes=auxMes;
                    arrayEmpleados[indice].fechaIngreso.anio=auxAnio;
                }
                printf("\nEmpleado modificado:\n");
                mostrarUnEmpleado(arrayEmpleados[indice]);
                printf("Cambios guardados, volviendo al menu principal...\n\n");
                break;
            case 7:
                printf("Cambios descartados, volviendo al menu principal...\n\n");
                break;
            }
        }while(opcion!=6 && opcion!=7);
    }
    return retorno;
}
int bajaEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-2;
    char confirm='n';
    int indice=buscarEmpleado(arrayEmpleados,tam);
    if(arrayEmpleados!=NULL && tam>0)
    {
        while(indice==-1)
        {
            printf("No se encontro ningun empleado con ese legajo.\n");
            indice = buscarEmpleado(arrayEmpleados,tam);
        }
        printf("Empleado encontrado:\n");
        printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso\n");
        mostrarUnEmpleado(arrayEmpleados[indice]);
        if(!dam_getCaracter(&confirm,"Seguro desea dar de baja a este empleado? (s/n): ", "ERROR.\n",'s','n',10) && confirm=='s')
        {
            arrayEmpleados[indice].isEmpty=1;
            retorno = 0;
            printf("El usuario se dio de baja correctamente.\n");
        }
        else
        {
            printf("Se cancelo la baja o ingreso demasiadas opciones invalidas.\n");
            retorno = -1;
        }

    }

    return retorno;
}
