#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#define TAM 10
#define TAMSEC 4

int main()
{
    eSector sectores[TAMSEC]={
        {500,"Sistemas"},
        {501,"RRHH"},
        {502,"Cobranzas"},
        {503,"Legales"}
    };
    //HARDCODEAR VECTOR EMPLEADOS
    eEmpleado nomina[TAM] = {
        {20000,"Jose",24,'m',123000,{2,3,2001},"Sistemas",0},
        {20001,"Lucia",29,'f',120000,{21,5,2018},"Legales",0},
        {20002,"Alicia",21,'f',87000,{10,8,2004},"Cobranzas",0},
        {20003,"Donato",39,'m',123000,{12,8,2017},"Sistemas",0},
        {20004,"Chepi",30,'f',115000,{23,1,2015},"RRHH",0},
        {20005,"Alex",28,'m',118000,{13,10,2021},"Sistemas",0},
        {20006,"Rogelio",58,'m',95000,{6,7,2011},"Legales",0},
        {20007,"Maria",44,'f',133000,{16,12,2017},"Legales",0},
        {20008,"Valkirya",62,'f',185000,{8,4,2002},"Sistemas",0},
        {20009,"Bowie",19,'m',71000,{29,2,2020},"RRHH",0}
    };
    char exitConfirm='n';
    int nextId=20000;

    //inicializarEmpleados(nomina, TAM);
    nomina[0].isEmpty=0;
    nomina[1].isEmpty=0;
    nomina[2].isEmpty=0;
    nomina[3].isEmpty=0;
    nomina[4].isEmpty=0;
    //ordenarEmpleados(nomina, TAM, DOS_CRITERIOS);
    //mostrarEmpleados(nomina, TAM);
    /**
    TAREA ABM PARA 26-04
    1) Alta empleado
    2) Modificar empleado
    3) Baja empleado
    4) Listar empleados
    5) Salir
    **/
    //HACER FUNCION buscarLibre(arrayEmpleados, tam) PARA ENCONTRAR LUGAR y devuelve el indice
    //HACER FUNCION buscarEmpleado(legajo, arrayEmpleados, tam) PARA BUSCAR SI EXISTE UN LEGAJO y devuelve el indice
    do{
        switch(menuOpciones())
        {
        case 1:
            //ALTA DE EMPLEADO
            if(!altaEmpleado(nomina, TAM, &nextId, sectores, TAMSEC))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            system("pause");
            break;
        case 2:
            modificarEmpleado(nomina, TAM, sectores, TAMSEC);
            system("pause");
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
            break;
        case 4:
            //LISTAR EMPLEADOS
            mostrarEmpleados(nomina, TAM);
            break;
        case 5:
            //ORDENAR EMPLEADOS
            ordenarEmpleados(nomina,TAM);
            break;
        case 6:
            //MOSTRAR SECTORES
            mostrarSectores(sectores, TAMSEC);
            system("pause");
            break;
        case 7:
            //INFORMES
            break;
        case 12:
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}

