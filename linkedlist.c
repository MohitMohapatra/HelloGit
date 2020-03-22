#include "stdio.h"
#include <stdlib.h>

struct link
{
	int info;
	struct link *next;
};
struct link *start;				//struct link (struct link*)malloc(sizeof(struct link));

void createlist();
void display();
void insertatbegin();
void insertatend();
void insertmiddle();
void deletebegin();
void deleteend();
void deletespecific();


void main()
{
	createlist();
	// insertmiddle();
	// deletebegin();
	// deleteend();
	deletespecific();
	// insertatbegin();
	// insertatend();
	display();

}

void createlist()
{
	start=(struct link*)malloc(sizeof(struct link));
	if(start==NULL)
	{
		printf("Unable to allocate memory");
		exit(1);
	}
	struct link *temp=start;
	printf("Enter value:\n");
	scanf("%d",&temp->info);			//accessing structure variable
	temp->next=NULL;			//temp value is updated 
	char ch;
	printf("do you want to continue(y/n):");
	fflush(stdin);				//clear buffer keyboard input
	scanf("%c",&ch);
	while(ch=='y')
	{
		temp->next = (struct link*)malloc(sizeof(struct link));
		if (temp->next==NULL)
		{
			printf("unable to allocate memory");
			exit(1);
		}
		temp=temp->next;
		printf("Enter value:");
		scanf("%d",&temp->info);
		temp->next=NULL;
		printf("Do you want to continue (y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}
}

void display()
{
	printf("Display:\n");
	struct link *temp=start;
	while (temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}

void insertatbegin()
{
	struct link *node=(struct link *)malloc(sizeof(struct link));
	if (node==NULL)
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
	printf("Enter value at node:");
	scanf("%d",&node->info);
	node->next=start;
	start=node;

}

void insertatend()
{
	struct link *node=(struct link *)malloc(sizeof(struct link));
	printf("Enter value at node");
	scanf("%d",&node->info);
	node->next=NULL;

	struct link *temp=start;
	while(temp->next!=NULL)			//traversing through the address to reach NULL address
	{
		temp=temp->next;
	}
	temp->next=node;				//linking base address of node to the NULL base address 
}

void insertmiddle()
{
	struct link *node=(struct link*)malloc(sizeof(struct link));
		if (node==NULL)
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
	struct link *temp1=start;
	struct link *temp2=NULL;
	printf("Enter value at node:");
	scanf("%d",&node->info);			// 	node->next=temp1;
	int loc;
	printf("Enter location:");
	scanf("%d",&loc);			// 	temp2->next=node;
	int i=1;
	while(i<loc&&temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		i++;
	}
	if(temp1==NULL || loc<=0)
	{
		printf("\nInvalid location");
		exit(1);
	}
	if(temp1->next==NULL || loc==1)
	{
		printf("\nOperation not allowed");
		exit(1);
	}
	node->next=temp1;
	temp2->next=node;
}
void deletebegin()
{
	struct link *temp=start;
	start=start->next;
	free(temp);
}
void deleteend()
{
	struct link *temp=start;
	struct link *temp2=NULL;
	while(temp->next!=NULL)			//traversing through the address to reach NULL address
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=NULL;		
	free(temp);		//linking base address of node to the NULL base address 
}

void deletespecific()
{
	struct link *temp1=start;
	struct link *temp2=NULL;
	int loc;
	printf("Enter location:");
	scanf("%d",&loc);	
	int i=1;
	while(i<loc&&temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		i++;
	}
	temp2->next=temp1->next;
	free(temp1);
}



 