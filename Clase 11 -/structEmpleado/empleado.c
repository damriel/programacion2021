#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#include "empleado.h"
#define POR_EDAD 1
#define POR_NOMBRE 2
#define DOS_CRITERIOS 3

void inicializarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        arrayEmpleados[i].isEmpty=1;
    }
}

void cargarEmpleado(eEmpleado unEmpleado)
{
    dam_getNumero(&unEmpleado.legajo,"Ingrese legajo: ","Error.",1,999999,10);
    dam_getNombre(unEmpleado.nombre,"Ingrese nombre: ","Error.",20,10);
    dam_getNumero(&unEmpleado.edad,"Ingrese edad: ","Error.",1,199,10);
    dam_getCaracter(&unEmpleado.sexo,"Ingrese sexo: ","Error.",'f','m',10);
    dam_getNumeroFlotante(&unEmpleado.sueldo,"Ingrese sueldo: ","Error.",1.00,999999.0,10);
    dam_getNumero(&unEmpleado.fechaIngreso.dia,"Ingrese dia: ","Error.",1,31,10);
    dam_getNumero(&unEmpleado.fechaIngreso.mes,"Ingrese mes: ","Error.",1,12,10);
    dam_getNumero(&unEmpleado.fechaIngreso.anio,"Ingrese anio: ","Error.",1950,2021,10);
}

void cargarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        dam_getNumero(&arrayEmpleados[i].legajo,"Ingrese legajo: ","Error.",1,999999,10);
        dam_getNombre(arrayEmpleados[i].nombre,"Ingrese nombre: ","Error.",20,10);
        dam_getNumero(&arrayEmpleados[i].edad,"Ingrese edad: ","Error.",1,199,10);
        dam_getCaracter(&arrayEmpleados[i].sexo,"Ingrese sexo: ","Error.",'f','m',10);
        dam_getNumeroFlotante(&arrayEmpleados[i].sueldo,"Ingrese sueldo: ","Error.",1.00,999999.0,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.dia,"Ingrese dia: ","Error.",1,31,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.mes,"Ingrese mes: ","Error.",1,12,10);
        dam_getNumero(&arrayEmpleados[i].fechaIngreso.anio,"Ingrese anio: ","Error.",1950,2021,10);
    }
}

void mostrarUnEmpleado(eEmpleado unEmpleado)
{
    printf("%d %s %d %c %.2f %02d/%02d/%d\n",unEmpleado.legajo,
                                             unEmpleado.nombre,
                                             unEmpleado.edad,
                                             unEmpleado.sexo,
                                             unEmpleado.sueldo,
                                             unEmpleado.fechaIngreso.dia,
                                             unEmpleado.fechaIngreso.mes,
                                             unEmpleado.fechaIngreso.anio);

}

void mostrarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    int flagEmpleados=0;
    if(arrayEmpleados!=NULL)
    {
        printf("      LISTA DE EMPLEADOS\n");
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
