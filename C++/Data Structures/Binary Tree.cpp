
#include <iostream>
using namespace std;

class treenode
{
	char data[10];
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree
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
};

tree::tree()
{
	root=NULL;
}

void tree::create_r()
{
	root= new treenode;
	cout<<"Enter data\n";
	cin>>root->data;
	create_r(root);
};

void tree::create_r(treenode *temp)
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

void tree::inorder_r()
{
	inorder_r(root);
}

void tree::inorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->data;
		inorder_r(temp->right);
	}

}

void tree::preorder_r()
{
	preorder_r(root);
}

void tree::preorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		preorder_r(temp->left);
		preorder_r(temp->right);
	}

}

void tree::postorder_r()
{
	postorder_r(root);
}

void tree::postorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout<<temp->data;
	}

}

int main()
{

	tree  bt;
	int ch,a;
	do
	{
		cout<<"Enter your choice\n"<<"1:Create\n2:Inorder Traversal\n3:Preorder Traversal\n4:Postorder Traversal";
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
			cout<<"\npreorder Traversal\n";
			bt.preorder_r();
			break;
		case 4:
			cout<<"\npostorder Traversal\n";
			bt.postorder_r();
			break;

		}
		cout<<"\nEnter 1 to continue";
		cin>>a;
	}while(a==1);



	return 0;

}
