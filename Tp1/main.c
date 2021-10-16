#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int menu(int a, int b);
int realizarOperaciones(int a, int b);
void mostrarResultados(int a, int b);

int main()
{
	setbuf(stdout, NULL);
    int operandoUno = 0;
    int operandoDos = 0;
    int flagSalir = 1;
    int flagOpcionUno = 0;
    int flagOpcionDos = 0;
    int flagOpcionTres = 0;
    int flagOpcionCuatro = 0;

    do
    {
        switch(menu(operandoUno, operandoDos))
        {
            case 1:
                printf("\n1er operando: ");
                fflush(stdin);
                scanf("%d", &operandoUno);
                flagOpcionUno = 1;
                break;

            case 2:
                printf("\n2do operando: ");
                fflush(stdin);
                scanf("%d", &operandoDos);
                flagOpcionDos = 1;
                break;

            case 3:
                if (flagOpcionUno == 0)
                {
                    printf("El 1er operando no ha sido cargado\n");
                }
                else
                {
                    if(flagOpcionDos == 0)
                    {
                        printf("El 2do operando no ha sido cargado\n");
                    }
                    else
                    {
                        realizarOperaciones(operandoUno, operandoDos);
                        printf("\nCalculos realizados!\n");
                        flagOpcionTres = 1;
                        break;
                    }
                }
                break;

            case 4:
                if(flagOpcionTres == 0)
                {
                    printf("No es posible mostrar los resultados porque las operaciones no han sido realizadas\n");
                }
                else
                {
                    mostrarResultados(operandoUno, operandoDos);
                    flagOpcionCuatro = 1;
                }
                break;

            case 5:
                flagSalir = 0;
                break;

            default:
                printf("Opcion invalida.\n");

        }
        system("pause");
    }
    while(flagSalir == 1);
    return 0;
}

int menu(int a, int b)
{
    int opcionMenu;

    system("cls");
    printf("\n1. Ingresar 1er operando\n");
    printf("2. Ingresar 2do operando\n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
    printf("1er operando: %d\n", a);
    printf("2do operando: %d\n\n", b);
    printf("Ingresar opcion: ");
    fflush(stdin);
    scanf("%d", &opcionMenu);

    return opcionMenu;
}

int realizarOperaciones(int a, int b)
{
    sumar(a, b);
    restar(a, b);
    dividir(a, b);
    multiplicar(a, b);
    factorizarA(a);
    factorizarB(b);
}

void mostrarResultados(int a, int b)
{
    printf("\nEl resultado de %d + %d es: %d\n", a, b, sumar(a, b));

    printf("El resultado de %d - %d es: %d\n", a, b, restar(a, b));
    if (b == 0)
    {
        printf("No es posible dividir por 0\n");
    }
    else
    {
        printf("El resultado de %d / %d es: %.2f\n", a, b, dividir(a, b));
    }

    printf("El resultado de %d * %d es: %d\n", a, b, multiplicar(a, b));

    if (a == 0)
    {
        printf("No es posible realizar la factorizacion del 1er operando");
    }
    else
    {
        printf("El factorial de %d es: %d\n", a, factorizarA(a));
    }

    if (b == 0)
    {
        printf("No es posible realizar la factorizacion del 2do operando");
    }
    else
    {
        printf("El factorial de %d es: %d\n", b, factorizarB(b));
    }

}









