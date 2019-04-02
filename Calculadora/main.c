#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    int opcion;
    int flag1 = 0 ;
    int flag2 = 0 ;
    int flag3= 0;
    float num1,num2,suma,resta,multi,div,factorial,factorial2 ;
    char auxNum1[7],auxNum2[7];


    do
    {

        // Se utilza un switch para realizar cada opcion de la calculadora en cada case.
        switch(funcion_menu())  // se utiliza funcion menu para que muestre las opciones.
        {

        case 1: // se pide el ingreso del operando A.
            while(!(funcion_getStringFloat("Ingrese el primer operador:\nA: ",auxNum1)))
            {
                printf("**Eror** / Debe ingresar un numero.");
                system("pause");

            }
            num1 = atof(auxNum1);
            if(num1)
            {
                flag1++;
            }
            break;
        case 2: // se pide el ingreso de B
            while(!(funcion_getStringFloat("Ingrese el primer operador:\nB: ",auxNum2)))
            {
                printf("**Eror** / Debe ingresar un numero.");
                system("pause");
            }
            num2 = atof(auxNum2);
            if(num2)
            {
                flag2++;
            }
            break;
        case 3: // Calculo los resultados y se valida que haya puesto un valor en a y en b
            if(flag1 == 0 )
            {
                printf("ERROR / No se ingreso ningun numero en el valor A.") ;
            }
            else if(flag2 == 0)
            {
                printf("ERROR / No se ingreso ningun numero en el valor B.") ;
            }
            else
            {
                suma=funcion_suma(num1,num2);
                resta=funcion_resta(num1,num2);
                multi=funcion_multiplicar(num1,num2);
                div=funcion_dividir(num1,num2);
                /*factorial=funcion_factorial(num1);
                factorial2=funcion_factorial(num2); */
                printf(">>>>>>>>>>>>>> CALCULANDO RESULTADOS <<<<<<<<<<<<<<");
            }
            flag3++;
            break;
        case 4: // se muestran los resultados y se limpia la pantalla.


            if(flag3== 0)
            {
                printf("Error / No calculo los resultados.");
                system("pause");
                system("cls") ;
                break;
            }
            else
            {
                printf("La suma de (A+B) es: %0.2f \n",suma);
                printf("La resta de (A-B) es: %0.2f \n",resta) ;
                printf("La multiplicacion de (A*B) es: %0.2f \n",multi) ;
                if(num2 == 0)
                {
                    printf("No se puede dividir por 0");
                }
                else
                {
                    printf("La division de (A/B) es: %0.2f \n",div) ;
                }
                //    printf("El factorial de A es: %0.2f \n",factorial);
                //   printf("El factorial de B es: %0.2f \n",factorial2) ;
                system("pause");
                system("cls") ;
                break;
            }

        case 5:
            printf("\n Saliendo \n") ;
            system("pause") ;
            opcion = 5 ;
            break;

        default:

            printf("Opcion invalida, ingrese un numero del uno al cinco. \n") ;
            system("pause");
            system("cls");


        }


    }
    while(opcion !=5) ;
}
