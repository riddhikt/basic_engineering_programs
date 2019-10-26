#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    int a,b,c,d,q[15],e,n,i,f=0,h;
    double x = 2.0,k,m;

    cout<<"\nEnter address for organisation : ";
    cin>>a>>b>>c>>d;
   /* cout<<"\nEnter subnet mask for organisation : ";
    cin>>m;*/
    cout<<"\nAddress for organisation :"<<a<<"."<<b<<"."<<c<<"."<<d; //<<"/"<<m
    cout<<"\nEnter Number of subnets : ";
    cin>>e;


cout<<"\nclass of ip is:";
 if(a>=0 && a<=127){
       cout<<"\nCLASS A";
       cout<<"\nDEFAULT SUBNET MASK :255.0.0.0 ";
	cout<<"\n enter the no. of subnets you want to create\n";
	cin>>e;

	if(e>=2^1 ){
		cout<<"\n subnet mask = 255.128.0.0";
		f=128;
		}
	else if(e>=2^2 ){
		cout<<"\n subnet mask = 255.192.0.0";
		f=192;
		}
	else if(e>=2^3 ){
		cout<<"\n subnet mask = 255.224.0.0";
		f=224;			
		}
	else if(e>=2^4 ){
		cout<<"\n subnet mask = 255.240.0.0";
		f=240;		
		}
	else if(e>=2^5 ){
		cout<<"\n subnet mask = 255.248.0.0";
		f=248;		
		}
	else if(e>=2^6 ){
		cout<<"\n subnet mask = 255.252.0.0";
		f=252;	
		}
	else if(e>=2^7 ){
		cout<<"\n subnet mask = 255.254.0.0";
		f=254;	
		}
	else if(e>=2^8){
		cout<<"\n subnet mask = 255.255.0.0";
		f=255;	
		}
	else cout<<"error";
	

   }else if (a>=128 && a<=191){
          
            cout<<"\n CLASS B";
            cout<<"\n DEFAULT SUBNET MASK :255.255.0.0 ";
		cout<<"\n enter the no. of subnets you want to create\n";
cin>>e;

if(e>=2^1 ){
	cout<<"\n subnet mask = 255.255.128.0";
	cout<<"\n only subnet mask";
	f=128;
	}
else if(e>=2^2 ){
	cout<<"\n subnet mask = 255.255.192.0";
		f=192;
	}
else if(e>=2^3 ){
	cout<<"\n subnet mask = 255.255.224.0";
		f=224;
	}
else if(e>=2^4 ){
	cout<<"\n subnet mask = 255.255.240.0";
		f=240;
	}
else if(e>=2^5 ){
	cout<<"\n subnet mask = 255.255.248.0";
		f=248;
	}
else if(e>=2^6 ){
	cout<<"\n subnet mask = 255.255.252.0";
		f=252;
	}
else if(e>=2^7 ){
	cout<<"\n subnet mask = 255.255.254.0";
		f=254;
	}
else if(e>=2^8){
	cout<<"\n subnet mask = 255.255.255.0";
		f=255;
	}
else cout<<"error";
	

         }else if(a>=192 && a<=223){
                 
                 cout<<"\n CLASS C";
                 cout<<"\n DEFAULT SUBNET MASK : 255.255.255.0";
			cout<<"\n enter the no. of subnets you want to create\n";
			cin>>e;

			if(e>=2^1 ){
				cout<<"\n subnet mask = 255.255.255.128";
				f=128;
			}
			else if(e>=2^2 ){
				cout<<"\n subnet mask = 255.255.255.192";
				f=192;
			}
			else if(e>=2^3 ){
				cout<<"\n subnet mask = 255.255.255.224";
				f=224;
				}
			else if(e>=2^4 ){
				cout<<"\n subnet mask = 255.255.255.240";
				f=240;
				}
			else if(e>=2^5 ){
				cout<<"\n subnet mask = 255.255.255.248";
				f=248;
			}
			else if(e>=2^6 ){
				cout<<"\n subnet mask = 255.255.255.252";
				f=252;
			}
			else if(e>=2^7 ){
				cout<<"\n subnet mask = 255.255.255.254";
				f=254;
			}
			else if(e>=2^8){
				cout<<"\n subnet mask = 255.255.255.255";
				f=255;
			}
			else cout<<"error";
	

                }

h=255-f;

   /* for(int i=0;i<n;i++)
     {
 cout<<"\nHow many addresses for subnet "<<i+1<<" : ";
 cin>>q[i];
     }*/

     for(i=0;i<n;i++)
     {
   f=0;
   k=(int)pow(x,m);
   while(k!=h)
     {
    m++;
    k=(int)pow(x,m);
      }
   f=32-f;
   if(d>255)
    {
        d=0;
        c++;
    }
   cout<<"\nsubnet "<<i+1<<" : "<<a<<"."<<b<<"."<<c<<"."<<d;//"/"<<m
   d=d+h-1;
   if(d>255)
    {
        d=d-255-1;
        c++;
    }
    cout<<"  to  "<<a<<"."<<b<<"."<<c<<"."<<d++; //<<"/"<<m
     }

     return 0;
}


