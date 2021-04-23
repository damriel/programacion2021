#include <stdio.h>
#include <stdlib.h>

/**CLASROOM GENERAL VER CLASE 4 BIBLIOTECA INPUTS VER VIDEO Y PDF (CON FUNCIONES)**/
/** Mascara para long long int = "%ld" **/

/** \brief realiza la division de dos enteros y escribe el resultado en una variable
 *
 * \param a int dividendo
 * \param b int divisor
 * \param rta float* referencia (dir de memoria) donde se carga el resultado
 * \return int retorna 1 si se ralizo la operacion o 0 si no.
 *
 */
int dividir(int a, int b, float* rta);

int main()
{
    /*int numUno;
    int numDos;
    float respuesta;

    printf("Ingrese un numero: ");
    scanf("%d", &numUno);
    printf("Ingrese otro numero: ");
    scanf("%d", &numDos);

    if(dividir(numUno,numDos,&respuesta))
    {
        printf("El resultado de la division es: %.2f\n", respuesta);
    }
    else
    {
        printf("No se pudo realizar la operacion.\n");
    }*/

    /** OPCIONES DE SCANF **/
    int dia;
    int mes;
    int anio;
    int retorno;
    printf("Ingrese fecha dd/mm/aaaa: ");
    retorno = scanf("%d/%d/%d", &dia, &mes, &anio);

    printf("%d\n",retorno);
    if(retorno<3)
    {
        printf("Problema para obtener la fecha.");
    }
    else
    {
        printf("La fecha ingresada es %02d/%02d/%d",dia,mes,anio);
    }

    return 0;
}

int dividir(int a, int b, float* rta)
{
    int retorno=0;

    if(b!=0 && rta!=NULL)
    {
        *rta = (float)a/b;
        retorno = 1;
    }
    return retorno;
}
