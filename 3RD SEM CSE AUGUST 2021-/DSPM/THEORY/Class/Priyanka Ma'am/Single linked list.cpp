// Singly LL Insertion(all types).
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void ins_beg();
void ins_end();
void ins_any();
void traverse();

 main()
{
	int ch;
//	clrscr();
	while(1)
	{
		printf("\n 1. Insertion at Begining\n 2. Insertion at End\n 3. Insertion at any Position\n 4. Traverse\n 5. Exit\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: ins_beg();
			break;
			case 2: ins_end();
			break;
			case 3: ins_any();
			break;
			case 4: traverse();
			break;
			case 5: exit(0);
			break;
			default: printf(" Wrong Choice.");
		}
		getch();
	}
}
void ins_beg()
{
	int item;
	struct node *tmp;
	printf("\n Enter an Item : ");
	scanf("%d",&item);
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=item;
	if(start==NULL)
	{
		tmp->link=NULL;
		start=tmp;
	}
	else
	{
		tmp->link=start; 
		start=tmp;
	}
	printf(" %d is Inserted at Begining.",item);
}
void ins_end()
{
	int item;
	struct node *tmp,*ptr;
	printf("\n Enter an Item : ");
	scanf("%d",&item);
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->link=NULL;
	if(start==NULL)
		start=tmp;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=tmp;
	}
	printf(" %d is inserted at End.",item);
}
void ins_any()
{
	if(start==NULL)
	{
		printf(" Insertion at Begining Part conducted i.e.");
		ins_beg();
	}
	else
	{
		int item,key;
		struct node *tmp,*ptr,*next;
		printf("\n Enter an Item : ");
		scanf("%d",&item);
		tmp=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter item, after which you insert another item : ");
		scanf("%d",&key);
		ptr=start;
		while((ptr->data!=key)&&(ptr->link!=NULL))
			ptr=ptr->link;
		if((ptr->link==NULL)&&(ptr->data==key))
		{
			tmp->data=item;
			ptr->link=tmp;
			tmp->link=NULL;
			printf(" %d is inserted after %d",item,key);
		}
		else if(ptr->data==key)
		{
			next=ptr->link;
			tmp->data=item;
			tmp->link=next;
			ptr->link=tmp;
			printf(" %d is inserted after %d",item,key);
		}
		else
			printf(" key item %d is not Found.",key);
	}
}
void traverse()
{
	struct node *ptr;
	if(start==NULL)
		printf(" Link List is Empty.");
	else
	{
		ptr=start;
		printf(" The items are : ");
		while(ptr!=NULL)
		{
			printf("%d,",ptr->data);
			ptr=ptr->link;
		}
	}
}
