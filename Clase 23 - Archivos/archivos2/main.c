#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 45;

    ///ESCRITURA TXT
    FILE* f = fopen("Archivo2.txt","w");
    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    ///LECTURA TXT
    fprintf(f,"%d",num);
    fclose(f);


    char cadena[20];
    int entero;
    f = fopen("Archivo2.txt","r");
    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }
    fscanf(f,"%s",cadena);
    printf("cadena = %s\n", cadena);

    entero = atoi(cadena);
    printf("entero = %d\n", entero);
    /*char letra;
    while(!feof(f))
    {
        letra = fgetc(f);
        printf("%c",letra);
    }*/
    fclose(f);

    /**ESCRITURA EN BINARIO**/
    /*int num;
    int cant;

    FILE*  f = fopen("miArchivo.bin", "rb");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    do{
        cant = fread(&num, sizeof(int),1,f);
        if(cant==1)
        {
            printf("%d \n",num);
        }
    }while(!feof(f));


    while(!feof(f))   ///   OTRA OPCION
    {
        cant = fread(&num, sizeof(int),1,f);
        if(cant<1)
        {
            break;
        }
        printf("%d \n",num);
    }*/

    fclose(f);
    return 0;
}
