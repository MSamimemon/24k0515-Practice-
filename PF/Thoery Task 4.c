#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct 
{
    int *rating;
    int totalscore;
}employee;
void inputEmployee(employee* employees, int numemployee, int numperiods){
    for (int  i = 0; i < numemployee; i++)
    {
        printf("Enter the ratings for employee  %d: \n", i+1);

        employees[i].rating=(int *)calloc(numperiods,sizeof(int));
        employees[i].totalscore=0;

        for (int  j = 0; j < numperiods; j++)
        {
            do
            {
                printf(" Period%d\n", j+1);
                scanf("%d", &employees[i].rating[j]);
                if (employees[i].rating[j]>1 || employees[i].rating<=10)
                {
                    printf("Invalid Rating. Please enter a value between 1 and 10\n");
                }
                
            } while (employees[i].totalscore<1 || employees[i].totalscore>10);
            employees[i].totalscore+= employees[i].rating[j];

        }
        
    }
    
}
void displayperformance(employee* employees, int numemployee, int numperiod){
    printf("\n Performance Rating\n");
    for (int  i = 0; i <numemployee ; i++)
    {
        for (int  j = 0; j < numperiod; j++)
        {
            printf("%d ", employees[i].rating[j]);

        }
        printf("\n");
        
    }
    
}
int  findhighestoftheyear(employee* employees, int numemployee, int numperiods){
    int bestemployee=0;
    double highestaverage=0;
    for (int i = 0; i < numemployee; i++)
    {
        double average= employees[i].totalscore/numperiods;
        if (average>highestaverage)
        {
            highestaverage=average;
            bestemployee=i;
        }
        
    }
    return bestemployee;
}
int  findworstoftheyear(employee* employees, int numemployee, int numperiods){
    int worstemployee=0;
    double lowestaverage= INT_MAX;
    for (int i = 0; i < numemployee; i++)
    {
        double average= employees[i].totalscore/numperiods;
        if (average>lowestaverage)
        {
            lowestaverage=average;
            worstemployee=i;
        }
        
    }
    return worstemployee;
}
void freeMemory(employee* employees, int numemployee) {
    for (int i = 0; i < numemployee; i++) {
        free(employees[i].rating);
    }
    free(employees);
}

int main(){
    int numemployee, numperiods;
    printf("Enter the number of employees: \n");
    scanf("%d", &numemployee);

    employee* employees=(employee*)calloc(numemployee,sizeof(employee));
    inputEmployee(employees, numemployee, numperiods);
    displayperformance(employees, numemployee, numperiods);
    int bestemployee= findemployeeoftheyear(employees, numemployee, numperiods);
    printf("Employee of the year: Employee %d\n", bestemployee+1);
    int highestrate= findhighestoftheyear(employees, numemployee, numperiods);
    printf("Highest rated Period: Period %d", highestrate+1);
    int worst= findworstoftheyear(employees, numemployee, numperiods);
    printf("Worst Performing Employee: Employee %d\n", worst+1);
    
    freeMemory(employees,numemployee);
    
    return 0;
}