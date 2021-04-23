#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define POR_NOMBRE 1
#define POR_LEGAJO 2
#define POR_PROMEDIO 3
#define POR_SEXO 4
#define POR_NOMBRE_DES 5
#define POR_LEGAJO_DES 6
#define POR_PROMEDIO_DES 7
#define POR_SEXO_DES 8


void cargaSecuencialAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20],int tam)
{
    char auxCad[20];

    for(int i=0; i<tam; i++)
    {
        printf("Ingrese el nombre del alumno %d: ",i+1);
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad)>20)
        {
            printf("Error, nombre demasiado largo. Ingrese el nombre del alumno %d: ",i+1);
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(names[i],auxCad);

        printf("Ingrese el legajo del alumno %d: ",i+1);
        scanf("%d",&legajo[i]);

        printf("Ingrese el sexo del alumno %d: ",i+1);
        fflush(stdin);
        scanf("%c",&sexo[i]);

        printf("Ingrese nota del 1er parcial del alumno %d: ",i+1);
        scanf("%d",&n1[i]);

        printf("Ingrese nota del 2do parcial del alumno %d: ",i+1);
        scanf("%d",&n2[i]);
    }
}

void mostrarAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20],int tam)
{
    printf("     *** TABLA DE NOTAS Y PROMEDIOS ***\n");
    printf("   Nombre      Legajo     Sexo      Nota 1er parcial     Nota 2do Parcial     Promedio\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnAlumno(n1[i], n2[i], prom[i], legajo[i], sexo[i], names[i]);
    }
    printf("\n\n");
}

void mostrarUnAlumno(int n1, int n2, float prom, int legajo, char sexo, char names[])
{
    printf("  %10s        %6d       %c              %2d                   %2d              %5.2f\n", names,legajo,sexo,n1,n2,prom);
}

void ordenarDosCriterios(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam)
{
    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(sexo[i]<sexo[j] || (sexo[i]==sexo[j]&&strcmp(names[i],names[j])>0))
            {
                swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
            }
        }
    }
}

void ordenarAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam, int criterio, int orden)
{
    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            switch(criterio)
            {
            case POR_NOMBRE:
                if(strcmp(names[i],names[j])>0 && orden==1)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                else if(strcmp(names[i],names[j])<0 && orden==2)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                break;
            case POR_LEGAJO:
                if(legajo[i]>legajo[j] && orden==1)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                else if(legajo[i]<legajo[j] && orden==2)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                break;
            case POR_PROMEDIO:
                if(prom[i]>prom[j] && orden==1)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                else if(prom[i]<prom[j] && orden==2)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                break;
            case POR_SEXO:
                if(sexo[i]>sexo[j] && orden==1)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }
                else if(sexo[i]<sexo[j] && orden==2)
                {
                    swapDatos(n1,n2,prom,legajo,sexo,names,tam,i,j);
                }

                break;
            }
        }
    }
}

void swapDatos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam, int indexI, int indexJ)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[20];

    //swap nota1
    auxInt = n1[indexI];
    n1[indexI] = n1[indexJ];
    n1[indexJ] = auxInt;
    //swap nota2
    auxInt = n2[indexI];
    n2[indexI] = n2[indexJ];
    n2[indexJ] = auxInt;
    //swap promedio
    auxFloat = prom[indexI];
    prom[indexI] = prom[indexJ];
    prom[indexJ] = auxFloat;
    //swap legajo
    auxInt = legajo[indexI];
    legajo[indexI] = legajo[indexJ];
    legajo[indexJ] = auxInt;
    //swap sexo
    auxChar = sexo[indexI];
    sexo[indexI] = sexo[indexJ];
    sexo[indexJ] = auxChar;
    //swap nombre
    strcpy(auxCad,names[indexI]);
    strcpy(names[indexI],names[indexJ]);
    strcpy(names[indexJ],auxCad);
}
