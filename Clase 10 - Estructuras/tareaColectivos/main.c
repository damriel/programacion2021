#include <stdio.h>
#include <stdlib.h>
#define COLUMNAS 13
#define FILA 3

/*
Linea 1 / Linea 2 / Linea 3
12 internos en cada linea
matriz de 3 filas (lineas) y 12 columnas (internos)
Hacer un programa que pida
*/

void mostrarMatriz(int m[][13], int filas);
void totalizar(int m[][13], int filas);

int main()
{
    int mat[FILA][COLUMNAS] = {0};

    char seguir;
    int linea;
    int interno;
    int recaudacion;
    do{
        printf("Ingrese Linea: ");
        scanf("%d",&linea);
        printf("Ingrese Interno: ");
        scanf("%d",&interno);
        printf("Ingrese Recaudacion: ");
        scanf("%d",&recaudacion);

        mat[linea-1][interno-1] += recaudacion;

        printf("Quiere ingresar otra recaudacion? (s/n): ");
        fflush(stdin);
        scanf("%c",&seguir);
    }while(seguir=='s');

    mostrarMatriz(mat, FILA);

    return 0;
}

void mostrarMatriz(int m[][13], int filas)
{
    totalizar(m, filas);
    printf("                   ***Recaudaciones***\n");
    printf("                        Internos\n");
    printf("            1    2    3    4    5    6    7    8    9   10   11   12  Total\n");
    for(int f=0; f<filas; f++)
    {
        if(f==3)
        {
            printf("Total Int");
        }
        else
        {
            printf("Linea %d ",f+1);
        }
        for(int c=0; c<13; c++)
        {
            printf("%5d",m[f][c]);
        }
        printf("\n");
    }
}

void totalizar(int m[][13], int filas)
{
    for(int i=0; i<filas-1; i++)
    {
        for(int j=0; j<12; j++)
        {
            m[i][12] += m[i][j];
        }
    }
    for(int j=0; j<13; j++)
    {
        for(int i=0; i<filas-1; i++)
        {
            m[3][j] += m[i][j];
        }
    }
}
