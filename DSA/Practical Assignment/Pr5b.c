#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct polynomial
{
	int epx;
 	int epy;
 	int epz;
 	int coff;
 	struct polynomial *next;
};
void sort(struct polynomial* ptr)
{
	struct polynomial* t1,*t2,*t;
 	t1=ptr;
 	while(t1!=NULL)
	{
 		t2=t1->next;
 		while(t2!=NULL)
		{
 			if(t2->epx>t1->epx && t2->epy>t1->epy && t2->epz>t1->epz ||t2->epx>t1->epx && t2->epy>t1->epy || t2->epx>t1->epx)
			{
 				t=(struct polynomial*)malloc(sizeof(struct polynomial));
 				t->epx=t1->epx;
 				t->epy=t1->epy;
 				t->epz=t1->epz;
 				t->coff=t1->coff;
 				t1->epx=t2->epx;
 				t1->epy=t2->epy;
 				t1->epz=t2->epz;
 				t1->coff=t2->coff;
 				t2->epx=t->epx;
 				t2->epy=t->epy;
 				t2->epz=t->epz;
 				t2->coff=t->coff;
 			}
 			t2=t2->next;
		}
 		t1=t1->next;
	}
 }

 void show_polynomial (struct polynomial *ptr)
{
	struct polynomial* t=(struct polynomial*)malloc(sizeof(struct polynomial));
 	t=ptr;
 	while (t != NULL)
 	{
 		if(t->next==NULL)
		{
 			printf("%d x^%d y^%d z^%d = 0",t->coff,t->epx,t->epy,t->epz);
 		}
 		else
		{
 			printf("%d x^%d y^%d z^%d + ",t->coff,t->epx,t->epy,t->epz);
		}
 		t=t->next;
	}
 	printf ("\n");
}
void final_polynomial(struct polynomial* ptr){
	struct polynomial* t1,*t2,*t3;
 	t1=ptr;
 	while(t1!=NULL)
	{
 		t2=t1->next;
 		while(t2!=NULL)
		{
 			if(t1->epx==t2->epx && t1->epy==t2->epy && t1->epz==t2->epz)
			{
 				t1->coff=t1->coff+t2->coff;
 				t3=ptr;
 				while(t3->next!=t2)
				{
	 				t3=t3->next;
 				}
 				t3->next=t2->next;
 			}		
 			t2=t2->next;
 		}
 	t1=t1->next;
	}
}
void neglate_zero_coff(struct polynomial* ptr)
{
	struct polynomial* t1,*t2;
 	t1=ptr;
 	while(t1!=NULL)
	{
 		if(t1->coff==0)
		{
 			t2=ptr;
 			while(t2->next!=t1)
			{
	 			t2=t2->next;
 			}
 			t2->next=t1->next;
 		}	
 		t1=t1->next;
 	}
 }
 int main ()
{
	struct polynomial *poly1,*newnode1,*temp1,*poly2,*newnode2,*temp2,*polysum;
 	poly1 = NULL;
 	poly2=NULL;
 	polysum=NULL;
 	char ans1='y';
 	char ans2='y';
 	printf("enter polynomial equation 1 : \n");
 	while(ans1!='n')
	{
 		newnode1 = (struct polynomial *) malloc (sizeof (struct polynomial));
 		printf(" Enter exponential of x : ");
 		scanf("%d",&newnode1->epx);
 		printf(" Enter exponential of y : ");
 		scanf("%d",&newnode1->epy);
 		printf(" Enter exponential of z : ");
 		scanf("%d",&newnode1->epz);
 		printf(" Enter cofficient : ");
 		scanf("%d",&newnode1->coff);
 		if(poly1==NULL)
		{
 			poly1=temp1=newnode1;
 		}
 		else
		{
 			temp1->next=newnode1;
 			temp1=newnode1;
 		}
 		printf("do you want to continue (y or n): ");
 		scanf("%s",&ans1);
 	}
 	struct polynomial* k1;
 	k1=NULL;
 	while(poly1!=NULL)
	{
 		struct polynomial* s,*j;
 		s=(struct polynomial*)malloc(sizeof(struct polynomial));
 		s->epx=poly1->epx;
 		s->epy=poly1->epy;
 		s->epz=poly1->epz;
 		s->coff=poly1->coff;
 		if(k1==NULL)
		{
 			k1=j=s;
 		}
 		else
		{
 			j->next=s;
 			j=s;
 		}
 		poly1=poly1->next;
 	}
 	final_polynomial(k1);
 	sort(k1);
 	neglate_zero_coff(k1);
	printf("*************************************************************************************\n");
 	printf("enter polynomial equation 2 : \n");
 	while(ans2!='n')
	{
 		newnode2 = (struct polynomial *) malloc (sizeof (struct polynomial));
 		printf(" Enter exponential of x : ");
 		scanf("%d",&newnode2->epx);
 		printf(" Enter exponential of y : ");
 		scanf("%d",&newnode2->epy);
 		printf(" Enter exponential of z : ");
 		scanf("%d",&newnode2->epz);
 		printf(" Enter cofficient : ");
 		scanf("%d",&newnode2->coff);
 		if(poly2==NULL)
		{
 			poly2=temp2=newnode2;
 		}
 		else
		{
 			temp2->next=newnode2;
 			temp2=newnode2;
 		}
 		printf("do you want to continue (y or n): ");
 		scanf("%s",&ans2);
 	}
	printf("*************************************************************************************\n");
 	final_polynomial(poly2);
 	sort(poly2);
 	neglate_zero_coff(poly2);
 	printf("first polynomial : \n");
 	show_polynomial(k1);
 	printf(" + \n");
 	printf("second polynomial : \n");
 	show_polynomial(poly2);
 	struct polynomial* newnode3,*l1,*l2,*temp3;
	l1=k1;
 	l2=poly2;
 	while(l1!=NULL)
	{
 		newnode3=(struct polynomial*)malloc(sizeof(struct polynomial));
 		newnode3->epx=l1->epx;
 		newnode3->epy=l1->epy;
 		newnode3->epz=l1->epz;
 		newnode3->coff=l1->coff;
 		if(polysum==NULL)
		{
 			polysum=temp3=newnode3;
 		}
 		else
		{
 			temp3->next=newnode3;
 			temp3=newnode3;
 		}
 		l1=l1->next;
 	}
 	while(l2!=NULL)
	{
 		newnode3=(struct polynomial*)malloc(sizeof(struct polynomial));
 		newnode3->epx=l2->epx;
 		newnode3->epy=l2->epy;
 		newnode3->epz=l2->epz;
 		newnode3->coff=l2->coff;
 		temp3->next=newnode3;
 		temp3=newnode3;
 		l2=l2->next;
 	}
 	printf("addition of two polynomial : \n");
 	sort(polysum);
 	final_polynomial(polysum);
 	show_polynomial(polysum);
 	return 0;
}
