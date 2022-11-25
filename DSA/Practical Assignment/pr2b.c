#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char infix[100];
char postfix[100];
char stack[100];

int top = -1;
int i=0,j=0;
int rank=0;
char temp;

void push(char t)
{
    if(top == 99)
    {
        printf("Stack Overflow !\n");
        return;
    }
    top++;
    stack[top] = t;
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow !\n");
        return;
    }
    top--;
}

int f(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='/' || x=='*')
        return 3;
    if(x=='^')
        return 6;
    if(x=='(')
        return 9;
    if(x==')')
        return 0;
    if(x>='a' && x<='z')
        return 7;
    if(x>='A' && x<='Z')
        return 7;
    if(x>=0 && x<=9)
        return 7;
    else
        {
            printf("f is Invalid...\n");
            exit(0);
        }
}

int g(char x)
{
    if(x=='+' || x=='-')
        return 2;
    if(x=='/' || x=='*')
        return 4;
    if(x=='^')
        return 5;
    if(x=='(')
        return 0;
    if(x>='a' && x<='z')
        return 8;
    if(x>='A' && x<='Z')
        return 8;
    if(x>=0 && x<=9)
        return 8;
    else
        {
            printf("g is Invalid...\n");
            exit(0);
        }
}

int r(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
        return -1;
    if(x>='a' && x<='z')
        return 1;
    if(x>='A' && x<='Z')
        return 1;
    if(x>='0' && x<='9')
        return 1;
}

int main()
{
    printf("Enter Infix expression :\n");
    scanf("%s",infix);
    printf("\n");
    push('(');
    strcat(infix,")");

    printf("SYMBOL    STACK           POSTFIX           RANK \n\n");
    while(infix[i] != '\0')
    {
        char a=infix[i];
        while(f(a)<g(stack[top]))
        {
            temp = stack[top];
            postfix[j] = stack[top];
            j++;
            pop();
            rank=rank+r(temp);
            if(rank < 1)
            {
                printf("\n INVALID\n");
            }
        }

        if(f(a) != g(stack[top]))
            push(a);
        else
            pop();

        printf("%-8c  %-14s  %-16s  %d\n",infix[i],stack,postfix,rank);
        i++;
    }

    if(top!=-1 || rank!=1)
        printf("\nINVALID\n");
    else
    {
        postfix[j]='\0';
        printf("\nThe Postfix expression is : %s \n",postfix);
    }
    return 0;
}
