#include<stdio.h>

void main() 
{
	int ch;
	int data[10];
    	int drec[10],c,c1,c2,c3,i;
	while(ch<2)
	{
	printf("\nEnter your choice");
	printf("\n1:Even bits\n2:odd bits");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		

    		printf("Enter 4 bits of data\n");
    		scanf("%d",&data[0]);
    		scanf("%d",&data[1]);
   		scanf("%d",&data[2]);
   		scanf("%d",&data[4]);

   
   		data[6]=data[0]^data[2]^data[4];
   		data[5]=data[0]^data[1]^data[4];
    		data[3]=data[0]^data[1]^data[2];

    		printf("\nEncoded data is\n");
    		for(i=0;i<7;i++)
        	printf("%d",data[i]);

    		printf("\n\nEnter received data bits\n");
    		for(i=0;i<7;i++)
        	scanf("%d",&drec[i]);

    		c1=drec[6]^drec[4]^drec[2]^drec[0];
    		c2=drec[5]^drec[4]^drec[1]^drec[0];
    		c3=drec[3]^drec[2]^drec[1]^drec[0];
    		c=c3*4+c2*2+c1 ;

    		if(c==0) 
		{
        		printf("\nNo error while transmission\n");
    		}
    		else 
		{
        		printf("\nError on position %d",c);

        		printf("\nData sent : ");
        		for(i=0;i<7;i++)
            		printf("%d",data[i]);

       			printf("\nData received : ");
        		for(i=0;i<7;i++)
            		printf("%d",drec[i]);

        		printf("\nCorrect message is\n");

       
        		if(drec[7-c]==0)
            			drec[7-c]=1;
        		else
            			drec[7-c]=0;

        		for (i=0;i<7;i++) {
            		printf("%d",drec[i]);
        	}
		break;
	case 2:
	break;
		
    	}
	}	
	}
}


