#include<stdio.h>
#include<stdlib.h>
int student();
int tutor();
int registation();
int login();
int tutor_profile();
FILE *f1,*f2;
int choice;

struct user{
	char mail[100];
	char password[100];
	char name[100];
	char mobile[100];
	char location[100];
	char study[100];
	char description[100];
	char teachclass[20];
	
}regi[100];
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
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t''''''''''Registation page:''''''''''");
	int i, count=0;
	f2=fopen("count.txt","rb+");
    if (f2==NULL)
    {
        f2 = fopen("count.txt","wb+");
        fwrite(&count, sizeof(count), 1, f2);
        fclose(f2);
    }
    fread(&count, sizeof(count), 1, f2);
    fclose(f2);
    
    
    f1 = fopen("regi.txt","rb+");
    if (f1==NULL)
    {
        f1 = fopen("regi.txt","wb+");
        fclose(f1);
    }
    fread(&regi, sizeof(regi), 1, f1);
    fclose(f1);
    fflush(stdin);
    
    for(i=count; i<count+1; ++i)
    {
        printf("\n\n\t\t\tEnter full Name: ");
        fgets(regi[i].name, 100, stdin);
        printf("\n\n\t\t\tEnter your Email: ");
        fgets(regi[i].mail, 100, stdin);
        printf("\n\n\t\t\tPassword: ");
        fgets(regi[i].password, 100, stdin);
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t''''''''''Enter parsonal detailes''''''''");
        printf("\n\n\t\t\tWrite about ur stady life: ");
        fgets(regi[i].study, 100, stdin);
        printf("\n\n\t\t\tWrite about ur location: ");
        fgets(regi[i].location, 100, stdin);
        printf("\n\n\t\t\tEnter your mobile number:");
        fgets(regi[i].mobile, 100, stdin);
        printf("\n\n\t\t\tWrite something about your self: ");
        fgets(regi[i].description, 100, stdin);
        printf("\n\n\t\t\tWhich class student u can teach:");
        fgets(regi[i].teachclass, 1, stdin);
    }
    
    f1 = fopen("regi.txt","wb+");
    fwrite(&regi, sizeof(regi), 1, f1);
    fclose(f1);
    f2 = fopen("pnumber.txt","wb+");
    ++count;
    fwrite(&count, sizeof(count), 1, f2);
    fclose(f2);
    system("cls");
    
    printf("\n\n\n\n\n\n\t\t\t\t\tYou have been succesfully registert to easy_tutor");
    printf("\n\t\t\t\t\tThank you very much");
    thanks:
    printf("\n\n\t\t\tPress 1 for Login");
    printf("\n\n\t\t\tPress 2 for Again Registration");
    printf("\n\n\t\t\tEnter You choice: ");
    scanf("%d",&choice);
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
		    printf("Entered wrong option");
		    system("cls");
		    goto thanks;			
	}
		
}


int login(){
	
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\t\t ''''''''''Welcome to login page''''''''");
	int i,login;
	char email[100],pass[100];
    fflush(stdin);
    printf("\n\n\t\t\tEnter your email: ");
    fgets(email, 100, stdin);
    fflush(stdin);
    printf("\n\n\t\t\tPassword: ");
    fgets(pass, 100, stdin);
    fflush(stdin);
    f1 = fopen("regi.txt","rb+");
    fread(&regi, sizeof(regi), 1, f1);
    fclose(f1);
    
    for(i=0; i<100; ++i)
    {
        if ((0==strcmp(email,regi[i].mail)) && (0==strcmp(regi[i].password)))
        {
            printf("\n\n\t\tLogin Successfully\n");
            printf("\n");
            login=1;
            system("cls");
            i=100;
            //break;
        }

    }
    
    if(login==1){
    	printf("\n\n\t\tLogin Successfully\n");
    	system("pause");
    	tutor_profile();
	}
	else{
		printf("\n\n\t\t*****Login Failed*****");
		system("pause");
		tutor();
	}
}
int student(){
	printf("studednt");
}
int tutor_profile(){
	printf("yet to make");
}

