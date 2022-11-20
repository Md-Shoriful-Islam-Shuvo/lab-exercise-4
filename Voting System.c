#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
//Function of this project......
int ConsoleTitle(void);
int MaximizeOutputWindow(void);
int SetConsoleSize(void);
int loading();
int user_registration();
int user_login();
int mainmenu(void);
int main_mainmenu();
int user_style(void);
int home_page();
int voter(void);
int voter_registration();
int voter_login();
int voter_mainmenu();
int voter_style(void);
int voter_information_form();
int voter_information_list();
int candidate();
int candidate_information();
int sheikh_hasina();
int khaleda_zia();
int muhammad_ershad();
int voting();
int logo();
int result();

int i=0,choice,n,a;
int rem=0,pc=0,optioon=0;
char ch;
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;

struct registration
{
    char fname[30];
    char nid[20];
    char add[30];
    char gname[25];
    char mobile[50];
    char uname[30];
    char pass[25];

} cus[100],cust[100],y[99];

int main()
{
    ConsoleTitle();
    MaximizeOutputWindow();
    SetConsoleSize();
    system("COLOR 5E");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    char a[16] = "Loading......!!";
    for(i=0;i<16;i++)
    {
        printf("%c",a[i]);
        Sleep(60);
        printf(" ");
    }
    printf("\n\n\n\t\t\t\t");
        system("pause");
        system("cls");
    int n;
    printf("\n\n\n\n\t\t");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO THE PROJECT $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\t\t");
    printf("\t\t\t\t\t\t\t\t\t<<<<<<<<<<<<<<<ADMIN PAGE>>>>>>>>>>>>>>>>>\n\n\n\n\t\t");
    printf("1. Log in\n\n\t\t");
    printf("2. Registration\n\n\n\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        loading();
        user_login();
        break;
    case 2:
        loading();
        user_registration();
        break;
    default:
        printf("\n\n\t\t");
        printf("Wrong Pressed\n\n\t");
        system("pause");
        mainmenu();
    }
    getch();
}

int ConsoleTitle(void)
{

    SetConsoleTitle("1st_Workplace");

    return 0;

}
int MaximizeOutputWindow(void)
{

    HWND ConsoleWindow;

    ConsoleWindow = GetConsoleWindow();

    ShowWindow(ConsoleWindow, SW_MAXIMIZE);

    return 0;

}

int SetConsoleSize(void)
{

    system("mode CON: COLS=220");

    return 0;

}

int user_login()

{
    system("cls");
    system("COLOR 0E");
    printf("\n\n\n\n\t\t");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO THE PROJECT $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t-------------------------------------USER LOGIN PAGE---------------------------------------\n\n\n\n");
    printf("\n\n\t\tFor Login Enter User Name & Password\n\n");
    int i, rem=0, optioon=0;
    char ch;
    FILE *fp1,*fp2;
    fflush(stdin);
    char uname1[30];
    char passl[30];
    printf("\n\n\t\t\tUser Name: ");
    fgets(uname1, 30, stdin);
    fflush(stdin);

    printf("\n\t\t\tPassword: ");
    fgets(passl, 30, stdin);
    fp1 = fopen("regis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp1);
    fclose(fp1);
    for(i=0; i<100; ++i)
    {
        if ((0==strcmp(uname1,cust[i].uname)) && (0==strcmp(passl,cust[i].pass)))
        {
            printf("\n\n\t\tLogin Successfully\n");
            printf("\n");
            i=100;
            optioon=1;
            loading();
            system("cls");
            extra_logo();

        }

    }
    if(optioon==1)
    {
        system("pause");
    }
    else
    {

        printf("\n\n\t\t\tWrong User Name or Password\n\n\n\n\t\t");
        system("pause");
        printf("\n\n\n\n\t\t\t");
        printf("Press 1 for Log in Again\n\n\t\t\t");
        printf("Press 2 for Registration\n\n\n\n\t\t\t");
        printf("Enter Your Choice: ");
        fflush(stdin);
        scanf("%d",&choice);
        if(choice==1)
        {
            loading();
            user_login();
        }
        else if(choice==2)
        {
            loading();
            user_registration();
        }
        else
        {
            printf("\n\n\n\t\tWrong Entry\n\n\n\t\t");
            system("pause");
            mainmenu();
        }
    }
}

int user_registration(void)
{
    system("cls");
    user_style();
    printf("\n\n\n\t\t\t\t");
    printf("\t\t\t\t    For Registration: Enter Your[Full Name,User Name,Password,Mobile Number]\n\n");
    int i, rem=0, optioon;
    FILE *fp1,*fp2;
    fp2=fopen("pnumber.bin","rb+");
    if (fp2==NULL)
    {
        fp2 = fopen("pnumber.bin","wb+");
        fwrite(&rem, sizeof(rem), 1, fp2);
        fclose(fp2);
    }
    fread(&rem, sizeof(rem), 1, fp2);
    fclose(fp2);

    fp1 = fopen("regis.bin","rb+");
    if (fp1==NULL)
    {
        fp1 = fopen("regis.bin","wb+");
        fclose(fp1);
    }
    fread(&cus, sizeof(cus), 1, fp1);
    fclose(fp1);
    fflush(stdin);
    for(i=rem; i<rem+1; ++i)

    {

        printf("\n\n\n\t\t\tFull Name: ");
        fgets(cus[i].fname, 30, stdin);
        printf("\n\n\t\t\tUser Name: ");
        fgets(cus[i].uname, 30, stdin);
        printf("\n\n\t\t\tPassword: ");
        fgets(cus[i].pass, 30, stdin);
        printf("\n\n\t\t\tMobile Number: ");
        fgets(cus[i].mobile, 30, stdin);

    }

    fp1 = fopen("regis.bin","wb+");
    fwrite(&cus, sizeof(cus), 1, fp1);
    fclose(fp1);
    fp2 = fopen("pnumber.bin","wb+");
    ++rem;
    fwrite(&rem, sizeof(rem), 1, fp2);
    fclose(fp2);
    pc=pc+1;
    printf("\n\n\t\tYour are successfully Registered\n\n\t\t");
    printf("Thanks For Your Registration\n\n\t\t\t");
    printf("Press 1 for Login\n\n\t\t\t");
    printf("Press 2 for Again Registration\n\n\t\t\t");
    printf("Enter You choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        loading();
        user_login();
    }
    else if(choice==2)
    {
        loading();
        user_registration();
    }
    else
    {
        printf("\n\n\n\t\tWrong Entry\n\n\n\t\t");
        system("pause");
        mainmenu();
    }
}

int mainmenu()

{
    loading();
    system("cls");
    printf("\n\n\n\n\t\t");
    printf("\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO THE PROJECT $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\t\t");
    printf("\t\t\t\t\t\t\t\t\t<<<<<<<<<<<<<<<ADMIN PAGE>>>>>>>>>>>>>>>>>\n\n\n\n\t\t");
    printf("1. Log in\n\n\t\t");
    printf("2. Registration\n\n\n\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&n);
    switch(n)
    {

    case 1:
        loading();
        user_login();
        break;
    case 2:
        loading();
        user_registration();
        break;
    default:
        printf("\n\n\t\t");
        printf("Wrong Pressed\n\n\t");
        system("pause");

    }
}

extra_logo()

{
    printf("\n\n");
    style();
    system("COLOR 0E");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t                                                            ``      \n");
    printf("\t\t\t\t\t                                                    ```    ``````   \n");
    printf("\t\t\t\t\t                                                   ``````` ``````   \n");
    printf("\t\t\t\t\t                                                  ````````````````  \n");
    printf("\t\t\t\t\t                                                 ``````````````.    \n");
    printf("\t\t\t\t\t                                                  `````````````.`   \n");
    printf("\t\t\t\t\t                                                   `............    \n");
    printf("\t\t\t\t\t                                                     `.------.`     \n");
    printf("\t\t\t\t\t                        ````  ``                   ````....`        \n");
    printf("\t\t\t\t\t                         `````````   `          ```````````````     \n");
    printf("\t\t\t\t\t                           `.```````...`````` ```..```` ````````    \n");
    printf("\t\t\t\t\t                               `````  `.............`````````.```   \n");
    printf("\t\t\t\t\t                                        ``      `..``````..-.```    \n");
    printf("\t\t\t\t\t                                                  ..`````...`-.`.`  \n");
    printf("\t\t\t\t\t                                                 ``.........  .-....``````````````\n");
    printf("\t\t\t\t\t                                                 `..........    ```````..`````..``\n");
    printf("\t\t\t\t\t                               ``..`       ````` `..........            `.......` \n");
    printf("\t\t\t\t\t                            .//:::::: `.://////+//:--.........-://++oosssys/--..........```````    \n");
    printf("\t\t\t\t\t           `..`           /+////////oo+/////::::/+/.++osyyyysssssssssooooos+:-..............--.    \n");
    printf("\t\t\t\t\t         -:://:::--`       `++/////+yso++/////////:/+ohysosyyyyyyssssssooooos+:---...........--:-  \n");
    printf("\t\t\t\t\t          .+//:--:::/`      -++/////oyso++o+--:///////ohyysyyyyyyyysssssssoos+:----:----....----/` \n");
    printf("\t\t\t\t\t           `/++/:::::/`     /++/////yyso+ss/   `./////+yyyshhhhhhssssy/``  `+/:---/- ```.....----  \n");
    printf("\t\t\t\t\t            `/++/:::::/`   .+++/////syso+oo/    `-+////so.:-.`yhhssssy.    .+::--:/.\n");
    printf("\t\t\t\t\t              :+++:::::/`  :+++///+-oyso+oo+ ````.+////oo.--``hhhosssy`    -+::--::-----....```    \n");
    printf("\t\t\t\t\t               -+++/::://``o+++///+`/yss+soo`````.+////oo...`.hhhoysss     :+::----..----------`   \n");
    printf("\t\t\t\t\t                ./++/:////:oo++//+: -yss+soo.````-+////oo/:``.hhyoysso```  //:::--------------:`   \n");
    printf("\t\t\t\t\t                 `/++//////ss+//++.``sss+osso::./o+////o+-+/.-hhyoysy+ ``` +/::-:/-----------:/    \n");
    printf("\t\t\t\t\t                   :++/////+o+/++/```-sso+/ooo++//+////s:.-::/hhysssy/`````o/::-//``` ```....-.    \n");
    printf("\t\t\t\t\t                    -+++//////+++-````-ooo+///++++////++..--.-yyysysy-````-+/::-/:--....```        \n");
    printf("\t\t\t\t\t                     ./++///+++++.....--/oo++++//////+/..---.:ysysysh.`...:/::::-------------`     \n");
    printf("\t\t\t\t\t                  ````./++/+++++/--....--/ossooo++oss/:------:ysysysh....-/++/::::----------:.``   \n");
    printf("\t\t\t\t\t                 ``````./+++++++/--....-//////+++oo+++:------/ysssyyy.....::/+++++/:-------:/````` \n");
    printf("\t\t\t\t\t                 `````../oooooo+:.....-::::::::::--:::::----.:+ossso+.....--------:///++/////.```` \n");
    printf("\t\t\t\t\t                 ``````.::::------````-::----....--...---....-//::::-``.......`..........---.````  \n");
    printf("\t\t\t\t\t                       `....`````.````.......` ````````..````.--.....``````````.````````````       \n");

    printf("\n\n\n\t\t\t");
    system("pause");
    home_page();
}


int home_page()

{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t  ******************************************************************\n\n");
    style();
    printf("\n\n\t\t\t\t\t\t\t\t   ******************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t__________________HOME PAGE________________\n\n");
    printf("\n\n\n\t\t\tPress 1.========<> Candidate\n\n\t\t\t");
    printf("Press 2.========<> Voter\n\n\t\t\t");
    printf("Press 3.========<> Result\n\n\t\t\t");
    printf("Press 4.========<> Voter Information\n\n\t\t\t");
    printf("Press 5.========<> Candidate Information\n\n\n\n\t\t\t");
    printf("Press 6.========<> Exit\n\n\n\n\t\t\t");

    printf("Enter Your Choice: ");

    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        candidate();
        break;
    case 2:
        system("cls");
        voter();
        break;
    case 3:
        system("cls");
        result();
        break;
    case 4:
        system("cls");
        voter_information_list();

        break;
    case 5:
        system("cls");
        candidate_information();
        break;
    case 6:
        getch();
        break;
    default:
        printf("\n\n\n\t\t\tWrong Entry\n\n\t\t\t");
        system("pause");
        home_page();


    }
}

style()

{
    system("COLOR 5E");
    int i;
    char a[15]=" Voting System ";
    printf("\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("\xB1");
        Sleep(10);
    }
    for(i=0; i<15; i++)
    {
        printf("%c",a[i]);
        Sleep(60);
    }
    for(i=0; i<20; i++)
    {
        printf("\xB1");
        Sleep(10);
    }

}

int user_style()

{
    system("COLOR 1E");
    int i;
    char a[22]=" Welcome To New User ";
    printf("\n\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
    for(i=0; i<22; i++)
    {
        printf("%c",a[i]);
        Sleep(60);
    }
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
}

int loading()

{
    int i;
    char a[8]="Loading";
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
    for(i=0; i<8; i++)
    {
        printf(" ");
        printf("%c",a[i]);
        Sleep(60);
    }
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }

}

int project_logo()

{
    system("COLOR 0E");
    int i;
    char a[24]="    __VOTING SYSTEM__    ";
    printf("\n\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t\t\t\t");

    for(i=0; i<64; i++)
    {
        printf("*");
        Sleep(1);
    }
    printf("\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("*");
        Sleep(2);
    }
    for(i=0; i<24; i++)
    {
        printf("%c",a[i]);
        Sleep(15);
    }
    for(i=0; i<20; i++)
    {
        printf("*");
        Sleep(2);
    }
    printf("\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<64; i++)
    {
        printf("*");
        Sleep(1);
    }
}

int voter()

{
    system("cls");
    project_logo();
    printf("\n\n\n\n\n\t\t1. Log in(Voter)\n\n\t\t");
    printf("2. Registration(Voter)\n\n\n\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        voter_login();
        break;
    case 2:
        system("cls");
        voter_registration();
        break;
    default:
        printf("\n\n\t\t");
        printf("Wrong Pressed\n\n\t");
        system("pause");
        system("cls");
        voter_mainmenu();
    }
}

int voter_login()

{
    system("cls");
    project_logo();
    printf("\n\n\n\n\t\tFor Voter's Login Enter NID & Password\n\n");
    int i, rem=0, optioon=0;
    char ch;
    FILE *fp3,*fp4;
    fflush(stdin);
    char nidl[25];
    char passl[25];
    printf("\n\n\t\t\tNational Id: ");
    fgets(nidl, 30, stdin);
    fflush(stdin);

    printf("\n\t\t\tPassword: ");
    fgets(passl, 30, stdin);
    fp3 = fopen("voterregis.bin","rb+");
    fread(&cust, sizeof(cust), 1, fp3);
    fclose(fp3);
    for(i=0; i<100; ++i)
    {
        if ((0==strcmp(nidl,cust[i].nid)) && (0==strcmp(passl,cust[i].pass)))
        {
            printf("\n\n\t\tLogin Successfully\n");
            loading();
            system("cls");
            logo();
            system("pause");
            system("cls");
            printf("\n");
            i=100;
            optioon=1;
        }

    }
    if(optioon==1)
    {
        system("pause");
    }
    else
    {

        printf("\n\n\t\t\tWrong National Id or Password\n\n\n\n\t\t");
        system("pause");
        printf("\n\n\n\n\t\t\t");
        printf("Press 1 for Log in Again(Voter)\n\n\t\t\t");
        printf("Press 2 for Registration(Voter)\n\n\n\n\t\t\t");
        printf("Enter Your Choice: ");
        fflush(stdin);
        scanf("%d",&choice);
        if(choice==1)
        {
            system("cls");
            voter_login();
        }
        else if(choice==2)
        {
            system("cls");
            voter_registration();
        }
        else
        {
            printf("\n\n\n\t\tWrong Entry\n\n\t\t");
            system("cls");
            voter_mainmenu();
        }
    }
}

int voter_registration(void)

{
    voter_information_form();
    system("cls");
    voter_style();
    printf("\n\n\n\t\t\t\t");
    printf("\t\t\tFor Registration(Voter): Enter Your[Full Name,Father's/Husband's Name, National Id,Address,Mobile Number,Password]\n\n");
    int i, rem=0, optioon;
    FILE *fp3,*fp4;
    fp4=fopen("vnumber.bin","rb+");
    if (fp4==NULL)
    {
        fp4 = fopen("vnumber.bin","wb+");
        fwrite(&rem, sizeof(rem), 1, fp4);
        fclose(fp4);
    }
    fread(&rem, sizeof(rem), 1, fp4);
    fclose(fp4);



    fp3 = fopen("voterregis.bin","rb+");
    if (fp3==NULL)
    {
        fp3 = fopen("voterregis.bin","wb+");
        fclose(fp3);
    }
    fread(&cus, sizeof(cus), 1, fp3);
    fclose(fp3);
    fflush(stdin);
    for(i=rem; i<rem+1; ++i)

    {

        printf("\n\n\n\t\t\tFull Name: ");
        fgets(cus[i].fname, 30, stdin);
        printf("\n\n\t\t\tFather's/Husband's Name: ");
        fgets(cus[i].gname, 30, stdin);
        printf("\n\n\t\t\tNational Id: ");
        fgets(cus[i].nid, 30, stdin);
        printf("\n\n\t\t\tAddress: ");
        fgets(cus[i].add, 30, stdin);
        printf("\n\n\t\t\tMobile Number: ");
        fgets(cus[i].mobile, 30, stdin);
        printf("\n\n\t\t\tPassword: ");
        fgets(cus[i].pass, 30, stdin);

    }

    fp3 = fopen("voterregis.bin","wb+");
    fwrite(&cus, sizeof(cus), 1, fp3);
    fclose(fp3);
    fp4 = fopen("vnumber.bin","wb+");
    ++rem;
    fwrite(&rem, sizeof(rem), 1, fp4);
    fclose(fp4);
    pc=pc+1;
    printf("\n\n\t\tYour are successfully Registered\n\n\t\t");
    printf("Thanks For Your Registration\n\n\t\t\t");
    printf("Press 1 for Login(Voter)\n\n\t\t\t");
    printf("Press 2 for Again Registration(Voter)\n\n\t\t\t");
    printf("Enter You choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        voter_login();
    }
    else if(choice==2)
    {
        voter_registration();
    }
    else
    {
        printf("\n\n\n\t\tWrong Entry\n\n\\n\t\t");
        system("pause");
        voter_mainmenu();
    }
}

int voter_mainmenu()

{
    system("cls");
    system("COLOR 4E");
    printf("\n\n\t\t");
    printf("1. Log in(Voter)\n\n\t\t");
    printf("2. Registration(Voter)\n\n\n\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        //system("cls");
        voter_login();
        break;
    case 2:
        //system("cls");
        voter_registration();
        break;
    default:
        printf("\n\n\t\t");
        printf("Wrong Pressed\n\n\t");
        system("pause");
        voter();
    }
}

int voter_information_form()

{
    system("cls");
    project_logo();

    fp6 = fopen("Voter information.txt","a");

    printf("\n\n\n\n\n\t\tEnter Your Full Name: ");
    gets(y[i].fname);
    gets(y[i].fname);

    printf("\n\n\t\tEnter National ID No: ");
    gets(y[i].nid);

    printf("\n\n\t\tEnter Your Guardian Name: ");
    gets(y[i].gname);

    printf("\n\n\t\tEnter Your Address: ");
    gets(y[i].add);

    printf("\n\n\t\tEnter Your Contact Number: ");
    gets(y[i].mobile);


    fprintf(fp6,"Name:%s\t\tNID:%s\t\tGUARDIAN:%s\t\tADDRESS:%s\t\tCONTACT NO:%s\n\n",y[i].fname,y[i].nid,y[i].gname,y[i].add,y[i].mobile);
    printf("\n");
    fclose(fp6);
    printf("\n\n\n\t\t\tYour Information Are Process\n\n\n\t\t");
    system("pause");
    loading();

}
int voter_information_list()

{
    char ch;
    FILE *fp6;
    printf("\n\n\n");

    printf("\t\t\t--------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t**********VOTER INFORMATION*************\n");
    printf("\t\t\t--------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n");
    fp6 = fopen("Voter information.txt","r");
    while(!feof(fp6))
    {
        ch = fgetc(fp6);
        printf("%c",ch);
    }
    printf("\n\n\n\t\t\t");
    system("pause");
    home_page();
}

int voter_style()

{
    system("COLOR 5F");
    int i;
    char a[34]=" People's Republic of Bangladesh ";
    printf("\n\n\t\t\t\t\t\t\t\t\t");
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
    for(i=0; i<34; i++)
    {
        printf("%c",a[i]);
        Sleep(60);
    }
    for(i=0; i<20; i++)
    {
        printf("\xB2");
        Sleep(10);
    }
}
int candidate()
{
    char pname[15];
    char ppass[16];
    int b;
    project_logo();
    printf("\n\n\n\t\tParty Name: ");
    scanf("%s",&pname);
    printf("\n\n\t\tEnter Your Password: ");
    scanf("%s",&ppass);
    if(strcmp(pname,"bnp") == 0 && strcmp(ppass, "1234") == 0)
    {
        printf("\n\n\n\tYou Have Successfully Logged In...\n\n\n");
        loading();
        system("cls");
        project_logo();
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("\t\t\t\t\t\t\t\t\t\t    WELCOME TO BANGLADESH NATIONALIST PARTY\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n");
        printf("\t\tIf Are You Want To See How Many Votes Do You Get Then: \n\n\n\t\t\t");
        system("pause");
        system("cls");
        result();

    }
    else if (strcmp(pname,"bal") == 0 && strcmp(ppass, "1234") == 0)
    {
        printf("\n\n\n\tYou Have Successfully Logged In...\n\n\n");
        loading();
        system("cls");
        project_logo();
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("\t\t\t\t\t\t\t\t\t\t    WELCOME TO BANGLADESH AWAMILEAGUE PARTY\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n");
        printf("\t\tIf Are You Want To See How Many Votes Do You Get Then: \n\n\n\n\t\t\t");
        system("pause");
        system("cls");
        result();
    }
    else if (strcmp(pname,"bjp") == 0 && strcmp(ppass, "1234") == 0)
    {
        printf("\n\n\n\tYou Have Successfully Logged In...\n\n\n");
        loading();
        system("cls");
        project_logo();
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("\t\t\t\t\t\t\t\t\t\t    WELCOME TO BANGLADESH JATIO PARTY\n");
        printf("\t\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n");
        printf("\t\tIf Are You Want To See How Many Votes Do You Get Then: \n\n\n\t\t\t");
        system("pause");
        system("cls");
        result();
    }
    else
    {
        printf("\n\n\n\t\tUser Name or Password are Incorrect\n\n\n\t\t");
        system("pause");
        home_page();
    }
}

int candidate_information()

{

    int a;
    loading();
    system("cls");
    project_logo();
    printf("\n\n\n\n\n\t\t\tCandidates are:\n\n\t\t\t");
    printf("Press 1. SHEIKH HASINA\n\n\t\t\t");
    printf("Press 2. KHALEDA ZIA\n\n\t\t\t");
    printf("Press 3. HUSSAIN MUHAMMAD ERSHAD\n\n\n\t\t\t");
    printf("Enter Your Choice: ");
    scanf("%d",&a);
    switch(a)

    {

    case 1:
        loading();
        sheikh_hasina();
        break;
    case 2:
        loading();
        khaleda_zia();
        break;
    case 3:
        loading();
        muhammad_ershad();
        break;
    default:
        printf("\n\n\nt\t\tWrong Entry\n\n\n\t\t");
        system("pause");
        home_page();

    }
}
int khaleda_zia()
{
    system("cls");
    project_logo();
    printf("\n\n\n\t");
    printf("Name: Begum Khaleda Zia\n\t");
    printf("Date of Birth:15 August 1945\n\t");
    printf("Spouse:GENERAL ZIAUR RAHMAN\n\t");
    printf("Birth Place:Dinajpur,Bengal Presidency\n\t");
    printf("Religion:ISLAM\n\t");
    printf("Profession: Politician\n\t");
    printf("Political Party: Bangladesh Nationalist Party(BNP)\n\n\n\t");
    printf("Political Journey\n\t");
    printf("KHALEDA ZIA is the 9th PRIME MINISTER of Bangladesh\n\t");
    printf("i.Elected Chairperson of the BNP in August(1984)\n\t");
    printf("ii.She won an election for the first time in 1991\n\t");
    printf("iii.1991-1996 She served as the PRIME MINISTER of Bangladesh in her First Term\n\t");
    printf("iv.1996-2001 She served as the Leader of the Opposition\n\t");
    printf("vi.2001-2006 She served as the PRIME MINISTER of Bangladesh in her Second Term\n\t");
    printf("vii.2008-2014 She served as the Leader of the Opposition for the Second Time\n\n\n\t");
    printf("Awards:\n\t");
    printf("New Jersey State Honored Zia as a'Fighter for Democracy'\n\t");
    printf("In its list of the 100 Most Powerful Women in the World, Forbes magazine ranked Khaleda Zia at number 14 in 2004\n\n\n\t");
    system("pause");
    candidate_information();

}
int sheikh_hasina()
{
    system("cls");
    project_logo();
    printf("\n\n\n\t");
    printf("Name: Sheikh Hasina Wazed\n\t");
    printf("Date of Birth: 28 September 1947\n\t");
    printf("Birth Place: Tungipara Gopalganz\n\t");
    printf("Spouse: Dr.M. A. Wazed Miah\n\t");
    printf("Sheikh Hasina is the daughter of Bangladesh's first President Sheikh Mujibur Rahman\n\t");
    printf("Religion:ISLAM\n\t");
    printf("Profession: Politician\n\t");
    printf("Political Party: Bangladesh Awami League(BAL)\n\n\n\t");
    printf("Political Journey\n\t");
    printf("SHEIKH HASINA is the current and 10th PRIME MINISTER of Bangladesh\n\t");
    printf("i.She won an election for the first time in 1996\n\t");
    printf("ii.1996-2001 She served as the PRIME MINISTER of Bangladesh in her First Term\n\t");
    printf("iii.1986-1990 She served as the Leader of the Opposition\n\t");
    printf("iv.1991-1996 She served as the Leader of the Opposition\n\t");
    printf("v.2009-2014 She served as the PRIME MINISTER of Bangladesh in her Second Term\n\t");
    printf("vi.2009-2014 She served as the PRIME MINISTER of Bangladesh in her Third Term\n\n\n\t");
    printf("Achievements:\n\t");
    printf("Sheikh Hasina is one of the most powerful women in the world, ranking 30th on Forbes' list of The World's 100 Most Powerful Women in 2017\n\t");
    printf("Sheikh Hasina is a member of the Council of Women World Leaders\n\t");
    printf("Sheikh Hasina's second term (2009 to 2014) as Prime Minister is overshadowed by quite a few scandalous incidents\n\t");
    printf("These include:1.Padma Bridge Scandal 2.Hallmark-Sonali Bank Scam 3.Share market Scandal 3.and Bangladesh road safety protests 2018\n\n\n\t");
    system("pause");
     candidate_information();

}
int muhammad_ershad()
{
    system("cls");
    project_logo();
    printf("\n\n\n\n\n\t");
    printf("Name: Hussain Muhammad Ershad\n\t");
    printf("Date of Birth: 01 February 1930\n\t");
    printf("Birth Place: Rangpur\n\t");
    printf("Spouse: Rowshan Ershad\n\t");
    printf("Profession: Politician & Retired Military Officer\n\t");
    printf("He is the founder of the Jatiya Party\n\t");
    printf("Ershad is currently a member of parliament and the Chairman of Jatiya Party\n\t");
    printf("Ershad served as the President of Bangladesh from 1983 to 1990\n\t");
    printf("Ershad stabilized the Bangladesh Armed Forces\n\t");
    printf("Ershad serviced Bangladesh Military in 1973-1986\n\t");
    printf("Ershad introduced the Upazila and Zila Parishad system\n\n\n\t");
    system("pause");
    candidate_information();

}

int voting()
{
    int n,stop;
   printf("Enter Your Choice: ");
   scanf("%d",&n);
   if(n>0&&n<=3)
   {
    Vote(n);
   }
   else
    {
    printf("\n\n\n\\t\t\tEnter Valid Input(1-3)\n");
   }
  printf("\n\n\n\t\tPress 1 continue else 0 to finish Voting: ");
  scanf("%d",&stop);
  if(stop==1)
  {
      voter_login();
  }

  else if(stop==0)
    {

  Vote(stop);
    }
    else
    {
        printf("\n\n\n\t\t\tWrong Entry\n");
        home_page();
    }
}
void Vote(int choice)
{
    static int a=0,b=0,c=0;
 if(choice==1)
 {
  a=a+1;
 }
 if(choice==2)
 {
  b=b+1;
   }
 if(choice==3)
 {
  c=c+1;
 }
    if(choice==0)
 {
  FILE *fp5;
  fp5=fopen("vote.txt","w");
  //fflush(stdin);
  ///fflush(stdin);
  fprintf(fp5,"\t\tBangladesh Awami League = %d\n\n\t\tBangladesh Nationalist Party = %d\n\n\t\tBangladesh Jatio Party = %d",a,b,c);
  if(a>b&&a>c)
  {

      fprintf(fp5,"\n\n\n\t\tThe Winner Party Is Bangladesh Awami League And get %d vote\n\n",a);

      fclose(fp5);
  }
  else if(b>a&&b>c)
  {
      fprintf(fp5,"\n\n\n\t\tThe Winner Party Is Bangladesh Nationalist Party And get %d vote\n\n",b);

     fclose(fp5);
  }
  else if(c>a&&c>b)
  {
     fprintf(fp5,"\n\n\n\t\tThe Winner Party Is Bangladesh Jatio Party And get %d vote\n\n",c);

     fclose(fp5);
  }
  //else
    //printf("something is wrong\n)

  fclose(fp5);
 }
 //
 home_page();
}
int logo()
{
    style();
    system("cls");
    printf("   .............................................................................................................................................................................................................\n");
    printf("   *```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````*\n");
    printf("   *                                                                                                   `                                                                                                       *\n");
    printf("   *                                                                                             `  -:s/.:+o//oo `.---`                                                                                        *\n");
    printf("   *                                             ```                                                ./+o ///.-+/:///::/y+:-:`                                                                                  *\n");
    printf("   *                                             -//                                              //s::.+o``/oo://+:--.``-o+/:-                                                                                *\n");
    printf("   *                                             -//                                             /ss/  y//`yos/o//:--.     .:os+                -so                         `/o-                               *\n");
    printf("   *                                             -/+                          :s/`              `.s+/ -y+./s+////:`:/+++/:-  :/y                 ods-                       -sdh`                              *\n");
    printf("   *                                             -/+                           .hms-  `o-.      sso-:o/+//y//:---.   `.--:/+-                    .mNo.                     +sho                                *\n");
    printf("   *                                             -/+                             omys. -+oy:    o/:-oosho++o.`             .`                   sdomNo.                   ssd:                                 *\n");
    printf("   *                                             -/+                             /hsh/  -so:   `yo:ss/:/++//-                                  -: -Nd+`                 :yyh.                                  *\n");
    printf("   *                             `+:             -/o                              ossy/  :sh+ :y/o.o-so/-:        `:/+++++:`                       +Mho                +yhs                                    *\n");
    printf("   *                            -h/              -/o                              `yooy-  y:o o++`o-+++///     -/sys/:-.````                        yMs+             `ysd:                                     *\n");
    printf("   *                          `so`.--::::::/::/:://o                               -hooh.`ys. /o:o//s..ys.  ./sss/.                                 `dMo:           :ysd.                                      *\n");
    printf("   *             do.        `:s-/soyh/:+o--o+-+o-ohy.                                sssoh`y:y/ .y-+s`.++/ .+sss/`                                    -NNy-         +shs                                       *\n");
    printf("   *             +NMh:     -do`yshhsyhh++y//so/oh+sys+            `                  `d+yo+./h+o`s//o+o:.`ossso`                                       /Mhs`      `sod/                                        *\n");
    printf("   *              .hMMmo..ss` o+os/yoyodohsoodo+sy+h+oo       -+ym+                   :hoyy.`h/s+s+/y/+ -yssy/                                          yMhy     -ysd.                                         *\n");
    printf("   *               +NMMMNs`  hodododohsy+y//yo++d+ohoh`  .+yNMmo.                      /sssy-+o:h-//o. +yyoh/                                           `dMys   +syy`                                          *\n");
    printf("   *                 `dMMMMNh+d+h/h/h/yso:y::oo::y::h/h+ymMMMd/`                        :ssso+oym`+oo syyod/                                             -NNyy.s+d/                                            *\n");
    printf("   *                .yNshMMMMMMMMNNdmymNhhNddmNmmNNNMMMMMMNs.                            .yss/ `m`+//+yyod/                                               +MmoNsm-                                             *\n");
    printf("   *             +oyNMo..-hNNNMMMMMMMMMMMMMMMMMMMMMMMNNmmh+/:---://                       `yos- ms+::hhod-                                                 hM::hmho:.                                          *\n");
    printf("   *             sNMMyoosyyo++oyddhyso+/+osyhys+/++ooo/-.-+syysoooo                        `yos d+ `hhsy.                                                  -Mdydhhhhdmdddhys+::`-Mdydhhhhs+::                  *\n");
    printf("   *              -syyyysso+ooo+oshyssooooosssyysssssooosyysooosssso                         `hh oo +my+                                                     sysssooo+++++////:sysss++////:.                   *\n");
    printf("   *                  `...`      `-::-.`  ``.--:::.   `-.`     `                             .d/:h dh.                                                                                                         *\n");
    printf("   *                                                                                          `++Mos                                                                                                           *\n");
    printf("   *                                                                                            .dd                                                                                                            *\n");
    printf("   *                                                                                             .N:                                                                                                           *\n");
    printf("   *                                                                                                                                                                                                           *\n");
    printf("   *                                                                                                                                                                                                           *\n");
    printf("   *                                Press:1                                                     Press:2                                                            Press:3                                     *\n");
    printf("   *                                                                                                                                                                                                           *\n");
    printf("   *...........................................................................................................................................................................................................*\n");
    printf("   `````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");

voting();
}

int result()

{
    project_logo();
    printf("\n");
    char ch;

    FILE *fp5;
    fp5= fopen("vote.txt","r");
    while(!feof(fp5))
    {
        ch = fgetc(fp5);
        printf("%c",ch);
    }
    system("pause");
    home_page();
}




