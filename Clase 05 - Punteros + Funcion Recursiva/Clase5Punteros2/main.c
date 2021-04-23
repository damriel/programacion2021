#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);

int main()
{
    int a = 20;
    int b = 10;

    printf("Antes del swap... a: %d    b: %d\n",a,b);

    swap(&a,&b);

    printf("Despues del swap... a: %d    b: %d\n",a,b);
    return 0;
}

void swap(int* x, int* y)
{
    int aux;
    if(x!=NULL && y!=NULL)
    {
        aux=*x;
        *x=*y;
        *y=aux;
    }
}
