
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void Create(struct node *h)
{
	struct node *temp;
	struct node *curr;
	temp=h;
	int ch,d;
	do	{
		curr=(struct node *)malloc(sizeof(struct node));
		curr->next=NULL;
		printf("\nEnter node data: ");
		scanf("%d", &d);
		curr->data=d;
		temp->next=curr;
		temp=curr;
		printf("\nEnter 1 to Continue: ");
		scanf("%d", &ch);
	}while(ch==1);
}
void Display(struct node *h)
{
	struct node *curr;
	if(h->next==NULL)
		printf("\nList is empty.");
	else
	{
		printf("%x", h->next);
		curr=h->next;
		printf("\nCurrent Add   Data      Next Link");
		while(curr!=NULL)
		{
			printf("\n%x  \t %d\t      %x", curr,curr->data,curr->next);
			curr=curr->next;
		}
	}
}

int length(struct node *h)
{
	struct node *curr;
	curr=h->next;
	int i=1;
	if(h->next==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		while(curr->next!=NULL)
		{
			i++;
			curr=curr->next;
		}
		return i;
	}
}

void inspos(struct node *h)
{
	struct node *curr;
	struct node *nnode;
	int k;
	int i=1;
	int pos;
	int data;
	curr=h;
	nnode=(struct nnode *)malloc(sizeof(struct node));
	nnode->next=NULL;
	printf("Enter Position where you want to insert data: \n");
	scanf("%d",&pos);
	printf("Enter Data to be inserted: \n");
	scanf("%d",&data);
	nnode->data=data;
	k=length(h);
	if(pos>k+1)
	{
		printf("Data cannot be inserted\n");
	}
	else
	{
		while(curr!=NULL && i<pos)
		{
			i++;
			curr=curr->next;
		}
		nnode->next=curr->next;
		curr->next=nnode;
	}
}

int main()
{
	int ch,con;
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	do	{
		printf("\n1.Create\n2.Display\n3.Insert by position\n4.Exit"
				"\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: Create(head);
					break;
			case 2: Display(head);
					break;
			case 3: inspos(head);
					break;
			default:printf("\nWrong Choice.");
					break;
		}
	printf("\nEnter 1 to continue: ");
	scanf("%d",&con);
	}while(con==1);
	return 0;
}

