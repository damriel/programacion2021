#include <stdio.h>
#include <stdlib.h>
//prototipo
void sumarv1(void);
// otra forma de nombrarla "void sumarv1();"

int main()
{
    sumarv1();
    return 0;
}

void sumarv1(){

    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;
    printf("El resultado es %d\n", resultado);

}
