#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
int Q[5],F=-1,R=-1,op;

void insertQ();
void deleteQ();
void displayQ();
int main()
{
    do{
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter Operation: ");
    scanf("%d",&op);
    switch(op)
    {
        case 1: insertQ();
                break;
        case 2: deleteQ();
                break;
        case 3: displayQ();
                break;
        case 4: exit(0);
                break;
        default: printf("Invalid Operation");
                 break;
    }
    }while(op!=4);
    return(0);
}
void insertQ()
{  
    int item;
    if(R==4)
    {
        printf("Queue Overflow");
    }
    else
    {
        if(F==-1)
        {
            F++;
        }
        R++;
        printf("Enter Value to Insert: ");
        scanf("%d",&item);
        Q[R]=item;
        printf("Insertion Successful\n");
    }
}
void displayQ()
{
    if(F==-1 || F>R)
    {
        printf("Queue Underflow");
    }
    else
    {
        int i;
        printf("Queue: ");
        for(i=F;i<=R;i++)
        {
            printf("%d\t",Q[i]);
        }
    }
}
void deleteQ()
{
    if(F==-1 || F>R)
    {
        printf("Queue Underflow\n");
        F=-1;
    }
    else
    {
        printf("Element Deleted: %d",Q[F]);
        F++;
    }
}
