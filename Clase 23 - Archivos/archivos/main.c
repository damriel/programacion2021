#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x = 45;
    int vec[] = {32,56,43,12,89};

            //modos  r = read text   /  w = write text
            //      rb = read binary / wb = write binary
    FILE* f = fopen("miArchivo.bin","wb");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    if(fwrite(vec, sizeof(int),5,f)==5)
    {
        printf("Se guardaron los datos en el archivo con exito!!!\n");
    }

    fclose(f);

    return 0;
}
