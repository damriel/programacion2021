#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "dam.h"
#define TAM 10
#define POR_NOMBRE 1
#define POR_LEGAJO 2
#define POR_PROMEDIO 3
#define POR_SEXO 4
#define ASCEN 1
#define DESCEN 2

int main()
{
    char nombres[TAM][20]= {{"Dami"},{"Maru"},{"Christian"},{"Mabel"},{"Patricia"},{"Moncho"},{"Sandra"},{"Merlin"},{"Hector"},{"Carolina"}};
    int legajos[TAM]={1234, 2211, 3322, 5761, 2132, 6544, 8756, 3415, 6681, 9322};
    char sexos[TAM]={'m','f','m','f','f','m','f','m','m','f'};
    int notas1[TAM]={2,8,7,10,4,1,7,7,8,10};
    int notas2[TAM]={7,4,9,2,6,10,4,1,7,7};
    float promedios[TAM];

    //cargaSecuencialAlumnos(notas1,notas2,promedios,legajos,sexos,nombres,TAM);

    //CALCULO DE PROMEDIOS*/
    for(int i=0; i<TAM; i++)
    {
        promedios[i]=((float)notas1[i]+notas2[i])/2;
    }

    system("cls");
    mostrarAlumnos(notas1, notas2, promedios, legajos, sexos, nombres, TAM);
    ordenarAlumnos(notas1, notas2, promedios, legajos, sexos, nombres, TAM, POR_NOMBRE, ASCEN);
    //ordenarDosCriterios(notas1, notas2, promedios, legajos, sexos, nombres, TAM);
    mostrarAlumnos(notas1, notas2, promedios, legajos, sexos, nombres, TAM);

    return 0;
}
