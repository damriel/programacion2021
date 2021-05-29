#include "fecha.h"
#include "sector.h"
#include "almuerzo.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

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

int inicializarEmpleados(eEmpleado aEmpleados[], int tam);
int cargarUnEmpleado(eEmpleado* unEmpleado, eSector arraySectores[], int tamSec);
void cargarEmpleados(eEmpleado arrayEmpleados[], int tam);
void mostrarUnEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamsec);
int mostrarEmpleados(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void ordenarEmpleados(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
int menuOpciones();
int altaEmpleado(eEmpleado arrayEmpleados[], int tam, int* pId, eSector arraySectores[], int tamSec);
int modificarEmpleado(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
int buscarEmpleadoXLeg(eEmpleado arrayEmpleados[], int tam, int legajoBuscado);
int cargarNombreEmpleado(int legajo, eEmpleado aEmpleados[], int tam, char nombre[]);
int cargarSectorPorLegajo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, int legajo, char descripcion[]);
int buscarEmpleado(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
int menuOrdenamiento();
int subMenuOrdenamiento();
int buscarLibre(eEmpleado arrayEmpleados[], int tam);
int menuModificaciones();

#endif // EMPLEADO_H_INCLUDED

