//============================================================================
// Name        : complex.cpp
// Author      : Riddhik Tilawat
// Copyright   : Your copyright notice
// Description : Performing arithmetic operations on complex number
//============================================================================

#include<iostream>
using namespace std;

class complex32
{
	int real,img;
public:


	complex32() //Default Constructor
	{
		real=0;
		img=0;
	}
	complex32(int r,int i) //parameterized constructor
	{
		real=r;
		img=i;
	}
	complex32(complex32 &C) //copy constructor
	{
		real=C.real;
		img=C.img;
	}

	complex32 operator +(complex32 y) //operator overloading for +
	{
		complex32 q;
		q.real=real+y.real;
		q.img=img+y.img;
		return q;


	}
	complex32 operator -(complex32 y) //operator overloading for -
	{
			complex32 q;
			q.real=real-y.real;
			q.img=img-y.img;
			return q;


	}
	complex32 operator /(complex32 y) //operator overloading for /
		{
			complex32 q;
			q.real=real/y.real;
			q.img=img/y.img;
			return q;


		}
	complex32 operator *(complex32 y) //operator overloading for *
		{
			complex32 q;
			q.real=(real*y.real)-(img*y.img);
			q.img=(img*y.real)+(y.img*real);
			return q;


		}


	~complex32() 	//destructor
	{
		cout<<"object deleted \n";
	}

	friend istream & operator >>(istream &inp,complex32 &c) //operator overloading for >>
	{
		cout<<"enter real part \n";
		inp>>c.real;
		cout<<"enter img part \n";
		inp>>c.img;
	}
	friend ostream & operator <<(ostream &op,complex32 &c) //operator overloading for <<
	{
		op<<"Complex no. is \n";
		op<<c.real<<"+i"<<c.img;

	}

};
 int main()
 {

	 int ch=0;
	 complex32 s1,s2,s3;
	 do{
	 cout<<"enter a complex no \n";
	 cin>>s1;
	 cout<<"enter another complex no. \n";
	 cin>>s2;
	 cout<<"select 1 for addition \n select 2 for subtraction \n select 3 for multiplication \n select 4 for division \n";
	 cin>>ch;

	switch(ch)
	{
	case 1:
		s3=s1+s2; //addition performed
		cout<<s3;
		break;
	case 2:
		s3=s1-s2; //subtraction performed
		cout<<s3;
		break;
	case 3:
		s3=s1*s2; //multiplication performed
		cout<<s3;
		break;
	case 4:
		s3=s1/s2; //division performed
		cout<<s3;
		break;

	}
	 }while(ch<=4);

	 return 0;
 }


 /**************************************************************************************************

  O/P:

  enter a complex no
enter real part
5
enter img part
7
enter another complex no.
enter real part
7
enter img part
5
select 1 for addition
 select 2 for subtraction
 select 3 for multiplication
 select 4 for division
1
object deleted
object deleted
Complex no. is
12+i12enter a complex no
enter real part
66
enter img part
77
enter another complex no.
enter real part
66
enter img part
99
select 1 for addition
 select 2 for subtraction
 select 3 for multiplication
 select 4 for division
2
object deleted
object deleted
Complex no. is
0+i-22enter a complex no
enter real part
10
enter img part
5
enter another complex no.
enter real part
5
enter img part
10
select 1 for addition
 select 2 for subtraction
 select 3 for multiplication
 select 4 for division
3
object deleted
object deleted
Complex no. is
0+i125

  */
