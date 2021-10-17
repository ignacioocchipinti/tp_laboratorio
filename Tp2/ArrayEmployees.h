#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED

void printEmployee(Employee employee);

void printEmployees(Employee list[], int len);

int initEmployees(Employee list[], int len);

int findEmptyEmployee(Employee list[], int len);

int findEmployeeById(Employee list[], int len, int id);

int addEmployee(Employee list[], int len, int* pId);

int removeEmployee(Employee list[], int len);

int modifyEmployee(Employee list[], int len);

int sortEmployees(Employee list[], int len, int order);

int totalAndPromedio(Employee lista[], int len, int acumuladorEmpleados);
