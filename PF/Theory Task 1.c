#include <stdio.h>
typedef struct Employeedetails
{
    int employeecode;
    char employeename[30];
    int  dateofjoining[3];
}employee;

employee assignvalue(){
    employee emp;
    printf("Enter the Employee code\n");
    scanf("%d", &emp.employeecode);
    getchar();
    printf("Enter the Employee Name\n");
    fgets(emp.employeename, 30, stdin);
    printf("Enter the Date of joining(DD,MM,Year)\n");
    scanf("%d %d %d", &emp.dateofjoining[0], &emp.dateofjoining[1], &emp.dateofjoining[2]);
    return emp;
}
void tenureofemployee(employee employees[4], int count){
    int currentdate, currentmonth, currentyear;
    printf("Enter the current(dd,mm,yy)\n");
    scanf("%d%d%d", &currentdate, &currentmonth, &currentyear);
    int eligiblecount=0;

    printf("List of Employees with tenure more than 3 years\n");
    for (int i = 0; i < count; i++)
    {
        int date=currentdate-employees[i].dateofjoining[0];
        int month=currentmonth-employees[i].dateofjoining[1];
        int years=currentyear-employees[i].dateofjoining[2];

        if(month<0 || (month==0 && date<0)){
            years--;
        }
        if (years>3)
        {
            eligiblecount++;
            printf("Employee Code: %d\n", employees[i].employeecode);
            printf("Employee Name: %s\n", employees[i].employeename);
            printf("Employee Date of joining: %d-%d-%d\n", employees[i].dateofjoining[0],employees[i].dateofjoining[1], employees[i].dateofjoining[2]);
            printf("Total Tenure: %d\n", years);
        }
        
    }
    printf("--------------------------------------------------\n");
    printf("Total employees with tenure > 3 years: %d\n", eligiblecount);
    

}

int main(){
    employee Employee[4];
    
    for (int  i = 0; i < 4; i++)
    {
      printf("\nEnter details for Employee %d:\n", i + 1);
      Employee[i]=assignvalue();
    }
    tenureofemployee(Employee,4);
    

    return 0;
}