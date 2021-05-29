#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#include "empleado.h"
#define DESCENDENTE 0
#define ASCENDENTE 1

int inicializarEmpleados(eEmpleado aEmpleados[], int tam)
{
    int retorno=-1;
    if(aEmpleados!=NULL && tam>0)
    {
        retorno=0;
        for(int i=0; i<tam; i++)
        {
            aEmpleados[i].isEmpty=1;
        }
    }
    return retorno;
}

int cargarUnEmpleado(eEmpleado* unEmpleado, eSector aSectores[], int tamSec)
{
    int retorno=-1;
    if(!dam_getNombre((*unEmpleado).nombre,"Ingrese nombre: ","Error.\n",20,10)&&
       !dam_getNumero(&(*unEmpleado).edad,"Ingrese edad: ","Error.\n",1,199,10)&&
       !dam_getCaracter(&(*unEmpleado).sexo,"Ingrese sexo: ","Error.\n",'f','m',10)&&
       !dam_getNumeroFlotante(&(*unEmpleado).sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10)&&
       !dam_getNumero(&(*unEmpleado).fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10)&&
       !mostrarSectores(aSectores, tamSec)&&
       !dam_getNumero(&(*unEmpleado).idSector,"Ingrese el ID del sector: ","Error. ",500,503,10))
    {
        retorno=0;
    }
    return retorno;
}

void cargarEmpleados(eEmpleado aEmpleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        dam_getNumero(&aEmpleados[i].legajo,"Ingrese legajo: ","Error.\n",1,999999,10);
        dam_getNombre(aEmpleados[i].nombre,"Ingrese nombre: ","Error.\n",20,10);
        dam_getNumero(&aEmpleados[i].edad,"Ingrese edad: ","Error.\n",1,199,10);
        dam_getCaracter(&aEmpleados[i].sexo,"Ingrese sexo: ","Error.\n",'f','m',10);
        dam_getNumeroFlotante(&aEmpleados[i].sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10);
        dam_getNumero(&aEmpleados[i].fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10);
        dam_getNumero(&aEmpleados[i].fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10);
        dam_getNumero(&aEmpleados[i].fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10);

    }
}

void mostrarUnEmpleado(eEmpleado unEmpleado, eSector aSectores[], int tamSec)
{
    char descripcion[20];
    cargarDescripcionSector(unEmpleado.idSector, aSectores, tamSec, descripcion);
    printf("%6d %10s    %2d    %c    %9.2f      %02d/%02d/%d        %10s\n",unEmpleado.legajo,
                                                                            unEmpleado.nombre,
                                                                            unEmpleado.edad,
                                                                            unEmpleado.sexo,
                                                                            unEmpleado.sueldo,
                                                                            unEmpleado.fechaIngreso.dia,
                                                                            unEmpleado.fechaIngreso.mes,
                                                                            unEmpleado.fechaIngreso.anio,
                                                                            descripcion);
}

int mostrarEmpleados(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    int retorno=-1;
    int flagEmpleados=0;
    if(aEmpleados!=NULL && tam>0)
    {
        retorno=0;
        for(int i=0; i<tam; i++)
        {
            if(aEmpleados[i].isEmpty==0)
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
        for(int i=0; i<tam; i++)
        {
            if(!aEmpleados[i].isEmpty)
            {
                mostrarUnEmpleado(aEmpleados[i], aSectores, tamSec);
            }
        }
    }
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

void ordenarEmpleados(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    int criterio;
    int orden;
    eEmpleado auxEmpleado;
    if(aEmpleados!=NULL && tam>0)
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
        for(int i=0; i<tam-1 && !aEmpleados[i].isEmpty; i++)
        {
            for(int j=i+1; j<tam && !aEmpleados[j].isEmpty; j++)
            {
                switch(criterio)
                {
                case 1:
                    if(aEmpleados[i].legajo>aEmpleados[j].legajo && orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    else if(aEmpleados[i].legajo<aEmpleados[j].legajo && !orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 2:
                    if(strcmp(aEmpleados[i].nombre,aEmpleados[j].nombre)>0 && orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    if(strcmp(aEmpleados[i].nombre,aEmpleados[j].nombre)<0 && !orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 3:
                    if(aEmpleados[i].edad>aEmpleados[j].edad && orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    else if(aEmpleados[i].edad<aEmpleados[j].edad && !orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 4:
                    if(aEmpleados[i].sexo>aEmpleados[j].sexo && orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    else if(aEmpleados[i].sexo<aEmpleados[j].sexo && !orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 5:
                    if(aEmpleados[i].sueldo>aEmpleados[j].sueldo && orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    else if(aEmpleados[i].sueldo<aEmpleados[j].sueldo && !orden)
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 6:
                    for(int index1=0; index1>tamSec; index1++)
                    {
                        for(int index2=0; index2>tamSec; index2++)
                        {
                            if(aEmpleados[i].idSector==aSectores[index1].id && aEmpleados[j].idSector==aSectores[index2].id && orden && strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)>0)
                            {
                                auxEmpleado = aEmpleados[i];
                                aEmpleados[i] = aEmpleados[j];
                                aEmpleados[j] = auxEmpleado;
                            }
                            else if(aEmpleados[i].idSector==aSectores[index1].id && aEmpleados[j].idSector==aSectores[index2].id && !orden && strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)<0)
                            {
                                auxEmpleado = aEmpleados[i];
                                aEmpleados[i] = aEmpleados[j];
                                aEmpleados[j] = auxEmpleado;
                            }
                        }
                    }
                    break;
                case 7:
                    if(aEmpleados[i].sexo>aEmpleados[j].sexo ||
                      (aEmpleados[i].sexo==aEmpleados[j].sexo&&
                       aEmpleados[i].legajo>aEmpleados[j].legajo))
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 8:
                    if(aEmpleados[i].sexo<aEmpleados[j].sexo ||
                      (aEmpleados[i].sexo==aEmpleados[j].sexo&&
                       aEmpleados[i].sueldo>aEmpleados[j].sueldo))
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 9:
                    if(aEmpleados[i].sexo<aEmpleados[j].sexo ||
                      (aEmpleados[i].sexo==aEmpleados[j].sexo&&
                       strcmp(aEmpleados[i].nombre,aEmpleados[j].nombre)>0))
                    {
                        auxEmpleado = aEmpleados[i];
                        aEmpleados[i] = aEmpleados[j];
                        aEmpleados[j] = auxEmpleado;
                    }
                    break;
                case 10:
                    for(int index1=0; index1>tamSec; index1++)
                    {
                        for(int index2=0; index2>tamSec; index2++)
                        {
                            if((aEmpleados[i].idSector==aSectores[index1].id &&
                                aEmpleados[j].idSector==aSectores[index2].id &&
                                strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)>0) ||
                                (aEmpleados[i].idSector==aSectores[index1].id &&
                                aEmpleados[j].idSector==aSectores[index2].id &&
                                strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)==0 &&
                                aEmpleados[i].sueldo>aEmpleados[j].sueldo))
                            {
                                auxEmpleado = aEmpleados[i];
                                aEmpleados[i] = aEmpleados[j];
                                aEmpleados[j] = auxEmpleado;
                            }
                        }
                    }
                    break;
                case 11:
                    for(int index1=0; index1>tamSec; index1++)
                    {
                        for(int index2=0; index2>tamSec; index2++)
                        {
                            if((aEmpleados[i].idSector==aSectores[index1].id &&
                                aEmpleados[j].idSector==aSectores[index2].id &&
                                strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)>0) ||
                                (aEmpleados[i].idSector==aSectores[index1].id &&
                                aEmpleados[j].idSector==aSectores[index2].id &&
                                strcmp(aSectores[index1].descripcion, aSectores[index2].descripcion)==0 &&
                                strcmp(aEmpleados[i].nombre, aEmpleados[j].nombre)>0))
                            {
                                auxEmpleado = aEmpleados[i];
                                aEmpleados[i] = aEmpleados[j];
                                aEmpleados[j] = auxEmpleado;
                            }
                        }
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
    printf("8) Actualizar Sueldo por Sector.\n");
    printf("9) Totales Sueldos.\n");
    printf("10) Mostrar Comidas.\n");
    printf("11) Alta Almuerzo.\n");
    printf("12) Mostrar Almuerzo.\n");
    printf("13) Sectores que mas cobran.\n");
    printf("14) Almuerzos Empleado.\n");
    printf("15) Total Gasto Almuerzo.\n");
    printf("16) Sumatoria gastos de un sector.\n");
    printf("17) Comida favorita de un sector.\n");
    printf("18) Sector amantes milanesas.\n");
    printf("19) Descontar almuerzo al empleado.\n");
    printf("20) Salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.",1,20,10)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int buscarLibre(eEmpleado aEmpleados[], int tam)
{
    int indice=-1;
    if(aEmpleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(aEmpleados[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaEmpleado(eEmpleado aEmpleados[], int tam, int* pId, eSector aSectores[], int tamSec)
{
    int retorno=-1;
    int indice;
    eEmpleado nuevoEmpleado;

    if(aEmpleados!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("      Alta Empleado\n\n");
        indice = buscarLibre(aEmpleados,tam);
        if(indice!=-1)
        {
            printf("Legajo: %d\n",*pId);
            if(!dam_getNombre(nuevoEmpleado.nombre,"Ingrese nombre: ","Error.\n",20,10)&&
               !dam_getNumero(&nuevoEmpleado.edad,"Ingrese edad: ","Error.\n",1,199,10)&&
               !dam_getCaracter(&nuevoEmpleado.sexo,"Ingrese sexo: ","Error.\n",'f','m',10)&&
               !dam_getNumeroFlotante(&nuevoEmpleado.sueldo,"Ingrese sueldo: ","Error.\n",1.00,999999.0,10)&&
               !dam_getNumero(&nuevoEmpleado.fechaIngreso.dia,"Ingrese dia: ","Error.\n",1,31,10)&&
               !dam_getNumero(&nuevoEmpleado.fechaIngreso.mes,"Ingrese mes: ","Error.\n",1,12,10)&&
               !dam_getNumero(&nuevoEmpleado.fechaIngreso.anio,"Ingrese anio: ","Error.\n",1950,2021,10)&&
               !mostrarSectores(aSectores, tamSec)&&
               !dam_getNumero(&nuevoEmpleado.idSector,"Ingrese el ID del sector: ","Error. ",500,503,10))
            {
                aEmpleados[indice]=nuevoEmpleado;
                aEmpleados[indice].isEmpty=0;
                aEmpleados[indice].legajo = *pId;
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
            printf("No hay lugar para cargar mas empleados.\n");
        }
    }
    return retorno;
}

int buscarEmpleado(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    int indice=-1;
    int legajoBuscado;
    if(aEmpleados!=NULL && tam>0 &&
       !mostrarEmpleados(aEmpleados,tam, aSectores, tamSec) &&
       !dam_getNumero(&legajoBuscado,"\n\nIngrese el legajo del empleado: ","ERROR. Legajo no valido.\n",1,999999,10))
    {
        for(int i=0; i<tam; i++)
        {
            if(legajoBuscado==aEmpleados[i].legajo && !aEmpleados[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarEmpleadoXLeg(eEmpleado aEmpleados[], int tam, int legajoBuscado)
{
    int indice=-1;
    if(aEmpleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(legajoBuscado==aEmpleados[i].legajo && !aEmpleados[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int menuModificaciones()
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

int modificarEmpleado(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    int retorno=-1;
    int indice;
    int opcion;
    eEmpleado auxEmpleado;
    int flagNombre=1;
    int flagSexo=1;
    int flagEdad=1;
    int flagSueldo=1;
    int flagFecha=1;
    int flagSector=1;


    if(aEmpleados!=NULL && tam>0)
    {
        indice = buscarEmpleado(aEmpleados,tam,aSectores,tamSec);
        if(indice==-1)
        {
            printf("No se encontro ningun empleado con ese legajo.\n");
        }
        else
        {
            printf("Empleado encontrado:\n");
            printf("Legajo     Nombre   Edad Sexo    Sueldo     Fecha de Ingreso        Sector\n");
            mostrarUnEmpleado(aEmpleados[indice], aSectores, tamSec);

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
                    mostrarSectores(aSectores, tamSec);
                    if(!dam_getNumero(&auxEmpleado.idSector,"Ingrese ID del nuevo sector: ","Error. ",500,503,10))
                    {
                        flagSector=0;
                    }
                    break;
                case 7:
                    if(!flagNombre)
                    {
                        strcpy(aEmpleados[indice].nombre,auxEmpleado.nombre);
                    }
                    if(!flagEdad)
                    {
                        aEmpleados[indice].edad=auxEmpleado.edad;
                    }
                    if(!flagSexo)
                    {
                        aEmpleados[indice].sexo=auxEmpleado.sexo;
                    }
                    if(!flagSueldo)
                    {
                        aEmpleados[indice].sueldo=auxEmpleado.sueldo;
                    }
                    if(!flagFecha)
                    {
                        aEmpleados[indice].fechaIngreso.dia=auxEmpleado.fechaIngreso.dia;
                        aEmpleados[indice].fechaIngreso.mes=auxEmpleado.fechaIngreso.mes;
                        aEmpleados[indice].fechaIngreso.anio=auxEmpleado.fechaIngreso.anio;
                    }
                    if(!flagSector)
                    {
                        aEmpleados[indice].idSector=auxEmpleado.idSector;
                    }
                    printf("\nEmpleado modificado!\n");
                    mostrarUnEmpleado(aEmpleados[indice], aSectores, tamSec);
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


int cargarNombreEmpleado(int legajo, eEmpleado aEmpleados[], int tam, char nombre[])
{
    int retorno=0;
    if(legajo>=20000 && legajo<=29000 && aEmpleados!=NULL && tam>0 && nombre!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(aEmpleados[i].legajo==legajo && !aEmpleados[i].isEmpty)
            {
                strcpy(nombre, aEmpleados[i].nombre);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int cargarSectorPorLegajo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, int legajo, char descripcion[])
{
    int retorno=0;
    int indice;
    if(aEmpleados!=NULL && aSectores!=NULL && descripcion!=NULL && tamEmp>0 && tamSec>0)
    {
        indice=buscarEmpleadoXLeg(aEmpleados,tamEmp,legajo);
        if(indice!=-1)
        {
            if(cargarDescripcionSector(aEmpleados[indice].idSector,aSectores,tamSec,descripcion))
            {
                retorno=1;
            }
        }
    }
    return retorno;
}
