#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado e);
void mostrarEmpleadoRef(eEmpleado* e);

int main()
{
    eEmpleado emp1;
    eEmpleado* pEmp2 = (eEmpleado*)malloc(sizeof(eEmpleado));
    ///falta validar el puntero != NULL

    emp1.legajo=1234;
    emp1.sexo='m';
    strcpy(emp1.nombre,"Jose");
    emp1.sueldo=30000;

    pEmp2->legajo=3333;
  //(*pEmp2).legajo=3333; ESTA ES OTRA FORMA
    strcpy(pEmp2->nombre,"Luisa");
    pEmp2->sexo='f';
    pEmp2->sueldo=31000;



    mostrarEmpleado(emp1);
    mostrarEmpleadoRef(pEmp2);

    return 0;
}

void mostrarEmpleado(eEmpleado e)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n", e.legajo,e.nombre,e.sexo,e.sueldo);
}

void mostrarEmpleadoRef(eEmpleado* e)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n", e->legajo,e->nombre,e->sexo,e->sueldo);
}
