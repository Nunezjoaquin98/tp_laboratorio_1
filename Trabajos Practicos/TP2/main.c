#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "Funciones.h"

#define tam 1001


int funcion_opciones();

int main()
{
    char seguir ='s';
    eEmployee employee[tam];
    initEmployees(employee,tam);
    int flagSinAlta=0;
    int ret = 0;

    //harcodeoEmpleados(employee);

    do
    {

        switch (funcion_opciones())
        {
        case 1:
            addEmployee(employee, tam);
            flagSinAlta++;
            break;
        case 2:
            if (flagSinAlta == 0)
            {
                printf("\nNo hay ningun empleado cargado en el sistema.\n\n");
                system("pause");
                break;
            }
            else
            {
                modifyEmployee(employee, tam);
            }
            break;
        case 3:
            if (flagSinAlta == 0)
            {
                printf("\nNo hay ningun empleado cargado en el sistema.\n\n");
                system("pause");
                break;
            }
            else
            {
                removeEmployee(employee, tam);
            }
            break;
        case 4:
            if (flagSinAlta == 0)
            {
                printf("\nNo hay ningun empleado cargado en el sistema.\n\n");
                system("pause");
                break;
            }
            else
            {
                sortEmployees(employee, tam);
                viewEmployees(employee, tam);
                printf("\n\n");
                system("pause");
            };

            break;
        case 5:
            if (flagSinAlta == 0)
            {
                printf("\nNo hay ningun empleado cargado en el sistema.\n\n");
                system("pause");
                break;
            }
            else
            {
                reports(employee,tam);
                printf("\n\n");
                system("pause");
            };
            break;
        case 6:
            printf("\nSaliendo...\n");
            seguir = 'n';
            ret = -1;
            break;
        default:
            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
            system("pause");
            break;

        }
    }
    while (seguir == 's');

    return ret;
}
