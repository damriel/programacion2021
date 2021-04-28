#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 5

void mostrarMatriz(int m[][5], int filas);

int main()
{
    /*char nombres[5][20];
    nombres[0][0] = 'a';
    printf("%c\n",nombres[0][0]);*/

    //int mat[][COLUMNAS] = {8,9,3,2,1,4,7,10,15,21,1,2,6,7,11};
    int mat[FILAS][COLUMNAS];

    for(int f=0; f<FILAS; f++)
    {
        for(int c=0; c<COLUMNAS; c++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &mat[f][c]);
        }
        printf("\n");
    }



    mostrarMatriz(mat[], FILAS);

    return 0;
}

void mostrarMatriz(int m[][5], int filas)
{
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<5; c++)
        {
            printf("%2d ",m[f][c]);
        }
        printf("\n");
    }
}
