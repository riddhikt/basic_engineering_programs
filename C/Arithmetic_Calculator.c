/*  Name:Riddhik Tilawat
	Class:SY-CSE-G2
	Roll no.:203732
*/	


//Write a Menu driven program in C to implement the basic arithmetic calculator using looping and switch case


#include<stdio.h>

float d;    //Global Declaration
int c;
int a,b,ch;

 int addn(int x,int y)  //Function Definition
 {
 				c=a+b;
				printf("\n Addition of %d + %d = %d \n",a,b,c);
				return 0;
				
}

int subn(int x,int y)	 //Function Definition
{
				c=a-b;
				printf("\n Substraction of %d - %d = %d \n",a,b,c);
				
}
int muln(int x,int y)	 //Function Definition
{
				c=a*b;
				printf("\n Multiplication of %d * %d = %d \n",a,b,c);
				
}

int divn(int x,int y)	 //Function Definition
{
				d=a/b;
				printf("\n Division of %d / %d = %f \n",a,b,d);
				
}
int modn(int x,int y)	 //Function Definition
{
				c=a%b;
				printf("\n Mod of %d mod %d = %d \n",a,b,c);
				
}




void main() 
{
	


	do {									//Loop
	
		printf("Enter val1 - \n");
		scanf("%d",&a);

		printf("Enter val2 - \n");
		scanf("%d",&b);
	
		printf("\n What do you want to do ? \n");
		printf("1.Addition \n 2.Substraction \n 3.Multiplication \n 4.Division \n 5.Mod \n 6.Exit\t");
		scanf("%d",&ch);
		switch(ch) {                        //switch case
			case 1: 
				addn(a,b); //Addition Function called
				break;
			case 2: 
				subn(a,b); //Subtraction Function called
				break;
			case 3: 
				muln(a,b); //Multiplication Function called
				break;
			case 4: 
				divn(a,b); //Division Function called
				break;
			case 5: 
				modn(a,b); //Modulus Function called
				break;
			case 6:
				printf("End of program \n"); //Exit
				break;
			default :
				printf("Not possible \n");
			
				
		}
		
	}while(ch != 6);

}

/*
Output:
 Addition of 10 + 20 = 30 
Enter val1 - 
1
Enter val2 - 
2

 What do you want to do ? 
1.Addition 
 2.Substraction 
 3.Multiplication 
 4.Division 
 5.Mod 
 6.Exit	2

 Substraction of 1 - 2 = -1 
 */
