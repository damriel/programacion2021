#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED



#endif // FUNCTIONS_H_INCLUDED

void cargaSecuencialAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20],int tam);

void mostrarAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20],int tam);

void ordenarAlumnos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam, int criterio, int orden);

void swapDatos(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam, int indexI, int indexJ);

void ordenarDosCriterios(int n1[], int n2[], float prom[], int legajo[], char sexo[], char names[][20], int tam);

void mostrarUnAlumno(int n1, int n2, float prom, int legajo, char sexo, char names[]);
