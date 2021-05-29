#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int mostrarTipos(eTipo aTipos[], int tamTipos)
{
    int retorno=0;
    if(aTipos!=NULL && tamTipos>0)
    {
        retorno=1;
        for(int i=0; i<tamTipos; i++)
        {
            printf(" ID    TIPOS\n");
            printf("%5d     %10s\n",aTipos[i].id,aTipos[i].descripcion);
        }
    }

    return retorno;
}
