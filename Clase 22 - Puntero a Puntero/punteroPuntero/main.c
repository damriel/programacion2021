#include <stdio.h>
#include <stdlib.h>

int main()
{
    int*** j;
    int* p = (int*) malloc(sizeof(int));

    *p = 5;

    int** r = (int**) malloc(sizeof(int*));

    j = &r;

    *r = p;

    printf("Espacio en memoria apuntado por p: %d\n",*p);
    printf("Ese cuadradito: %d\n",**r);

    **r = 30;

    printf("Espacio en memoria apuntado por p: %d\n",*p);
    printf("Ese cuadradito: %d\n",**r);
    printf("Ese cuadradito: %d\n",***j);

    return 0;
}
