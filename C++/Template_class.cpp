Aim: Create a class template stack.
Problem Statement: Design a class Template to implement a stack consisting following member functions:
a) Create
b) Display
c) Push
d) Pop

Program:

#include <iostream>
using namespace std;
#define MAX 5
template<class T>
class stack                           //class
{
protected:
    T arr[MAX];
public:
    T item;
    int top;
    stack()                          //constructor
    {
    for(int i=0;i<MAX;i++)
        arr[i]=NULL;
        top=-1;
    }
   void push(T data)                //function for pushing
    {
        if(top==(MAX-1))
        cout<<"Stack Is Full,Cannot Enter Data\n";
        else
        {
            top++;
            arr[top]=data;
        }
    }
   T pop()                           //function for poping
   {
       if(top==-1)
       {
           cout<<"Stack Is Empty cannot pop\n";
            return NULL;
       }
       else
       {
           T data=arr[top];
           arr[top]=NULL;
           top--;
           return data;
       }
   }
   void display()                    //function for displaying
   {
       int i;
       cout<<"Stack Contents Are \n";
       for(i=top;i>=0;i--)
       {
           cout<<arr[i]<<endl;

       }
   }
};
int main()
{
    int ch;
    int c;
    stack<int>a;
    do
    {
    cout<<"Enter Your Choice \n1.Display \n2.Push \n3.Pop\n";
    cin>>ch;
    switch(ch)		//switch
    {
    case 1: a.display();
            break;
    case 2: int c;
            cout<<"Enter the data u want to enter the stack\n";
            cin>>c;
            a.push(c);

            break;
    case 3: cout<<"Value at that position is\n";
            int b=a.pop();
            cout<<b;

            break;
    }
    cout<<"\nDo u want to continue \n1.Yes\n0.N0\n";
    cin>>c;
    }while(c==1);
}

