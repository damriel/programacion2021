#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 5

void mostrarCaracteres(char str[], int tam);

void pasarMayusculas(char str[], int tam);

int main()
{
    char caracteres[TAM]={'H','o','l','i','s'};

    mostrarCaracteres(caracteres, TAM);
    pasarMayusculas(caracteres, TAM);
    mostrarCaracteres(caracteres, TAM);

    return 0;
}

void mostrarCaracteres(char str[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n\n");
}

void pasarMayusculas(char str[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        str[i] = toupper(str[i]);
    }
}
