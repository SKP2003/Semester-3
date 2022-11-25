#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int size;

void insert(int pq[size][5],int front[size],int rear[size])
{
    printf("Enter the element to insert:\n");
    int temp;
    scanf("%d", &temp);
    printf("Enter the Priority:\n");
    int p;
    scanf("%d", &p);
    if (rear[p] == 4)
    {
        printf("Overflow!\n");
    }
    else
    {
        if (rear[p] == -1)
        {
            front[p] = 0;
            rear[p] = 0;
        }
        else
        {
            rear[p]++;
        }
        pq[p][rear[p]] = temp;
        printf("Item inserted!\n");
    }
}

void delete (int pq[size][5],int front[size],int rear[size])
{
	int i,j;
        for (i = 0; i < size; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if (pq[i][j] != 'a'){
                    pq[i][j]='a';
                    printf("Item deleted!\n");
                    return;
                }
            }
        }
        printf("No item to be deleted!\n");
}

void print(int pq[size][5],int front[size],int rear[size])
{
	int i,j;
    printf("Displaying Queue:\n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if (pq[i][j] == 'a')
                printf("_ ");
            else
                printf("%d ", pq[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("Enter Size of Priority:\n");
    scanf("%d",&size);
    int pq[size][5];
    int front[size];
    int rear[size],i,j;
    for(i=0;i<size;i++){
        front[i]=-1;
        rear[i]=-1;
        for(j=0;j<5;j++){
            pq[i][j]='a';
        }
    }

    label:;
    int choice;
    printf("\n----Menu----\n");
    printf("1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Print Elements\n");
    printf("4. Exit\n");
    printf("Enter choice:\n");
    scanf(" %d", &choice);
    printf("\n");
    if (choice == 1)
        insert(pq,front,rear);
    else if (choice == 2)
        delete (pq,front,rear);
    else if (choice == 3)
        print(pq,front,rear);
    else
        exit(0);
    goto label;
}
