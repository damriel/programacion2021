/**
        FUNCIONES
    Son fragmentos de codigo con una funcionalidad especifica.
    Implementan el concepto de reutilizacion de codigo.
    Faciles de mantener.

    Hay 4 tipos de funciones en cuanto a lo que reciben y lo que retornan
    Pueden o no devolver algo / recibir o no recibir nada...
        no devuelve F1(no recibe)
        no devuelve F2(Recibe algo)
        devuelve algo F3(no recibe)
        devuelve algo F4(Recibe algo)

    estructurado = prototipo  // POO = firma
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    printf("El resultado es %d\n", resultado);
    return 0;
}
