

#include <iostream>
#define min -1
#define max 20
using namespace std;
 class phnnet
 {
 private:
	int matrix[max][max];
	int vertices=0;
	int nearest[max];
	int mst[max][max];
 public:
	phnnet()
	{
		for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
			{
				matrix[i][j]=min;
			}
		}
	}
	void create();
	void display();
	int prims();
 };

 void phnnet::create()
 {
	 int ch;

	 cout<<"Enter number of vertices\n";
	 cin>>vertices;
	 for(int i=0;i<vertices;i++)
	 {
		 for(int j=0;j<vertices;j++)
		 {
			 if(i!=j)
			 {
				 if(matrix[i][j]==min)
				 {
					 cout<<"Enter 1 if edge is present between "<<i<<" and"<<j;
					 cin>>ch;
					 if(ch==1)
					 {
						 cout<<"Enter Weight from edge "<<i<<" to edge "<<j;
						 cin>>matrix[i][j];
						 matrix[j][i]=matrix[i][j];
					 }
				 }
			 }
		 }
	 }
 }

 void phnnet::display()
 {
	 for(int i=0;i<vertices;i++)
	 {
		 //cout<<"\t"<<i;
	 }
	 for(int i=0;i<vertices;i++)
	 {
		 cout<<"\n";
		 for(int j=0;j<vertices;j++)
		 {
			 //cout<<i;
			 cout<<"\t"<<matrix[i][j];
		 }
	 }
 }

 int phnnet::prims()
 {
	 int stv;
	 int cost=0;
	 cout<<"\nEnter starting vertex\n";
	 cin>>stv;
	 nearest[stv]=-1;
	 for(int i=0;i<vertices;i++)
	 {
		 if(i!=stv)
		 {
			 nearest[i]=stv;
		 }
	 }
	 int r=0,j;
	 for(int i=1;i<vertices;i++)
	 {
		 int mini=999;
		 for(int k=0;k<vertices;k++)
		 {
			 if(nearest[k]!=-1 && matrix[k][nearest[k]]<mini)
			 {
				 j=k;
				 mini=matrix[k][nearest[k]];

			 }
		 }
		 mst[r][1]=j;
		 mst[r][2]=nearest[j];
		 r=r+1;
		 cost=cost+matrix[j][nearest[j]];
		 nearest[j]=-1;
		 for(int k=0;k<vertices;k++)
		 {
			 if(nearest[k]!=-1 && matrix[k][nearest[k]]>matrix[k][j])
			 {
				 nearest[k]=j;
			 }
		 }

	 }
	 return cost;
 }
int main()
{
	phnnet p;
	int cost;
	p.create();
	p.display();
	cost=p.prims();
	cout<<"\n Minimum cost is "<<cost;
	return 0;
}
