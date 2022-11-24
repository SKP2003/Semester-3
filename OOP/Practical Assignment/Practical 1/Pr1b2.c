#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k=0,n;
    int a[n],a1[n],a2[n];
    printf("Enter No. of elements to be stored in array: ");
    scanf("%d",&n);
    printf("Enter %d elemets: \n",n);
    for(i=0;i<n;i++)
    {
        printf("Element-%d: ",i);
        scanf("%d",&a[i]);
    }   
    for(i=0;i<n;i++)
    {
        if(a[i]==0) 
            continue;
        int c=1;
        for(j=i+1;j<n;j++)
        {
            if(a[j]==a[i])
            {
                c++;
                a[j]=0;
            }
        }
        a1[k]=a[i];
        a2[k]=c;
        k++;
    }
    printf("The frequency of all elements of an array: \n");
    for(i=0;i<k;i++)
    {
        printf("%d occurs %d times\n",a1[i],a2[i]);
    }
    printf("\n");
    return 0;
}