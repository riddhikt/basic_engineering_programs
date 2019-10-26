
#include<iostream>
using namespace std;
class tbtnode
{
    char data;
    int rbit;
    int lbit;
    tbtnode *right;
    tbtnode *left;
    friend class tbt;
public:
    tbtnode();
};

tbtnode::tbtnode()
{
    lbit=1;
    rbit=1;


}

class tbt
{
    tbtnode *head;
public:
    void create();
    void inorder();
    tbtnode *inordersucc(tbtnode *temp);
    void preorder();
    tbt();
};

tbt::tbt()
{
    head = new tbtnode;
    head -> rbit=0;
    head -> left =head;
    head -> right =head;
}

void tbt::create ()
{
    int flag,ch;
    tbtnode *root,*temp,*curr;
    root = new tbtnode;
    cout<<"\n Enter root node: ";
    cin>>root->data;
    head -> lbit=0;
    root -> left = head;
    root -> right = head;
    head ->left=root;
    do
    {
        flag =0;
        temp=root;
        curr=new tbtnode;
        cout<<"\nEnter data: ";
        cin>>curr->data;
        while(flag==0)
        {
            cout<<"Do you want to add to the left of"<<temp->data<<"?(y=1/n=0)\n";
            cin>>ch;
            if (ch==1)
            {
                if(temp->lbit==1)
                {
                    curr->right=temp;
                    curr->left=temp->left;
                    temp->left=curr;
                    temp->lbit=0;
                    flag=1;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if (temp->rbit==1)
                {
                    curr->right=temp;
                    curr->right=temp->right;
                    temp->right=curr;
                    temp->rbit=0;
                    flag=1;
                }
                else
                    temp=temp->right;
            }
        }
        cout<<"Do you want to continue?(y=1/n=0): ";
        cin>>ch;
    }while(ch==1);

}

void tbt::inorder()
{
    tbtnode *temp;
    temp=head;
    while(1)
    {
        temp=inordersucc(temp);
        if(temp==head)
            break;
        cout<<"\n"<<temp->data;
    }
}
tbtnode *tbt::inordersucc(tbtnode *temp)
{
    tbtnode *x;
    x=temp->right;
    if(temp->rbit==0)
    {
        while(x->lbit==0)
            x=x->left;
    }return x;
}

 void tbt::preorder()
{
    tbtnode *temp;
    temp=head->left;
    while(temp!=head)
    {
    	cout<<temp->data<<"\n";
        while(temp->lbit!=1)
        {
        	temp=temp->left;
        	cout<<"\n"<<temp->data;
        }
        while(temp->rbit==1)
        {
        	temp=temp->right;

        }
        temp=temp->right;
    }


}

int main()
{
    tbt t1;
    int choice,c;
    do{
            cout<<"\nMenu:\n1.Create\n2.Inorder\n3.preorder";
            cout<<"\nEnter your choice: ";
            cin>>choice;
            switch (choice)
            {
            case 1: t1.create();
                    break;
            case 2: t1.inorder();
                    break;
            case 3:
            	t1.preorder();
            	break;
            default: cout<<"Wrong Choice.";
            }
            cout<<"Enter 1 to continue\n";
            cin>>c;
          }while(c==1);
          return 0;
}
