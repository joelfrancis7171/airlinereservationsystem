#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
struct airline
{
	char passport[30];
	char name[30];
    char destination[30];
	int seat_num;
	char email[30];
	struct airline *following;
}
*begin, *stream;
struct airline *dummy;
void main()
{
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL;
	int num = 1;
	do
	{

		printf("\n\n\t\t********************************************************************");
		printf("\n\t\t                Welcome to Airline Reservation System                   ");
		printf("\n\t\t********************************************************************");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. Display Records");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
            savefile();
			break;
		}
		default:
			printf("\n\n\t INVALID CHOICE!");
		}
		getch();
	} while (choice != 4);
}
void details()
{
	printf("\n\t Enter your Passport Number: ");
	gets(stream->passport); fflush(stdin);
	printf("\n\t Enter your Name: ");
	gets(stream->name); fflush(stdin);
	printf("\n\t Enter your Email Address: ");
	gets(stream->email); fflush(stdin);
    printf("\n\t Enter the Destination: ");
    gets(stream->destination); fflush(stdin);
}
void details();
void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		begin = stream = (struct airline*)malloc(sizeof(struct airline));
		details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t Your seat number is A-%d", x);
		stream->seat_num = x;
		return;
	}
	else if (x > 15)
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		while (stream->following)
        stream = stream->following;
		stream->following = (struct airline *)malloc(sizeof(struct airline));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t Your seat number is A-%d", x);
		stream->seat_num = x;
		return;
	}
}
void savefile()
{
	FILE *fpointer = fopen("records", "w");
	if (!fpointer)
	{
		printf("\n Cannot open file!");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-30s", stream->passport);
		fprintf(fpointer, "%-30s", stream->name);
		fprintf(fpointer, "%-30s", stream->email);
        fprintf(fpointer, "%-30s", stream->destination);
        fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to the file 'records'");
	fclose(fpointer);
}
void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n\t Passport Number: %-30s", stream->passport);
		printf("\n\t Name: %-30s", stream->name);
		printf("\n\t Email Address: %-30s", stream->email);
		printf("\n\t Seat number: A-%d", stream->seat_num);
        printf("\n\t Destination: %-30s\n", stream->destination);
		printf("\n\t ==============================");
		stream = stream->following;
	}
}
void cancel()
{
	stream = begin;
	system("cls");
	char passport[30];
	printf("\n\n\t Enter passport number to delete record: ");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf("\t Booking has been deleted");
		Sleep(800);
		return;
	}
	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("\t Booking has been deleted");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
}
