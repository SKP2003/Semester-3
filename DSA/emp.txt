#include<stdio.h>
#include<conio.h>

struct empl
{
    int eid,sal;
    char ename[30];
    char desg[10];
}e[50];
    int main()
    {
        int n,i,choice,ch=1;
      do{    
        printf("1. Add Data\n");
        printf("2. Display Data\n");
        printf("3. Exit");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1: printf("Enter no. of data to be added: ");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("Enter employee id: ");
                        scanf("%d",&e[i].eid);
                         printf("Enter employee name: ");
                        scanf("%s",&e[i].ename);
                        printf("Enter salary of employee: ");
                        scanf("%d",&e[i].sal);
                        printf("Enter Designation: ");
                        scanf("%s",&e[i].desg);
                    }
                    break;
            case 2: for(i=0;i<n;i++)
                    {   
                        printf("Eid: %d\n",e[i].eid);
                        printf("Name: %s\n",e[i].ename);
                        printf("Salary: %d\n",e[i].sal);
                        printf("Designation: %s\n",e[i].desg);
                    }
                    break;
            case 3: exit(0); 
            default: printf("Invalid choice");
                     break;
        }
        /*printf("1. Choice\n 2. Exit");
        scanf("%d",&ch);*/
       }while(ch==1);
        
        
        
        
        return 0;
    }