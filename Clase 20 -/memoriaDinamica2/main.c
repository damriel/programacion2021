#include <stdio.h>
#include <stdlib.h>

void mostrarEnterosV(int vec[], int tam);

void mostrarEnterosP(int* vec, int tam);

int main()
{
    //int numeros[5]; ///Memoria Estatica
    int tam = 5;
    int* vector=NULL;
    int* pAux=NULL;
    vector = (int*)malloc(sizeof(int)*tam); ///Memoria Dinamica
    //falta validar que vector no quede cargado con NULL

    ///Nomenclatura de corchetes
    /*for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero (estatica): ");
        scanf("%d",&numeros[i]);
    }
    mostrarEnterosV(numeros, 5);
    */

    ///Nomenclatura de punteros
    for(int i=0; i<tam; i++)
    {
        printf("Ingrese un numero (dinamica): ");
        scanf("%d",vector+i);
    }

    pAux=(int*)realloc(vector,sizeof(int)*10);///Redimensionamiento de memoria
    if(pAux==NULL)
    {
        printf("No se consiguio agrandar el vector.\n");
        system("pause");
        exit(1);
    }
    printf("Se agrando el vector con exito!\n");
    vector=pAux;
    pAux=NULL;
    tam+=5;

    for(int i=5; i<tam; i++)
    {
        printf("Ingrese un numero (dinamica): ");
        scanf("%d",vector+i);
    }
    mostrarEnterosP(vector, tam);

    printf("Achico el vector\n");
    vector=(int*)realloc(vector,sizeof(int)*7);
    tam-=3;
    mostrarEnterosP(vector, 10);

    free(vector);

    return 0;
}

void mostrarEnterosV(int vec[], int tam)
{
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%d ",vec[i]);
        }
        printf("\n\n");
    }
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
