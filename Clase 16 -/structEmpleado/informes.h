#include "empleado.h"
#include "almuerzo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void empleadosSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void actualizarSueldosXSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void aPonerla(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec);
void sectorQueMasCobra(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec);
void mostrarAlmuerzosEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void totalGastoAlmuerzo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);

//Versiones Baus
void totalesComidasXSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void comidaPreferidaSectorBaus(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void sectorAmanteMilanesa(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eAlmuerzo aAlmuerzos[], int tamAlm);
void descontarAlmuerzosDeEmpleadoBaus(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);

//Versiones no Baus
void sumatoriaAlmuerzosSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void comidaPreferidaSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void sectorQueMasComioUnaComida(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void descontarAlmuerzosDeEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm);
void sectorQueMasComioUnaComidaBaus(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eAlmuerzo aAlmuerzos[], int tamAlm);


#endif // INFORMES_H_INCLUDED
