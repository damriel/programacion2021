#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED

int mostrarSectores(eSector aSectores[], int tamSec);
int mostrarUnSector(eSector unSector);
int cargarDescripcionSector(int id, eSector aSectores[], int tamSec, char descripcion[]);
int buscarSector(eSector aSectores[], int tamSec, int idBuscado);
