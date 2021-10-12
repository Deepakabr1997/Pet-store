//main.c
#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
#define MAX 30
int arg[MAX];
int str_cmp(char arg1[],char arg2[])
{
 int i = 0, flag = 0;
    while(arg1[i] != '\0' &&arg2[i] != '\0')
	{
        if(arg1[i] != arg2[i]) 
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0 && arg1[i] == '\0' && arg2[i] == '\0')
        return 1;
    else
        return 0;	
}
int main(int argc, char *argv[]) 
{
	char *username,*password;
	username = (char *)calloc(30, sizeof(char));
	password = (char *)calloc(30, sizeof(char));
	if((username==NULL)||(password==NULL))
	{
		printf("Memory Allocation Failed\n");
		exit(0);
	}
		char ch='y';
		int no=0,id;
		char c;
	printf("-------------------------------------WELCOME TO LOGIN PAGE---------------------------------------------\n\n");
	printf("enter the username\n");
	scanf("%s",username);
	printf("enter the password\n");
	scanf("%s",password);
			if((str_cmp(username,"deepak")==1)&&(str_cmp(password,"deepak")==1))
		{
		    printf("----------------------------LOGIN SUCCESSFULL----------------------------\n\n");
			system("CLS");
			printf("welcome %s\n",username);
			free(username);
			free(password);
			username=NULL;
			password=NULL;
			do
			{
			printf("\n\n    MENU\n");
			printf("   ------\n");
			printf("1.ADD NEW CUSTOMER\n");
			printf("2.VIEW CUSTOMER DETAILS\n");
			printf("3.DELETE CUTOMER\n");
			printf("4.ADD NEW PET DETAILS\n");
			printf("5.VIEW PET DETAILS\n");
			printf("6.DELETE PET\n");
			printf("7.SELL PET\n");
			printf("8.SALES REPORT\n");
			printf("9.EXIT\n");
			printf("ENTER YOUR CHOICE!!\n");
			scanf("%d",&c);
			system("cls");
			  switch(c)
			   {
				 case 1:
				 	system("cls");
					addcustomer();
					 break;
				 case 2:
					viewcustomer();
					 break;
				case 3:
					deletecustomer();
					 break;	 
				 case 4:
				 	system("cls");
					printf("enter the number of pets you like to add\n");
					scanf("%d",&no);
					 	addpet(&no);
					 	break;
				 case 5:
				 		viewpet();
						break;
				 case 6:
				    	deletepet();
						break;
				 case 7:
				    	sellpet();
						break;
				 case 8:
				 		viewsold();
				 		break;		
				 case 9:
					 	exit_function();
					 	break;
					default:
					  printf("wrong choice\n");
			   }
			printf("\n Do You Want To Perform More Operations? y/n \n");
			getchar();
			scanf("%c",&ch);
		   }
			while(ch=='y');
	   }
	    else
	    {
        printf("\nUnauthorised access!\n\n\n");
        fflush(stdin);
        printf("---------------------------------------PROGRAM EXITED-----------------------------------------\n\n\n");
	    getch();
		exit_function();
		}
		return 0;
}

