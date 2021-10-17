#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

void printEmployee(Employee employee)
{
    printf("%4d %10s %10s %.2f %d", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

void printEmployees(Employee list[], int len)
{
    int flag = 0;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("LISTA DE EMPLEADOS\n\n");
        printf("ID      NOMBRE      APELLIDO        SALARIO     SECTOR\n\n");

        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
                flag = 1;
            }
        }
        if(flag)
        {
            printf("No hay ningun empleado cargado en el sistema");
        }
    }
}

int initEmployees(Employee list[], int len)
{
    int allOk = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            allOk = 1;
        }
    }

    return allOk;
}

int findEmptyEmployee(Employee list[], int len)
{
    int indice = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i > len; i++)
        {
            if(list[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        indice = 1;
    }

    return indice;
}

int findEmployeeById(Employee list[], int len, int id)
{
    int indice = -1;

    if(list != NULL && (len && id) > 0)
    {
        for(int i = 0; i > len; i++)
        {
            if(!list[i].isEmpty && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int addEmployee(Employee list[], int len, int* pId)
{
    Employee newEmp;
    int allOk;
    int indice;

    if(list != NULL && len > 0 && pId > 0)
    {
        allOk = 0;
        system("cls");
        printf("ALTA EMPLEADO\n");
        indice = findEmptyEmployee(list, len);

        if(indice != -1)
        {
            newEmp.id = *pId;

            printf("Ingrese nombre: \n");
            gets(newEmp.name);
            printf("Ingrese apellido: \n");
            gets(newEmp.lastName);
            printf("Ingrese salario: \n");
            scanf("%f", newEmp.salary);
            printf("Ingrese sector: \n");
            gets(newEmp.sector);

            newEmp.isEmpty = 0;

            list[indice] = newEmp;
            *pId++;

            allOk = 1;
        }
        else
        {
            printf("Ya no hay lugar.");
        }
    }

    return allOk;
}

int removeEmployee(Employee list[], int len)
{
    int allOk = 0;
    int id;
    int indice;
    char confirmBaja;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("DAR DE BAJA EMPLEADO");
        printEmployees(list, len);
        print("\n\n");
        printf("Ingrese el ID: ");
        scanf("%d", &id);
        indice = findEmployeeById(list, len, id);

        if(indice != -1)
        {
            printEmployee(list[indice]);
            printf("Confirmar baja: (s - n)");
            scanf("%c", &confirmBaja);
            while(confirmBaja != 's' && confirmBaja != 'n')
            {
                printf("Confirmar baja: (s - n)");
                scanf("%c", &confirmBaja);
            }
            if(confirmBaja == 's')
            {
                list[indice].isEmpty = 1;
                allOk = 1;
            }
            else
            {
                printf("Baja cancelada");
            }


        }
    }

    return allOk;
}

int modifyEmployee(Employee list[], int len)
{
    int allOk = 0;
    int id;
    int indice;
    char confirmModification;
    char confirmSalida;
    char seguir = 's';
    Employee newName;
    Employee newLastName;
    Employee newSalary;
    Employee newSector;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("MODIFICAR EMPLEADO");
        printEmployees(list, len);
        print("\n\n");
        printf("Ingrese el ID: ");
        scanf("%d", &id);
        indice = findEmployeeById(list, len, id);

        if(indice != -1)
        {
            do
            {
                printEmployee(list[indice]);
                switch(subMenu())
                {
                case 1:
                    printf("Ingresar nuevo nombre: ");
                    gets(newName.name);
                    printf("Confirmar modificacion: (s - n)");
                    scanf("%c", &confirmModification);
                    if(confirmModification == 's')
                    {
                        strcpy(list[indice].name, newName.name);
                        printf("Modificacion exitosa");
                    }
                    else
                    {
                        printf("ERROR AL MODIFICAR");
                    }
                    break;

                case 2:
                    printf("Ingresar nuevo apellido: ");
                    gets(newLastName.lastName);
                    printf("Confirmar modificacion: (s - n)");
                    scanf("%c", &confirmModification);
                    if(confirmModification == 's')
                    {
                        strcpy(list[indice].lastName, newLastName.lastName);
                        printf("Modificacion exitosa");
                    }
                    else
                    {
                        printf("ERROR AL MODIFICAR");
                    }
                    break;

                case 3:
                    printf("Ingresar nuevo salario: ");
                    scanf("%d", &newSalary.salary);
                    printf("Confirmar modificacion: (s - n)");
                    scanf("%c", &confirmModification);
                    if(confirmModification == 's')
                    {
                        list[indice].salary = newSalary.salary;
                        printf("Modificacion exitosa");
                    }
                    else
                    {
                        printf("ERROR AL MODIFICAR");
                    }
                    break;

                case 4:
                    printf("Ingresar nuevo sector: ");
                    gets(newSector.sector);
                    printf("Confirmar modificacion: (s - n)");
                    scanf("%c", &confirmModification);
                    if(confirmModification == 's')
                    {
                        strcpy(list[indice].sector, newSector.sector);
                        printf("Modificacion exitosa");
                    }
                    else
                    {
                        printf("ERROR AL MODIFICAR");
                    }
                    break;

                case 5:
                    printf("Desea salir? ");
                    scanf("%c", &confirmSalida);
                    if(confirmSalida == 'n')
                    {
                        seguir = 'n';
                    }
                    break;

                default:
                    printf("Opcion incorrecta");
                    break;
                }
                allOk = 1;
                system("pause");
            }
            while(seguir == 's');
        }
    }

    return allOk;
}

int sortEmployees(Employee list[], int len, int order)
{
    int allOk = 0;
    Employee auxEmp;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if((strcmp(list[i].lastName, list[j].lastName) > 0) && list[i].sector > list[j].sector)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }
            }
        }

        allOk = 1;
    }

    return allOk;
}


int totalAndPromedio(Employee lista[], int len, int acumuladorEmpleados)
{
    int allOk = 0;
    int counter = 0;
    float total = 0;
    float promedio;

    if(lista != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                total+=lista[i].salary;
            }
        }

        promedio = (float) total / acumuladorEmpleados;

        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].salary > promedio)
            {
                counter++;
            }
        }

        if(acumuladorEmpleados > 0)
        {
            sortEmployees(lista, len, 1);
            printEmployees(lista, len);
            printf("\n\n");
            printf("Total salary: $%.2f \n", total);
            printf("Promedio: %.2f \n", promedio);
            printf("Employees exceed promedio salary: %d \n", counter);
        }
        else
        {
            sortEmployees(lista, len, 1);
            printEmployees(lista, len);
            printf("\n\n");
            printf("Total salary: 0 \n");
            printf("Promedio: 0 \n");
        }


        allOk = 1;
    }

    return allOk;
}

