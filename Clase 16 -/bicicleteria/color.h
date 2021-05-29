#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int mostrarColores(eColor aColores[], int tamCol);
