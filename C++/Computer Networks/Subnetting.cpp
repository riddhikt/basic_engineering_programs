#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int a,b,c,d,e;
cout<<"\n enter ip:";
cout<<"\n enter the first octate-";
cin>>a;
cout<<"\nenter the second octate-";
cin>>b;
cout<<"\nenter the third octate-";
cin>>c;
cout<<"\nenter the fourth octate-";
cin>>d;
cout<<"\nIP address:"<<a<<"."<<b<<"."<<c<<"."<<d;
cout<<"\nclass of ip is:";
 if(a>=0 && a<=127){
       cout<<"\nCLASS A";
       cout<<"\nDEFAULT SUBNET MASK :255.0.0.0 ";
	cout<<"\n enter the no. of subnets you want to create\n";
	cin>>e;

	if(e>=2^1 ){
		cout<<"\n subnet mask = 255.128.0.0";
		}
	else if(e>=2^2 ){
		cout<<"\n subnet mask = 255.192.0.0";
		}
	else if(e>=2^3 ){
		cout<<"\n subnet mask = 255.224.0.0";
		}
	else if(e>=2^4 ){
		cout<<"\n subnet mask = 255.240.0.0";
		}
	else if(e>=2^5 ){
		cout<<"\n subnet mask = 255.248.0.0";
		}
	else if(e>=2^6 ){
		cout<<"\n subnet mask = 255.252.0.0";
		}
	else if(e>=2^7 ){
		cout<<"\n subnet mask = 255.254.0.0";
		}
	else if(e>=2^8){
		cout<<"\n subnet mask = 255.255.0.0";
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
	}
else if(e>=2^2 ){
	cout<<"\n subnet mask = 255.255.192.0";
	}
else if(e>=2^3 ){
	cout<<"\n subnet mask = 255.255.224.0";
	}
else if(e>=2^4 ){
	cout<<"\n subnet mask = 255.255.240.0";
	}
else if(e>=2^5 ){
	cout<<"\n subnet mask = 255.255.248.0";
	}
else if(e>=2^6 ){
	cout<<"\n subnet mask = 255.255.252.0";
	}
else if(e>=2^7 ){
	cout<<"\n subnet mask = 255.255.254.0";
	}
else if(e>=2^8){
	cout<<"\n subnet mask = 255.255.255.0";
	}
else cout<<"error";
	

         }else if(a>=192 && a<=223){
                 
                 cout<<"\n CLASS C";
                 cout<<"\n DEFAULT SUBNET MASK : 255.255.255.0";
			cout<<"\n enter the no. of subnets you want to create\n";
			cin>>e;

			if(e>=2^1 ){
				cout<<"\n subnet mask = 255.255.255.128";
			}
			else if(e>=2^2 ){
				cout<<"\n subnet mask = 255.255.255.192";
			}
			else if(e>=2^3 ){
				cout<<"\n subnet mask = 255.255.255.224";
				}
			else if(e>=2^4 ){
				cout<<"\n subnet mask = 255.255.255.240";
				}
			else if(e>=2^5 ){
				cout<<"\n subnet mask = 255.255.255.248.";
			}
			else if(e>=2^6 ){
				cout<<"\n subnet mask = 255.255.255.252";
			}
			else if(e>=2^7 ){
				cout<<"\n subnet mask = 255.255.255.254";
			}
			else if(e>=2^8){
				cout<<"\n subnet mask = 255.255.255.255";
			}
			else cout<<"error";
	

                }


}

