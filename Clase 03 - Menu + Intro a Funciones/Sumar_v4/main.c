#include <stdio.h>
#include <stdlib.h>

int sumarv4(int a, int b);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = sumarv4(num1, num2);

    printf("El resultado es %d \n", resultado);

    return 0;
}

int sumarv4(int a, int b){
    return a+b;
}
