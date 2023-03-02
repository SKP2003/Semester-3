/*Topic: Airline Reservation System
  Group: 22BCE537,22BCE538 
  Name: Sakariya Hardik, Shah Kaivan
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct airline
{
	char passport[6];
	char name[15];
	char source[15];
    char destination[15];
	int seat_num;
	char email[15];
	struct airline *following;
}*begin, *stream, *dummy;

void main()
{
	void reserve(int x), cancel(), display(), savefile();  //function prototypes
	int choice;
	begin = stream = NULL;  //initialize the struct pointers to NULL 
	int num = 1;
	do
	{
		
		printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   Welcome to Nirma Airline System                   ");
		printf("\n\t\t *******************************************************************");
		printf("\n\n\n\t\t Please enter your choice:");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t feel free to contact ");
		printf("\n\n\t\t Enter your choice :");
		scanf("%d", &choice); 
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
		    {
				reserve(num);
				num++;
				break;
		    }
		case 2:
			{
		 		cancel();
				break;
			}	
		case 3: 
			{
				display();
				break;
			}
		case 4:
			{
				savefile();
				break;
			}
		default:
			{
				printf("\n\n\t SORRY INVALID CHOICE!");
				printf("\n\n\t PLEASE CHOOSE FROM OPTION 1-4");
			}
		}
		getch();
	} while (choice != 4);
}

void details()
{
	printf("\n\t Enter your passport number:");
	scanf("%s",&stream->passport);
	fflush(stdin);   //reads a line from stdin and stores it into the string pointed
	printf("\n\t Enter your  name:");
	scanf("%s",&stream->name);
	fflush(stdin);
	printf("\n\t Enter your email address:");
	scanf("%s",&stream->email);
	fflush(stdin);
	printf("\n\t Enter Source: ");
	scanf("%s",&stream->source);
	fflush(stdin);
    printf("\n\t Enter the Destination : ");
    scanf("%s",&stream->destination);
	fflush(stdin);
}



void reserve(int x)
{
	
	stream = begin;
	if (begin == NULL)
	{
		// first user
		begin = stream = (struct airline*)malloc(sizeof(struct airline));
		details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: %d", x);
		stream->seat_num = x;
		return;
	}
	else if (x > 30) // FULL SEATS
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		// next user
		while (stream->following)
		{
			stream = stream->following;
		}
		stream->following = (struct airline *)malloc(sizeof(struct airline));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Seat booking succesful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
} 

void savefile()
{
	FILE *fpointer = fopen("multi records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
		fprintf(fpointer, "%-15s", stream->source);
        fprintf(fpointer, "%-15s", stream->destination);
        fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file (Records)");
	fclose(fpointer);
}

void display()
{
	stream = begin;
	while (stream)
	{	
		//printf("Reference No.: ",rand());
		printf("\n\n Passport Number : %-6s", stream->passport);
		printf("\n   Name : %-15s", stream->name);
		printf("\n   Email address: %-15s", stream->email);
		printf("\n   Seat number: A-%d", stream->seat_num);
		printf("\n   Source:%-15s", stream->source);
        printf("\n   Destination:%-15s", stream->destination);
		printf("\n\n++*=====================================================*++");
		stream = stream->following;
	}

}


void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter passort number to delete record?:");
	gets(passport); 
	fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" booking has been deleted");
		Sleep(100);
		return;

	}
	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("has been deleted ");
			getch();
			Sleep(100);
			return;
		}
		
		stream = stream->following;
	}
	printf("passport number is wrong please check your passport");

}
