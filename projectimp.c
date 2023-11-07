#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
void gotoxy(int ,int );
void signin();
void login();
void menu();
void list();
void list1();
void sample();
void display();
int search(char*,char*);
void modify();
void deleteacc();
void search2();
void search1();
void forgot();
void backup();
void admin();
void list2();
void deleteAnyAcc();
void duplicate();
char name[20];
char signame[20];
char word2[20];
struct Cyber
{
    char username[20];
    char password[20];
    char confirm[20];
    char email[20];
    int mobile;
    char answer[20];
};
int main()
{
    gotoxy(15,8);
    printf("<--:Cyber Security Management System:-->");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    
    char option;
    system("cls"); //clrscr()
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate choice to perform following task.");
    gotoxy(10,7);
    printf("a : sign in as new user.");
    gotoxy(10,8);
    printf("b : login.");
    gotoxy(10,9);
    printf("c : signin as admin");
    gotoxy(10,10);
    printf("Enter your option : ");
    scanf("%c",&option);
    switch(option)
    {
    	case 'a':signin();
    	         break;
        case 'b':login();
                 break;
        case 'c':admin();
     			 break;
    }
}
void signin()
{
    FILE *fp,*ft;
    struct Cyber std;
    system("cls");
	char another='y';
    fp = fopen("record1.txt","ab+");
    ft = fopen("target.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
  
        gotoxy(10,3);
        printf("<--:CREATING NEW ACCOUNT:-->");
        gotoxy(10,5);
        printf("Enter details of user.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(std.username);
        strcpy(signame,std.username);
        gotoxy(10,8);
        printf("Enter Password : ");
        gets(std.password);
        char word1[20];
        strcpy(word1,std.password);
        gotoxy(10,9);
        printf("Enter confirm password : ");
        sample();
        if(strcmp(word1,word2)!=0)
        {
        	gotoxy(10,10);
        	printf("Sorry! your password and confirm password are not matching");
        	Sleep(1000);
        	signin();
        }
        //check();
        gotoxy(10,10);
        printf("Enter Email : ");
        gets(std.email);
        gotoxy(10,11);
        printf("Enter Mobile Number : ");
        scanf("%d",&std.mobile);
        gotoxy(10,13);
        printf("Congratulations! your account is successfully created");
        gotoxy(10,15);
        printf("##### SECURITY QUESTION #####");
        gotoxy(10,16);
        printf("Birthday month : ");
        gets(std.answer);
        fwrite(&std,sizeof(std),1,fp);
        fwrite(&std,sizeof(std),1,ft);
        fclose(fp);
        fclose(ft);
        gotoxy(10,18);
        list1();
}
void list()
{
	 char another='y';
    printf("Want to perform any other action? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
       system("cls");
    while(another=='y'){
    	gotoxy(10,3);
    	printf("<--:MENU:-->");
    	gotoxy(10,4);
    	printf("Enter appropriate number to perform following task.");
    	gotoxy(10,5);
		printf("1. View Account Details");
		gotoxy(10,6);
		printf("2. Modify");
		gotoxy(10,7);
		printf("3. Delete");
		gotoxy(10,8);
		printf("4. Forgot Password?");
		gotoxy(10,9);
		printf("5. logout");
		gotoxy(10,10);
		printf("Enter your choice : ");
		int choice;
		scanf("%d",&choice);
	switch(choice)
    {
    case 1:
        search2();
        break;

    case 2:
        modify();
        break;

    case 3:
        deleteacc();
        break;
    case 4:
         forgot();
         break;
    case 5:
        exit(1);
        break;

    default:
        gotoxy(10,11);
        printf("Invalid Choice.");
    }
  }
    gotoxy(10,3);
    printf("Thanks for using!\n");
    exit(1);
}
void login()
{
	//char name[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:LOGIN:-->");
    gotoxy(10,5);
    printf("Enter Username : ");
    fflush(stdin);
    gets(name);
    char password1[128], c;
   int index = 0;
  gotoxy(10,6);
   printf("Enter Password : ");
   while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       password1[index++] = c;
       putch('*');
   }
   password1[index] = '\0';
   int k=search(name,password1);
   if(k==1)
   {
   	  gotoxy(10,7);
   	  printf("Congratulations! you are successfully logged in\n");
   }
   else{
   	gotoxy(10,7);
   	printf("Invalid Username or Password\n");
   	Sleep(2000);
   	login();
   }
   gotoxy(10,8);
   list();
  
}
int search(char* name,char* password1)
{
    FILE *fp;
    struct Cyber std;
 	fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if((strcmp(name,std.username) == 0)&&(strcmp(password1,std.password)==0)){
            return 1;
        }
    }
    fclose(fp);
    return 0;
}


void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void sample()
{
	int index=0;
	char c;
	struct Cyber std;
	while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       std.confirm[index++] = c;
       putch('*');
   }
   std.confirm[index] = '\0';
   strcpy(word2,std.confirm);
}
void display()
{
	FILE *fp;
    int i=1,j;
    struct Cyber std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW ACCOUNT DETAILS:-->");
    gotoxy(10,5);
    printf("S.No   USERNAME       PASSWORD     MOBILE NO      EMAIL");
    gotoxy(10,6);
    printf("---------------------------------------------------------------------------");
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-15s%-13s%-15d%-30s",i,std.username,std.password,std.mobile,std.email);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,j+4);
    list2();
}
void deleteacc()
{
	char name1[20];
    FILE *fp,*ft;
    struct Cyber std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE ACCOUNT:-->");
    gotoxy(10,5);
    printf("Enter name of the user to delete account : ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp1.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    if(strcmp(strlwr(name),strlwr(name1))!=0){
    	gotoxy(10,7);
    	printf("Sorry!,you are trying to delete another user account check it once");
    	Sleep(2000);
    	deleteacc();
    }
    	while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(name1,std.username)!=0)
            fwrite(&std,sizeof(std),1,ft);
    	}
    
   
    fclose(fp);
    fclose(ft);
    remove("record1.txt");
    rename("temp1.txt","record1.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,11);
    menu();
}
void modify()
{
	char name1[20];
    FILE *fp;
    struct Cyber std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of the user to modify: ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    if(strcmp(strlwr(name),strlwr(name1))==0){
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(name),strlwr(std.username)) == 0){
            gotoxy(10,7);
            printf("Enter username: ");
            gets(std.username);
            gotoxy(10,8);
            printf("Enter password : ");
            gets(std.password);
            gotoxy(10,9);
            printf("Enter confirm password : ");
            sample();
            gotoxy(10,10);
            printf("Enter Email : ");
            fflush(stdin);
            gets(std.email);
            gotoxy(10,11);
            printf("Enter Mobile number : ");
            fflush(stdin);
            scanf("%d",&std.mobile);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    }
    else{
    	gotoxy(10,7);
    	printf("Sorry! you are trying to modify another user account check it once");
    	Sleep(2000);
    	modify();
    }
    fclose(fp);
    gotoxy(10,16);
    list();
}
void search1()
{
    FILE *fp;
    struct Cyber std;
    char name1[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH ACCOUNT:-->");
    gotoxy(10,5);
    printf("Enter name of the user : ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    if(strcmp(strlwr(name1),strlwr(signame))==0){
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(name1,std.username) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.username);
            gotoxy(10,9);
            printf("Mobile Number : %d",std.mobile);
            gotoxy(10,10);
            printf("Password : %s",std.password);
            gotoxy(10,11);
            printf("Email : %s",std.email);
        }
    }
    }
    else{
    	gotoxy(10,6);
    	printf("Sorry! you are trying to view another user account check it once");
    	Sleep(2000);
    	search1();
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,17);
    list1();
}
void list1()
{
	 char another='y';
    printf("Want to perform any other action? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
       system("cls");
    while(another=='y'){
    	gotoxy(10,3);
    	printf("<--:MENU:-->");
    	gotoxy(10,4);
    	printf("Enter appropriate number to perform following task.");
    	gotoxy(10,5);
		printf("1. View Account");
		gotoxy(10,6);
		printf("2. Signout");
		gotoxy(10,7);
		printf("Enter your choice : ");
		int choice;
		scanf("%d",&choice);
	switch(choice)
    {
    case 1:
        search1();
        break;
    case 2:
        exit(1);
        break;

    default:
        gotoxy(10,8);
        printf("Invalid Choice.");
    }
  }
    gotoxy(10,3);
    printf("Thanks for using!\n");
    exit(1);
}
void admin()
{
    FILE *fa;
    struct Cyber std;
    char name1[20];
    int bufferLength=255;
    char line[bufferLength];
    system("cls");
    gotoxy(10,3);
    printf("<--:CHECKING PROCESS IS GOING ON........:-->");
    gotoxy(10,5);
    printf("Enter name of the admin : ");
    fflush(stdin);
    gets(name1);
    int wordExist=0;
    int linenum=1;
    fa = fopen("owner.txt","r");
    if(fa == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fgets(line, bufferLength, fa))
	{
		if(strstr(line,name1))
		{
			wordExist=1;
			break;
		}
		linenum++;
		
	}
	fclose(fa);
	if (wordExist==1)
	{
		gotoxy(10,6);
		printf("You are valid member to access the data!!.......");
	}
	else 
	{
		gotoxy(10,6);
		printf("Sorry! You are not valid member to access the data");
		Sleep(2000);
		menu();
	}
    
    gotoxy(10,8);
    list2();
}
void list2()
{
	char another='y';
    printf("Want to perform any other action? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
       system("cls");
    while(another=='y'){
	char option;
    system("cls"); //clrscr()
    gotoxy(10,3);
    printf("<--:OPERATIONS:-->");
    gotoxy(10,5);
    printf("Enter appropriate choice to perform following task.");
    gotoxy(10,6);
    printf("a : Display");
    gotoxy(10,7);
    printf("b : Delete Account.");
    gotoxy(10,8);
    printf("c : Recovery");
    gotoxy(10,9);
    printf("d : backup");
    gotoxy(10,10);
    printf("e : signout");
    gotoxy(10,11);
    printf("Enter your option : ");
    scanf("%c",&option);
    switch(option)
    {
    	case 'a':display();
    	         break;
        case 'b':deleteAnyAcc();
                 break;
        case 'c':duplicate();
        		 break;
 		case 'd':backup();
				 list2();
 				 break;
        case 'e':exit(1);
     			 break;
 		default:gotoxy(10,12);
                printf("Invalid Choice.");
    }
   }
}
void deleteAnyAcc()
{
	char name1[20];
    FILE *fp,*ft;
    struct Cyber std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE ACCOUNT:-->");
    gotoxy(10,5);
    printf("Enter name of the user to delete account : ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp1.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(name1,std.username)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record1.txt");
    rename("temp1.txt","record1.txt");
    gotoxy(10,10);
    //backup();
    list2();
}
void search2()
{
    FILE *fp;
    struct Cyber std;
    char name1[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH ACCOUNT:-->");
    gotoxy(10,5);
    printf("Enter name of the user : ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    if(strcmp(strlwr(name1),strlwr(name))==0){
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(name1,std.username) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.username);
            gotoxy(10,9);
            printf("Mobile Number : %d",std.mobile);
            gotoxy(10,10);
            printf("Password : %s",std.password);
            gotoxy(10,11);
            printf("Email : %s",std.email);
        }
    }
    }
    else{
    	gotoxy(10,6);
    	printf("Sorry! you are trying to view another user account check it once");
    	Sleep(2000);
    	search2();
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,17);
    list();
}
void duplicate()
{
	FILE *ft;
    int i=1,j;
    struct Cyber std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW ACCOUNT DETAILS:-->");
    gotoxy(10,5);
    printf("S.No   USERNAME       PASSWORD     MOBILE NO      EMAIL");
    gotoxy(10,6);
    printf("---------------------------------------------------------------------------");
    ft = fopen("target.txt","rb+");
    if(ft == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,ft) == 1){
        gotoxy(10,j);
        printf("%-7d%-15s%-13s%-15d%-30s",i,std.username,std.password,std.mobile,std.email);
        i++;
        j++;
    }
    fclose(ft);
    gotoxy(10,j+4);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,j+4);
    list2();
}
void backup()
{
	FILE *ft,*fp;
    struct Cyber std;
    char name1[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:BACKUP:-->");
    gotoxy(10,5);
    printf("Enter name of the user : ");
    fflush(stdin);
    gets(name1);
    ft = fopen("target.txt","rb+");
    fp = fopen("record1.txt","ab+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,ft ) == 1){
        if(strcmp(name1,std.username) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.username);
            gotoxy(10,9);
            printf("Password : %s",std.password);
            gotoxy(10,10);
            printf("Email : %s",std.email);
            gotoxy(10,11);
            printf("Mobile Number : %d",std.mobile);
            fwrite(&std,sizeof(std),1,fp);
    }
 }
   
    fclose(fp);
    fclose(ft);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,17);
}
void forgot()
{
	FILE *fp;
    struct Cyber std;
    char name1[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SECURITY QUESTION TO GET YOUR FORGOTTEN PASSWORD:-->");
    gotoxy(10,5);
    printf("Enter birthday month : ");
    fflush(stdin);
    gets(name1);
    fp = fopen("record1.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    if(strcmp(name1,std.answer)!=0){
    	gotoxy(10,6);
    	printf("Sorry! you gave wrong answer");
    	Sleep(1000);
    	list();
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(name1,std.username) == 0){
        	gotoxy(10,6);
            printf("Your Password : %s",std.password);
        }
    }
    fclose(fp);
    gotoxy(10,8);
    printf("Press any key to continue.");
    getch();
    gotoxy(10,9);
    list();
}
