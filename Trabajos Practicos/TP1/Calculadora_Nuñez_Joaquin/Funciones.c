#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

float funcion_suma(float a, float b)

{
    float resSuma;
    resSuma = a + b;
    return resSuma;
};

float funcion_resta(float a,float b)
{
    float resResta;
    resResta= a - b;
    return resResta;

};
float funcion_multiplicar(float a,float b)
{
    float resMultiplicacion;
    resMultiplicacion= a * b;
    return resMultiplicacion;

};
float funcion_dividir(float a,float b)
{
    float resDivision;

    if(b ==0)
    {

        return -1;

    }
    else
    {
        resDivision=a/b;
        return resDivision;
    }


};
int funcion_factorial(int a)
{
    int valor;
    if(a==0)
    {
        return 1;
    }
    valor=a*funcion_factorial(a-1);
    return valor;
};


void funcion_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}


int funcion_getStringNumeros(char mensaje[],char input[])
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
        if ((str[i] == '.' && cantidadPuntos == 0)|| str[i] == '-')
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


int funcion_getStringNumerosFlotantes(char mensaje[],char input[])
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

int menu()
{
    int opcion;
    char auxiliarOpcion[4];

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Ingrese 1er operando\n");
    printf(" 2- Ingrese 2do operando\n");
    printf(" 3- Calcular todas las operaciones\n");
    printf(" 4- Informar resultados\n");
    printf(" 5- Salir\n");

    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxiliarOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
        system("cls");
    }


    opcion=atoi(auxiliarOpcion);


    return opcion;
}

