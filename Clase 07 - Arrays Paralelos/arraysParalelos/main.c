#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void mostrarVectorEnteros(int vec[], int tam);

void mostrarVectorFloat(float vec[], int tam);

void mostrarPromedios(int n1[], int n2[], float prom[], int legajo[], char sexo[], int tam);

void ordenarFlotantes(int n1[], int n2[], float prom[], int legajo[], char sexo[], int tam);

int main()
{
    char nombres[TAM][20];
    int legajos[TAM]={1234, 2211, 3322, 5761, 2132, 6544, 8756, 3415, 6681, 9322};
    char sexos[TAM]={'f','f','m','f','m','f','m','m','f','m'};
    int notas1[TAM]={2,8,7,10,4,1,7,7,8,10};
    int notas2[TAM]={7,4,9,2,6,10,4,1,7,7};
    float promedios[TAM];

    //pedir notas1, notas2 y calcular el promedio

    for(int i=0; i<TAM; i++)
    {
        /*printf("Ingrese nota del 1er parcial del alumno %d: ",i+1);
        scanf("%d",&notas1[i]);
        printf("Ingrese nota del 2do parcial del alumno %d: ",i+1);
        scanf("%d",&notas2[i]);
        printf("Ingrese el legajo del alumno %d: ",i+1);
        scanf("%d",&legajos[i]);
        printf("Ingrese el sexo del alumno %d: ",i+1);
        fflush(stdin);
        scanf("%c",&sexos[i]);*/
        promedios[i]=((float)notas1[i]+notas2[i])/2;
    }

    system("cls");
    /*printf(" *** LISTADO DE NOTAS Y PROMEDIOS ***");
    printf("\nNotas 1er parcial: ");
    mostrarVectorEnteros(notas1, TAM);
    printf("\nNotas 2do parcial: ");
    mostrarVectorEnteros(notas2, TAM);
    printf("\nPromedios finales: ");
    mostrarVectorFloat(promedios, TAM);
    printf("\n\n");*/
    mostrarPromedios(notas1, notas2, promedios, legajos, sexos, TAM);
    ordenarFlotantes(notas1, notas2, promedios, legajos, sexos, TAM);
    mostrarPromedios(notas1, notas2, promedios, legajos, sexos, TAM);

    return 0;
}

void mostrarVectorEnteros(int vec[], int tam)
{
    for(int i=0; i<TAM; i++)
    {
        printf(" %d ", vec[i]);
    }
    printf("\n\n");
}

void mostrarVectorFloat(float vec[], int tam)
{
    for(int i=0; i<TAM; i++)
    {
        printf(" %.2f ", vec[i]);
    }
    printf("\n\n");
}

void mostrarPromedios(int n1[], int n2[], float prom[], int legajo[], char sexo[], int tam)
{
    printf("     *** TABLA DE NOTAS Y PROMEDIOS ***\n");
    printf(" Nota 1parcial     Nota 2Parcial     Promedio           Legajo         Sexo\n");
    for(int i=0; i<tam; i++)
    {
        printf("     %2d                 %2d             %5.2f            %6d          %c\n", n1[i],n2[i],prom[i],legajo[i],sexo[i]);
    }
    printf("\n\n");
}

void ordenarFlotantes(int n1[], int n2[], float prom[], int legajo[], char sexo[], int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i=0; i<tam; i++)
    {
        for(int j = i+1; j<tam; j++)
        {
            if(prom[i]<prom[j])
            {
                //swap nota1
                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;
                //swap nota2
                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;
                //swap promedio
                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;
                //swap legajo
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;
                //swap sexo
                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;
            }
        }
    }
}
