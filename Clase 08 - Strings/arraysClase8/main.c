#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/** \brief busca un caracter en un array de caracteres
 *
 * \param letras[] char array sobre el que se realiza la busqueda
 * \param tam int tamaño del array
 * \param caracterABuscar int caracter a buscar
 * \return int indice de la ubicacion de la primer ocurrencia del caracter buscado o -1 si no lo encuentra
 *
 */
int buscarCaracter(char vec[], int tam, char caracterABuscar);

int buscarReemplazar(char vec[], int tam, char caracterABuscar, char reemplazo);

int main()
{
    char letras[TAM]={'a','r','t','u','r'};

    printf("%d",buscarReemplazar(letras, TAM, 'r','h'));

    return 0;
}

int buscarCaracter(char vec[], int tam, char caracterABuscar)
{
    int indice=-1;
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(caracterABuscar==vec[i])
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarReemplazar(char vec[], int tam, char caracterABuscar, char reemplazo)
{
    int retorno=0;
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(caracterABuscar==vec[i])
            {
                vec[i]=reemplazo;
                retorno++;
            }
        }
    }
    return retorno;
}
