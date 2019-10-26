/*
Program to find frequency of a substring in a string

Name: Riddhik Tilawat
Roll no: 203732 
Class: SY BTech CSE G

*/

#include<stdio.h>
#include<string.h>
int count=0,count1=0;
char str[50];
char sub[30];

void main()
{
int i,j,l,l1,l2;

printf("Enter a string");		//accepting string
scanf("%s",str);
l1=strlen(str);				//calculating length
printf("Enter a sub string");
scanf("%s",sub);
l2=strlen(sub);
    for(i=0;i<l1;i++)			//loop
    {
        j=0;
        count=0;
            while((str[i]==sub[j]))		//comparison
            {
                count++;
                i++;
                j++;
            }
            if(count==l2)
            {
                count1++;
                count=0;
            }
                else
                {
                    i++;
                }
    }
printf("%s occurs %d times in %s",sub,count1,str);	//printing occurence 
}

/*Output:

Enter the string
nishant
Enter the substring to be matched
shant
Number of matches of substring in main string is 1


*/
