#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct list
{
    int data;
    struct list *link;
} node;

node *head;
void insertbeg()
{
    node *ptr;
    int data;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("\nNo memory left");
    }
    else
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->link = head;
        head = ptr;
        printf("Node inserted\n");
    }
}
void insertend()
{

    node *ptr, *temp;
    int data;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("\nNo memory left");
    }
    else
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        ptr->data = data;
        if (head == NULL)
        {
            ptr->link = NULL;
            head = ptr;
            printf("Node inserted\n");
        }
        else
        {
            temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = ptr;
            ptr->link = NULL;
            printf("Node inserted\n");
        }
    }
}
void deletenode()
{
    int data;
    node *ptr, *temp, *del;
    ptr = head;
    printf("\nEnter data: ");
    scanf("%d", &data);
    while (ptr->data != data)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    del = temp;
    temp->link = ptr->link;
    printf("Node Deleted\n");
}
void display()
{
    node *temp;
    temp = head;
    printf("\nPrinting the list...\n");
    while (temp->link != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
}
void search()
{
    node *temp;
    temp = head;
    int item;
    bool flag = false;
    printf("\nEnter data to search: ");
    scanf("%d", &item);
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        if (temp->data == item)
        {
            printf("\n%d is found at position %d", item, counter);
            flag = true;
            break;
        }
        temp = temp->link;
    }
    if (flag == false)
    {
        printf("\nItem is not found");
    }
}

void main()
{
    int choice = 0;
    while (choice != 6)
    {
        printf("\n---------Main Menu----------");
        printf("\n1. Insert node at beginning");
        printf("\n2. Insert node at end");
        printf("\n3. Delete a node");
        printf("\n4. Display list");
        printf("\n5. Search a node");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            deletenode();
            break;
        case 4:
            display();
            break;
        case 5:
            search();
            break;
        case 6:
            break;
        default:
            printf("Please enter a valid choice!\n");
        }
    }
}
