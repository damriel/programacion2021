#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "empleado.h"
#define TAM 5
#define POR_EDAD 1
#define POR_NOMBRE 2
#define DOS_CRITERIOS 3

int main()
{
    //HARDCODEAR VECTOR EMPLEADOS
    eEmpleado nomina[TAM] = {
        {20000,"Jose",24,'m',123000,{2,3,2001}},
        {20001,"Lucia",29,'f',120000,{21,5,2018}},
        {20002,"Alicia",21,'f',87000,{10,8,2004}},
        {20003,"Donato",39,'m',123000,{12,8,2017}},
        {20004,"Chepi",30,'f',115000,{23,1,2015}}
    };
    char exitConfirm='n';
    int nextId=20000;

    inicializarEmpleados(nomina, TAM);
    nomina[0].isEmpty=0;
    nomina[1].isEmpty=0;
    nomina[2].isEmpty=0;
    nomina[3].isEmpty=0;
    nomina[4].isEmpty=0;
    ordenarEmpleados(nomina, TAM, DOS_CRITERIOS);
    mostrarEmpleados(nomina, TAM);

    do{
        switch(menuOpciones())
        {
        case 1:
            //ALTA DE EMPLEADO
            if(!altaEmpleado(nomina, TAM, &nextId))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            modificarEmpleado(nomina, TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            //BAJA DE EMPLEADO
            if(!bajaEmpleado(nomina, TAM))
            {
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Hubo un problema. Baja cancelada.\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            //LISTAR EMPLEADOS
            mostrarEmpleados(nomina, TAM);
            system("pause");
            system("cls");
            break;
        case 5:
            //ORDENAR EMPLEADOS
            ordenarEmpleados(nomina,TAM,POR_EDAD);
            system("pause");
            system("cls");
            break;
        case 6:
            //INFORMES
            break;
        case 7:
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            system("cls");
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}
