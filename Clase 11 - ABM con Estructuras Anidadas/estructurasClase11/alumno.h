#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    int legajo;//={1234, 2211, 3322, 5761, 2132, 6544, 8756, 3415, 6681, 9322};
    char nombre[20];//= {{"Dami"},{"Maru"},{"Christian"},{"Mabel"},{"Patricia"},{"Moncho"},{"Sandra"},{"Merlin"},{"Hector"},{"Carolina"}};
    char sexo;//={'m','f','m','f','f','m','f','m','m','f'};
    int nota1;//={2,8,7,10,4,1,7,7,8,10};
    int nota2;//={7,4,9,2,6,10,4,1,7,7};
    float promedio;
}eAlumno;

#endif // ALUMNO_H_INCLUDED

