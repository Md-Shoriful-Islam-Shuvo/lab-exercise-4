#include<stdio.h>
#include<stdlib.h>
int student();
int tutor();
int registation();
int login();
int tutor_profile();
FILE *file;

struct user{
	char mail[100];
	char password[100];
	char name[100];
	char mobile[100];
	char location[100];
	char study[100];
	char description[100];
	
}s;
int main()
{
	start:
	printf("\n\n\n\n\t\tWelcome to easy_tutor\n\n\n\n");
	printf("\tpress 1 if you are a student \n\n\tPress 2 if you are a tutor\n");
	int choice;
	scanf("%d",&choice);
	system("cls");
	switch(choice){
		case 1: 
		    student();
            system("cls");
            break;
        
		case 2:
		    tutor();
			system("cls");
			break;
		default:
		    printf("\n\n\tWrong choise");
		    system("cls");
		    goto start;
            break;	
			       
	}
}
int tutor(){
	int choice;
	printf("\n\n\n\t/t\t\t***********Welcome to easy tutore**********");
	printf("\n\n\t\t Enter your option :>>>>>");
	printf("\n\n\tPress 1 to login");
	printf("\n\n\tPress 2 to creat new profile");
	scanf("%d",&choice);
	system("cls");
	switch(choice){
		case 1:
			login();
			system("cls");
			break;
		case 2:
			registation();
			system("cls");
			break;
		default:
			printf("\n\n\tWrong choise");
		    system("cls");
		    tutor();
            break;
			
	}
	
}
int registation(){
	
	
}
