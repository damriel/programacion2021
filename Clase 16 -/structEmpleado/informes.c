#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "dam.h"

void empleadosSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    int auxIdSector;
    int contador=0;
    char descripcion[20];
    system("cls");
    printf("   INFORME EMPLEADOS POR SECTOR\n");
    mostrarSectores(arraySectores, tamSec);
    if(arrayEmpleados!=NULL && tam>0 && arraySectores!=NULL && tamSec>0 && !dam_getNumero(&auxIdSector, "Ingrese el ID del sector: ","ERROR. ", 500,503,10))
    {
        cargarDescripcionSector(auxIdSector, arraySectores, tamSec, descripcion);
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].idSector==auxIdSector && !arrayEmpleados[i].isEmpty)
            {
                mostrarUnEmpleado(arrayEmpleados[i],arraySectores,tamSec);
                contador++;
            }
        }
        if(!contador)
        {
            printf("No hay empleados en el sector %s.\n",descripcion);
        }
        else
        {
            printf("Hay %d empleados en el sector %s.\n",contador,descripcion);
        }
        system("pause");
    }
}

void actualizarSueldosXSector(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    int auxAumento;
    int auxIdSector;
    char descripcion[20];

    system("cls");
    printf("     ACTUALIZAR SUELDOS POR SECTOR");
    mostrarSectores(arraySectores, tamSec);
    if(!dam_getNumero(&auxIdSector, "Ingrese el ID del sector: ", "ERROR. ",500,503,10) &&
       !dam_getNumero(&auxAumento, "Ingrese el porcentaje de aumento: ", "ERROR. ",1,99,10) &&
       cargarDescripcionSector(auxIdSector,arraySectores,tamSec,descripcion))
    {
        for(int i=0; i<tam; i++)
        {
            if(arrayEmpleados[i].idSector==auxIdSector && !arrayEmpleados[i].isEmpty)
            {
                arrayEmpleados[i].sueldo+=(arrayEmpleados[i].sueldo*auxAumento/100);
            }
        }
        printf("Se han actualizado los sueldos del sector %s\n",descripcion);
    }
}

void aPonerla(eEmpleado arrayEmpleados[], int tam, eSector arraySectores[], int tamSec)
{
    float totalSector;
    float total=0;

    system("cls");
    printf("  INFORME SUELDOS POR SECTOR Y TOTAL\n\n");
    for(int i=0; i<tamSec; i++)
    {
        totalSector=0;
        printf("Sector: %s\n",arraySectores[i].descripcion);
        for(int j=0; j<tam; j++)
        {
            if(!arrayEmpleados[j].isEmpty && arrayEmpleados[j].idSector==arraySectores[i].id)
            {
                totalSector+=arrayEmpleados[j].sueldo;
            }
        }
        printf("Total: %.2f\n\n",totalSector);
        total+=totalSector;
    }
    printf("Total de todos los sueldos: %.2f\n",total);
    system("pause");
}

void sectorQueMasCobra(eEmpleado aEmpleados[], int tam, eSector aSectores[], int tamSec)
{
    float totales[tamSec];
    float auxFloat;
    int idSector;
    int mayor;

    for(int i=0; i<tamSec; i++)
    {
        auxFloat=0;
        idSector=aSectores[i].id;
        for(int j=0; j<tam; j++)
        {
            if(aEmpleados[j].isEmpty==0 && aEmpleados[j].idSector==idSector)
            {
                auxFloat+=aEmpleados[j].sueldo;
            }
        }
        totales[i]=auxFloat;
    }
    mayor=totales[0];
    for(int i=1; i<tamSec; i++)
    {
        if(totales[i]>mayor)
        {
            mayor=totales[i];
        }
    }

    printf("Sectores que mas cobran:\n");
    for(int i=0; i<tamSec; i++)
    {
        if(totales[i]==mayor)
        {
            printf(" %s ", aSectores[i].descripcion);
        }
    }
    printf("\n\n");
}

void mostrarAlmuerzosEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajo;
    int flag=0;
    printf("       Almuerzos Empleado \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajo,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajo)==-1)
    {
        dam_getNumero(&legajo,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(aAlmuerzos[i].legEmpleado == legajo && !aAlmuerzos[i].isEmpty)
        {
            mostrarUnAlmuerzo(aAlmuerzos[i],aComidas,tamCom,aEmpleados,tamEmp,aSectores,tamSec);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n",legajo);
    }
}

void totalGastoAlmuerzo(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajoBuscado;
    int flag=0;
    float gastoTotal=0;
    int indice;
    printf("       Total Gasto Almuerzo \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajoBuscado,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado)==-1)
    {
        dam_getNumero(&legajoBuscado,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(aAlmuerzos[i].legEmpleado == legajoBuscado && !aAlmuerzos[i].isEmpty)
        {
            /*for(int j=0; j<tamCom; j++)
            {
                if(aAlmuerzos[i].idComida==aComidas[j].id)
                {
                    gastoTotal+=aComidas[j].precio;
                    flag=1;
                }
            }*/
            indice = buscarComida(aComidas,tamCom,aAlmuerzos[i].idComida);
            gastoTotal+=aComidas[indice].precio;
            flag=1;
        }
    }

    if(!flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n",legajoBuscado);
    }
    else
    {
        printf("Total a pagar $ %.2f\n",gastoTotal);
    }
}


//1) Elegir un sector y hacer la sumatoria de todas los almuerzos de ese sector.
void sumatoriaAlmuerzosSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    float total=0;
    int idSectorBuscado;
    int flag=0;
    mostrarSectores(aSectores,tamSec);
    dam_getNumero(&idSectorBuscado,"Ingrese ID del sector: ","ERROR. ",500,504,0);
    while(buscarSector(aSectores,tamSec,idSectorBuscado)==-1)
    {
        dam_getNumero(&idSectorBuscado,"Ingrese un ID valido: ","ERROR. ",500,504,0);
    }

    for(int i=0; i<tamEmp; i++)
    {
        if(aEmpleados[i].idSector==idSectorBuscado && !aEmpleados[i].isEmpty)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(aAlmuerzos[j].legEmpleado==aEmpleados[i].legajo && !aAlmuerzos[j].isEmpty)
                {
                    for(int k=0; k<tamCom; k++)
                    {
                        if(aComidas[k].id==aAlmuerzos[j].idComida)
                        {
                            total+=aComidas[k].precio;
                            flag=1;
                        }
                    }
                }
            }
        }
    }

    if(!flag)
    {
        printf("El sector de ID %d no registra almuerzos.\n",idSectorBuscado);
    }
    else
    {
        printf("Total a pagar por el sector $ %.2f\n",total);
    }
}

//Punto 1 version baus
void totalesComidasXSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int flag=1;
    float total;
    for(int i=0; i<tamSec; i++)
    {
        total=0;
        for(int j=0; j<tamEmp; j++)
        {
            if(!aEmpleados[j].isEmpty && aEmpleados[j].idSector==aSectores[i].id)
            {
                for(int k=0; k<tamAlm; k++)
                {
                    if(!aAlmuerzos[k].isEmpty && aAlmuerzos[k].legEmpleado==aEmpleados[j].legajo)
                    {
                        //recorro comidas para leer el precio de la comida de este almuerzo
                        for(int l=0; l<tamCom; l++)
                        {
                            if(aComidas[l].id==aAlmuerzos[k].idComida)
                            {
                                total+=aComidas[l].precio;
                                flag=0;
                            }
                        }
                    }
                }
            }
        }//fin for empleados
        if(!flag)
        {
            printf("Sector %s Total $ %.2f\n",aSectores[i].descripcion,total);
        }
        else
        {
            printf("No se registraron comidas del sector %s\n",aSectores[i].descripcion);
        }
    }//fin for sectores
}

//2) Cual es la comida preferida de un sector.
void comidaPreferidaSector(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int contador[5]={0};
    int idSectorBuscado;
    int mayor;

    mostrarSectores(aSectores,tamSec);
    dam_getNumero(&idSectorBuscado,"Ingrese ID del sector: ","ERROR. ",500,504,0);
    while(buscarSector(aSectores,tamSec,idSectorBuscado)==-1)
    {
        dam_getNumero(&idSectorBuscado,"Ingrese un ID valido: ","ERROR. ",500,504,0);
    }

    for(int i=0; i<tamEmp; i++)
    {
        if(aEmpleados[i].idSector==idSectorBuscado && !aEmpleados[i].isEmpty)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(aAlmuerzos[j].legEmpleado==aEmpleados[i].legajo && !aAlmuerzos[j].isEmpty)
                {
                    switch(aAlmuerzos[j].idComida)
                    {
                    case 1000:
                        contador[0]++;
                        break;
                    case 1001:
                        contador[1]++;
                        break;
                    case 1002:
                        contador[2]++;
                        break;
                    case 1003:
                        contador[3]++;
                        break;
                    case 1004:
                        contador[4]++;
                        break;
                    }
                }
            }
        }
    }

    mayor=contador[0];
    for(int i=1; i<tamCom; i++)
    {
        if(contador[i]>mayor)
        {
            mayor=contador[i];
        }
    }

    printf("Comidas favoritas del sector:\n");
    for(int i=0; i<tamCom; i++)
    {
        if(contador[i]==mayor)
        {
            printf(" %s ", aComidas[i].descripcion);
        }
    }
    printf("\n\n");

}

//2) Version Baus
void comidaPreferidaSectorBaus(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int contador[tamCom];
    int idSectorBuscado;
    int mayor=0;
    int indice;
    int flag=1;

    for(int i=0; i<tamCom; i++)
    {
        contador[i]=0;
    }

    mostrarSectores(aSectores,tamSec);
    dam_getNumero(&idSectorBuscado,"Ingrese ID del sector: ","ERROR. ",500,504,0);
    while(buscarSector(aSectores,tamSec,idSectorBuscado)==-1)
    {
        dam_getNumero(&idSectorBuscado,"Ingrese un ID valido: ","ERROR. ",500,504,0);
    }

    for(int i=0; i<tamEmp; i++)
    {
        if(aEmpleados[i].idSector==idSectorBuscado && !aEmpleados[i].isEmpty)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(aAlmuerzos[j].legEmpleado==aEmpleados[i].legajo && !aAlmuerzos[j].isEmpty)
                {
                    indice=buscarComida(aComidas,tamCom,aAlmuerzos[j].idComida);
                    contador[indice]++;
                    /*OTRA OPCION
                    for(int k=0; k<tamCom; k++)
                    {
                        if(aComidas[k].id==aAlmuerzos[j].idComida)
                        {
                            contador[k]++;
                        }
                    }*/
                }
            }
        }
    }

    for(int i=0; i<tamCom; i++)
    {
        if(flag==1 || contador[i]>mayor)
        {
            mayor=contador[i];
            flag=0;
        }
    }

    printf("Comidas favoritas del sector:\n");
    for(int i=0; i<tamCom; i++)
    {
        if(contador[i]==mayor)
        {
            printf(" %s ", aComidas[i].descripcion);
        }
    }
    printf("\n\n");
}

//3) Cual es el sector que más comio de una comida.
void sectorQueMasComioUnaComida(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int idComidaBuscada;
    int mayor;
    int contador[5]={0};

    mostrarComidas(aComidas,tamCom);
    dam_getNumero(&idComidaBuscada,"Ingrese ID: ","ERROR. ",1000,1004,0);
    while(buscarComida(aComidas,tamCom,idComidaBuscada)==-1)
    {
        dam_getNumero(&idComidaBuscada,"Ingrese un ID valido: ","ERROR. ",1000,1004,0);
    }

    for(int i=0; i<tamCom; i++)
    {
        if(aComidas[i].id==idComidaBuscada)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(aAlmuerzos[j].idComida==aComidas[i].id && !aAlmuerzos[j].isEmpty)
                {
                    for(int k=0; k<tamEmp; k++)
                    {
                        if(aAlmuerzos[j].legEmpleado==aEmpleados[k].legajo && !aEmpleados[k].isEmpty)
                        {
                            switch(aEmpleados[k].idSector)
                            {
                            case 500:
                                contador[0]++;
                                break;
                            case 501:
                                contador[1]++;
                                break;
                            case 502:
                                contador[2]++;
                                break;
                            case 503:
                                contador[3]++;
                                break;
                            case 504:
                                contador[4]++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    mayor=contador[0];
    for(int i=1; i<tamCom; i++)
    {
        if(contador[i]>mayor)
        {
            mayor=contador[i];
        }
    }

    printf("Los sectores que mas comieron esa comida fueron:\n");
    for(int i=0; i<tamSec; i++)
    {
        if(contador[i]==mayor)
        {
            printf(" %s ", aSectores[i].descripcion);
        }
    }
    printf("\n\n");
}

//3) Version Baus
//CUANTAS MILANESAS COMIO CADA SECTOR
void sectorAmanteMilanesa(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int contadores[tamSec];
    int idMilanga=1000;
    int mayor;
    int flag=1;

    for(int i=0; i<tamSec; i++)
    {
        contadores[i]=0;
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(!aAlmuerzos[i].isEmpty && aAlmuerzos[i].idComida==idMilanga)
        {
            for(int j=0; j<tamEmp; j++)
            {
                if(!aEmpleados[j].isEmpty && aEmpleados[j].legajo==aAlmuerzos[i].legEmpleado)
                {
                    for(int k=0; k<tamSec; k++)
                    {
                        if(aSectores[k].id==aEmpleados[j].idSector)
                        {
                            contadores[k]++;
                        }
                    }
                }
            }
        }
    }
    //los contadores estan cargados

    for(int i=0; i<tamSec; i++)
    {
        if(flag || contadores[i]>mayor)
        {
            mayor=contadores[i];
            flag=0;
        }
    }

    printf("Sectores milaneseros:\n");
    for(int i=0; i<tamSec; i++)
    {
        if(contadores[i]==mayor)
        {
            printf(" %s ", aSectores[i].descripcion);
        }
    }
    printf("\n\n");
}

//4) Elegir un empleado o varios, una vez que calcula el costo de la comida que se lo descuente del sueldo.
//   Que salte una alarma si los gastos de los almuerzos son más grandes que los sueldos (es porque no tiene dinero para pagar).
void descontarAlmuerzosDeEmpleado(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajoBuscado;
    int indiceEmpleado;
    float sueldoFinal;

    printf("       Descuento de Almuerzos \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajoBuscado,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    indiceEmpleado=buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado);
    while(indiceEmpleado==-1)
    {
        dam_getNumero(&legajoBuscado,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
        indiceEmpleado=buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado);
    }
    sueldoFinal=aEmpleados[indiceEmpleado].sueldo;

    for(int i=0; i<tamAlm; i++)
    {
        if(aAlmuerzos[i].legEmpleado == legajoBuscado && !aAlmuerzos[i].isEmpty)
        {
            for(int j=0; j<tamCom; j++)
            {
                if(aAlmuerzos[i].idComida==aComidas[j].id)
                {
                    sueldoFinal-=aComidas[j].precio;
                }
            }
        }
    }
    if(sueldoFinal>0)
    {
        printf("El sueldo bruto es $ %.2f\n",aEmpleados[indiceEmpleado].sueldo);
        printf("El sueldo descontando los almuerzos es $ %.2f\n",sueldoFinal);
    }
    else
    {
        printf("AVISO: el empleado no gana suficiente para cubrir sus almuerzos!\n");
        printf("Deuda acumulada: $ %.2f\n",sueldoFinal*(-1));
    }
}

//Punto 4 Version Baus
void descontarAlmuerzosDeEmpleadoBaus(eEmpleado aEmpleados[], int tamEmp, eSector aSectores[], int tamSec, eComida aComidas[], int tamCom, eAlmuerzo aAlmuerzos[], int tamAlm)
{
    int legajoBuscado;
    int indice;
    float total;

    printf("       Descuento de Almuerzos \n\n");

    mostrarEmpleados(aEmpleados,tamEmp,aSectores,tamSec);
    dam_getNumero(&legajoBuscado,"Ingrese legajo: ","ERROR. ",20000,29999,0);
    while(buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado)==-1)
    {
        dam_getNumero(&legajoBuscado,"Ingrese un legajo valido: ","ERROR. ",20000,29999,0);
    }

    for(int i=0; i<tamAlm; i++)
    {
        if(!aAlmuerzos[i].isEmpty && aAlmuerzos[i].legEmpleado==legajoBuscado)
        {
            indice=buscarComida(aComidas,tamCom,aAlmuerzos[i].idComida);
            total+=aComidas[indice].precio;
        }
    }

    indice = buscarEmpleadoXLeg(aEmpleados,tamEmp,legajoBuscado);

    if(aEmpleados[indice].sueldo<total)
    {
        printf("El empleado de legajo %d nos debe plata $ %.2f\n",aEmpleados[indice].legajo, aEmpleados[indice].sueldo-total);
    }
    else
    {
        aEmpleados[indice].sueldo-=total;
    }
}
