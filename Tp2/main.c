#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

#define TAM 1000

int main()
{
	setbuf(stdout, NULL);
    Employee listaEmp[TAM];
    int flag = 0;
    int nextId = 1000;
    int acumuladorEmpleados = 0;
    char seguir = 's';
    char salir;

    if(initEmployees(listaEmp, TAM))
    {
        printf("INICIALIZACION CORRECTA\n");
    }
    else
    {
        printf("EEROR AL INICIALIZAR\n");
    }

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                if(addEmployee(listaEmp, TAM, &nextId))
                {
                    printf("ALTA EXITOSA");
                    acumuladorEmpleados++;
                    flag = 1;
                }
            break;

            case 2:
                if(!flag)
                {
                    printf("PRIMERO DAR DE ALTA A UN EMPLEADO");
                }
                else
                {
                    if(modifyEmployee(listaEmp, TAM))
                    {
                        printf("ALTA EXITOSA");
                    }
                    else
                    {
                        printf("ERROR AL MODIFICAR");
                    }
                }
            break;

            case 3:
                if(!flag)
                {
                    printf("PRIMERO DAR DE ALTA A UN EMPLEADO");
                }
                else
                {
                    if(removeEmployee(listaEmp, TAM))
                    {
                        printf("BAJA EXITOSA");
                    }
                    else
                    {
                        printf("ERROR AL DAR DE BAJA");
                    }
                }
            break;

            case 4:
                if(!flag)
                {
                    printf("PRIMERO DAR DE ALTA A UN EMPLEADO");
                }
                else
                {
                    if(totalAndPromedio(listaEmp, TAM, acumuladorEmpleados))
                    {
                        printf("OK");
                    }
                    else
                    {
                        printf("ERROR");
                    }
                }
            break;

            case 5:
                printf("Desea salir? (s - n)");
                scanf("%c", &salir);
                if(salir == 's')
                {
                    seguir = 'n';
                }
            break;

            default:
                printf("Opcion incorrecta");
            break;
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}


