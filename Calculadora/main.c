#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    // se declaran las variables a utilizar en el programa
    int salir = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int factorialA,factorialB;
    float A,B,suma,resta,div,multi;

    do
    {
        switch(funcion_menu())
        {
        case 1:

            printf("\n\nInserte el Operador A = ");
            fflush(stdin);
            scanf("%f",&A);
            system("pause");
            system("cls");
            if(A)
            {
                flag1++;
            }

            break;
        case 2:
            fflush(stdin);
            printf("\n\nInserte el Operador B = ");
            scanf("%f",&B);
            if(B)
            {
                flag2++;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flag1 == 0)
            {
                printf("\n\n*Error* No se ingreso el operador A.\n\n");
                system("pause");
                system("cls");
            }
            else if(flag2 == 0)
            {
                printf("\n\n*Error* No se ingreso el operador B.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                suma = funcion_suma(A,B);
                resta = funcion_resta(A,B);
                multi = funcion_multiplicar(A,B);
                if(A >= 0) // se realiza un if para ver si el numero es mayor o igual a 0 para poder realizar el factorial
                {
                factorialA = funcion_factorial(A);
                }
                if(B >= 0)
                {
                factorialB = funcion_factorial(B);
                }

                if(B!=0) // se verifica que el divisor no sea 0
                {
                    div = funcion_dividir(A,B);
                }
                printf("\nCalculando resultados.:.:.:.:.:.:.:.:.:..:.:.:.:.:.:.:.:.:..:.:.:.:.:.:.:.:.:.\n\n");
                flag3++;
                system("pause");
                system("cls");

            }
            break;
        case 4:
            if(flag3 != 0)
            {
                printf("\n\n\t\t\tOperador A = %0.2f",A);
                printf("\t\tOperador B = %0.2f\n\n",B);
                printf("La suma de (A+B) es: %0.2f \n",suma);
                printf("La resta de (A-B) es: %0.2f \n",resta) ;
                printf("La multiplicacion de (A*B) es: %0.2f \n",multi) ;
                if(B == 0)
                {
                    printf("No se puede dividir por 0\n\n");
                }
                else
                {
                    printf("La division de (A/B) es: %0.2f \n",div) ;
                }
                if(A < 0)
                {
                    printf("No se puede calcular el factorial de un numero negativo.\n") ;
                }else
                {
                    printf("El factorial de A es: %d \n",factorialA) ;
                }
                if(B < 0)
                {

                printf("No se puede calcular el factorial de un numero negativo.\n");

                }else
                {
                    printf("El factorial de B es: %d \n",factorialB) ;
                }
                system("pause");
                system("cls") ;
            }else
            {
                printf("\n*Error* No se calcularon los resultados.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 5: // opcion de salir
            printf("\n\n\n**SALIENDO** ") ;
            system("pause") ;
            salir = 1;
            break;
        }
    }
    while(salir == 0) ;

    return 0;
}
