#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int mostrarColores(eColor aColores[], int tamCol)
{
    int retorno=0;
    if(aColores!=NULL && tamCol>0)
    {
        retorno=1;
        for(int i=0;i<tamCol;i++)
        {
            printf(" ID    COLOR\n");
            printf("%5d     %10s\n",aColores[i].id,aColores[i].nombreColor);
        }
    }
    return retorno;
}
