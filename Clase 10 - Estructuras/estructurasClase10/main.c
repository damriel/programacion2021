#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "alumno.h"
#define TAM 10

int inicializarAlumnos(eAlumno arrayAlumnos[], int tam);
int cargarAlumnos(eAlumno arrayAlumnos[], int tam);
void mostrarAlumnos(eAlumno arrayAlumnos[], int tam);
void harcodearAlumnos(eAlumno arrayAlumnos[], int tam);

int main()
{
    eAlumno alumnos[TAM];
    inicializarAlumnos(alumnos, TAM);
    cargarAlumnos(alumnos, TAM);
    mostrarAlumnos(alumnos, TAM);


    return 0;
}

int inicializarAlumnos(eAlumno arrayAlumnos[], int tam)
{
    int retorno=-1;
    if(arrayAlumnos!=NULL && tam>0)
    {
        retorno=0;
        for(int i=0; i<tam; i++)
        {
            arrayAlumnos[i].legajo=-1;
        }
    }
    return retorno;
}

int cargarAlumnos(eAlumno arrayAlumnos[], int tam)
{
    int retorno=-1;
    int counter=0;
    char confirm='s';
    if(arrayAlumnos!=NULL && tam>0)
    {
        retorno=0;
        do
        {
            if(arrayAlumnos[counter].legajo==-1 &&
               (dam_getNumero(&arrayAlumnos[counter].legajo,"Ingrese legajo del alumno: ", "Error. El legajo solo puede contener numeros entre 110000 y 990000.\n", 110000, 990000, 50)==-1 ||
                dam_getNombre(arrayAlumnos[counter].nombre,"Ingrese el nombre: ", "Error, el nombre no es valido.\n", 20, 50)==-1 ||
                dam_getCaracter(&arrayAlumnos[counter].sexo,"Ingrese el sexo: (m/f): ", "Error, el caracter no es valido.\n (s/n): ", 'f', 'm',50)==-1 ||
                dam_getNumero(&arrayAlumnos[counter].nota1,"Ingrese nota 1 del alumno: ", "Error. La nota puede ser entre 1 y 10.\n", 1, 10, 50)==-1 ||
                dam_getNumero(&arrayAlumnos[counter].nota2,"Ingrese nota 2 del alumno: ", "Error. La nota puede ser entre 1 y 10.\n", 1, 10, 50)==-1 ||
                dam_getCaracter(&confirm,"Desea cargar otro alumno? (s/n): ", "Error, el caracter no es valido.\n? (s/n): ", 's', 'n',50)==-1))
            {
                retorno=-2;
                break;
            }
            arrayAlumnos[counter].promedio = ((float)arrayAlumnos[counter].nota1+arrayAlumnos[counter].nota2)/2;
            counter++;
        }while(counter<tam && confirm=='s');
    }
    return retorno;
}

void mostrarAlumnos(eAlumno arrayAlumnos[], int tam)
{
    int flagCarga=0;
    if(arrayAlumnos!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayAlumnos[i].legajo!=-1)
            {
                flagCarga=1;
                break;
            }
        }
        if(flagCarga==0)
        {
            printf("AUN NO SE CARGO NINGUN ALUMNO AL SISTEMA.");
        }
        else
        {
            printf("     *** ALUMNOS INGRESADOS ***\n");
            printf("   Legajo    Nombre     Sexo      Nota 1er parcial     Nota 2do Parcial     Promedio\n");
            for(int i=0; i<tam && arrayAlumnos[i].legajo!=-1; i++)
            {
                printf("  %6d %10s       %c              %2d                   %2d              %5.2f\n", arrayAlumnos[i].legajo,
                                                                                                           arrayAlumnos[i].nombre,
                                                                                                           arrayAlumnos[i].sexo,
                                                                                                           arrayAlumnos[i].nota1,
                                                                                                           arrayAlumnos[i].nota2,
                                                                                                           arrayAlumnos[i].promedio);
            }
        }
    }
}

void harcodearAlumnos(eAlumno arrayAlumnos[], int tam)
{
    if(arrayAlumnos!=NULL)
    {
        arrayAlumnos={110055,"Damian",'m',9,8}{110066,"Christian",'m',5,2}{110077,"German",'m',10,9}{110088,"Maria",'f',8,10}{110099,"Chepi",'f',2,6};

        for(int i=0; i<tam; i++)
        {
            arrayAlumnos[i].promedio = ((float)arrayAlumnos[i].nota1+arrayAlumnos[i].nota2)/2;
        }
    }
}

/*typedef struct{
int legajo;
char nombre[20];
int edad;
char sexo;
float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado unEmpleado);

int main()
{
    eEmpleado emp1 = {110055, "Lucia", 24, 'f', 67500}; // HARDCODEO

    mostrarEmpleado(emp1);

    return 0;
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d %s %d %c %.2f\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo);
}*/
