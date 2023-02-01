#include<iostream> 
using namespace std; 
class tree 
{ 
public: 
	tree *l, *r; 
	int data;
}*root=NULL, *p = NULL,*temp=NULL; 
 
void create() 
{ 
	int value,n,c=1;
	while(c) 
	{ 
		if(root==NULL) 
		{ 
			root= new tree; 
			cout<<"Enter the value of root node\n"; 
			cin>>root->data; 
			root->r=NULL; 
			root->l=NULL; 
		} 
		else 
		{ 
			p=root; 
			cout<<"\nEnter value of new node : "; 
			cin>>value; 
			while(true) 
			{ 
				if(value < p->data) 
				{ 
					if(p->l ==NULL) 
					{ 
						p->l= new tree; 
						p = p->l; 
						p->data = value; 
						p->l = NULL; 
						p->r = NULL; 
						cout<<"\nValue entered in left\n"; 
						break; 
					} 
					else if(p->l !=NULL) 
					{ 
						p=p->l; 
					} 
				} 
				else if (value > p->data) 
				{ 
					if(p->r==NULL) 
					{ 
						p->r= new tree; 
						p = p->r; 
						p->data = value; 
						p->l =  NULL; 
						p->r= NULL; 
						cout<<"\nValue entered in right side\n"; 
						break; 
					} 
					else if(p->r!=NULL) 
					{ 
						p=p->r;  
					} 
				}
			} 
		}
		cout<<"Do you to continue entering new nodes(1/0) : ";
		cin>>n;
		if(n==0)
		{
			c=0;
		}
	}  
}
tree* FindMin(tree *p)
{
	if(p==NULL)
		return NULL;
	
	if(p->l)
		return (FindMin(p->l));
	else
		return p;
}
tree *delnode(tree *p,int data)
{
	tree *temp;
	if(p==NULL)
		cout<<"element not found";
	else if(data<p->data)
		p->l=delnode(p->l,data);
	else if(data>p->data)
		p->r=delnode(p->r,data);
		
	else
	{
		if(p->r && p->l)
		{
			temp = FindMin(p->r);
			p->data=temp->data;
			p->r=delnode(p->r,temp->data);
		}
		else
		{
			temp = p;
			if(p->l==NULL)
				p=p->r;
			else if(p->r==NULL)
				p=p->l;
		}
	}
	return p;
}
void in(tree *p) 
{ 
    if(p!=NULL) 
    { 
    	in(p->l); 
        cout<<"\n\t\t"<<p->data; 
        in(p->r);
    } 
} 
void pre(tree *p) 
{ 
    if(p!=NULL) 
    { 
        cout<<"\n\t\t"<<p->data;
        pre(p->l);  
        pre(p->r); 
    } 
} 
void post(tree *p) 
{ 
    if(p!=NULL) 
    { 
        post(p->l); 
        post(p->r); 
        cout<<"\n\t\t"<<p->data;
    }
}	 
int inordermin(tree *p) 
{ 
	int min; 
	while(p->l!=NULL) 
	{ 
		p=p->l; 
	} 
	return(p->data); 		 
}  
int inordermax(tree *p) 
{ 
	int max; 
	while(p->r!=NULL) 
	{ 
		p=p->r; 
	} 
	return(p->data); 
}
int tree_height(tree* p)
{
    if (p == NULL)
        return 0;
    else {
        int lh = tree_height(p->l);
        int rh = tree_height(p->r);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}
void display()
{
	int x,y;
	cout<<"Height of Tree : "<<tree_height(root);
	cout<<"\n Inorder : ";
    in(root);
    cout<<"\n preorder : ";
    pre(root); 
    cout<<"\n postorder : ";
    post(root);
	x=inordermin(root); 
	y=inordermax(root);
	cout<<"\n\nMin value of tree:"<<x<<endl; 
	cout<<"Max value of tree:"<<y<<endl; 
}
int main() 
{ 
	int ch,value;
	while(1)
	{
		cout<<"\n\n1.) To Insert a Node";
		cout<<"\n2.) To Delete a Node";
		cout<<"\n3.) To Show all data about the tree";
		cout<<"\n4.) To Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: create();
			break;
			case 2:
			{
				cout<<"\nEnter value of node to be deleted : "; 
				cin>>value;
				delnode(root,value);
				break;
			}
			case 3: display();
			break;
			case 4:exit(0);
			default:cout<<"Enter the Right Choice!";
		}
	}
	return(0); 
}

