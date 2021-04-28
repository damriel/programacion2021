#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_NAME 20
#define SIZE_LNAME 20
#define SECURE_SIZE 100

int main()
{
    char nombre[SIZE_NAME];
    char apellido[SIZE_LNAME];
    char nombreCompleto[SIZE_NAME+SIZE_LNAME+1];
    char auxCad[SECURE_SIZE];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=SIZE_NAME)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=SIZE_LNAME)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(apellido, auxCad);

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto,", ");
    strcat(nombreCompleto,nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for(int i=0; nombreCompleto[i]!='\0'; i++)
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }

    printf("%s\n",nombreCompleto);

    return 0;
}
