#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
}eEmpleado;

///INICIALIZAR
int inicializarEmpleados(eEmpleado**, int sizeEmp);
///MOSTRAR
int mostrarEmpleado(eEmpleado* emp);
int mostrarEmpleados(eEmpleado** emp, int sizeEmp);
///BUSCAR LIBRE
int buscarLibreEmpleado(eEmpleado** emp, int sizeEmp, int* pIndice);
///REDIMENSIONAR
int agrandarArray(eEmpleado*** pEmp, int* pTam);
///ORDENAMIENTO
int ordenarEmpleadosPorLegajo(eEmpleado** emp, int sizeEmp);
int ordenarEmpleadosPorApellido(eEmpleado** emp, int sizeEmp);


///FUNCIONES CONSTRUCTORAS
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo);
///SETTERS para setear el valor
int empleadoSetLegajo(eEmpleado* emp, int legajo);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetApellido(eEmpleado* emp, char* apellido);
int empleadoSetSexo(eEmpleado* emp, char sexo);
int empleadoSetSueldo(eEmpleado* emp, int sueldo);
///GETTERS para leer el valor
int empleadoGetLegajo(eEmpleado* emp, int* pLegajo);
int empleadoGetNombre(eEmpleado* emp, char* pNombre);
int empleadoGetApellido(eEmpleado* emp, char* pApellido);
int empleadoGetSexo(eEmpleado* emp, char* pSexo);
int empleadoGetSueldo(eEmpleado* emp, float* pSueldo);
int empleadoGetNombreCompleto(eEmpleado* emp, char* pNombreCompleto);
///DESTRUCTOR
int destroyEmpleado(eEmpleado* emp);

#endif // EMPLEADO_H_INCLUDED
