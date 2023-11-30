#include <stdio.h>
#include <string.h>
#include <limits.h>

void totalSalaryCalculateAndDisplay(char *department , int *totalLowSalary , char *totalLowSalaryDepartment);

struct employee
{
	char employeeDepartment[80];
};

int main()
{
	FILE *f;
	char line[300] , totalLowSalaryDepartment[80];
	int comaCount = 0 , count = 0 , len , i;
	int totalLowSalary = INT_MAX , size = 0 , isUnique , dc;
	
	struct employee ed[100];
	
	f = fopen("EmployeeList.csv" , "r");
		
	while(fgets(line , 299 , f) != NULL)
	{
		char tempDepartment[80] = "";
		comaCount = 0 , dc = 0;
	
		for(i=0; i<strlen(line); i++)
		{
			if(line[i] == ',')
				comaCount++;
				
			else if(comaCount == 2)
				tempDepartment[dc++] = line[i];
		}
		
		/* check is unique */
		isUnique = 1;
		
		for(i=0; i<size; i++)
			if(!strcmp(tempDepartment , ed[i].employeeDepartment))
				isUnique = 0;
				
		if(isUnique && strcmp(tempDepartment , "DeptName"))
			strcpy(ed[size++].employeeDepartment , tempDepartment);
			
		/* printf("%s\n" , ed[count-1].employeeDepartment); */
	}
	
	fclose(f);
	
	for(i=0; i<size; i++)	
		totalSalaryCalculateAndDisplay(ed[i].employeeDepartment , &totalLowSalary , totalLowSalaryDepartment);
	
	printf("\n=============================================\n");
	printf("Total Low Salary Amount Department and Amount\n");
	printf("=============================================\n");
	printf("%-50s %d\n" , totalLowSalaryDepartment , totalLowSalary);
	
	return 0;	 
}

void totalSalaryCalculateAndDisplay(char *department , int *totalLowSalary , char *totalLowSalaryDepartment)
{
	FILE *f;
	char line[300];
	int comaCount = 0 , i , dc = 0 , sc = 0;
	int totalSalary = 0;
	char dpm[100] = "";
	char salary[50] = "";
	
	f = fopen("EmployeeList.csv" , "r");
	
	while((fgets(line , 299 , f)) != NULL)
	{
		
		for(i = 0; i <strlen(line); i++)
			if(line[i] == ',')
				comaCount++;
			else if(comaCount == 2)
				dpm[dc++] = line[i];
			else if(comaCount == 3)
				salary[sc++] = line[i];
		
		dpm[dc] = '\0';
		salary[sc] = '\0';
		comaCount = dc = sc = 0;
		
		if(!strcmp(dpm , department))
			totalSalary += atoi(salary);
	}
	
	fclose(f);
	
	if(totalSalary < *totalLowSalary)
	{
		*totalLowSalary = totalSalary;
		strcpy(totalLowSalaryDepartment , department);
	}
	
	printf("%-50s  %6d\n" , department , totalSalary);
}



