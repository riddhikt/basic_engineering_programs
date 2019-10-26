

#include <stdio.h>


void accept(int a[6][6], int r, int c)	//for accepting matrix
{
    int i, j;
    printf("\nEnter elements of matrix");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void compact(int a[6][6],int r,int c,int b[20][3])		//for coverting into compact
{
    int i,j,k;
    k=1;
    b[0][0]=r;
    b[0][1]=c;
    for (i =0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2]=k-1;
    }
}

void display(int b[6][3])		//for displaying compact matrix
{
    int i, column;
    column = b[0][2];
    printf("\nSparse form - list of 3 triples\n\n");
    for (i = 0; i < column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void displaycompact(int b[20][3])	//for displaying transposed matrix
{
    int i;
    for(i=0;i<(b[0][2]+1);i++)
    {
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
    }
}

void transpose(int b[20][3])	//Simple transpose
{
    int t[20][3],q,i,j,m,n,o;
    m=b[0][0];
    n=b[0][1];
    o=b[0][2];
    t[0][1]=m;
    t[0][0]=n;
    t[0][2]=o;
    if(t<=0)
        return;
    q=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=o;j++)
        {
            if(b[j][1]==i)
            {
                t[q][0]=b[j][1];
                t[q][1]=b[j][0];
                t[q][2]=b[j][2];
                q++;
            }
        }
    }
    displaycompact(t);
}
void ftrans(int b[20][3])		//Fast transpose
{
    int t[20][3],s[20],w[20],i,j,m,n,o;
    m=b[0][0];
    n=b[0][1];
    o=b[0][2];
    t[0][1]=m;
    t[0][0]=n;
    t[0][2]=o;
    if(t<=0)
        return;
    for(i=0;i<n;i++)
        w[i]=0;
    for(i=1;i<=o;i++)
        s[b[i][1]]=s[b[i][1]]+1;
    w[0]=1;
    for(i=1;i<n;i++)
        w[i]=w[i-1]+s[i+1];

    for(i=1;i<=o;i++)
    {
        j=b[i][1];
        t[w[j]][0]=b[i][1];
        t[w[j]][1]=b[i][0];
        t[w[j]][2]=b[i][2];
        w[j]=w[j]+1;
    }
    for(i=0;i<=(b[0][2]+1);i++)
    {
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
    }

}

/*void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
    int t1,t2,i,j,k;
    t1=b1[0][2];
    t2=b2[0][2];
    i=j=k=0;
    b3[0][0]=b1[0][0];
    b3[0][1]=b1[0][1];
    while(i<=t1 && j<=t2)
    {
        if(b1[i][0] < b2[j][0])
        {
            b3[k][0]=b1[i][0];
            b3[k][1]=b1[i][1];
            b3[k][2]=b1[i][2];
            k++;
            i++;
            continue;//go to  end of the loop
        }
        if(b2[j][0] < b1[i][0])
        {
            b3[k][0]=b2[j][0];
            b3[k][1]=b2[j][1];
            b3[k][2]=b2[j][2];
            k++;
            j++;
            continue;//go to end of the loop
        }
        if(b1[i][1] < b2[j][1])
        {
            b3[k][0]=b1[i][0];
            b3[k][1]=b1[i][1];
            b3[k][2]=b1[i][2];
            k++;
            i++;
            continue;//go to end of the loop
        }
        if(b2[j][1] < b1[i][1])
        {
            b3[k][0]=b2[j][0];
            b3[k][1]=b2[j][1];
            b3[k][2]=b2[j][2];
            k++;
            j++;
            continue; //go to end of the loop
        }
//else add the two tuples
        b3[k][0]=b1[i][0];
        b3[k][1]=b1[i][1];
        b3[k][2]=b1[i][2]+b2[j][2];
        k++;
        i++;
        j++;

     }//end of loop
        while(i<=t1)
        {
            b3[k][0]=b1[i][0];
            b3[k][1]=b1[i][1];
            b3[k][2]=b1[i][2];
            i++;
            k++;
        }
        while(j<=t2)
        {
            b3[k][0]=b2[j][0];
            b3[k][1]=b1[j][1];
            b3[k][2]=b1[j][2];
            j++;
            k++;
        }
        b3[0][2]=k-1;
 }*/
int main()
{
    int a[6][6], b[6][3], row, column,ch;
    printf("\nEnter the size of matrix (rows, columns): ");	//accepting size
    scanf("%d%d", &row, &column);
    do
    {
    	printf("\nEnter your choice: \n");
    	printf("1:Accept\n2:Display\n3:Compact\n4:Transpose\n5:Fast Transpose\n6:Exit\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    	case 1:
    		accept(a, row, column);	//accepting matrix
    		break;
    	case 2:
    		display(b);	//displaying compact
    		break;
    	case 3:
    		compact(a, row, column, b);	//converting matrix
    		break;
    	case 4:
    		transpose(b);	//transposing matrix
    		break;
    	case 5:
    		ftrans(b);	//Fast transpose

    		break;
    	case 6:
    		break;		//exit
    	}
    }while(ch!=6);

    return 0;
}

/*
 Output:


Enter the size of matrix (rows, columns): 6
6

Enter your choice:
1:Accept
2:Display
3:Compact
4:Transpose
5:Fast Transpose
6:Exit
1

Enter elements of matrix[0][0]: 15
[0][1]: 0
[0][2]: 0
[0][3]: 22
[0][4]: 0
[0][5]: -15
[1][0]: 0
[1][1]: 0
[1][2]: 0
[1][3]: -6
[1][4]: 0
[1][5]: 0
[2][0]: 0
[2][1]: 0
[2][2]: 0
[2][3]: 0
[2][4]: 0
[2][5]: 0
[3][0]: 91
[3][1]: 0
[3][2]: 0
[3][3]: 0
[3][4]: 0
[3][5]: 0
[4][0]: 0
[4][1]: 0
[4][2]: 23
[4][3]: 0
[4][4]: 0
[4][5]: 0
[5][0]: 0
[5][1]: 0
[5][2]: 0
[5][3]: 0
[5][4]: 0
[5][5]: 0

Enter your choice:
1:Accept
2:Display
3:Compact
4:Transpose
5:Fast Transpose
6:Exit
3

Enter your choice:
1:Accept
2:Display
3:Compact
4:Transpose
5:Fast Transpose
6:Exit
2

Sparse form - list of 3 triples

6	6	6
0	0	15
0	3	22
0	5	-15
1	3	-6
3	0	91

Enter your choice:
1:Accept
2:Display
3:Compact
4:Transpose
5:Fast Transpose
6:Exit
4
6	6	6
0	0	15
0	3	91
2	4	23
3	0	22
3	1	-6
5	0	-15

Enter your choice:
1:Accept
2:Display
3:Compact
4:Transpose
5:Fast Transpose
6:Exit
5
6	6	6
0	0	15
0	3	91
2	4	23
3	0	22
3	1	-6
5	0	-15
6
 */
