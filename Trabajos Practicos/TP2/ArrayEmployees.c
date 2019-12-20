#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Funciones.h"

#define tam 1001

int initEmployees(eEmployee list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};
int findEmpty(eEmployee list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findEmployee(eEmployee list[],int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewEmployee(eEmployee aEmployee)
{

    printf(" \n%d %s %s %.2f %d \n ", aEmployee.id, aEmployee.name, aEmployee.lastName, aEmployee.salary, aEmployee.sector);
};

void viewEmployees(eEmployee list[], int len)
{
    printf(" ID NOMBRE APELLIDO SALARIO SECTOR \n\n");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewEmployee(list[i]);
        }
    }

};
int addEmployee(eEmployee list[], int len)

{
    eEmployee newEmployee;

    int index;
    char auxName[31];
    char auxLastName[31];
    char auxSalary[10];
    char auxSector[10];
    int ret;

    int nombre=0,apellido=0,salario=0,sector=0;

    if(list != NULL)
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("\t\t*** ALTA EMPLEADO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Empleado Nuevo, su ID es : %d \n",index);
            newEmployee.id = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("\nIngrese Nombre: ", auxName))
                {
                    printf("\nERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("\nIngrese Apellido: ", auxLastName))
                {
                    printf("\nERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n\n",auxName,auxLastName);
            if(salario == 0)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ", auxSalary))
                {
                    printf("\nERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
                    salario=1;
                };
                salario=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s \n",auxName,auxLastName,auxSalary);
            if(sector == 0)
            {
                while(!funcion_getStringNumeros("Ingrese Sector: ", auxSector))
                {
                    printf("\nERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxSalary);
                    sector=1;
                };
                sector=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Sector %s \n\n",auxName,auxLastName,auxSalary,auxSector);
            while((nombre == 1) && (apellido == 1) && (salario == 1) && (sector == 1) )
            {
                strcpy(newEmployee.name,auxName);
                strcpy(newEmployee.lastName,auxLastName);
                newEmployee.sector = atoi(auxSector);
                newEmployee.salary = atof(auxSalary);
                newEmployee.isEmpty=0;
                list[index] = newEmployee ;
                system("cls");
                printf("\n\n********NUEVO EMPLEADO, BIENVENIDO*********\n\n");
                viewEmployee(list[index]);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};

int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA\n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA\n");
    printf(" 4- INFORMAR\n");
    printf(" 5- REPORTES\n");
    printf(" 6- SALIR\n ");
    while(!funcion_getStringNumeros("\n\nIngrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n\t\t******* Modificar empleado *******");
    printf("\n 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- SUELDO \n");
    printf(" 4- SECTOR \n");
    printf(" 5- VOLVER \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int removeEmployee(eEmployee* list, int len)
{

    int index;
    int ret;
    char next[3];
    int id;
    char auxId[4];

    system("cls");
    printf("\t\t*** BAJA EMPLEADO ***\n\n");

    viewEmployees(list,len);
    while(!funcion_getStringNumeros("\n\nIngrese ID del empleado a borrar: ", auxId))
    {
        printf("\nERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == -1)
    {
        printf("\nNO HAY NINGUN EMPLEADO CON ESE ID %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un ID existente: ", auxId))
        {
            printf("\nERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }

    viewEmployee(list[index]);

    while(!funcion_getStringNumeros("\nIngrese 1 si quiere borrar el usuario / Ingrese 2 si NO quiere borrar el usuario: ",next))
    {
        printf("\n ERROR DEBE CONTENER SOLO NUMEROS\n");
        system("pause");
    }

    fflush(stdin);
    if(atoi(next) == 2)
    {
        printf("\nNO SE REALIZO LA BAJA\n\n");
        ret = 1;

    }else if(atoi(next) == 1)
    {

        list[index].isEmpty = 1;
        printf("\nSE HIZO LA BAJA DEL EMPLEADO CORRECTAMENTE\n\n");
        system("pause");
        ret = 1;


    }else
    {
        printf("\nDebe ingresar 1 o 2. ***ERROR***\n");
        system("pause");
        ret = 0;

    }

    return ret;

}


void modifyEmployee(eEmployee list[], int len)
{
    int id;
    char auxId[5];
    int index;
    char newSalary[10];
    char newSector[3];
    char newName[31];
    char newLastName[31];
    char seguir='s';

    system("cls");
    printf("\t\t*** Modificar  empleado ***\n\n");
    viewEmployees(list,len);

    while(!funcion_getStringNumeros("\nIngrese ID: ", auxId))
    {
        printf("\nERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == -1)
    {
        printf("\nNO HAY NINGUN EMPLEADO CON ESE ID %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un ID existente: ", auxId))
        {
            printf("\nERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }


    do
    {
        switch (funcion_opcionesModificacion())
        {
        case 1:
            fflush(stdin);
            viewEmployee(list[index]);

            while(!funcion_getStringLetras("\nIngrese nombre nuevo: ", newName))
            {
                printf("\nERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                system("pause");
                system("cls");
            };
            strcpy(list[index].name,newName);
            break;
        case 2:
            fflush(stdin);
            viewEmployee(list[index]);
            while(!funcion_getStringLetras("\nIngrese apellido nuevo: ",newLastName))
            {
                printf("\nERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                system("pause");
                system("cls");
            };
            strcpy(list[index].lastName,newLastName);

            break;
        case 3:
            fflush(stdin);
            viewEmployee(list[index]);

            while(!funcion_getStringNumerosFlotantes("\nIngrese Salario: ", newSalary))
            {
                printf("\nERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                system("pause");
                system("cls");

            };

            list[index].salary = atof(newSalary);
            break;
        case 4:
            fflush(stdin);
            viewEmployee(list[index]);
            while(!funcion_getStringNumeros("\nIngrese sector nuevo: ", newSector))
            {
                printf("\nERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                system("pause");
                system("cls");
            };
            list[index].sector=atoi(newSector);
            break;
        case 5:
            printf("\nVolviendo a menu principal...\n\n");
            system("pause");
            seguir = 'n';
            break;
        default:
            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
            system("pause");
            break;


        }

    }
    while (seguir == 's');


}




void harcodeoEmpleados(eEmployee* list)
{

    eEmployee x[]=
    {
        {0,"Juan Roman", "Riquelme",23.00,2,0},
        {1,"Martin", "Palermo",30.00,1,0},
        {2,"Joaquin", "Nunez",90.00,2,0},
        {3,"Manuel", "Ginobilli",42.00,2,0},
        {4,"Hugo", "Pozo",8.00,2,0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
};

int sortEmployees(eEmployee list[], int len)
{
    eEmployee auxEmployee;
    char auxOrder[1] ;
    int ret,order;


    if(list != NULL && len > 0)
    {
        while(!funcion_getStringNumeros("\n Ingrese 1 para ordenar Apellido de forma ascendente o ingrese 2 para ordenar de forma descendente: ",auxOrder))
        {
            printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

        }
        order = atoi(auxOrder);
        switch(order)
        {
        case 1:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            printf("\n\nSe ordeno correctamente.\n");
            system("pause") ;
            system("cls") ;
            break;
        case 2:
            for(int i = 0; i < len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }

            system("pause") ;
            system("cls") ;
            break;
        default:
            printf("No ingreso 1 o 2");
        }

    }
    else
    {
        ret = -1;
    }


    return ret;

};

void reports (eEmployee list[],int len)
{
    float acum=0.00;
    float promedio=0.00;
    float contador=0.00;
    int contSuperan=0.00;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acum = acum + list[i].salary;
            contador++;
        }
    }

    promedio = funcion_Division(acum,contador);

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > promedio)
        {
            contSuperan++;
        }
    }

    printf("\nEl total de todos los salarios es de: %.2f \nEl promedio de los salarios es: %.2f \nLa cantidad de empleados que superan el promedio es de: %d\n\n",acum,promedio,contSuperan);

}








