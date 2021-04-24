#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    //cargarEmpleados(nomina, TAM);

    inicializarEmpleados(nomina, TAM);
    mostrarEmpleados(nomina, TAM);
    nomina[0].isEmpty=0;
    nomina[2].isEmpty=0;
    ordenarEmpleados(nomina, TAM, DOS_CRITERIOS);
    mostrarEmpleados(nomina, TAM);
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

    return 0;
}


