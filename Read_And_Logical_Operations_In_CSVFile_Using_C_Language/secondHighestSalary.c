#include <stdio.h>
#include <string.h>

void displaySecondHighestSalary(char *name , int salary);
void secondHighestSalaryComparision(char *EmpName , char *MonthlySalary , char *highSalaryEmployeeName , int *highSalary , int *secondHighestSalary , char *secondHighestSalaryEmployee);

int main()
{
	FILE *f;
	int c;
	char EmpName[50] , MonthlySalary[10];
	int comaCount = 0 , nc = 0 , msc = 0 , EOL_Reached = 0; /* nameCount , monthlySalaryCount */
	char highSalaryEmployeeName[80] , secondHighestSalaryEmployee[80];
	int highSalary = 0 , secondHighestSalary = 0;
	
	f = fopen("EmployeeList.csv" , "r");
	
	while((c = getc(f)) != EOF)
	{
		switch(c)
		{
			case ',':
				comaCount++;
				break;
				
			case '\n':
				EmpName[nc] = '\0';
				MonthlySalary[msc] = '\0';
				comaCount = nc = msc  = 0;
				EOL_Reached = 1;
				break;
				
			default:
				if(comaCount == 1)
					EmpName[nc++] = c;
				
				
				else if(comaCount == 3)
					MonthlySalary[msc++] = c;
				
				break;	  
		}
		
		if(EOL_Reached)
		{
			secondHighestSalaryComparision(EmpName , MonthlySalary , highSalaryEmployeeName , &highSalary , &secondHighestSalary , secondHighestSalaryEmployee);  	 	 
		
			EOL_Reached = nc  = msc = 0;
		
		}	 	 
	}
	
	fclose(f);
	
	displaySecondHighestSalary(secondHighestSalaryEmployee , secondHighestSalary);
	
	return 0;	 
}


void displaySecondHighestSalary(char *name , int salary)
{
	/*
	printf("\nHighest Salary Employee\n");
	printf("-----------------------\n\n");
	printf("Employe Name : %-20s Salary : %5d\n" , name , salary);
	
	*/
	
	printf("\nSecond Highest Salary Employee\n");
	printf("-----------------------\n\n");
	printf("Employe Name : %-20s Salary : %5d\n" , name , salary);
}


void secondHighestSalaryComparision(char *EmpName , char *MonthlySalary , char *highSalaryEmployeeName , int *highSalary , int *secondHighestSalary , char *secondHighestSalaryEmployee)
{	
    int salary = atoi(MonthlySalary);

    if (salary > *highSalary) 
	{
        *secondHighestSalary = *highSalary;
        strcpy(secondHighestSalaryEmployee, highSalaryEmployeeName);
        *highSalary = salary;
        strcpy(highSalaryEmployeeName, EmpName);
    }
	
	else if (salary > *secondHighestSalary && salary < *highSalary) 
	{
        *secondHighestSalary = salary;
        strcpy(secondHighestSalaryEmployee, EmpName);
    }
}


