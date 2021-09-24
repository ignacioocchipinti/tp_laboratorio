#include "operaciones.h"

int sumar (int a, int b)
{
    int suma;

    suma = a + b;

    return suma;
}

int restar(int a, int b)
{
    int resta;

    resta = a - b;

    return resta;
}

float dividir(int a, int b)
{
    float division;

    division = (float) a / b;

    return division;
}

int multiplicar(int a, int b)
{
    int multiplicacion;

    multiplicacion = a * b;

    return multiplicacion;
}

int factorizarA(int a)
{
    int factorialA = 1;

    if(a >= 0)
    {
        for(int i = factorialA; i <= a; i++)
        {
            factorialA = factorialA * i;
        }
    }
    else
    {
        factorialA = 0;
    }

    return factorialA;
}

int factorizarB(int b)
{
    int factorialB = 1;

    if(b >= 0)
    {
        for(int i = factorialB; i <= b; i++)
        {
            factorialB = factorialB * i;
        }
    }
    else
    {
        factorialB = 0;
    }

    return factorialB;
}





