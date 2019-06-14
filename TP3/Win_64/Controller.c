#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;

    FILE* puntFile = fopen("data.csv","r");

    if(puntFile != NULL)
    {
        ret = parser_EmployeeFromText(puntFile,pArrayListEmployee);
    }

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    int ret = 0;

    FILE* puntFile = fopen("data.csv","rb");

    if(puntFile != NULL)
    {
        ret = parser_EmployeeFromBinary(puntFile,pArrayListEmployee);
    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    char auxId[6];
    char auxNombre[128];
    char auxHorasTrabajadas[9];
    char auxSueldo[7];

    Employee* empleadoNuevo = employee_new();

    printf("**** Alta de empleado *****\n\n");


    while(!function_getStringNumeros("\nIngrese el ID del empleado: ",auxId)) /// ID
    {
        printf("**** ERROR **** El ID debe tener solamente numeros...\n\n");
        system("pause");
    }

    while(!function_getStringLetras("\nIngrese el nombre del empleado: ",auxNombre)) ///NOMBRE
    {
        printf("**** ERROR **** El nombre debe tener solamente letras...\n\n");
        system("pause");
    }

    while(!function_getStringNumeros("\nIngrese la cantidad de horas trabajadas del empleado: ",auxHorasTrabajadas)) /// HS TRABAJADAS
    {
        printf("**** ERROR **** Las horas deben tener solamente numeros...\n\n");
        system("pause");
    }

    while(!function_getStringNumeros("\nIngrese el sueldo del empleado: ",auxSueldo)) /// SUELDO
    {
        printf("**** ERROR **** El sueldo debe tener solamente numeros...\n\n");
        system("pause");
    }

    ///seteamos todos los datos

    employee_setId(empleadoNuevo,atoi(auxId));
    employee_setNombre(empleadoNuevo,auxNombre);
    employee_setHorasTrabajadas(empleadoNuevo,atoi(auxHorasTrabajadas));
    employee_setSueldo(empleadoNuevo,atoi(auxSueldo));
    employee_showEmployee(empleadoNuevo);
    printf("\n\n");
    system("pause");

    ll_add(pArrayListEmployee,empleadoNuevo);

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int ret = 0;
    int id;
    int tam = ll_len(pArrayListEmployee);
    Employee* empl = employee_new();
    char auxId[6];
    char auxNombre[128];
    char auxHorasTrabajadas[9];
    char auxSueldo[7];

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
        for(int i; i < tam; i++)
        {
            empl = (Employee*)ll_get(pArrayListEmployee,i);
            employee_showEmployee(empl);
        }

        while(!function_getStringNumeros("\n\nIngrese el ID del empleado a modificar:",auxId))
        {
            printf("**** ERROR **** El ID debe tener solamente numeros...\n\n");
            system("pause");
        }

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empl = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(empl, &id);

            if(id == atoi(auxId))
            {
                switch(menuModificar())
                {
                case 1:
                    system("cls");
                    printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
                    employee_showEmployee(empl);
                    while(!function_getStringLetras("\nIngrese el nombre del empleado: ",auxNombre)) ///NOMBRE
                    {
                        printf("**** ERROR **** El nombre debe tener solamente letras...\n\n");
                        system("pause");
                    }
                    employee_setNombre(empl,auxNombre);
                    break;

                case 2:
                    system("cls");
                    printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
                    employee_showEmployee(empl);
                    while(!function_getStringNumeros("\nIngrese la cantidad de horas trabajadas del empleado: ",auxHorasTrabajadas)) /// HS TRABAJADAS
                    {
                        printf("**** ERROR **** Las horas deben tener solamente numeros...\n\n");
                        system("pause");
                    }
                    employee_setHorasTrabajadas(empl,atoi(auxHorasTrabajadas));
                    break;

                case 3:
                    system("cls");
                    printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
                    employee_showEmployee(empl);
                    while(!function_getStringNumeros("\nIngrese el sueldo del empleado: ",auxSueldo)) /// SUELDO
                    {
                        printf("**** ERROR **** El sueldo debe tener solamente numeros...\n\n");
                        system("pause");
                    }
                    employee_setSueldo(empl,atoi(auxSueldo));
                    break;
                case 4:
                    printf("\nRegresando...\n");
                    system("pause");
                    break;

                }
                ret = ll_set(pArrayListEmployee, i, empl);
                break;
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }


    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int id;
    int tam = ll_len(pArrayListEmployee);
    Employee* empl = employee_new();
    char auxId[6];

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
        for(int i; i < tam; i++)
        {
            empl = (Employee*)ll_get(pArrayListEmployee,i);
            employee_showEmployee(empl);
        }

        while(!function_getStringNumeros("\n\nIngrese el ID del empleado a BORRAR:",auxId))
        {
            printf("**** ERROR **** El ID debe tener solamente numeros...\n\n");
            system("pause");
        }

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empl = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(empl, &id);

            if(id == atoi(auxId))
            {
                employee_showEmployee(empl);
                ll_remove(pArrayListEmployee,i);
                printf("El empleado ha sido borrado \n\n");
                system("pause");
                ret = 1;
                break;
            }
        }
        if(ret == 0)
        {
            printf("No se encontro el empleado.\n\n");
            system("pause");
        }
    }

return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int ret = 0;
    int tam = ll_len(pArrayListEmployee);
    Employee* empl = employee_new();

    if(pArrayListEmployee != NULL)
    {

        printf("Id\tNombre\tHoras Trab.\tSueldo\n\n");
        for(int i; i < tam; i++)
        {
            empl = (Employee*)ll_get(pArrayListEmployee,i);
            employee_showEmployees(empl);
        }
        ret = 1;
        printf("\n\n");
        system("pause");
    }
    else
    {
        printf("No hay datos\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int ret = 0;
    FILE* pFile;
    pFile = fopen("data.csv", "w");
    Employee* emp;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d,%s,%d,%d",emp->id,emp->nombre,emp->horasTrabajadas, emp->sueldo);
        }
        fclose(pFile);
        ret = 1;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    Employee* emp;

    if(ll_len(pArrayListEmployee)!= 0)
    {
        if(pArrayListEmployee != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListEmployee); i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(emp, sizeof(Employee*), 1, pFile);
            }
            fclose(pFile);
            ret = 1;
        }
        else
        {
            printf("No hay Archivo\n");
            system("pause");
        }
    }
    else
    {
        printf("No hay Datos\n");
    }

    return ret;
}

