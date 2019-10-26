//============================================================================
// Name        : Hashing.cpp
// Author      : Riddhik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 10
using namespace std;

class student
{
	int roll;
	string name=" ";
	char grade=' ';
public:
	student();
	friend class Hashtable;
};
student::student()
{
	roll=-1;
}
class Hashtable
{
	student st[max];
public:
	Hashtable();
	void insert_wor();
	void insert_wr();
	void display();
};
Hashtable::Hashtable()
{
	for(int i=0;i<max;i++)
		st[i].roll=-1;
}
void Hashtable::insert_wor()
{
	student s;
	int ch,count=0;
	int index,i,flag=0;
	do
	{
		cout<<"\n Enter student's Roll No:";
		cin>>s.roll;
		cout<<"\n Enter name:";
		cin>>s.name;
		cout<<"\n Enter Student's grade";
		cin>>s.grade;
		index=s.roll%max;
		if(st[index].roll==-1)
		{
			st[index]=s;
		}
		else
		{
			i=1;
			i=(index+1)%max;
			while(i!=index)
			{
				if(st[i].roll==-1)
				{
					st[i]=s;
					count++;
					break;
				}
				i=(i+1)%max;
			}
			if(count==max)
			{
				cout<<"Hash table full";
				break;
			}
		}
		cout<<"\nEnter 1 to add more ";
		cin>>ch;
	}while(ch==1);
}
void Hashtable::insert_wr()
{
	student s,temp;
	int ch,count=0;
	int index,i,flag=0;
	do{
	cout<<"\n Enter student's roll no:";
	cin>>s.roll;
	cout<<"Name:";
	cin>>s.name;
	cout<<"Grade:";
	cin>>s.grade;
	index=s.roll%max;
	if(st[index].roll==-1)
	{
		st[index]=s;
	}
	else{
		temp=s;
		if(st[index].roll%max!=index)
		{
			temp=st[index];
			st[index]=s;
		}
			i=1;
			i=(index+1)%max;
			while(i!=index)
			{
				if(st[i].roll==-1)
				{
					st[i]=temp;
					count++;
					break;
				}
				i=(i+1)%max;
			}
			if(count==max)
			{
						cout<<"Hash table full";
						break;
			}
		}
	cout<<"\nEnter 1 to add more records ";
	cin>>ch;
	}while(ch==1);
}

void Hashtable::display()
{
	cout<<"\nRoll No\t Name\t Grade";
	for(int i=0;i<max;i++)
	{
		cout<<"\n"<<st[i].roll<<"\t"<<st[i].name<<"\t"<<st[i].grade;
	}
}

int main() {
	Hashtable ht;
	int ch,cond;
	do
	{
		cout<<"\n Enter your choice: ";
		cout<<"\n1.Insert Without Replacement\n2.Insert With Replacement\n3.Display\n";
		cin>>ch;
		switch(ch)
		{
			case 1: ht.insert_wor();
			break;
			case 2:	ht.insert_wor();
			break;
			case 3:	ht.display();
			break;
			default: cout<<"\nPlease enter correct choice";
		}
		cout<<"\nEnter 1 to continue ";
		cin>>cond;
	}while(cond==1);
	return 0;
}
