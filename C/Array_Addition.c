/*  
				Assignment 3
	Name:Riddhik Tilawat
	Class:SY-CSE-G2
	Roll no.:203732
	
	Title:Write a recursive function to find sum of n numbers
*/	

#include<stdio.h>
void accept(int a[],int size);		//function declaration
void display(int a[],int size);		//function declaration
int find_sum(int a[],int size);		//function declaration


int main()
{
	int a[5];
	int size=5;

	accept(a,size);					//function call
	find_sum(a,size);				//function call
	display(a,size);				//function call
	
	return 0;
}

void accept(int a[5],int size)		//function definition
{
	int i;
	
	printf("enter 5 numbers \n");
	for(i=0;i<size;i++)	 
	{
		scanf("%d",&a[i]);
	}
}		

void display(int a[5],int size)		//function definition
{
	int i;
	
	printf("array : \n");
	for(i=0;i<size;i++)	 
	{
		printf("%d \n",a[i]);
	}
}
	
int find_sum(int a[5],int size)		//function definition
{
	
	int static b,i=0;
	
	if(i<size)
	{
	
		b=a[i]+b;
		i++;
		find_sum(a,size);
	}
	
	else
	{
	printf("sum is %d \n",b);
	}
	
} 


/*
Output:

enter 5 numbers 
2           
3
4
5
3
sum is 17 
array : 
2 
3 
4 
5 
3 

*/

	
