#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#define TAM 5

int main()
{
    /*int numero;
    int numeros[5];

    numero = 14;
    numeros[0] = 18;

    printf("numero: %d\n", numero);
    printf("primer elemento de numeros: %d\n", numeros[0]);*/

    /**int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int total;

    for(int i = 0; i < 5; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&num1);
    }

    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese un numero: ");
    scanf("%d",&num2);
    printf("Ingrese un numero: ");
    scanf("%d",&num3);
    printf("Ingrese un numero: ");
    scanf("%d",&num4);
    printf("Ingrese un numero: ");
    scanf("%d",&num5);

    total = num1 + num2 + num3 + num4 + num5;
    printf("El total es: %d", total);

    SIMPLIFICADO CON ARRAYS:                            **/

    int numeros[TAM];//para inicializar int numeros[] = [4, 3, 2, 7, 1];
    //scanf("%d", &numeros[2]); NOTACION VECTORIAL
    //scanf("%d", numeros + 2); NOTACION DE PUNTEROS
    //printf("%d\n", numeros[2])); NOTACION VECTORIAL
    //printf("%d\n", *(numeros+2)); NOTACION DE PUNTEROS

    //carga secuencial del array "numeros[]"
    /*for(int i = 0; i < TAM; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&numeros[i]);
    }*/
    dam_cargarVectorEnteros(numeros, TAM);

    //mostrar secuencialmente los valores del array "numeros[]"
    /*for(int i = 0; i < TAM; i++){
        printf("%d ", numeros[i]);
    }*/
    if(!dam_mostrarVectorEnteros(numeros, TAM))
    {
        printf("No se pudo mostrar el vector");
    }
    printf("\n\n");

    return 0;
}
