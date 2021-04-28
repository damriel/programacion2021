#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int miStrlen(char vec[]);

void miStrupr(char vec[]);

int main()
{
    /**char cadena1[20]="Hola";
    char cadena2[5]="Mundo";
    strcpy(cadena2, cadena1);
    printf("%d\n",miStrlen(cadena1));
    printf("Nombre: %s\n",cadena1);
    printf("Nombre: %s\n",cadena2);
    //strlwr(cadena1); // A MINUSCULAS
    printf("Nombre: %s\n",cadena1);
    //miStrupr(cadena1); // A MAYUSCULAS
    printf("Nombre: %s\n",cadena1);
    printf("%d\n",strcmp(cadena1, cadena2));
    //devuelve 0 si son iguales, -1 si cadena1 es primera alfabeticamente o 1 si cadena2 es primera
    //stricmp(cadena1, cadena2); no le da importancia a mayusculas y minusculas*/
    /**strcat(cadena1, cadena2);
    printf("%s", cadena1);
    puts(cadena2);//muestra cadenas sin mas texto
    gets(cadena1);//pide una cadena - INSEGURA
    puts(cadena1);//muestra cadenas sin mas texto
    fgets(cadena2,5,stdin);//pide una cadena - SEGURA!
    puts(cadena2);*/
    char nombre[20];
    char auxCad[100];

    /**MEJOR VALIDACION DE CADENAS PARA EL USUARIO**/
    printf("Ingrese nombre: ");
    gets(auxCad);

    while(strlen(auxCad)>19)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);
    puts(nombre);


    return 0;
}

int miStrlen(char vec[])
{
    int contador=0;
    for(int i=0; vec[i]!='\0'; i++)
    {
        contador++;
    }
    return contador;
}

void miStrupr(char vec[])
{
    for(int i=0; vec[i]!='\0'; i++)
    {
        if(vec[i]>=97 && vec[i]<=122)
        {
            vec[i]=vec[i]-32;
        }
    }
}
