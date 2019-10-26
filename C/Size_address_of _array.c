/*  Name:Riddhik Tilawat
	Class:SY-CSE-G2
	Roll no.:203732
	
	address of array variables and size of pointers
*/	

#include<stdio.h>
int main()
{
	int arr[10];		//declarations
	int *p;
	float *f;
	char *c;

	printf("Enter a values for 10 array element\n");
	for(int i=0; i<10; i++)		//accepting values
	{
		scanf("%d",&arr[i]);
	}

	printf("Array element are\n");
	for(int i=0; i<10; i++)		//Displaying values
	{
		printf("%d\n",arr[i]);
	}

	for(int i=0; i<10; i++)		//Displaying address
	{
		printf("%p\n",arr+i);
	}

	printf("%d %d %d ",sizeof(*p),sizeof(*f),sizeof(*c));
	return 0;
}

/*
Output:

Enter a values for 10 array element
2        
8
5
8
6
5
7
44
66
665
Array element are
2
8
5
8
6
5
7
44
66
665

0x7ffc2e5af450
0x7ffc2e5af454
0x7ffc2e5af458
0x7ffc2e5af45c
0x7ffc2e5af460
0x7ffc2e5af464
0x7ffc2e5af468
0x7ffc2e5af46c
0x7ffc2e5af470
0x7ffc2e5af474
4 4 1 
*/