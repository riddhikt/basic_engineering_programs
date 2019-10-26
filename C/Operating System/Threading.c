#include<stdio.h>			//header files
#include<pthread.h>
pthread_t thread1,thread2;		//global declaration
int add1(int a[3])			//add function 1
{
	a[2]=a[1]+a[0];
	printf("Result from Thread1 is %d \n",a[2]);
}
int add2(int b[3])			//add function 2
{
	b[2]=b[1]+b[0];
	printf("Result from Thread2 is %d \n",b[2]);
}
int main()
{
	int arr[4],a[3],b[3],i,ans=0;	
	pthread_t thread1,thread2;	//thread init	
	printf("Enter 4 numbers\n");
	for(i=0;i<4;i++)		//accepting numbers
		scanf("%d",&arr[i]);
	a[0]=arr[0];
	a[1]=arr[1];
	b[0]=arr[2];
	b[1]=arr[3];
	
	pthread_create(&thread1,NULL,(void *)add1,a);	//creation of thread1
	pthread_create(&thread2,NULL,(void *)add2,b);	//creation of thread2
	pthread_join(thread1,NULL);			//making t1 joinable
	pthread_join(thread2,NULL);			//making t2 joinable
	
	ans=a[2]+b[2];					
	printf("The result= %d\n",ans);			//printing answer	
	return 0;
}
