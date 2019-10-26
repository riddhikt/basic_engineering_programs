

#include<iostream>
#include<cmath>
using namespace std;
class node              //node class
{
	int exp;
	int coef;
	node *next;
	friend class Poly;
};
class Poly              //Polynomial class
{
	node *head;
public:
	Poly();
	void Create();
	void Create(node *);
	void Display();
	void Display(node *);
	void Add(node *, node *);
	void Eval(node *, int);
};
Poly::Poly()            //constructor
{
	head=new node;
	head->exp=-1;
	head->next=head;
}
void Poly::Create()        //poly creation
{
	Create(head);
}
void Poly::Create(node *temp)	//poly creation :workhorse
{
	int cond;
        do
        {
		node *curr=new node;
		curr->next=head;
		cout<<"\nEnter coefficient: ";
		cin>>curr->coef;
		cout<<"\nEnter exponent: ";
		cin>>curr->exp;
		temp->next=curr;
		temp=temp->next;
		cout<<"\nDo you want to continue creation? (Y=1/N=0): ";
		cin>>cond;
	}while(cond==1);
}
void Poly::Display()        //poly display
{
	Display(head);
}
void Poly::Display(node *temp)          //poly display :workhorse
{
	temp=temp->next;
        while(temp->exp!=-1)
        {
		cout<<"\nCoefficient: "<<temp->coef<<"\tExponent: "<<temp->exp;
		temp=temp->next;
	}
}
void Poly::Add(node *h1, node *h2)	//adding node
{
	node *t1,*t2,*t3;
	t1=h1->next;
	t2=h2->next;
	node *head3=new node;
	head3->exp=-1;
	head3->next=head3;
	t3=head3;
        while(t1->exp!=-1 && t2->exp!=-1)
        {
		if(t1->exp==t2->exp)	{
			node *temp=new node;
			temp->coef=(t1->coef+t2->coef);
			temp->exp=t1->exp;
			t3->next=temp;
			temp->next=head3;
			t3=temp;
			t1=t1->next;
			t2=t2->next;
		}
                else if(t1->exp>t2->exp)
                {
			t3->next=t1;
			t3=t3->next;
			t1=t1->next;
		}
		else	{
			t3->next=t2;
			t3=t3->next;
			t2=t2->next;
		}
	}
	Display(head3);
}
void Poly::Eval(node *h1, int x)	//poly evaluation
{
	int sum=0;
	node *temp=h1->next;
        while(temp->exp!=-1)
        {
		int res=0;
		res = temp->coef*(int)(pow(x,temp->exp));
		temp=temp->next;
		sum=sum+res;
	}
	cout<<"Result of evaluation is: "<<sum;
}
int main()
{
	Poly p;
        int c,ch,x;
	node *head1=new node;
	node *head2=new node;
	do	{
		cout<<"\n Enter your choice\n1.Addition \n2.Evaluation\n ";
		cin>>ch;
                switch(ch)
                {
                case 1: cout<<"\nEnter 1st polynomial: ";
				p.Create(head1);
                                cout<<"\nEnter 2nd polynomial: ";
				p.Create(head2);
				cout<<"\nAddition:\n";
				p.Add(head1,head2);
				break;
		case 2: cout<<"\nEnter polynomial for evaluation: ";
				p.Create(head1);
				cout<<"\nEnter value of x: ";
				cin>>x;
				p.Eval(head1,x);
				break;
                default: cout<<"\nPlease enter correct choice";
		}
                cout<<"\nPress 1 to continue ";
                cin>>c;
	}while(cond==1);
	return 0;
}

