#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int funcion_menu()
{
        int opcion ;

        printf("\n \t\t.: Calculadora :. \n") ;
        printf("1 - Ingresar el primer operando(A = X) \n") ;
        printf("2 - Ingresar el segundo operando(B = X) \n") ;
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

void funcion_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

int funcion_getStringInt(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_ValidarNumero(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int funcion_ValidarNumero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
};


int funcion_validarNumeroFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0 || str[i] == '-')
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9' )
       {
           return 0;
       }
       i++;
   }
   return 1;
}


int funcion_getStringFloat(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
