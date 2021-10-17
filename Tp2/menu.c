#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

int menu()
{
    int opcion;

    printf("1. ALTAS\n");
    printf("2. MODFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenu()
{
    int opcion;

    printf("1. NOMBRE\n");
    printf("2. APELLIDO\n");
    printf("3. SALARIO\n");
    printf("4. SECTOR\n");
    printf("5. SALIR");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
