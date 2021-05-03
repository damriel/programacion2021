#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo; //aca el SO fracciona la memoria y le asigna 4 bytes, no asigna menos
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;
}eEmpleado;

#endif // EMPLEADO_H_INCLUDED

int hardcodearEmpleados(eEmpleado arrayEmpleados[], int tam, int cant, int* pLegajo);
void empleadosSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);

void inicializarEmpleados(eEmpleado arrayEmpleados[], int tam);
int cargarUnEmpleado(eEmpleado* unEmpleado, eSector arraySectores[], int tamSec);
void cargarEmpleados(eEmpleado arrayEmpleados[], int tam);
void mostrarUnEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamsec);
int mostrarEmpleados(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void ordenarEmpleados(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
int menuOpciones();
int altaEmpleado(eEmpleado arrayEmpleados[], int tam, int* pId, eSector arraySectores[], int tamSec);
int modificarEmpleado(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
int bajaEmpleado(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
