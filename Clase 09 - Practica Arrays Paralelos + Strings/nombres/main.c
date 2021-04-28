#include <stdio.h>
#include <stdlib.h>

int main()
{
    char z;
    char x[20];
    char y[5][20];
    //char auxCad[100];

    printf("Ingrese un caracter: ");
    scanf("%c",&z);

    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c",&x[0]);

    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c",&y[1][1]);

    printf("Ingrese una cadena: ");
    fflush(stdin);
    scanf("%s",x);

    strcpy(x,"Juan");

    printf("Ingrese una cadena: ");
    fflush(stdin);
    scanf("%s",y[3]);

    strcpy(y[3],"Sofia");

    return 0;
}
