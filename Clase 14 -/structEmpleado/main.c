#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 11
#define TAMSEC 4
#define TAMCOM 5
#define TAMALM 30

int main()
{
    eSector sectores[TAMSEC]={
        {500,"Sistemas"},
        {501,"RRHH"},
        {502,"Cobranzas"},
        {503,"Legales"}
    };

    eComida comidas[TAMCOM]={
        {1000,"Milanesa", 100},
        {1001,"Fideos", 120},
        {1002,"Churrasco", 140},
        {1003,"Ensalada", 160},
        {1004,"Pescado", 110}
    };

    char exitConfirm='n';
    int nextId=20000;
    int nextIdAlmuerzo=50000;
    eAlmuerzo almuerzos[TAMALM];
    eEmpleado nomina[TAM];
    inicializarEmpleados(nomina, TAM);
    inicializarAlmuerzos(almuerzos,TAMALM);
    hardcodearEmpleados(nomina,TAM,10,&nextId);

    do{
        switch(menuOpciones())
        {
        case 1:
            //ALTA DE EMPLEADO
            if(!altaEmpleado(nomina, TAM, &nextId, sectores, TAMSEC))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            system("pause");
            break;
        case 2:
            modificarEmpleado(nomina, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 3:
            //BAJA DE EMPLEADO
            if(!bajaEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Hubo un problema. Baja cancelada.\n");
            }
            system("pause");
            break;
        case 4:
            //LISTAR EMPLEADOS
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);
            break;
        case 5:
            //ORDENAR EMPLEADOS
            ordenarEmpleados(nomina,TAM, sectores, TAMSEC);
            break;
        case 6:
            //MOSTRAR SECTORES
            mostrarSectores(sectores, TAMSEC);
            system("pause");
            break;
        case 7:
            //INFORMES
            empleadosSector(nomina,TAM,sectores,TAMSEC);
            break;
        case 8:
            //AUMENTO DE SUELDO
            actualizarSueldosXSector(nomina,TAM,sectores,TAMSEC);
            break;
        case 9:
            //AUMENTO DE SUELDO
            aPonerla(nomina,TAM,sectores,TAMSEC);
            break;
        case 10:
            system("cls");
            mostrarComidas(comidas, TAMCOM);
            break;
        case 11:
            altaAlmuerzo(almuerzos,TAMALM,nomina,TAM,sectores,TAMSEC,comidas,TAMCOM,&nextIdAlmuerzo);
            break;
        case 12:
            mostrarAlmuerzos(almuerzos,TAMALM,comidas,TAMCOM,nomina,TAM);
            break;
        case 20:
            //SALIR
            dam_getCaracter(&exitConfirm,"Seguro desea salir? (s/n): ","ERROR. Opcion invalida.\n",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}



