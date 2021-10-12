//custfunc.c
#include "headers.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define GTOTAL(cost) cost+(cost*20/100)
typedef struct customer
{
	char name[30];
	char address[80];
	long int phno;
}record;

enum result{success,failure};

record *ptr[MAX];

static int id=1;
char arg[100];

int str_len(char arg[])
{
int i,count=0;
for (i = 0; arg[i]!='\0';i++) 
 count++;
 return count;
}

int addcustomer()
{
	int n;
	register int i;
	printf("enter the number of customers you like to add\n");
	scanf("%d",&n);
	for(i=id;i<(id+n);i++)
	{
	fflush(stdin);
	ptr[i] = (struct customer*) malloc (sizeof(struct customer));
	if(ptr[i]==NULL)
	{
		printf("Dynmaic memory allocation failed\n");
		exit(0);
	}
	printf("id:%d\n",i);
	printf("enter the full name\n");
	gets(ptr[i]->name);
	ma:
	printf("enter the address details\n");
	gets(ptr[i]->address);
	if(str_len(ptr[i]->address)>80)
	{
		printf("Limit address to 80 words\n");
		goto ma;
	}
	mo:
	printf("enter the phno\n");
	scanf("%lld",&ptr[i]->phno);
	if(((ptr[i]->phno)>999999999)&&((ptr[i]->phno<=9999999999)))
      {
        	printf("phno valid\n");
	        printf("\nCustomer Added Successfully!!\n");
            printf("===========================================================================================================\n");
        	
      }
	else
	  {
	    	printf("phno invalid\n");
	    	goto mo;
	  }
    }
    id=i;
	return success;
}
int viewcustomer()
{
   int choice;
   	system("cls");
	fflush(stdin);
	printf("MENU\n");
	printf("-------\n");
	printf("1.view customers by id\n");
	printf("2.view all customers\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
		{
			auto int i,no;
			case 1:
					printf("\nenter the customer id\n");
					scanf("%d",&no);
					if((id<=no)||(no==0))
					{
					printf("Invalid Id\n");
					break;
				    }
				    printf("customer details:\n");
				    printf("===========================================================================================================\n");
					printf("id: %d\n",no);
					printf("name: ");
					puts(ptr[no]->name);
					printf("details: ");
					puts(ptr[no]->address);
					printf("phno:");
					printf("%lld\n",ptr[no]->phno);
					printf("===========================================================================================================\n");
					break;
			case 2:
						if(id==0)
						printf("Database empty plz input values!\n");
						else
						{
						system("cls");
						printf("\ncustomer details:\n");
						printf("-----------------------------------------------------------------------------------------------------------------------\n");
						for(i=1;i<id;i++)
							{
								printf("id: %d\n",i);
								printf("name:");
								puts(ptr[i]->name);
								printf("details: ");
								puts(ptr[i]->address);
								printf("phno:");
								printf("%lld\n",ptr[i]->phno);
								printf("-----------------------------------------------------------------------------------------------------------------------\n");
							}
						}
						break;
			default:
					printf("wrong input\n");
		}
	return success;
}
int deletecustomer()
{
	int d;
	printf("enter the customer id to delete\n");
	scanf("%d",&d);
	if((d>=id)||(d==0))
	{
		printf("Record doesnt exist\n");
		return failure;
	}
	else
	{
		int c;
		for(c=d;c<=id;c++)
		{
		ptr[c]=ptr[c+1];	
		}
		id=id-1;
		printf("Record successfully deleted\n");
	}	
return success;
}
int exit_function()
{
	register int i;
	for(i=0;i<=id;i++)
	{
		free(ptr[i]);
		ptr[i]=NULL;
	}
	exit(0);
}
