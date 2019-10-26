/*
 ============================================================================
 Name        : Stud.c
 Author      : Riddhik
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
struct stud
	{
		int roll;
		char div;
		char name[20];
		float per;
	};
void accept(struct stud s[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Roll number");
		scanf("%d",&s[i].roll);
		printf("\nEnter Division");
		scanf(" %c",&s[i].div);
		printf("\nEnter Name");
		scanf("%s",&s[i].name);
		printf("\nEnter Percentage");
		scanf("%f",&s[i].per);

	}
}

void display(struct stud s[20],int x)
{

	printf("\nRoll number: %d",s[x].roll);
	printf("\nDivision: %c",s[x].div);
	printf("\nName: %s",s[x].name);
	printf("\nPercentage: %f \n",s[x].per);

}

int linsearch(struct stud s[20],int n,int key)
{
	int i=0;
	int flag=0;

	for(i=0;i<n;i++)
	{
		if(key==s[i].roll)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		printf("\nElement Found at location %d",i);
	}
	else
	{
		printf("\nElement not found");
	}
}

int Binarysearch(struct stud s[20],int n, int key)
{
	int mid,i=0,low=0,high=n-1;
	while(low <= high)	{
		mid=(low+high)/2;
		if(s[mid].roll==key)
			return i;
		else if(key>s[mid].roll)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
void swap(struct stud student[20],int a, int b, int n)
{
        student[n+1] = student[a];
        student[a] = student[b];
        student[b] = student[n+1];
}

void selection_sort(struct stud student[20], int n)
{
    int min;

    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(student[min].roll>student[j].roll)
                min = j;
        }
        swap(student,min,i,n);
    }
}


void insertion_sort(struct stud student[20], int n)
{    int j;
    struct stud temp;
    for(int i=1;i<n;i++)
    {
        temp = student[i];
        for(j=i-1;(j>=0)&&(temp.roll<student[j].roll);j--)
        {
            student[j+1] = student[j];
        }
        student[j+1] = temp;
    }
}

/*int BubbleSort(struct stud s[10],int n)	{
	int i=0,j=0;
	for(i=0; i<n-1; i++)	{
		for(j=0; j<n-i; j++)	{
			if(s[j].roll>s[j+1].roll)	{
				s[j+1] = s[j];
				s[a] = s[b];
				s[b] = s[n+1];
			}
		}
	}
	return 0;
}
*/
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int ch,i;
	int flag=0;
	int n,key,number,result;
	struct stud s[20];


	printf("\nEnter number of students in database:");
	scanf("%d",&n);
	do
	{
		printf("\nEnter your Choice:");
		printf("\n1:For Accepting Student Details\n2:For Displaying student details\n3:Linear Search\n4:Binary Search\n5:Bubble sort\n6:Insertion sort\n7:Selection sort");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept(s,n);
				break;

			case 2:
				display(s,n);
				break;

			case 3:
				printf("Enter Roll number to be searched:");
				scanf("%d",&key);
				i=linsearch(s,n,key);
				break;

			case 4:
				printf("\nEnter roll no key to be searched: ");
				scanf("%d",&key);
				flag= Binarysearch(s,n,key);
				if(flag==-1)
				printf("\nRecord not found.");
				else	{
				printf("\nRecord found at: %d index", flag);
				display(s,flag);
				}
				break;
            case 5:
            	/*Bubblesort(s,n);
            	display(s,n);
            	break;*/

            case 6:
            	insertion_sort(s,n);
            	display(s,n);
            	break;

            case 7:
            	selection_sort(s,n);
            	display(s,n);
            	break;



			default:
				printf("\nEnter correct choice");
				break;
	}
	}while(ch!=8);
}
