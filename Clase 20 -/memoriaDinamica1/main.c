#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int numero; ///Memoria Estatica

    int* pNumero=NULL;
    pNumero=(int*)malloc(sizeof(int)); ///Memoria Dinamica

    if(pNumero==NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        system("pause");
        exit(1);
    }

    printf("Ingrese un numero (estatica): ");
    scanf("%d",&numero);

    //*pNumero=10;
    printf("Ingrese un numero (dinamica): ");
    scanf("%d",pNumero);

    printf("Numero: %d\n",numero);
    printf("pNumero: %d\n",*pNumero);

    free(pNumero);

    return 0;
}
