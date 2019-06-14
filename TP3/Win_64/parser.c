#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int ret = 0;
    int r;
    char a[50];
    char b[50];
    char c[50];
    char d[50];

    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        printf("El archivo no existe\n");
        system("pause");
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]",a,b,c,d);
        if(r==4)
        {
            Employee* auxEmployee = employee_new();
            employee_setId(auxEmployee,atoi(a));
            employee_setNombre(auxEmployee,b);
            employee_setHorasTrabajadas(auxEmployee,atoi(c));
            employee_setSueldo(auxEmployee,atoi(d));
            ll_add(pArrayListEmployee,auxEmployee);
            ret = 1;
        }
        break;
    }
    while(!feof(pFile));


    fclose(pFile);
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int ret = 0;
    int r;
    char a[50];
    char b[50];
    char c[50];
    char d[50];

    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        printf("El archivo no existe\n");
        system("pause");
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]",a,b,c,d);
        if(r==4)
        {
            Employee* auxEmployee = employee_new();
            employee_setId(auxEmployee,atoi(a));
            employee_setNombre(auxEmployee,b);
            employee_setHorasTrabajadas(auxEmployee,atoi(c));
            employee_setSueldo(auxEmployee,atoi(d));
            ll_add(pArrayListEmployee,auxEmployee);
            ret = 1;
        }
        break;
    }
    while(!feof(pFile));


    fclose(pFile);

    return ret;
}
