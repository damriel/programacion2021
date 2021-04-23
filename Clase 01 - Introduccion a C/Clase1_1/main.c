#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hola mundo!\n");

    system("pause"); /*system = funcion de sistema operativo
    "pause" pone en pausa al proyecto*/

    int numero; // ocupa 32 bits u 8 Bytes
    char letra; // ocupa 8 bits o 1 Byte
    float pi;

    letra = 'a'; // asigno el caracter 'a' a la variable letra
    numero = 123;
    pi = 3.14;

    // MASCARAS para printf: %d %f %i %c

    printf("La variable numero vale: %d\n", numero);
    printf("La variable pi vale: %.2f\n", pi);
    printf("La variable numero vale: %d. La variable letra vale: %c\n", numero, letra);

    printf("Ingrese un numero: ");
    fflush(stdin); //limpia el buffer de entrada, poner siempre antes del scanf
    scanf("%d", &numero);
    printf("El nuevo valor de numero es: %d",numero);
    printf("Ingrese un char: ");
    fflush(stdin); //limpia el buffer de entrada, poner siempre antes del scanf
    scanf("%c", &letra);
    printf("El nuevo valor de letra es: %c",letra);

    return 0;
}
