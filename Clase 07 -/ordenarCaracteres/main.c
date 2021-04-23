#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorCaracteres(char vec[], int tam);

int ordenarVectorCaracteres(char vec[], int tam, int criterio);

int main()
{
    char caracteres[TAM]={'d','g','a','h','S'};
    int crit = 1;

    mostrarVectorCaracteres(caracteres, TAM);
    ordenarVectorCaracteres(caracteres, TAM, crit);
    printf("\n\n");
    mostrarVectorCaracteres(caracteres, TAM);
    printf("\n\n");

    return 0;
}

void mostrarVectorCaracteres(char vec[], int tam)
{
    for(int i=0; i<TAM; i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}

/** \brief Ordena un array de enteros
 *
 * \param vec[] int Array a ordenar
 * \param tam int tamaño del array
 * \param criterio int 1 para ordenar creciente / 0 decreciente
 * \return int devuelve 1 si ordeno o 0 si hubo un problema con los parametros
 *
 */
int ordenarVectorCaracteres(char vec[], int tam, int criterio)
{
    char aux;
    int retorno=0;

    if(vec!=NULL && tam>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<TAM; i++)
        {
            for(int j = i+1; j<TAM; j++)
            {
                if((criterio && vec[i]>vec[j]) || (!criterio && vec[i]<vec[j]))
                {
                    //swap
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
    return retorno;
}
