#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 5;

enum Role {
    MANAGER,
    STAFF,
};

struct Employee {
    int id;
    char name[50];
    enum Role role;
    float salary;
};

bool hasAdminAccess(struct Employee emp) {
    return emp.role == MANAGER ? true : false;
}

int getPayrollSum(struct Employee allEmployees[], int allEmployeesSize) {
    int result;
    
    for (int i = 0; i < allEmployeesSize; i++) {
        result = result + (int) allEmployees[i].salary;
    }
    return result;
}

struct Employee getHighestSalary(struct Employee allEmployees[], int allEmployeesSize) {
    float highestSalary;
    struct Employee *highestSalaryEmployee;

    for (int i = allEmployeesSize - 1; i >= 0; i--) {
        if (allEmployees[i].salary > highestSalary) {
            highestSalary = allEmployees[i].salary;
            highestSalaryEmployee = &allEmployees[i];
        }
    }
    return *highestSalaryEmployee;
}

int main() {
    struct Employee charlotte = {1, "Charlotte", STAFF, 90000.32};
    struct Employee daniel = {2, "Daniel", MANAGER, 120000.50};
    
    struct Employee employees[] = {charlotte, daniel};
    int employeesSize = sizeof(employees) / sizeof(employees[0]);
    for (int i = 0; i < employeesSize; i++) {
        bool canAccess = hasAdminAccess(employees[i]);
        printf("%s can access? %d\n", employees[i].name, canAccess);
    }
    
    printf("Total payroll: %d\n", getPayrollSum(employees, employeesSize));

    struct Employee bestPaidEmployee = getHighestSalary(employees, employeesSize);

    printf("The highest salary employee is %s with a payroll of $%.2f", bestPaidEmployee.name, bestPaidEmployee.salary);

    return 0;
}