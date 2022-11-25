#include<stdio.h>
#include<conio.h>
void reverse(char *str)
{
   if (*str)
   {
       reverse(str+1);
       printf("%c", *str);
   }
}
 
/* Driver program to test above function */
int main()
{
   char a[] = "Nirma";
   reverse(a);
   return 0;
}
