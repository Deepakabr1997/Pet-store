//petfunc.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
#define GST(cost) cost+(cost*18/100)
struct pet
{
	char name[30];
	char breed[30];
	char details[80];
	float price;
	float gtotal;
	int sold;
}objp[MAX];

static int pid=1;
int addpet(int *n)
{
	register i;
	auto int price=0;
	for(i=pid;i<(pid+*n);i++)
	{
	fflush(stdin);	
	printf("id:%d\n",i);
	printf("enter the name\n");
	gets(objp[i].name);
	printf("enter the breed\n");
	gets(objp[i].breed);
	printf("enter the pet details\n");
	gets(objp[i].details);
	printf("enter the price\n");
	scanf("%d",&price);
	objp[i].price=(float)price;
	objp[i].sold=0;
	printf("\nPet Added Successfully!!\n");
    printf("===========================================================================================================\n");
    }
    pid=i;
	return 0;
}
int viewpet()
{
	int choice;
	system("cls");
	fflush(stdin);
	printf("MENU\n");
	printf("-------\n");
	printf("1.view pet by id\n");
	printf("2.view all the pets\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
		{
			auto int i,no;
			case 1:
					printf("enter the pet id\n");
					scanf("%d",&no);
					if((pid<=no)||(no==0))
					{
					printf("Invalid Id\n");
					break;
				    }
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					printf("\t\t\t\t\t\tPET SEARCH\n");
					printf("-----------------------------------------------------------------------------------------------------------------------\n");
					printf("id: %d\n",no);
					printf("name: ");
					puts(objp[no].name);
					printf("breed: ");
					puts(objp[no].breed);
					printf("details: ");
					puts(objp[no].details);
					printf("price: ");
					printf("%.2f\n",objp[no].price);
					printf("Status: ");
					if(objp[no].sold==1)
					{
					printf("Sold\n");
					}
					else
					{
					printf("Stock Available\n");
					}
					printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
					break;
			case 2:
							printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
							printf("\t\t\t\t\t\tPET DATABASE\n");
							printf("-----------------------------------------------------------------------------------------------------------------------\n");
							for(i=1;i<pid;i++)
							{
								printf("id: %d\n",i);
								printf("name:");
								puts(objp[i].name);
								printf("breed: ");
								puts(objp[i].breed);
								printf("details: ");
								puts(objp[i].details);
								printf("price: ");
								printf("%.2f\n",objp[i].price);
								printf("Status: ");
								if(objp[i].sold==1)
								{
								printf("No Stocks Available\n");
								}
								else
								{
								printf("Stock Available\n");
								}
								printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
							}
						if(pid==0)
				    		printf("Database empty plz input values!\n");
							break;
			default:
					printf("wrong input\n");
		}
	return 0;
}


int sellpet()
{
	auto int no;
	system("cls");
	fflush(stdin);
	printf("Enter the id of pet to sell\n");
	scanf("%d",&no);
	if(no>pid)
	 {
	 	printf("Invalid Id\n");
		return 0; 
     }
     if(objp[no].sold==1)
     {
     printf("Out of Stock\n");
     return 0;
     }
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tPET BILLING\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("id: %d\n",no);
	printf("name: ");
	puts(objp[no].name);
	printf("breed: ");
	puts(objp[no].breed);
	printf("details: ");
	puts(objp[no].details);
	//calculation
	objp[no].gtotal=GST(objp[no].price);
	printf("price: ");
	printf("%.2f-------------",objp[no].gtotal);
	#ifdef GST
    printf("Inclusive of Taxes\n");
    #else
    printf("Please pay 18% extra GST\n");
    #endif
    objp[no].sold=1;
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You!!Please visit Again...\n");
return 0;
}
int viewsold()
{
	int i;
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tPET SALES REPORT\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	for(i=1;i<=pid;i++)
	{
	if(objp[i].sold==1)
	{
		float tax=0.0;
		printf("id: %d\n",i);
		printf("name: ");
		puts(objp[i].name);
		printf("breed: ");
		puts(objp[i].breed);
		printf("details: ");
		puts(objp[i].details);
		printf("Selling price: ");
		printf("%.2f\n",objp[i].price);
		printf("Tax: ");
		tax=objp[i].gtotal-objp[i].price;
		printf("%.2f\n",tax);
		printf("Grand Total price: ");
		printf("%.2f\n",objp[i].gtotal);
		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	}
	}
}


int deletepet()
{
	int id;
	printf("enter the pet id to delete\n");
	scanf("%d",&id);
	if((id>=pid)||(id==0))
	{
		printf("Record doesnt exist\n");
		return 0;
	}
	else
	{
		int c;
		for(c=id;c<=pid;c++)
		{
		objp[c]=objp[c+1];	
		}
		pid=pid-1;
		printf("Record successfully deleted\n");
	}
	return 0;	
}
