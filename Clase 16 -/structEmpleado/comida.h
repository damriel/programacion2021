#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eComida;

int mostrarComidas(eComida aComidas[], int tam);
void mostrarUnaComida(eComida unaComida);
int buscarComida(eComida aComidas[], int tam, int idBuscado);
int cargarDescripcionComida(int id, eComida aComidas[], int tamCom, char descripcion[]);

#endif // COMIDA_H_INCLUDED
