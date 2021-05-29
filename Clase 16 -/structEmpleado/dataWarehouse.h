#include "fecha.h"
#include "empleado.h"
#include "almuerzo.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hardcodearEmpleados(eEmpleado arrayEmpleados[], int tam, int cant, int* pLegajo);
int hardcodearAlmuerzos(eAlmuerzo aAlmuerzos[], int tamAlm, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED
