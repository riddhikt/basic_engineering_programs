
#include <iostream>

using namespace std;

class node
{
	string keyword;
	string meaning;
	node *left,*right;
	friend class treenode;
};

class treenode
{
	node *root;
public:
	void create_nr();
	treenode();
	void inorder_r();
	void inorder_r(node *);
	void search_nr();
	void search_r();
	int search_r(node *,string );
	void bfs();
	void delete1();
	void copy_r();
	node* copy_r(node* root);
	void copy_nr();
	void mirror_r();
	void mirror_r(node *);
	void mirror_nr();
	void copy_nr(treenode t1);
	void erase();



};

void treenode:: mirror_r()
{
    mirror_r(root);

}
void treenode:: mirror_r(node* root)
{
    node* temp;
    temp= root->right;
    root->right=root->left;
    root->left=temp;
    if(root->left!=NULL)
    {
        mirror_r(root->left);
    }
    if(root->right!=NULL)
    {
        mirror_r(root->right);
    }
}


void treenode :: copy_r()
{
    node* root2;
    root2 = copy_r(root);
    cout<<"Copy operation complete\n";
    inorder_r(root2);
}
node* treenode :: copy_r(node* root)
{
    node* temp=NULL;
    if(root!=NULL)
    {
        temp=new node;
        temp->keyword=root->keyword;
        temp->meaning=root->meaning;
        temp->left=copy_r(root->left);
        temp->right=copy_r(root->right);
    }
    return temp;
}

treenode::treenode()
{
	root=NULL;
}
void treenode::create_nr()
{
	int c;
	node *curr;
	node *temp;

	int flag=0;
	if(root==NULL)
	{
		root=new node;
		root->left=NULL;
		root->right=NULL;

		cout<<"\nEnter keyword for Root\n";
		cin>>root->keyword;
		cout<<"\nEnter Meaning of the Entered keyword\n";
		cin>>root->meaning;
	}
	do
	{
		temp=root;

		flag=0;
		curr=new node;
		cout<<"Enter keyword to be added\n";
		cin>>curr->keyword;
		cout<<"Enter Meaning\n";
		cin>>curr->meaning;
		while(flag==0)
		{
			if(curr->keyword<temp->keyword)
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
				if(curr->keyword>temp->keyword)
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
		cout<<"Press 1 to add more keywords\n";
		cin>>c;

	}while(c==1);
}

void treenode:: delete1()
{
	node *temp,*parent,*curr,*s;
	int flag=0;
	string key;
	cout<<"Enter key to be Deleted\n";
	cin>>key;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->keyword == key)
		{
			flag=1;
			break;
		}
		else if(curr->keyword <key)
		{
			parent=curr;
			curr=curr->right;
		}
		else
		{
			parent=curr;
			curr=curr->left;
		}
	}
	if(flag==1)
	{
		if(curr==root)
		{
			if(curr->right==NULL)
			{
				root=root->left;
			}
			else if(curr->left==NULL)
			{
				root=root->right;
			}
			else if(curr->right!=NULL && curr->left!=NULL)
			{
				temp=curr->left;
				root=curr->right;
				s=curr->right;
				while(s->left!=NULL){
				s=s->left;
			}
			s->left=temp;
        }
    }
    else if( curr!=root)
    {
        if(curr->left==NULL && curr->right==NULL)
        {
            if(parent->left==curr)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
            }
        }
        else if(curr->left==NULL)
        {
            if(parent->left==curr)
            {
                parent->left=curr->right;
            }
            else
            {
                parent->right=curr->right;
            }
        }
        else if(curr->right==NULL)
        {
            if(parent->left==curr)
            {
                parent->left=curr->left;
            }
            else
            {
                parent->right=curr->left;
            }
        }
                else
                 {
                    s=curr->right;
                    temp=curr->left;
                    while(s->left!=NULL)
                    {
                        s=s->left;
                    }
                    s->left=temp;
                    if(parent->left==curr)
                    {
                        parent->left=curr->right;
                    }
                    else
                    {
                        parent->right=curr->right;
                    }
                 }
             }
                curr->left=NULL;
                curr->right=NULL;
                delete(curr);
}
                else
                {
                    cout<<"Keyword doesn't exist";
                }
}

void treenode::inorder_r()
{
	inorder_r(root);
}
void treenode::inorder_r(node *temp)
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->keyword<<":"<<temp->meaning<<"\n";
		inorder_r(temp->right);

	}
}


void treenode::search_nr()
{
	string key;
	int flag=0;
	node *temp;
	cout<<"Enter key to be searched: \n";
	cin>>key;
	temp=root;
	while(temp!=NULL)
	{
		if(key==temp->keyword)
		{
			cout<<"Element Found";
			flag=1;
			break;
		}
		else if(key<temp->keyword)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}

}

void treenode::search_r()
{
	int flag=0;
	string key;
	cout<<"Enter Key to be Searched\n";
	cin>>key;
	flag=search_r(root,key);
	if(flag==1)
	{
		cout<<"Element Found!\n";
	}
	else
	{
		cout<<"Element not found!\n";
	}
}

int treenode::search_r(node *temp,string key)
{
	int f1=0,f2=0;
	if(temp!=NULL)
	{
		if(key==temp->keyword)
		{
			return 1;
		}
		if(key<temp->keyword)
		{
			f1=search_r(temp->left,key);
		}
		if(key>temp->keyword)
		{
			f2=search_r(temp->right,key);
		}
	}
	if(f1==1 || f2==1)
		return 1;
	else
		return 0;
}



class queue
{
    int rear,front;
    node* data[30];
public:
     queue();
     int is_empty();
     void insert(node*);
     node* delete_q();
     friend class node;
};
queue:: queue()
{
    rear=-1;
    front=-1;
}
void queue:: insert (node* temp)
{
   rear++;
  data[rear]=temp;
}
node* queue:: delete_q ()
{
    front++;
    return(data[front]);
}
int queue::is_empty()
{
    if(rear==front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void treenode :: bfs()
{
    queue q;
    node* temp;
    if(root==NULL)
    {
        cout<<"BINARY SEARCH TREE IS EMPTY\n";
    }
    else
    {

      temp=root;
      q.insert(temp);
      while(!q.is_empty())
      {
    	  temp=q.delete_q();
          cout<<temp->keyword<<":"<<temp->meaning<<"\n";
          if(temp->left!=NULL)
          {
            q.insert(temp->left);

          }
          if(temp->right!=NULL)
          {
            q.insert(temp->right);

          }

        cout<<endl;

    }
}
}

void treenode:: mirror_nr()
{
  queue q;
  node* temp;
  node* temp1;
  temp=root;
  q.insert(temp);
  while(!q.is_empty())
  {
      temp=q.delete_q();
      temp1= temp->right;
      temp->right=temp->left;
      temp->left=temp1;
      if(temp->left!=NULL)
      {
          q.insert(temp->left);
      }
      if(temp->right!=NULL)
      {
          q.insert(temp->right);
      }
  }
}

class stack{
    int top;
    node *data[30];
public:
    stack(){
        top=-1;
    }
    void push(node *temp);
    node *pop();
    int empty();
    friend class treenode;
};
void stack::push(node *temp){
    top++;
    data[top]=temp;
}
node* stack::pop(){
    node* temp;
    temp=data[top];
    top--;
    return(temp);
}
int stack ::empty(){
    if(top==-1){
        return (1);
    }
    else{
        return (0);
    }
}

void treenode::copy_nr(treenode t1){
	stack s1,s2;
	node *temp1,*temp2;
	node *root1= new node;
	temp2=root1;
	temp1=t1.root;
	temp2->keyword=temp1->keyword;
	temp2->meaning=temp1->meaning;
	while(1){
		while(temp1!=NULL){
			if(temp1->left!=NULL){
				temp2->left=new node;
				temp2->left->keyword=temp1->left->keyword;
				temp2->left->meaning=temp1->left->meaning;
			}
			if(temp1->right!=NULL){
				temp2->right=new node;
				temp2->right->keyword=temp1->right->keyword;
			}
			s2.push(temp2);
			s1.push(temp1);
			temp1=temp1->left;
			temp2=temp2->left;
			}
		if (s1.empty()==-1)
			break;
		else{
			temp1=s1.pop();
			temp2=s2.pop();
			temp1=temp1->right;
			temp2=temp2->right;
		}
	}
}

void treenode :: erase(){
    stack s;
    node *temp;
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
            delete(temp);
        }
        while( s.top!=-1 && s.data[s.top]->right==temp ){
            temp=s.pop();
            delete(temp);
        }
        if(s.empty()==1){
                    break;
                }
            temp=s.data[s.top]->right;
    	}
	}
}

int main()
{
	treenode t;
	int ch,cc;
	do
	{
		cout<<"Enter your choice:\n";
		cout<<"1:Create\n2:Delete\n3:Inorder display\n4:Search_NR\n5:Search_R\n6:BFS\n7:Copy_NR\n8:Copy_R\n9:Mirror_NR\n10:Mirror_R\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			t.create_nr();
			break;
		case 2:
			t.delete1();
		cout<<"Deleted Sucessfully\n";
		break;
		case 3:
			cout<<"Inorder Display\n";
			t.inorder_r();
			break;
		case 4:
			cout<<"non recursive\n";
			t.search_nr();
			break;
		case 5:
			cout<<"Recursive\n";
			t.search_r();
			break;
		case 6:
			cout<<"BFS Display\n";
			t.bfs();
			break;
		case 7:
			cout<<"Copy NR\n";
			t.copy_nr();
			break;
		case 8:
			cout<<"Copy R\n";
			t.copy_r();
			break;
		case 9:
			cout<<"Mirror NR\n";
			t.mirror_nr();
			break;
		case 10:
			cout<<"Mirror R\n";
			t.mirror_r();
			break;
		case 11:
			cout<<"Erasing...\n";
			break;
		default:
			cout<<"Enter correct choice";
			break;

		}
		cout<<"Enter 1 to Cotinue\n";
		cin>>cc;


	}while(cc==1);


	return 0;
}

