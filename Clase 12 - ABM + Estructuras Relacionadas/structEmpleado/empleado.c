#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#include "empleado.h"
#define DESCENDENTE 0
#define ASCENDENTE 1
#define POR_LEGAJO 1
#define POR_NOMBRE 2
#define POR_EDAD 3
#define POR_SEXO 4
#define POR_SUELDO 5
#define POR_SECTOR 6
#define DOS_CRITERIOS 30

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
    //dam_getNumero(&unEmpleado.legajo,"Ingrese legajo: ","Error.\n",1,999999,10);
    dam_getNombre(unEmpleado.nombre,"Ingrese nombre: ","Error.\n",20,10);
    dam_getNumero(&unEmpleado.edad,"Ingrese edad: ","Error.\n",1,199,10);
    dam_getCaracter(&unEmpleado.sexo,"Ingrese sexo: ","Error.\n",'f','m',10);
    dam_getNumeroFlotante(&unEmpleado.sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10);
    dam_getNumero(&unEmpleado.fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10);
    dam_getNumero(&unEmpleado.fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10);
    dam_getNumero(&unEmpleado.fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10);
}

int cargarUnEmpleado(eEmpleado* unEmpleado, eSector arraySectores[], int tamSec)
{
    int retorno=-1;
    int auxIdSector;
    if(!dam_getNombre((*unEmpleado).nombre,"Ingrese nombre: ","Error.\n",20,10)&&
       !dam_getNumero(&(*unEmpleado).edad,"Ingrese edad: ","Error.\n",1,199,10)&&
       !dam_getCaracter(&(*unEmpleado).sexo,"Ingrese sexo: ","Error.\n",'f','m',10)&&
       !dam_getNumeroFlotante(&(*unEmpleado).sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10))
    {
        mostrarSectores(arraySectores, tamSec);
        if(!dam_getNumero(&auxIdSector,"Ingrese el ID del sector: ","Error. ",500,503,10))
        {
            for(int i=0; i<tamSec; i++)
            {
                if(arraySectores[i].id==auxIdSector)
                {
                    strcpy((*unEmpleado).sector,arraySectores[i].descripcion);
                    break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
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
    printf("%6d %10s    %2d    %c    %9.2f      %02d/%02d/%d        %10s\n",unEmpleado.legajo,
                                                                            unEmpleado.nombre,
                                                                            unEmpleado.edad,
                                                                            unEmpleado.sexo,
                                                                            unEmpleado.sueldo,
                                                                            unEmpleado.fechaIngreso.dia,
                                                                            unEmpleado.fechaIngreso.mes,
                                                                            unEmpleado.fechaIngreso.anio,
                                                                            unEmpleado.sector);

}

int mostrarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-1;
    int flagEmpleados=0;
    if(arrayEmpleados!=NULL && tam>0)
    {
        retorno=0;
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].isEmpty==0)
            {
                flagEmpleados=1;
                break;
            }
        }
        if(flagEmpleados)
        {
            printf("      LISTA DE EMPLEADOS\n");
            printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso        Sector\n");
        }
        else
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
        for(int i=0; i<tam && !arrayEmpleados[i].isEmpty; i++)
        {
            mostrarUnEmpleado(arrayEmpleados[i]);
        }
    }
    system("pause");
    return retorno;
}

int menuOrdenamiento()
{
    int retorno=0;
    system("cls");
    printf("      ORDENAR EMPLEADOS\n");
    printf("1) Por Legajo (ascendente o descendente)\n");
    printf("2) Por Nombre (ascendente o descendente)\n");
    printf("3) Por Edad (ascendente o descendente)\n");
    printf("4) Por Sexo (ascendente o descendente)\n");
    printf("5) Por Sueldo (ascendente o descendente)\n");
    printf("6) Por Sector (ascendente o descendente)\n");
    printf("     ** Agrupar y Ordenar **\n");
    printf("7) Por Sexo y Legajo (Ascendentes)\n");
    printf("8) Por Sexo y Sueldo (Ascendentes)\n");
    printf("9) Por Sexo y Nombre (Ascendentes)\n");
    printf("10) Por Sector y Sueldo (Ascendentes)\n");
    printf("11) Por Sector y Nombre (Ascendentes)\n");
    printf("12) Volver al menu principal.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.",1,12,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int subMenuOrdenamiento()
{
    int retorno=0;
    printf("      ORDENAR EMPLEADOS\n");
    printf("1) Descendente.\n");
    printf("2) Ascendente.\n");
    printf("3) Cancelar.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.",1,12,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

void ordenarEmpleados(eEmpleado arrayEmpleados[], int tam)
{
    int criterio;
    int orden;
    eEmpleado auxEmpleado;
    if(arrayEmpleados!=NULL && tam>0)
    {
        criterio = menuOrdenamiento();
        if(criterio>0 && criterio<7)
        {
            orden = subMenuOrdenamiento()-1;
            if(orden==2)
            {
                criterio=12;
            }
        }
        for(int i=0; i<tam-1 && !arrayEmpleados[i].isEmpty; i++)
        {
            for(int j=i+1; j<tam && !arrayEmpleados[j].isEmpty; j++)
            {
                switch(criterio)
                {
                case 1:
                    if(arrayEmpleados[i].legajo>arrayEmpleados[j].legajo && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    else if(arrayEmpleados[i].legajo<arrayEmpleados[j].legajo && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 2:
                    if(strcmp(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre)>0 && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    if(strcmp(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre)<0 && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 3:
                    if(arrayEmpleados[i].edad>arrayEmpleados[j].edad && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    else if(arrayEmpleados[i].edad<arrayEmpleados[j].edad && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 4:
                    if(arrayEmpleados[i].sexo>arrayEmpleados[j].sexo && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    else if(arrayEmpleados[i].sexo<arrayEmpleados[j].sexo && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 5:
                    if(arrayEmpleados[i].sueldo>arrayEmpleados[j].sueldo && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    else if(arrayEmpleados[i].sueldo<arrayEmpleados[j].sueldo && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 6:
                    if(strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)>0 && orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    if(strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)<0 && !orden)
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 7:
                    if(arrayEmpleados[i].sexo>arrayEmpleados[j].sexo ||
                      (arrayEmpleados[i].sexo==arrayEmpleados[j].sexo&&
                       arrayEmpleados[i].legajo>arrayEmpleados[j].legajo))
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 8:
                    if(arrayEmpleados[i].sexo<arrayEmpleados[j].sexo ||
                      (arrayEmpleados[i].sexo==arrayEmpleados[j].sexo&&
                       arrayEmpleados[i].sueldo>arrayEmpleados[j].sueldo))
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 9:
                    if(arrayEmpleados[i].sexo<arrayEmpleados[j].sexo ||
                      (arrayEmpleados[i].sexo==arrayEmpleados[j].sexo&&
                       strcmp(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre)>0))
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 10:
                    if(strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)>0||
                      (strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)==0&&
                       arrayEmpleados[i].sueldo>arrayEmpleados[j].sueldo))
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 11:
                    if(strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)>0||
                      (strcmp(arrayEmpleados[i].sector,arrayEmpleados[j].sector)==0&&
                       strcmp(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre)>0))
                    {
                        auxEmpleado = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[j];
                        arrayEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 12:
                    printf("Ordenamiento cancelado.\n");
                    i=tam;
                    j=tam;
                    break;
                }
            }
        }
    }
    system("pause");
}

/**********************************************************************************************************************************************************/

int menuOpciones()
{
    int retorno=0;
    system("cls");
    printf("      *** ABM DE EMPLEADOS ***\n");
    printf("1) Alta empleado.\n");
    printf("2) Modificar empleado.\n");
    printf("3) Baja empleado.\n");
    printf("4) Listar empleados.\n");
    printf("5) Ordenar Empleados.\n");
    printf("6) Mostrar Sectores.\n");
    printf("7) Informes.\n");
    printf("12) Salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.",1,12,10)==-1)
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
            if(arrayEmpleados[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaEmpleado(eEmpleado arrayEmpleados[], int tam, int* pId, eSector arraySectores[], int tamSec)
{
    int retorno=-1;
    eEmpleado nuevoEmpleado;
    int indice;
    if(arrayEmpleados!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("      Alta Empleado\n\n");
        indice = buscarLibre(arrayEmpleados,tam);
        if(indice!=-1)
        {
            printf("Legajo: %d\n",*pId);
            if(!cargarUnEmpleado(&nuevoEmpleado, arraySectores, tamSec))
            {
                arrayEmpleados[indice]=nuevoEmpleado;
                arrayEmpleados[indice].isEmpty=0;
                arrayEmpleados[indice].legajo = *pId;
                (*pId)++;
                retorno=0;
            }
            else
            {
                printf("Error, no se pudo dar de alta al empleado.");
            }
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
            if(legajoBuscado==arrayEmpleados[i].legajo && !arrayEmpleados[i].isEmpty)
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
    printf("6) Sector.\n");
    printf("7) Guardar cambios y salir.\n");
    printf("8) Descartar cambios y salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.\n",1,8,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int modificarEmpleado(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    int retorno=-1;
    int indice;
    int opcion;
    eEmpleado auxEmpleado;
    int auxIdSector;
    int flagNombre=1;
    int flagSexo=1;
    int flagEdad=1;
    int flagSueldo=1;
    int flagFecha=1;
    int flagSector=1;


    if(arrayEmpleados!=NULL && tam>0)
    {
        indice = buscarEmpleado(arrayEmpleados,tam);
        if(indice==-1)
        {
            printf("No se encontro ningun empleado con ese legajo.\n");
        }
        else
        {
            printf("Empleado encontrado:\n");
            printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso        Sector\n");
            mostrarUnEmpleado(arrayEmpleados[indice]);

            do{
                opcion = menuModificaciones();
                switch(opcion)
                {
                case 1:
                    flagNombre = dam_getNombre(auxEmpleado.nombre,"Ingrese nuevo nombre: ","Error. ",20,10);
                    break;
                case 2:
                    flagEdad = dam_getNumero(&auxEmpleado.edad,"Ingrese neuva edad: ","Error. ",1,199,10);
                    break;
                case 3:
                    flagSexo = dam_getCaracter(&auxEmpleado.sexo,"Ingrese nuevo sexo: ","Error. ",'f','m',10);
                    break;
                case 4:
                    flagSueldo = dam_getNumeroFlotante(&auxEmpleado.sueldo,"Ingrese neuvo sueldo: ","Error. ",1.00,999999.0,10);
                    break;
                case 5:
                    if (!dam_getNumero(&auxEmpleado.fechaIngreso.dia,"Ingrese nuevo dia: ","Error. ",1,31,10) &&
                        !dam_getNumero(&auxEmpleado.fechaIngreso.mes,"Ingrese nuevo mes: ","Error. ",1,12,10) &&
                        !dam_getNumero(&auxEmpleado.fechaIngreso.anio,"Ingrese nuevo anio: ","Error. ",1950,2021,10))
                    {
                        flagFecha=0;
                    }
                    break;
                case 6:
                    mostrarSectores(arraySectores, tamSec);
                    if(!dam_getNumero(&auxIdSector,"Ingrese ID del nuevo sector: ","Error. ",500,503,10))
                    {
                        for(int i=0; i<tamSec; i++)
                        {
                            if(arraySectores[i].id==auxIdSector)
                            {
                                strcpy(auxEmpleado.sector,arraySectores[i].descripcion);
                                flagSector=0;
                            }
                        }
                    }
                    break;
                case 7:
                    if(!flagNombre)
                    {
                        strcpy(arrayEmpleados[indice].nombre,auxEmpleado.nombre);
                    }
                    if(!flagEdad)
                    {
                        arrayEmpleados[indice].edad=auxEmpleado.edad;
                    }
                    if(!flagSexo)
                    {
                        arrayEmpleados[indice].sexo=auxEmpleado.sexo;
                    }
                    if(!flagSueldo)
                    {
                        arrayEmpleados[indice].sueldo=auxEmpleado.sueldo;
                    }
                    if(!flagFecha)
                    {
                        arrayEmpleados[indice].fechaIngreso.dia=auxEmpleado.fechaIngreso.dia;
                        arrayEmpleados[indice].fechaIngreso.mes=auxEmpleado.fechaIngreso.mes;
                        arrayEmpleados[indice].fechaIngreso.anio=auxEmpleado.fechaIngreso.anio;
                    }
                    if(!flagSector)
                    {
                        strcpy(arrayEmpleados[indice].sector,auxEmpleado.sector);
                    }
                    printf("\nEmpleado modificado!\n");
                    mostrarUnEmpleado(arrayEmpleados[indice]);
                    printf("\nCambios guardados, volviendo al menu principal...\n\n");
                    retorno=0;
                    break;
                case 8:
                    printf("Cambios descartados, volviendo al menu principal...\n\n");
                    break;
                }
            }while(opcion!=7 && opcion!=8);
        }
    }
    return retorno;
}

int bajaEmpleado(eEmpleado arrayEmpleados[], int tam)
{
    int retorno=-1;
    char confirm='n';
    int indice;

    system("cls");
    printf("     Baja Empleado\n\n");
    if(arrayEmpleados!=NULL && tam>0)
    {
        indice=buscarEmpleado(arrayEmpleados, tam);
        if(indice==-1)
        {
            printf("No se encontro ningun empleado con ese legajo.\n");
        }
        else
        {
            printf("Empleado encontrado:\n");
            printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso        Sector\n");
            mostrarUnEmpleado(arrayEmpleados[indice]);
            if(!dam_getCaracter(&confirm,"Seguro desea dar de baja a este empleado? (s/n): ", "ERROR.\n",'s','n',10) && confirm=='s')
            {
                arrayEmpleados[indice].isEmpty=1;
                retorno = 0;
            }
        }
    }

    return retorno;
}
