#include <stdio.h>

int main()
{
	FILE *f;
	int c;
	char EmpName[50];
	char MonthlySalary[10];
	int comaCount = 0 , nc = 0 , msc = 0;
	int EOL_Reached = 0 , i;
	char highSalaryEmployeeName[80];
	int highSalary = 0;
	
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
           
            if(highSalary < atoi(MonthlySalary))
			{
				 /* printf("%s %s" , EmpName , MonthlySalary); */
				
				highSalary = atoi(MonthlySalary);
				strcpy(highSalaryEmployeeName , EmpName);
			}

            EOL_Reached = 0;
			
			nc = 0;
			msc = 0;
        }	   	   	   
	}
	
	printf("\nHighest Salary Employee\n");
	printf("-----------------------\n\n");
	printf("Employe Name : %-20s Salary : %5d\n" , highSalaryEmployeeName , highSalary);
	
	return 0;	 
}




