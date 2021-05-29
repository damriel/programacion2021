#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int altaBicicleta(eBicicleta aBicis[], int tamBici, eTipo aTipo[], int tamTipos, eColor aColores[], int tamCol);

int buscarLibreBici(eBicicleta aBicis[], int tamBici);

