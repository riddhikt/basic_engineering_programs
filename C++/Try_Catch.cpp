#include<iostream>
using namespace std;

class div			//class definition

{
    float a,b,c;
public:
    div(int a1,int b1)		//parametersied constructor
    {
        a=a1;
        b=b1;
    }
    void divide1()			//divide function
    {
        c=a/b;
        cout<<"division is"<<c<<endl;

    }
};
int main()
{
    int a,b;
    try					//try block
    {
        cout<<"enter number"<<endl;
        cin>>a;
        cin>>b;
        if(a==0 || b==0)		//condition check
        {
            throw(a);
        }
    }
    catch(int c)			//catch block
    {
        cout<<"Cannot divide by 0";
    }
    div d1(a,b);
    d1.divide1();

}


O/P:

enter number
0 
10
Cannot divide by 0

enter number
10 0
Cannot divide by 0 division isinf

enter number
10
5
division is 2


