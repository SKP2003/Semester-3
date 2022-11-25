#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct empl
{
	int eid,sal;
	char ename[30];
	char desg[10];
}e[50];

int main()
{
	int choice,n,i,id;
	
	do
	{	
	printf("1. Add Employee Data\n");
	printf("2. Delete Employee Data\n");
	printf("3. Display Employee Data\n");
	printf("4. Exit\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:	printf("Enter No. of data to be added: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter Employee ID: ");
			   		scanf("%d",&e[i].eid);
			   		printf("Enter Employee Name: ");
			   		scanf("%s",&e[i].ename);
			   		printf("Enter Employee Designation: ");
			   		scanf("%s",&e[i].desg);
			   		printf("Enter Salary: ");
			   		scanf("%d",&e[i].sal);
				}
				break;
				
		case 2: printf("Enter ID of employee to be Deleted: ");
				scanf("%d",&id);
				for(i=id-1;i<=n-1;i++)
				{
					e[i]=e[i+1];
				}
				printf("Deletion Successfull\n\n");
				break;
				
				
		case 3: for(i=0;i<n;i++)
				{
					printf("Employee ID: %d\n",e[i].eid);
					printf("Employee Name: %s\n",e[i].ename);
					printf("Employee Designation: %s\n",e[i].desg);
					printf("Employee Salary: %d\n\n",e[i].sal);
				}
				break;
		 
		case 4: exit(0);
		
		default: printf("Invalid Choice");
	}
	}while(choice!=4);
	return 0;
}
