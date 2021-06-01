#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
}eEmpleado;

int mostrarEmpleado(eEmpleado* emp);
///FUNCIONES CONSTRUCTORAS
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo);
///SETTERS para setear el valor
int empleadoSetLegajo(eEmpleado* emp, int legajo);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetApellido(eEmpleado* emp, char* apellido);
int empleadoSetSueldo(eEmpleado* emp, int sueldo);
int empleadoSetSexo(eEmpleado* emp, char sexo);
///GETTERS para leer el valor
int empleadoGetLegajo(eEmpleado* emp, int* pLegajo);
int empleadoGetNombre(eEmpleado* emp, char* pNombre);
int empleadoGetApellido(eEmpleado* emp, char* pApellido);
int empleadoGetSexo(eEmpleado* emp, char* pSexo);
int empleadoGetSueldo(eEmpleado* emp, float* pSueldo);
int empleadoGetNombreCompleto(eEmpleado* emp, char* pNombreCompleto);
///DESTRUCTOR
int destroyEmpleado(eEmpleado* emp);

int main()
{
    int tam = 5;
    eEmpleado* nomina = (eEmpleado*)malloc(sizeof(eEmpleado)*tam); ///ARRAY DE EMPLEADOS

    eEmpleado** lista = (eEmpleado**)malloc(sizeof(eEmpleado*)*tam); ///ARRAY DE PUNTEROS A EMPLEADOS

    eEmpleado* emp1 = newEmpleadoParam(2233, "Analia","Perez", 'f', 45670);

    mostrarEmpleado(emp1);

    destroyEmpleado(emp1);
    return 0;
}

/*****************************************************************************/

int mostrarEmpleado(eEmpleado* emp)
{
    int todoOk = 0;
    if(emp!=NULL)
    {
        printf("Legajo: %d Nombre: %s Apellido: %s Sexo: %c Sueldo: %.2f\n", emp->legajo,emp->nombre,emp->apellido,emp->sexo,emp->sueldo);
        todoOk=1;
    }
    return todoOk;
}

/*****************************************************************************/
/********                 FUNCIONES CONSTRUCTORAS               **************/
/*****************************************************************************/

eEmpleado* newEmpleado()
{
    eEmpleado* nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->legajo=0;
        strcpy(nuevoEmpleado->nombre,"");
        strcpy(nuevoEmpleado->apellido,"");
        nuevoEmpleado->sexo=' ';
        nuevoEmpleado->sueldo=0;
    }
    return nuevoEmpleado;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado = newEmpleado();
    if(nuevoEmpleado!=NULL)
    {
        if(!(empleadoSetLegajo(nuevoEmpleado,legajo) &&
           empleadoSetNombre(nuevoEmpleado,nombre) &&
           empleadoSetApellido(nuevoEmpleado,apellido) &&
           empleadoSetSexo(nuevoEmpleado,sexo) &&
           empleadoSetSueldo(nuevoEmpleado,sueldo)))
        {
            free(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }
    }
    return nuevoEmpleado;
}

/******************************************************************************
******************                 SETTERS                    *****************
******************************************************************************/

int empleadoSetLegajo(eEmpleado* emp, int legajo)
{
    int retorno=0;
    if(emp!=NULL && legajo>0)
    {
        emp->legajo=legajo;
        retorno=1;
    }
    return retorno;
}

int empleadoSetNombre(eEmpleado* emp, char* nombre)
{
    int retorno=0;
    if(emp!=NULL && nombre!=NULL && strlen(nombre)>3 && strlen(nombre)<20)
    {
        strcpy(emp->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int empleadoSetApellido(eEmpleado* emp, char* apellido)
{
    int retorno=0;
    if(emp!=NULL && apellido!=NULL && strlen(apellido)>3 && strlen(apellido)<20)
    {
        strcpy(emp->apellido,apellido);
        retorno=1;
    }
    return retorno;
}

int empleadoSetSueldo(eEmpleado* emp, int sueldo)
{
    int retorno=0;
    if(emp!=NULL && sueldo>=0)
    {
        emp->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

int empleadoSetSexo(eEmpleado* emp, char sexo)
{
    int retorno=0;
    if(emp!=NULL && (sexo=='m'||sexo=='f'))
    {
        emp->sexo=sexo;
        retorno=1;
    }
    return retorno;
}

/******************************************************************************
******************                 GETTERS                    *****************
******************************************************************************/

int empleadoGetLegajo(eEmpleado* emp, int* pLegajo)
{
    int retorno=0;
    if(emp!=NULL && pLegajo!=NULL)
    {
        *pLegajo=emp->legajo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetNombre(eEmpleado* emp, char* pNombre)
{
    int retorno=0;
    if(emp!=NULL && pNombre!=NULL)
    {
        strcpy(pNombre,emp->nombre);
        retorno=1;
    }
    return retorno;
}

int empleadoGetApellido(eEmpleado* emp, char* pApellido)
{
    int retorno=0;
    if(emp!=NULL && pApellido!=NULL)
    {
        strcpy(pApellido,emp->apellido);
        retorno=1;
    }
    return retorno;
}

int empleadoGetSexo(eEmpleado* emp, char* pSexo)
{
    int retorno=0;
    if(emp!=NULL && pSexo!=NULL)
    {
        *pSexo=emp->sexo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetSueldo(eEmpleado* emp, float* pSueldo)
{
    int retorno=0;
    if(emp!=NULL && pSueldo!=NULL)
    {
        *pSueldo=emp->sueldo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetNombreCompleto(eEmpleado* emp, char* pNombreCompleto)
{
    int retorno=0;
    if(emp!=NULL && pNombreCompleto!=NULL)
    {
        strcpy(pNombreCompleto,emp->nombre);
        strcat(pNombreCompleto," ");
        strcat(pNombreCompleto,emp->apellido);
        retorno=1;
    }
    return retorno;
}

/******************************************************************************
******************                 DESTROYER                  *****************
******************************************************************************/

int destroyEmpleado(eEmpleado* emp)
{
    int retorno=0;
    if(emp!=NULL)
    {
        free(emp);
        retorno=1;
    }
    return retorno;
}

    /* CARGA DE DATOS
    printf("Ingrese legajo: ");
    scanf("%d",&pEmp->legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pEmp->nombre);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&pEmp->sexo);

    printf("Ingrese sueldo: ");
    scanf("%f",&pEmp->sueldo);
    */


    //mostrarEmpleadoRef(pEmp);
