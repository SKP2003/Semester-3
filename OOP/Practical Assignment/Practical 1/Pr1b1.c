#include<stdio.h>
#include<conio.h>
int main()
{
    int c=0,i,j;
    int a[6]={2,1,2,3,3,1};
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<=6;j++)
        {
            if(a[j]==a[i])
            {
                c++;
                printf("DuplicateElements: %d\n",a[i]);
            }
        }
    }
    printf("Total no. of Duplicate elements found in array: %d",c);
    return 0;
}