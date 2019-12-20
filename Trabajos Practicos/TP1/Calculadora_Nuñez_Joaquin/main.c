#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

#define MAX 99999

int main()
{
    //SE DECLARAN LAS VARIABLES QUE SE USARAN PARA EL DESAROLLO DEL PROGAMA
    char seguir = 's';
    char auxOperandoA[MAX];
    char auxOperandoB[MAX];
    float operandoA;
    float operandoB;
    float suma,resta,multi,division,factorialA,factorialB;
    int flagOperadorA=0;
    int flagOperadorB=0;
    int flagSinCalcular=0;
    int ret = 0;


    do
    {
        //UTILIZO UN SWITCH PARA DESAROLLAR LAS OPCIONES MULTIPLES.
        switch(menu())
        {
        //EN ESTE CASO PIDO EL VALOR DEL OPEANDO A Y VALIDO QUE SEA NUMERO
        case 1:
            while(!funcion_getStringNumerosFlotantes("Ingrese una operando A : ",auxOperandoA))
            {
                printf("ERROR- La opcion tiene que ser solo numeros\n\n");
                system("pause");

            }
            operandoA=atof(auxOperandoA);
            flagOperadorA=1;
            break;

        //EN ESTE CASO PIDO EL VALOR DEL OPEANDO B Y VALIDO QUE SEA NUMERO
        case 2:
            if(flagOperadorA == 1)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese una operando B : ",auxOperandoB))
                {
                    printf("ERROR- La opcion tiene que ser solo numeros\n\n");
                    system("pause");

                }
                operandoB=atof(auxOperandoB);
                flagOperadorB++;


            }
            else
            {
                printf("\nNo ingreso operando A, por favor ingrese nuevamente\n");
            }

            break;
        //EN ESTE CASO SE CALCULAN TODAS LAS OPERACIONES Y SE VALIDA QUE HAYAN INGRESADO LOS VALORES
        case 3:
            if(flagOperadorA == 0)
            {
                printf("\n\n*Error* No se ingreso el operador A.\n\n");
                system("pause");
                system("cls");
            }
            else if(flagOperadorB == 0)
            {
                printf("\n\n*Error* No se ingreso el operador B.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                suma = funcion_suma(operandoA,operandoB);
                resta = funcion_resta(operandoA,operandoB);
                multi = funcion_multiplicar(operandoA,operandoB);
                if(operandoA >= 0) // se realiza un if para ver si el numero es mayor o igual a 0 para poder realizar el factorial
                {
                factorialA = funcion_factorial(operandoA);
                }
                if(operandoB >= 0)
                {
                factorialB = funcion_factorial(operandoB);
                }

               if(operandoB!=0) // se verifica que el divisor no sea 0
                {
                    division = funcion_dividir(operandoA,operandoB);
                }
                printf("\nSe han calculado los resultados.\n\n");
                flagSinCalcular++;
                system("pause");
                system("cls");

            }
            break;
        //EN ESTE CASO SE INFORMA SOBRE LOS RESULTADOS DE LAS OPERACIONES O MUESTRA UN ERROR SI NO SE CALCULARON
        case 4:
            if(flagSinCalcular == 1)
            {

                printf("\nA:%0.2f\n",operandoA);
                printf("\nB:%0.2f\n",operandoB);
                printf("\nLa suma es: %0.2f",suma);
                printf("\nLa resta es: %0.2f",resta);
                printf("\nLa multiplicacion es: %0.2f",multi);
                printf("\nLa division es: %0.2f",division);

                printf("\nLa factorial de A es: %0.0f",factorialA);
                printf("\nLa factorial de B es: %0.0f\n\n",factorialB);
                system("pause");
            }
            else
            {
                printf("\nNo resolvio las operaciones \n");

            }
            break;
        //EN ESTE CASO SALE DE LA CALCULADORA
        case 5:
            printf("Saliendo...");
            printf("\n\n");
            seguir = 'n';
            ret = -1;
            break;
        default:

            printf("Opcion invalida, ingrese un numero del uno al 5. \n") ;
            system("pause");

        }
    }
    while(seguir == 's');

    return ret;
}
