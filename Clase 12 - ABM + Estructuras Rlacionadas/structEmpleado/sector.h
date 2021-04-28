#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED

void mostrarSectores(eSector arraySectores[], int tam);
void mostrarUnSector(eSector unSector);
