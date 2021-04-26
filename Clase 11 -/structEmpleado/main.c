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
        {1234,"Jose",24,'m',123000,{2,3,2001}},
        {2211,"Lucia",29,'f',120000,{21,5,2018}},
        {4434,"Alicia",21,'f',87000,{10,8,2004}},
        {2145,"Donato",39,'m',123000,{12,8,2017}},
        {6655,"Chepi",30,'f',115000,{23,1,2015}}
    };
    char exitConfirm='n';

    inicializarEmpleados(nomina, TAM);
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
            altaEmpleado(nomina, TAM);
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
            bajaEmpleado(nomina, TAM);
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
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            system("cls");
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}
