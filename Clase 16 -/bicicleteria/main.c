#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "datawarehouse.h"
#include "bicicleta.h"

#define TAMTIPOS 4
#define TAMCOL 5
#define TAMSER 4
#define TAMBICI 100

int main()
{
    char confirm='n';
    eTipo tipos[TAMTIPOS];
    eColor colores[TAMCOL];
    eServicio servicios[TAMSER];
    eBicicleta bicicletas[TAMBICI];

    /*hardcodearTipos(tipos,TAMTIPOS);
    for(int i=0;i<TAMTIPOS;i++)
    {
        printf("ID Tipo: %d\n",tipos[i].id);
        printf("Descripcion: %s\n\n",tipos[i].descripcion);
    }
    printf("\n ********************* \n");
    hardcodearColores(colores,TAMCOL);
    for(int i=0;i<TAMCOL;i++)
    {
        printf("ID Color: %d\n",colores[i].id);
        printf("Descripcion: %s\n\n",colores[i].nombreColor);
    }
    printf("\n ********************* \n");
    hardcodearServicios(servicios,TAMSER);
    for(int i=0;i<TAMSER;i++)
    {
        printf("ID Servicio: %d\n",servicios[i].id);
        printf("Descripcion: %s - ",servicios[i].descripcion);
        printf("Precio: $ %f\n\n",servicios[i].precio);
    }*/

    do{
        switch(menuOpciones())
        {
        case 'A':
            if(altaBicicleta(bicicletas,TAMBICI,tipos,TAMTIPOS,colores,TAMCOL))
            {
                printf("Carga exitosa!\n");
            }
            system("pause");
            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'E':
            break;
        case 'F':
            break;
        case 'G':
            break;
        case 'H':
            break;
        case 'I':
            break;
        case 'J':
            dam_getCaracter(&confirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            break;
        }
        system("cls");
    }while(confirm=='n');

    return 0;
}
