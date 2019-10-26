/*  Name:Riddhik Tilawat
	Class:SY-CSE-G2
	Roll no.:203732
	
	Structure student database
*/	


#include<stdio.h>
struct student
{
	int roll;
	char name[20];
	float marks;
}s[20];



void accept(struct student s[20],int n)
{
	int i;
	int a=n;
	for(i=0;i<a;i++)
	{
		printf("Enter Roll no,name,marks");
		scanf("%d %s %f",&s[i].roll,&s[i].name,&s[i].marks);
	}
}

void display(struct student s[20],int n)
{
	int i;
	int a=n;
	
	for(i=0;i<a;i++)
	{
		printf("Student %d \n",i+1);
		printf("Roll no: %d \n",s[i].roll);
		printf("Name: %s \n",s[i].name);
		printf("Marks: %f \n",s[i].marks);
	}
}


void avg(struct student s[20],int n)
{
	int sum;
	float avg;
	int i;
	int t=n;
	for(i=0;i<n;i++)
	{
		sum=s[i].marks+sum;
	}
	avg=sum/t;
	printf("\n average= %f",avg);
}

void main()
{
	
	int n=0;
	printf("how many students data do you want to enter? \n");
	scanf("%d",&n);
	accept(s,n);
	
	display(s,n);
	avg(s,n);
}
/*
Output:
how many students data do you want to enter? 
2
Enter Roll no,name,marks22
riddhik
80
Enter Roll no,name,marks23
bharat
79
Student 1 
Roll no: 22 
Name: riddhik 
Marks: 80.000000 
Student 2 
Roll no: 23 
Name: bharat 
Marks: 79.000000 

 average= 79.000000
 
 */

	
		