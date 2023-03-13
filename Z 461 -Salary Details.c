#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[55];
    int salary;
};

// Helper function to compare two employees
int cmp(const void *a, const void *b) {
    const struct Employee *emp1 = (const struct Employee *) a;
    const struct Employee *emp2 = (const struct Employee *) b;
    
    if (emp1->salary == emp2->salary) {
        return strcmp(emp1->name, emp2->name);
    }
    
    return emp1->salary - emp2->salary;
}

// Function to sort employees and print them in the required format
void sort_employees(struct Employee *employees, int n) {
    qsort(employees, n, sizeof(struct Employee), cmp);
    
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", employees[i].name, employees[i].salary);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Employee employees[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%s%d", employees[i].name, &employees[i].salary);
    }
    
    sort_employees(employees, n);
    
    return 0;
}

