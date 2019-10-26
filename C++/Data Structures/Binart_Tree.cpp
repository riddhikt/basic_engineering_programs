

#include <iostream>
using namespace std;

class treenode          //node structure
{
	char data[10];
	treenode *left;
	treenode *right;
	friend class tree;
};



class tree              //tree class
{
	treenode *root;
public:
	tree();
	void create_r();
	void create_r(treenode *);
	void inorder_r();
	void inorder_r(treenode *);
	void preorder_r();
	void preorder_r(treenode *);
	void postorder_r();
	void postorder_r(treenode *);
	void create_nr();
	void inorder_nr();
	void preorder_nr();
	void postorder_nr();

};

tree::tree()        //constructor
{
	root=NULL;
}

void tree::create_r()       //creation of tree
{
	root= new treenode;
	cout<<"Enter data\n";
	cin>>root->data;
	create_r(root);
};

void tree::create_r(treenode *temp)     //creation of tree (workhorse)
{
	char ch;
	cout<<"Should the data be added at the left of "<<temp->data<<"\n";
	cin>>ch;
	if(ch=='y')
	{
		treenode *curr=new treenode;
		curr->left=NULL;
		curr->right=NULL;
		cout<<"Enter data to be added\n";
		cin>>curr->data;
		temp->left=curr;
		create_r(curr);
	}

	cout<<"Should the data be added at the Right of "<<temp->data<<"\n";
	cin>>ch;
	if(ch=='y')
	{
		treenode *curr=new treenode;
		curr->left=NULL;
		curr->right=NULL;
		cout<<"Enter data to be added\n";
		cin>>curr->data;
		temp->right=curr;
		create_r(curr);
	}

}

void tree::inorder_r()      //inorder display recursive
{
	inorder_r(root);
}

void tree::inorder_r(treenode *temp)        //inorder display workhorse
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->data;
		inorder_r(temp->right);
	}

}

void tree::preorder_r()         //preorder display recursive
{
	preorder_r(root);
}

void tree::preorder_r(treenode *temp)       //preorder display workhorse
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		preorder_r(temp->left);
		preorder_r(temp->right);
	}

}

void tree::postorder_r()            //postorder display recursive
{
	postorder_r(root);
}

void tree::postorder_r(treenode *temp)      //postorder display workhorse
{
	if(temp!=NULL)
	{
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout<<temp->data;
	}

}

//non recusrive:

void tree::create_nr()      //nr create
{
	int ch,c;
	int flag=0;
	treenode *temp,*curr;
	if(root==NULL)
	{
		root=new treenode;
		root->left=NULL;
		root->right=NULL;
		cout<<"\nEnter Data for Root:\n";
		cin>>root->data;

	}
	do
	{

		temp=root;
		flag=0;
		curr=new treenode;
		curr->left=NULL;
		curr->right=NULL;
		cout<<"Enter data\n";
		cin>>curr->data;
		while(flag==0)
		{
			cout<<"Enter your Choice:\n1=Left\n2=Right"<<"\nof "<<temp->data;
			cin>>c;
			if(c==1)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					flag=1;
				}
				temp=temp->left;
			}
			else
			{
				if(c==2)
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						flag=1;
					}
					temp=temp->right;
				}
			}
		}
		cout<<"\nEnter 1 to add more\n";
		cin>>ch;


	}while(ch==1);
}

//Stack class

class stack
{
    int top;
    treenode *data[30];
public:
    stack(){
        top=-1;
    }
    void push(treenode *temp);
    treenode *pop();
    int empty();
    friend class tree;
};
void stack::push(treenode *temp)
{
    top++;
    data[top]=temp;
}
treenode* stack::pop()
{
    treenode* temp;
    temp=data[top];
    top--;
    return(temp);
}

void tree :: inorder_nr()
{
    stack s;//object of class stack
    treenode *temp;
    if (root == NULL)
    {
                cout<<"\nBinary tree empty!";
    }
    else
    {
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()==1)
        {                            //terminating condition
            break;
        }
            temp=s.pop();
            cout<<"\t"<<temp->data;
            temp=temp->right;
    }
}
}
void tree :: preorder_nr()
{
    stack s;
    treenode *temp;
    if (root == NULL)
    {
                cout<<"\nBinary tree is empty";
    }
            else
    {
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<temp->data<<"\t";
            temp=temp->left;
        }
        if(s.empty()==1){
            break;
        }
            temp=s.pop();
            temp=temp->right;
    }
}
}

void tree :: postorder_nr(){
    stack s;
    treenode *temp;
    if (root == NULL){
                    cout<<"\nBinary tree empty!";
                }
else{
    temp=root;
    while(1){
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }

        if(s.data[s.top]->right==NULL){
            temp=s.pop();
            cout<<temp->data<<"\t";
        }
        while( s.top!=-1 && s.data[s.top]->right==temp ){
            temp=s.pop();
            cout<<temp->data<<"\t";
        }
        if(s.empty()==1){
                    break;
                }
            temp=s.data[s.top]->right;
    }
}
}

int stack ::empty(){
    if(top==-1){
        return (1);
    }
    else{
        return (0);
    }
}

int main()
{

	tree  bt;
	int ch,a;
	do
	{
		cout<<"Enter your choice\n"<<"Recursive:\n1:Create\n2:Inorder Traversal\n3:Preorder Traversal\n4:Postorder Traversal\n"
				"\nNon-Recursive:\n5:Create\n6:Inorder Traversal\n7:Preorder Traversal\n8:Postorder Traversal";
		cin>>ch;
		switch(ch)
		{
		case 1:
			bt.create_r();
			break;
		case 2:
			cout<<"\nInorder Traversal\n";
			bt.inorder_r();
			break;
		case 3:
			cout<<"\nPreorder Traversal\n";
			bt.preorder_r();
			break;
		case 4:
			cout<<"\nPostorder Traversal\n";
			bt.postorder_r();
			break;
		case 5:
			bt.create_nr();
			break;
		case 6:
			cout<<"\nNR Inorder Traversal\n";
			bt.inorder_nr();
			break;
		case 7:
			cout<<"\nNR Preorder Traversal\n";
			bt.preorder_nr();
			break;
		case 8:
			cout<<"\nNR Postorder Traversal\n";
			bt.postorder_nr();
			break;

		}
		cout<<"\nEnter 1 to continue";
		cin>>a;
	}while(a==1);



	return 0;

}
