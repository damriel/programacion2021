#include <stdio.h>
#include <stdlib.h>

void duplicar(int* a);

int main()
{
    int x = 5;
    /**int* puntero;

    puntero = &x;
    *puntero = 14; // *puntero es igual a decir x
    //es lo mismo que     x = 14
    //y que           *(&x) = 14;

    // & operador de direccion (direccion de memoria de una variable)
    // * operador de indireccion (valor escrito en esa direccion de memoria)
    // *(&x) = 20;

    printf("%d\n", x);**/

    duplicar(&x);

    printf("x vale %d\n", x);

    return 0;
}

void duplicar(int* a)
{
    *a = *a * 2;
}
