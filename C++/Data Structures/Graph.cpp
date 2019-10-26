
#include <iostream>
#define max 20
using namespace std;
class node
{
	string name;
	node *next;
	friend class Graph;
};

class Graph
{
	node *head[20];
	int visited[max];
	int users;

public:
	Graph()
	{
		for(int i=0;i<max;i++)
		{
			head[i]=new node;
			head[i]->next=NULL;

		}
	}
	void Create();
		void Display();
		int Search(node *name);
		void DFS();
		void DFS(int v);
		void DFSnr();
		void BFT();
};

class Stack
{
		int top;
	    int data[30];
	public:
	    Stack(){
	        top=-1;
	    }
	    void Push(int temp);
	    int Pop();
	    int IsEmpty();
	    friend class Graph;
};

void Stack::Push(int temp)
{
	    top++;
	    data[top]=temp;
}

int Stack::Pop()
{
	    int temp;
	    temp=data[top];
	    top--;
	    return(temp);
}
int Stack::IsEmpty()
{
	    if(top==-1){
	        return 1;
	    }
	    else
	        return 0;
}
class Queue
{
	int f=-1,r=-1;
	int q[max];
public:
	int IsEmpty();
	int IsFull();
	void Addq(int item);
	int Delq();
	friend class Graph;
};
int Queue::IsEmpty()
{
	if(f==r)
			return 0;
		else
			return 1;
}
int Queue::IsFull()
{
		if(r==(max-1))
			return 0;
		else
			return 1;
}
void Queue::Addq(int item)
{
		if(IsFull()==1)
		{
			r++;
			q[r]=item;
		}
		else
		{
			cout<<"\nQueue is full";
		}
}
int Queue::Delq()
{
		int temp;
		if(IsEmpty()==1)
		{
			f++;
			temp=q[f];
			return temp;
		}
		else
			return -1;
}
void Graph::Create()
{
	int ch;
	cout<<"\nEnter number of users: ";
	cin>>users;
	node *temp, *curr;
	for(int i=0; i< users ; i++)
	{
		cout<<"\nEnter user name: ";
		cin>>head[i]->name;
		head[i]->next=NULL;
	}
	for(int i=0 ; i<users; i++)
	{
		temp=head[i];
		int flag=0;
		do
		{
			curr=new node;
			cout<<"\nEnter friend's name of "<<head[i]->name<<" : ";
			cin>>curr->name;
			for(int j=0; j<users; j++)
			{
				if(curr->name==head[j]->name)
				{
					flag=1;
					break;
				}
				else
					flag=0;
			}
			if(flag==1)
			{
				if(curr->name==head[i]->name)
					cout<<"\nSelf loop is not allowed";
				else
				{
					temp->next=curr;
					curr->next=NULL;
					temp=curr;
				}
			}
			else if(flag==0)
			{
				cout<<"\nUser Not Found.";
			}
			cout<<"\nEnter 1 to add more friends\n ";
			cin>>ch;
		}while(ch==1);
	}
}
void Graph :: Display()
{
	node *temp;
	for(int i=0; i<users; i++)
	{
		temp=head[i];
		cout<<"\nFriends of ";
		while(temp!=NULL){
			cout<<temp->name<<"--->";
			temp=temp->next;
		}
	}
}
int Graph :: Search(node *x)
{
	node *temp;
	for(int i=0; i<users; i++)
	{
		temp=head[i];
		if(temp->name == x->name)
			return i;
	}
	return -1;
}
void Graph :: DFS()
{
		node *x=new node;
		int k;
		for(int i=0;i<users;i++)
			visited[i]=0;
		cout<<"\nEnter starting vertex: ";
		cin>>x->name;
		k=Search(x);
		if(k>=0)
			DFS(k);
		else
			cout<<"\nNode does not exist";
}
void Graph :: DFS(int v)
{
	int w;
	cout<<head[v]->name<<"\t";
	visited[v]=1;
	node *temp;
	temp=head[v]->next;
	while(temp!=NULL)
	{
			w=Search(temp);
			if(visited[w]==0)
		  	   DFS(w);
		  	else
		  		temp=temp->next;
	}

}
void Graph::DFSnr()
{
	int i,j,k;
		node *v;
		v=new node();
		node *curr;
		Stack s;
		for(i=0;i<users;i++)
			visited[i]=0;
		cout<<"\nEnter starting vertex:";
		cin>>v->name;
		k=Search(v);
		s.Push(k);
		visited[k]=1;
		do{
			j=s.Pop();
			curr=head[j];
			cout<<curr->name<<"\t";
			while(curr!=NULL){
				k=Search(curr);
				if(visited[k]==0){
					s.Push(k);
					visited[k]=1;
				}
				curr=curr->next;
			}
		}while(s.IsEmpty()!=1);
}
void Graph::BFT()
{
	Queue q;
	int i,j,k;
		node *v;
		v=new node();
		node *curr;
		for(i=0;i<users;i++)
			visited[i]=0;
		cout<<"\nEnter starting vertex: ";
		cin>>v->name;
		k=Search(v);
		q.Addq(k);
		visited[k]=1;
		do{
			j=q.Delq();
			curr=head[j];
			cout<<curr->name<<"\t";
			while(curr!=NULL){
				k=Search(curr);
				if(visited[k]==0){
					q.Addq(k);
					visited[k]=1;
				}
				curr=curr->next;
			}
		}while(q.IsEmpty()!=0);
}
int main()
{
	Graph g;
	int ch,c;
	do{
		cout<<"\nEnter your Choice:\n1.Create\n2.Display List\n3.DFS(r)"
				"\n4.DFS(nr)\n5.BFT\n Enter your choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:	g.Create();
	    			break;
	    	case 2:	g.Display();
	    			break;
	    	case 3:	g.DFS();
	    			break;
	    	case 4:	g.DFSnr();
	    			break;
	    	case 5:	g.BFT();
	    			break;
	    	default: cout<<"\nWrong Choice";
	    	}
	    cout<<"\nEnter 1 to Continue";
	    cin>>c;
	}while(c==1);
	return 0;
}
