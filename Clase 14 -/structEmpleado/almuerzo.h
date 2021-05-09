#include "fecha.h"
#include "empleado.h"
#include "sector.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id; //PK de almuerzo
    int legEmpleado; //FK de empleado
    int idComida; //FK de comida
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

/**
OPCIONES PARA GENERAR LA PRIMARY KEY DE ALMUERZO
OPCION 1: Combinar idComida + idEmpleado + Fecha (este ultimo
para desempatar, ya que los primeros dos pueden repetirse)
OPCION 2: Ponerle una idAlmuerzo
*/

#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo aAlmuerzos[], int tam);
int buscarLibreAlmuerzo(eAlmuerzo aAlmuerzos[], int tam);
int cargarUnAlmuerzo(eAlmuerzo* unAlmuerzo);
int altaAlmuerzo(eAlmuerzo aAlmuerzos[], int tamAlm,
                 eEmpleado aEmpleados[], int tamEmp,
                 eSector aSectores[], int tamSec,
                 eComida aComidas[], int tamCom,
                 int* pIdAlmuerzo);
int mostrarAlmuerzos(eAlmuerzo aAlmuerzos[], int tam, eComida aComidas[], int tamCom, eEmpleado aEmpleado[], int tamEmp);
void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, eComida aComidas[], int tamCom, eEmpleado aEmpleado[], int tamEmp);
