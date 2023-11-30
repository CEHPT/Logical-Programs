#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEE_LENGTH 400
#define MAX_CHAR_LENGTH 80
#define MAX_SALARY_LENGTH 10

struct EMPLOYEE
{
	char distinctDepartment[MAX_CHAR_LENGTH];
	char department[MAX_CHAR_LENGTH];
	char salary[MAX_SALARY_LENGTH];
	long totalSalary;
	long highSalary;
	long lowSalary;
	float avgSalary;
	int count;
	
}typedef employee;

void readAndStoreDataFromFile(employee e[] , int *count , int *distinctCount);
void statisticalAnalysis(employee e[] , int count , int distinctCount);
void displayResults(employee e[] , int distinctCount);

int main()
{
	employee e[MAX_EMPLOYEE_LENGTH];
	int count  , distinctCount;
	
	count = distinctCount = 0;
	
	readAndStoreDataFromFile(e , &count , &distinctCount);
	statisticalAnalysis(e , count , distinctCount);
	displayResults(e , distinctCount);
	
	return 0;
}

void readAndStoreDataFromFile(employee e[] , int *count , int *distinctCount)
{	 
	FILE *f;
	char c;
	int comaCount = 0 , EOL_Reached = 0 , dc = 0 , sc = 0 , i;
	int isUnique;
	
	f = fopen("EmployeeList.csv" , "r");
	
	while((c = getc(f)) != EOF)
	{
	    switch(c)
	    {
	        case ',':
	            comaCount++;
	            break;
	            
	        case '\n':
	            e[*count].department[dc] = '\0';
	            comaCount = 0;
	            EOL_Reached = 1;
	            break;
	            
	        default:
	            
	            if(comaCount == 2)
	                e[*count].department[dc++] = c;
	                
	            else if(comaCount == 3)
	                e[*count].salary[sc++] = c;
	            
	            break;      
	    }
	    
	    if(EOL_Reached)
	    {   
	        isUnique = 1;
	        
	        for(i = 0; i < *distinctCount; i++)
	            if(!strcmp(e[*count].department , e[i].distinctDepartment))
	                isUnique = 0;
	                
	        if(isUnique && strcmp(e[*count].department , "DeptName"))
	            strcpy(e[(*distinctCount)++].distinctDepartment , e[*count].department);
	    
	        (*count)++;
	        dc = comaCount = EOL_Reached = sc = 0;
	    }   
	}	   
	
	fclose(f);	  
}

void statisticalAnalysis(employee e[] , int count , int distinctCount)
{
	int i , j;
	
	for(i=0; i<distinctCount; i++)
	{
		e[i].totalSalary = 0;
		e[i].count = 0;
		e[i].highSalary = atoi(e[1].salary);
		e[i].lowSalary  = atoi(e[1].salary);
		
		for(j=0; j<count; j++)
		{
			if(!strcmp(e[i].distinctDepartment , e[j].department))
			{
				e[i].totalSalary += atoi(e[j].salary);
				e[i].count++;
				
			
				if(e[i].highSalary < atoi(e[j].salary))
					e[i].highSalary = atoi(e[j].salary);
				
			
				if(e[i].lowSalary > atoi(e[j].salary))
					 e[i].lowSalary  = atoi(e[j].salary);
			
			}
		}
		
		e[i].avgSalary = e[i].totalSalary / (float) e[i].count;
	}
}

void displayResults(employee e[] , int distinctCount)
{
	int i;
	
	printf("=====================================================================================================\n");
	printf("DEPARTMENT \t\t\t\t High        LOW      AVERAGE   \tCOUNT     TOTAL\n");
	printf("=====================================================================================================\n\n");
	
	for(i=0; i<distinctCount; i++)
		printf("%-35s %10ld  %10ld  %10.2f   %10d    %10d\n" , e[i].distinctDepartment , e[i].highSalary , e[i].lowSalary , e[i].avgSalary , e[i].count , e[i].totalSalary);
}


