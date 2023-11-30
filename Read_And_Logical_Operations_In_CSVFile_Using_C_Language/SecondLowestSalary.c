#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
	FILE *f;
	int c;
	char EmpName[50];
	char MonthlySalary[10];
	int comaCount = 0 , nc = 0 , msc = 0;
	int EOL_Reached = 0;
	char lowestSalaryEmployeeName[80] , secondLowestSalaryEmployeeName[80];
	int lowSalary = INT_MAX , secondLowestSalary = INT_MAX , salary;
	
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
				msc = 0;
				nc = 0;
				comaCount = 0;
				EOL_Reached = 1;
				break;
				
			default:
				if(comaCount == 1)
					EmpName[nc++] = c;
				
				
				else if(comaCount == 3)
					MonthlySalary[msc++] = c;
				
				break;	  
		}
		
		 if (EOL_Reached) 
		 {
		 	salary = atoi(MonthlySalary);

                if (salary > 0) 
				{
                    if (salary < lowSalary) 
					{
                        secondLowestSalary = lowSalary;
                        strcpy(secondLowestSalaryEmployeeName, lowestSalaryEmployeeName);
                        lowSalary = salary;
                        strcpy(lowestSalaryEmployeeName, EmpName);
                    } 
					
					else if (salary < secondLowestSalary && salary > lowSalary)
					{
                        secondLowestSalary = salary;
                        strcpy(secondLowestSalaryEmployeeName, EmpName);
                    }
                }
			
			/* printf("%s %d   %s %d\n" , lowestSalaryEmployeeName , lowSalary , secondLowestSalaryEmployeeName , secondLowestSalary); */

            EOL_Reached = 0;
			
			nc = 0;
			msc = 0;
        }	   	   	   
	}
	
	printf("\nSecond Lowest Salary Employee\n");
	printf("-----------------------\n\n");
	printf("Employe Name : %-20s Salary : %5d\n" , secondLowestSalaryEmployeeName , secondLowestSalary);
	
	return 0;	 
}




