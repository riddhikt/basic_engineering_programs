#include<stdio.h>
void accept(char s[40])
{
	printf("\nplease enter the string ");
			scanf("%s",s);
}
void display(char s[40])
{
	printf("\nEntered string : \n %s",s);
}
int calculate(char s[40])
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}
void copy(char s[40])
{
	char s1[40];
	int i=0;
	while(s[i]!='\0')
	{
		s1[i]=s[i];
		i++;
	}
	s1[i]='\0';
	printf("\n String Successfully copied\n");
	printf("\nOriginal String: %s",s);
	printf("\nCopied string: %s",s1);
}
void concat(char s1[40],char s2[40])
{
	char s3[80];
	int i=0,j=0;
	while(s1[i]!='\0')
	{
		s3[i]=s1[i];
		i++;
	}

	while(s2[j]!='\0')
	{
		s3[i]=s2[j];
		i++;
		j++;
	}
	s3[i]='\0';
	printf("String Concatinated Successfully\n");
	printf("Concatinated String: %s",s3);

}
int compare(char s[40],char s1[40])
{

	int i,l1,l2;
	int flag=0;
	l1=calculate(s);
	l2=calculate(s1);
	if(l1=l2)
	{
		while(s[i]!='\0')
		{
			if(s[i]==s1[i])
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
			i++;
		}
	}
	return flag;

}
char *reverse(char s[])
{
	int l,i=0;
		char s1[40];
		l=calculate(s);
		l=l-1;
		while(l>=0)
		{
			s1[i]=s[l];
			i++;
			l--;
		}
		s1[i]='\0';
  char *ch = s1;
  return ch;
}
void palindrome(char s[40])
{
	int flg=0;
	char *rev1;
	rev1=reverse(s);
	flg=compare(rev1,s);
	if(flg==1)
	{
		printf("It is a palimdrome \n");
	}
	else
	{
		printf("it is not a palindrome \n");
	}
}
int main()
{
	char s[40],s7[40],s1[40],s2[40],*rev;
	int ch,c,l,flag;

	do
	{
		printf("Enter your Choice:\n");
		printf("\n1:Accept the string \n2:Display the string \n3:Calculate length\n4:Copy String\n5:Concat strings\n6:Reverse string\n7:Palindrome\n8:Compare");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept(s);
				break;
			case 2:
				display(s);
				break;
			case 3:
				l=calculate(s);
				printf("\nLength of string is: %d",l);
				break;
			case 4:
				copy(s);
				break;
			case 5:

				printf("\nEnter string to be concatinated ");
				accept(s2);
				concat(s,s2);
				break;
			case 6:
				rev=reverse(s);
				printf("Reversed String is %s",rev);
				break;
			case 7:
				palindrome(s);
				break;
			case 8:
				accept(s7);
				flag=compare(s,s7);
				if(flag==1)
				{
					printf("String is equal");
				}
				else
				{
					printf("String is not equal");
				}
				break;
			default:
				printf("please enter correct choice");
				break;
		}
		printf("\nenter 1 to continue");
		scanf("%d",&c);
	}while(c==1);
	return 0;
}
