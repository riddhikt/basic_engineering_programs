
#include <iostream>
using namespace std;

class employee
{
	protected:
	string fname;
	string lname;
	string ssn;

	public:
	employee(string fn,string ln,string ss)
	{
		fname=fn;
		lname=ln;
		ssn=ss;
	}
	virtual void display();
	virtual double earnings()=0;
	virtual ~employee()
	{

	}


};

void employee::display()
{
	cout<<"First name"<<fname<<"\n";
	cout<<"Last name"<<lname<<"\n";
	cout<<"Social Security number"<<ssn<<"\n";

}

class salariedemployee:public employee
{
protected:
	double weeklysalary;
public:
	salariedemployee(string fn,string ln,string ss,double ws):employee(fname,lname,ssn)
{
		weeklysalary=ws;
}
	void display();
	double earnings();

};




void salariedemployee::display()
{
	employee::display();
	cout<<"salary"<<weeklysalary;
}
double salariedemployee:: earnings()
{
	return weeklysalary;
}
int main()
{
	salariedemployee se1("Sanket","Wadje","0001",10.00);

	se1.display();
	return 0;

}
