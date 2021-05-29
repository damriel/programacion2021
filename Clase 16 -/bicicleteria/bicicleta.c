#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "bicicleta.h"

int altaBicicleta(eBicicleta aBicis[], int tamBici, eTipo aTipo[], int tamTipos, eColor aColores[], int tamCol)
{
    int retorno=0;
    int indice;
    int opcionRodado;

    if(aBicis!=NULL && tamBici>0)
    {
        indice = buscarLibreBici(aBicis,tamBici);
        if(indice!=-1)
        {
            retorno=1;
            dam_getNumero(&aBicis[indice].id,"Ingrese ID: ","ERROR. ",1,9999999,10);
            dam_getNombre(aBicis[indice].marca,"Ingrese marca: ", "ERROR. Solo letras y 20 caracteres maximo.\n",20,10);
            mostrarTipos(aTipo,tamTipos);
            dam_getNumero(&aBicis[indice].idTipo,"\nSeleccione el tipo: ", "ERROR. ",0,9999999,10);
            mostrarColores(aColores,tamCol);
            dam_getNumero(&aBicis[indice].idColor,"\nSeleccione el color: ", "ERROR. ",0,9999999,10);
            dam_getNumero(&opcionRodado,"1)20 \n2)26 \n3)27.5 \n4)29 \nIngrese la opcion del rodado correspondiente: ","ERROR\n",1,4,10);
            switch(opcionRodado)
            {
            case 1:
                aBicis[indice].rodado=20;
                break;
            case 2:
                aBicis[indice].rodado=26;
                break;
            case 3:
                aBicis[indice].rodado=27.5;
                break;
            case 4:
                aBicis[indice].rodado=29;
                break;
            }
        }

    }
    return retorno;
}

int buscarLibreBici(eBicicleta aBicis[], int tamBici)
{
    int indice=-1;
    if(aBicis!=NULL && tamBici>0)
    {
        for(int i=0; i<tamBici; i++)
        {
            if(aBicis[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
