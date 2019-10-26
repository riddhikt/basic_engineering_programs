

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50
char stack[max];
int top=-1;

int isFull()
{
	if(top==max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char item)
{
	if(isFull()==0)
	{
		stack[++top]=item;
	}
	else
	{
		printf("\nStack is full");
	}
}
char pop()
{
	char temp;
	if(isEmpty()==0)
	{
		temp=stack[top];
		top--;
		return temp;

	}
	else
	{
		printf("\nStack is empty");


	}
	return 0;
}
 void display()
 {
	 int i;
	 for(i=top;i>=0;i--)
	 {

		 printf("\n | %c |\n",stack[i]);
		 printf("\n ‾‾‾‾‾‾");
	 }
 }

 int precedence(char ch)
 {
 	if(ch == '^')
 		return 4;
 	if(ch == '*' || ch == '/')
 		return 3;
 	if(ch == '+' || ch == '-')
 		return 2;
 	if(ch == '(')
 		return 1;
 	return 0;
 }

 void infix_post(char inExp[100])
 {
     char tkn;
     char postExp[50];
     int i,k;
 	k = 0;
 	i = 0;
 	tkn = inExp[i];
 	while(tkn != '\0')
 	{
         if((tkn >= 65 && tkn <=90) || (tkn >= 97 && tkn <=112))
         {
         	postExp[k] = inExp[i];
             k++;
         }
    	    else
    	    {
    	    	if(tkn == '(')
    	    	{
    	    		push('(');
    	    	}
    	    	else
    	    	{
    	    		if(tkn == ')')
    	    		{
    	    			while((tkn = pop()) != '(')
    	    			{
    	    				postExp[k] = tkn;
    	    				k++;
    	    			}
    	    		}
    	    		else
    	    		{
    	    			while(!isEmpty() && precedence(stack[top]) >= precedence(tkn)){
    	    				postExp[k] = pop();
    	    			}
    	    			push(tkn);
    	    		}
    	    	}
    	    }
         i++;
         tkn = inExp[i];
 	}
 	while(!isEmpty())
 	{
 		postExp[k] = pop();
 		k++;
 	}
 	printf("postFix Exp:  %s",postExp);
 }

 void post_pre(char postExp[100])
 {
	int count, length;
	       length = strlen(postExp);
	       printf("\nPrefix Expression:\t");
	       for(count = length - 1; count >= 0; count--)
	       {
	             printf("%c", postExp[count]);
	       }

 }

 void post_in(char postExp[])
 {
       int count, length;
       char element, operator,op1,op2;

       length = strlen(postExp);

       for(count = 0; count < top; count++)
       {
             stack[count] = 0;
       }
       printf("\n Infix postExp is:\n");
       printf("%c", postExp[0]);
       for(count = 1; count < length; count++)
       {
             if(postExp[count] == '/' || postExp[count] == '*' || postExp[count] == '-'|| postExp[count] == '+')
             {
                 op1=pop();
                 op2=pop();
                 e1=strcat('(',op2,postExp[count],op1,')');

            	 /*element = pop();
                   operator = postExp[count];
                   printf(" %c %c", operator, element);*/
             }
             else
             {
                   push(postExp[count]);
             }
       }
       printf("%c", postExp[top--]);
 }

 int main()
 {
	 int ch;
	 char item;
	 char p;
	 int x;
	 char *infix[max];

	 do
	 {
		 printf("\nEnter your choice");
		 printf("\n1:Push \n2:Pop \n3:Display\n4:Convert infix to postfix\n5:Convert postfix to preix\n6:Postfix to infix");
		 scanf("%d",&ch);
		 switch(ch)
		 {
		 case 1:
			 printf("\nEnter element to be pushed");
			 scanf(" %c",&item);
			 push(item);
			 break;
		 case 2:
			 p=pop();
			 printf("\nElement popped:%c",p);
			 break;
		 case 3:
			 display();
			 break;
		 case 4:
			 printf("\nenter infix expression");
			 scanf("%s",&infix);
			 infix_post(infix);
			 break;
		 case 5:
			 printf("\nenter postfix expression");
			 scanf(" %s",&infix);
			 post_pre(infix);
			 break;
		 case 6:
			 printf("\nenter postfix expression");
			 scanf(" %s",&infix);
			 post_in(infix);
			 break;
		 }
		 printf("\nDo you wish to continue: \n Yes:1 \t No=0");
		 scanf("%d",&x);
	 }while(x==1);

 }
