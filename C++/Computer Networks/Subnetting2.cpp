#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    int a,b,c,d,q[15],i,n;
    double x = 2.0,k,m;

    cout<<"\nEnter address for organisation : ";
    cin>>a>>b>>c>>d;
    cout<<"\nEnter subnet mask for organisation : ";
    cin>>m;
    cout<<"\nAddress for organisation :"<<a<<"."<<b<<"."<<c<<"."<<d;
    cout<<"\nEnter Number of subnets : ";
    cin>>n;

    for(int i=0;i<n;i++)
     {
 cout<<"\nHow many addresses for subnet "<<i+1<<" : ";
 cin>>q[i];
     }

     for(i=0;i<n;i++)
     {
   m=0;
   k=(int)pow(x,m);
   while(k!=q[i])
     {
    m++;
    k=(int)pow(x,m);
      }
   m=32-m;
   if(d>255)
    {
        d=0;
        c++;
    }
   cout<<"\nsubnet "<<i+1<<" : "<<a<<"."<<b<<"."<<c<<"."<<d;
   d=d+q[i]-1;
   if(d>255)
    {
        d=d-255-1;
        c++;
    }
    cout<<"  to  "<<a<<"."<<b<<"."<<c<<"."<<d++;
     }

     return 0;
}


