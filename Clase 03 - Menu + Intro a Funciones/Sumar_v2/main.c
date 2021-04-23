#include <stdio.h>
#include <stdlib.h>

void sumarv2(int a, int b);

int main()
{
    int num1;
    int num2;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    sumarv2(num1, num2); //parametros actuales (en POO argumentos)

    return 0;
}

void sumarv2(int a, int b){ //parametros formales (en POO parametros)
    int resultado;
    resultado = a + b;
    printf("El resultado es %d\n", resultado);
}
