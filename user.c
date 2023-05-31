#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"user_s.h"
void create();
void show_info(int);
struct user un;
void create() 
{ 
	int h;
	struct user check;
	system("cls"); 
	printf("\nEnter your first name : "); 
	fflush(stdin);
	gets(un.fname); 
	printf("\nEnter your last name : "); 
	fflush(stdin);
	gets(un.lname); 
	printf("\nEnter your phone number : "); 
	fflush(stdin);
	gets(un.phno); 
	un.no_borrowed=0; 
	up:  
	printf("\nEnter your username : "); 
	fflush(stdin);
	gets(un.username);
	FILE *f_user=fopen("users.txt","a+"); // opening file user
	h=0;
	fseek(f_user,0,SEEK_END);
	int f=ftell(f_user);
 	if(f!=0)
	{
		while(ftell(f_user)!=f)
		{	
			fseek(f_user,sizeof(un)*h ,SEEK_SET);
			fread(&check,sizeof(un),1, f_user);
			h++;
			if(strcmp(un.username,check.username)==0)//checks for unique user ID
			{ 
				printf("Username exits! please enter different username."); 
				getch(); 
				system("cls");  
				goto up; 
			} 
		}
	}
	printf("\nEnter your password : "); 
	fflush(stdin);
	gets(un.password); 
	bk: 
	printf("\nEnter the number of books you want to borrow at a time(max of 4):"); 
	fflush(stdin);
	scanf("%d",&un.no_bk); 
	if(un.no_bk<0 || un.no_bk>4) 
	{ 
		printf("\nInvalid"); 
		getch(); 
		system("cls"); 
		goto bk; 
	}
	mem: 
	printf("\nMembership plan :\n1.Monthly Plan\n2.Half yearly plan(10%% discount)"); 
	printf("\n3.Annual plan(20%% discount) : "); 
	scanf("%d",&un.mem_plan); 
	if(un.mem_plan>3 || un.mem_plan<1) 
	{ 
		printf("\nInvalid input try again"); 
		getch(); 
		system("cls"); 
		goto mem; 
	} 
	un.amt=un.no_bk*199; 
	if(un.mem_plan==2) 
		un.amt*=6; 
	if(un.mem_plan==3) 
		un.amt*=12; 
	printf("\nAmount to be paid before discount : Rs.%f",un.amt); 
	if(un.mem_plan==2) 
		un.amt-=un.amt*0.1; 
	if(un.mem_plan==3) 
		un.amt-=un.amt*0.2; 
	printf("\nAmount to be paid after discount : Rs.%f",un.amt);  
	getch(); 
	fwrite(&un,sizeof(struct user),1,f_user);
	fclose(f_user);
} 
int home(int k)
{
    int c, j = 0;
    while (j == 0)
    {
		system("cls");
        printf("\t\tHOME\n\n");
        printf(" 1.BORROW\n");
        printf(" 2.RETURN\n");
        printf(" 3.INFORMATION\n");
        printf(" 4.LOG OUT\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            borrow(k);
            break;
        case 2:
            //returnn(k);
            break;
        case 3:
            show_info(k);
            break;
        case 4:return 1;
        default:
            printf("Invalid input.\n");
			getch();
        }
    }
    return 0;
}
void show_info(int k) 
{
	struct user u;
	FILE *f_user=fopen("users.txt","r");
	fseek(f_user,sizeof(u)*k ,SEEK_SET);
	fread(&u,sizeof(u),1,f_user);
	fclose(f_user);
	system("cls");
	printf(" USER INFORMATION\n"); 
	printf("\n NAME: %s %s ",u.fname,u.lname); 
	printf("\n PHONE NUMBER: %s ",u.phno); //PRINTING WRONG
	printf("\n PLAN:  %d",u.mem_plan); 
	printf("\n NO. OF BOOKS:  %d",u.no_bk); 
	printf("\n NO. OF BOOKS BORROWED: %d",u.no_borrowed); 
	printf("\n USERNAME: %s ",u.username); 
	getch(); 
} 
void main()
{
	main_menu();
}