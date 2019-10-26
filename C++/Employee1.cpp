#include<iostream>
#include<string.h>
using namespace std;
		class Employee
		{
		public:
			int id;
			string name;
			void accept()
			{
				cout<<"\nEnter your name and id"<<endl;
				cin>>name>>id;
			}
			void display()
			{
				cout<<"\nNAME:-"<<name<<"\nID:-"<<id<<endl;
			}

		};

		class Salaried : public virtual Employee
		{
			protected:
			double salary;
			public:

				void accept()
				{
					cout<<"\nEnter your salary:-"<<endl;
					cin>>salary;
				}
				void display()
				{
					cout<<"\nSalary:-"<<salary<<endl;
				}
				void earnings()
				{

				}
		};
		class commision : public virtual Employee
		{
			protected:
				int sales,rate;
				double csalary;
			public:

				void accept()
				{
					cout<<"\nEnter the Number of sales:-"<<endl;
					cin>>sales;
					cout<<"\nEnter the Rate:-"<<endl;
					cin>>rate;
				}
				void earnings()
				{
					csalary=(sales*rate);
				}
				void display()
				{
					//cout<<"\nSales:-"<<sales<<"\nRate:-"<<rate<<endl;
					cout<<"Salary="<<csalary;
				}
		};
		class hourly : public Employee
		{
			int hours,wage;
			int hresult;
			public:

			void accept()
			{
					cout<<"\nEnter number of Hours"<<endl;
					cin>>hours;
				    cout<<"\nEnter Wages"<<endl;
					cin>>wage;
			}
			void earnings()
			{
				if(hours<=40)
				{
					hresult=hours*wage;
				}
				else
				{
					hresult=(40*wage)+((hours-40)*wage*1.5);

				}
			}
			void display()
			{
				cout<<"\nTotal Salary:-"<<hresult;
			}
		};

		class salariedcommision :public Salaried,public commision
		{
				public :
				int tsalary;

				void earnings()
				{
					tsalary=salary+(sales*rate);
				}
				void display()
				{
					cout<<"\nTotal Salaried Commission="<<tsalary;
				}

		};

int main()
{
	int ch;

	Salaried s1;
	commision c1;
	hourly h1;
	salariedcommision sc1;

	cout<<"Enter type of employee you are"<<endl;
	cout<<"\n1.Salaried\n2.hourly\n3.commissioned\n4.salariedcommissioned\n"<<endl;
	cin>>ch;
	switch(ch)
	{

		case 1:
					s1.Employee::accept();
					s1.accept();
					s1.Employee::display();
					s1.display();
					s1.earnings();
					break;
		case 2:

					c1.Employee::accept();
					c1.accept();
					c1.Employee::display();
					c1.earnings();
					c1.display();
					break;
		case 3:
					h1.Employee::accept();
					h1.accept();
					h1.Employee::display();
					h1.earnings();
					h1.display();
					break;
		case 4:
					sc1.Employee::accept();
					sc1.Salaried::accept();
					sc1.commision::accept();
					sc1.earnings();
					sc1.Employee::display();
					sc1.display();
					break;
	}

		return 0;

}
