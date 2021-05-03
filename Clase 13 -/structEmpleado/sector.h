#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED

int mostrarSectores(eSector arraySectores[], int tamSec);
int mostrarUnSector(eSector unSector);
int cargarDescripcionSector(int id, eSector arraySectores[], int tamSec, char descripcion[]);
