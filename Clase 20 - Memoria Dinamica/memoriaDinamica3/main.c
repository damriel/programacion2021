#include <stdio.h>
#include <stdlib.h>

void mostrarEnterosP(int* vec, int tam);

int main()
{
    //int numeros[5]; ///Memoria Estatica
    int tam = 5;
    int* vector=NULL;
    vector = (int*)calloc(tam, sizeof(int));
    mostrarEnterosP(vector, tam);



    free(vector);

    return 0;
}

void mostrarEnterosP(int* vec, int tam)
{
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%d ", *(vec+i));
        }
        printf("\n\n");
    }
}
