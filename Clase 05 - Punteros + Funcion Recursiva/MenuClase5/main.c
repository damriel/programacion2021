/**
               FUNCONES CON CARACTERES
    getchar(); sirve para devolver un caracter ingresado por teclado. uso: opcion = getchar();
    getch(); igual que la anterior pero esta no espera a que presione la tecla enter y no lo muestra en la pantalla. uso: opcion = getch();
    getche(); deja el "eco" de la tecla presionada en la consola (como getch pero mostrando el char en pantalla)

               OTROS DATOS
    Mayor cantidad de casos para "if else" son 3, no es necesario usar un switch.
    No usar una variable para varios propositos; que cada variable se encargue de algo especifico.


**/

#include <stdio.h>
#include <stdlib.h>

char menu();

/** \brief Pone a 1 el valor de una bandera
 *
 * \param pFlag int* referencia a la bandera
 * \return void
 *
 */
void activarFlag(int* pFlag);

/** \brief Pone a 0 el valor de una bandera
 *
 * \param pFlag int* referencia a la bandera
 * \return void
 *
 */
void resetFlag(int* pFlag);

int main()
{
    char seguir = 's';
    int flagSaludo = 0;
    int flagBrindis = 0;
    char confirmacion;

    do
    {
        switch(menu())
        {
        case 'a':
            printf("Hola, que tal?\n");
            system("pause");
            activarFlag(&flagSaludo);
            break;
        case 'b':
            if(flagSaludo)
            {
                printf("Chin chin!\n");
                activarFlag(&flagBrindis);
            }
            else
            {
                printf("Antes de brindar primero debemos saludarnos!\n");
            }
            system("pause");
            break;
        case 'c':
            if(flagSaludo && flagBrindis)
            {
                printf("Chau, nos vemos.\n");
                resetFlag(&flagSaludo);
                resetFlag(&flagBrindis);
            }
            else if(flagSaludo && !flagBrindis)
            {
                printf("Antes de despedirnos deberiamos brindar!\n");
            }
            else
            {
                printf("Antes de despedirnos deberiamos saludarnos!\n");
            }

            system("pause");
            break;
        case 'd':
            printf("Esta seguro que desea salir? SI(s) / NO(n): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            if(confirmacion=='s')
            {
                seguir = 'n';
            }
            else if(confirmacion=='n')
            {
                printf("Voliendo al programa!\n\n");
                system("pause");
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    system("cls"); //clear screen
    printf("     *** Menu de Opciones ***\n\n");
    printf("a)Saludar.\n");
    printf("b)Brindar.\n");
    printf("c)Despedir.\n");
    printf("d)Salir.\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

void activarFlag(int* pFlag)
{
    if(pFlag!=NULL)
    {
        *pFlag=1;
    }
}

void resetFlag(int* pFlag)
{
    if(pFlag!=NULL)
    {
        *pFlag=0;
    }
}
