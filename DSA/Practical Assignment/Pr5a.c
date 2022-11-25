#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;
struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
} *head = NULL;
void display(struct node *p)
{
    printf("Your songs are as: \n");
    printf("%s\n", p->song);
    p = p->next;
    while (p != head)
    {
        printf("%s\n", p->song);
        p = p->next;
    }
}
int size(struct node *p)
{
    int s = 1;
    if (p == NULL)
        return 0;
    p = p->next;
    while (p != head)
    {
        p = p->next;
        s++;
    }
    return s;
}
void insert(struct node *p, int y)
{
    int pos;

     struct node *t = (struct node *)malloc(sizeof(struct node));
    char s[100];
    printf("Enter song name: ");
    fflush(stdin);
    gets(s);
    strcpy(t->song, s);
    if (y == 1)
    {
        if (p == NULL)
        {
            t->next = t;
            t->prev = t;
            head = t;
        }
        else
        {
            t->next = p;
            t->prev = p->prev;
            p->prev->next = t;
            p->prev = t;
            head = t;
        }
    }
    else if (y == 2)
    {
        printf("Enter position to insert song: ");
        scanf("%d", &pos);
        pos--;
        if (pos<0 || pos>size(p))
        {
            printf("Invalid position entered ...\n");
            return;
        }
        for (i=0;i<pos;i++)
        {
            p = p->next;
        }
        t->prev = t;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
    else
    {
        while (p->next != head)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
    printf("%s song entered\n\n", t->song);
}
 void delete1(struct node *p, int y)
{
    struct node *t=p,*q;
    q = (struct node *)malloc(sizeof(struct node));
    int pos;
    if (y == 1)
    {
        if (size(p) == 1)
        {
            q = p;
            if (p == NULL)
                printf("1\n\n");
            strcpy(q->song, p->song);
            t = NULL;
            free(p);
        }
        else
        {
            t = p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            head = p->next;
            strcpy(q->song, p->song);
            free(p);
        }
    }
    else if (y == 2)
    {
        printf("Enter position to delete song: ");
        scanf("%d", &pos);
        pos--;
        if (pos < 0 || pos > size(p))
        {
            printf("Entered positon is not found in list..\n");
            return;
        }
        for (i = 0; i < pos; i++)
        {
            p = p->next;
        }
        t = p->prev;
        strcpy(q->song, p->song);
        t->next = p->next;
        p->next->prev = t;
        p->next = NULL;
        p->prev = NULL;
        free(p);
    }
    else
    {
         while (p->next != head)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        strcpy(q->song, p->song);
        p->next = NULL;
        p->prev = NULL;
        free(p);
    }
    printf("%s song Deleted\n", q->song);
}
void playnext(struct node **cur)
{
    printf("Now playing:- %s\n", (*cur) -> song);
    (*cur) = (*cur)->next;
}
void playprev(struct node **cur)
{
    (*cur) = (*cur)->prev;
    printf("Now playing:- %s\n", (*cur)->song);
}
void playfirst(struct node **cur)
{
    (*cur) = head;
    printf("Now playing:- %s\n", (*cur)->song);
}
void stop(struct node **cur)
{
    printf("not playing any music...!!\n");
    (*cur) = NULL;
}
int main()
{
    int ch, y, x = 0;
    struct node *cur;
    do
    {
		printf("\n 1. Add new song\n");
 		printf("2. Display playlist\n");
		printf("3. Delete song\n");
		printf("4. Play the next song\n");
		printf("5. Play the previous song\n"); 
		printf("6. Play from the first song\n"); 
		printf("7. stop playing\n"); 
		printf("8. Exit");
		printf("\nEnter a choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
        	case 1:	printf("1. Add at first\n2. Add at position\n3. Add at end\n");
          		   	printf("Enter a choice: \n\n");
            	   	scanf("%d", &y);
            		if (y < 1 || y > 3)
            		{
                		printf("Enter a valid choice ...\n");
                		break;
            		}
            		insert(head, y);
            		break;
        	case 2:
            		display(head);
            		break;
        	case 3:
		            printf("1. Delete first song \n2. delete at any position\n3. deletet at the end\n");
            		printf("Enter a choice: \n\n");
            		scanf("%d", &y);
            		if (y < 1 || y > 3)
            		{
                		printf("Enter a valid choice ...\n");
                		break;
            		}
            		delete1(head, y);
            		break;
        	case 4:
            		if (x == 0)
            		{
                		cur = head;
                		playnext(&cur);
                		x = 1;
                		break;
            		}
            		playnext(&cur);
            		break;
        	case 5:
            		if (x == 0)
            		{
                		cur = head;
                		playprev(&cur);
                		x = 1;
		                break;
         	   		}
            		playprev(&cur);
            		break;
        	case 6:
	            	playfirst(&cur);
            		break;
        	case 7:
            		stop(&cur);
          			x = 0;
            		break;
            case 8: exit(0);
            
        	default:
            		printf("enter a valid choice...\n");
		}
    } while (ch != 8);
}
