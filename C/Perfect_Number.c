/*
								Assignment 4
Name:Riddhik Tilawat
roll no.:203732
class:SYCSE-7
Batch-G2

Title:Find perfect number
*/

#include<stdio.h>	 
int main()
{
	int num,s=0,r,i;				//variable declaration
	
	printf("\nEnter a Number");	
	scanf("%d",&num);

	for(i=1;i<=(num-1);i++)			//loop for finding rem and finding sum
	{
		r=num%i;	
		
		if(r==0)		 
		{
			s=s+i;
			printf("%d\t",i);
		}
	}
	
	if(s==num)			
	{
		printf("\nEntered number is perfect=%d",num);
	}
	else
	{
		printf("\nEntered number is not perfect=%d",num);
	}

return 0;
}

Output:

Enter a Number 28
1	2	4	7	14	
Entered number is perfect=28