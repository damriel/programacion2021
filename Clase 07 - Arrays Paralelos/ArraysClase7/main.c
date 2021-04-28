#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorEnteros(int vec[], int tam);

int ordenarVectorEnteros(int vec[], int tam, int criterio);

int main()
{
    int numeros[TAM]={5,9,2,4,8};
    int crit;

    printf("Ingrese criterio (0 = decreciente / 1 = creciente): ");
    scanf("%d", &crit);

    ordenarVectorEnteros(numeros, TAM, crit);

    mostrarVectorEnteros(numeros, TAM);

    return 0;
}

void mostrarVectorEnteros(int vec[], int tam)
{
    for(int i=0; i<TAM; i++)
    {
        printf("%d ", vec[i]);
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
int ordenarVectorEnteros(int vec[], int tam, int criterio)
{
    int aux;
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
