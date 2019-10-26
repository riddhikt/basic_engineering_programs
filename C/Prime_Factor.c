/*
								Assignment 2
Name:Riddhik Tilawat
roll no.:203732
class:SYCSE-7
Batch-G2

Title:C program to find prime factors

*/


#include<stdio.h>
#include<math.h>


void primefactor(int n) 		//function definition
{
	int i;
	while(n%2==0)               //check for 2
	{
		printf("prime factor: 2 \n");
		n=n/2;
	}
	for(i=3;i<n/2;i=i+2)        //check for no. divisible by 3
	{
		while(n%i==0)
		{
			printf("%d \n",i);
			n=n/i;
		}
	}
	if(n>2)                     
	{
		printf("Prime factor: %d",n);
	}
	
}

void main()
{
	int a;
	printf("enter a number to find prime factors"); 
	scanf("%d",&a);
	primefactor(a); 		//function call
}		

/*
Output:

enter a number to find prime factors 12
prime factor: 2 
prime factor: 2 
Prime factor: 3
*/