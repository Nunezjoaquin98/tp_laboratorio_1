#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int funcion_menu(float A,float B)
{
        int opcion ;

        printf("\n \t\t.: Calculadora :. \n") ;
        printf("1 - Ingresar el primer operando(A = %.2f) \n",A) ;
        printf("2 - Ingresar el segundo operando(B = %.2f) \n",B) ;
        printf("3 - Calcular las operaciones.\n") ;
        printf("4 - Informar los resultados. \n") ;
        printf("5 - SALIR. \n\n") ;
        printf("Que operacion desea realizar? (1|2|3|4|5): ") ;
        fflush(stdin) ;
        scanf("%d",&opcion) ;

        return opcion;
}

float funcion_suma(float opc1,float opc2)
{

    float resp ;
    resp = opc1 + opc2 ;
    return resp ;
}

float funcion_resta(float opc1,float opc2)
{

    float resp;
    resp=opc1-opc2 ;
    return resp ;
}

float funcion_multiplicar(float opc1,float opc2)
{

    float resp ;
    resp=opc1*opc2 ;
    return resp ;
}

float funcion_dividir(float opc1,float opc2)
{

    float resp ;
    if(opc2 == 0)
    {

        return -1 ;
    }
    else
    {
        resp=opc1/opc2 ;
        return resp ;
    }
}

int funcion_factorial(int opc1)
{
    int resp;
    if(opc1==0)
    {
        return 1;
    }

    resp=opc1*funcion_factorial(opc1-1) ;
    return resp ;
}
