#include<iostream>
using namespace std;

class node
{
	int data;
	node *next,*pre;
	public:
		void insert_start();
		void insert_middle();
		void insert_end();
		void delete_start();
		void delete_middle();
		void delete_end();
		void display();
}*start=NULL,*ptr=NULL,*temp=NULL;
void node::insert_start()
{
	temp=new node;
	temp->next=NULL;
	temp->pre=NULL;
	cout<<"\nEnter the element : ";
	cin>>temp->data;
	if(start==NULL)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		start->pre=temp;
		temp->next=start;
		start=temp;
	}
}
void node::insert_middle()
{
	int pos;
	if(start!=NULL)
	{
		cout<<"\nEnter the number after which the element is to insert : ";
		cin>>pos;
	}
	temp=new node;
	temp->next=NULL;
	temp->pre=NULL;
	cout<<"\nEnter the element : ";
	cin>>temp->data;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr!=NULL && ptr->data!=pos)
		{
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			cout<<"\nNo element found";
		}
		else
		{
			if(ptr->next==NULL)
			{
				ptr->next=temp;
				temp->pre=ptr;	
			}
			else
			{
				temp->next=ptr->next;
				ptr->next->pre=temp;
				ptr->next=temp;
				temp->pre=ptr;
			}
		}
	}
}
void node::insert_end()
{
	temp=new node;
	temp->next=NULL;
	temp->pre=NULL;
	cout<<"\nEnter the element : ";
	cin>>temp->data;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->pre=ptr;
	}
}
void node::delete_start()
{
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		start=start->next;
		start->pre=NULL;
	}
}
void node::delete_middle()
{
	int val;
	cout<<"\nEnter the element you want to delete : ";
	cin>>val;
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		temp=start,ptr=NULL;
		while(temp!=NULL && temp->data!=val)
		{
			ptr=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			cout<<"\nNo such value found";
		}
		else
		{
			if(start->data==val)
			{
				start=start->next;
				start->pre=NULL;	
			}
			else
			{
				ptr->next=temp->next;
				temp->next->pre=ptr;
			}
		}
	}
}
void node::delete_end()
{
	if(start==NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		temp=start,ptr=NULL;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		if(temp==start)
		{
			start=NULL;
		}
		else
		{
			ptr->next=NULL;
		}
	}
}
void node::display()
{
	int l;
	if(start==NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		temp=start;
		cout<<"Enter for next or pre (1/0)";
		cin>>l;
		if(l==1)
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->pre;
			}
		}
	}
}
int main()
{
	node n;
	int p;
	while(1)
	{
		cout<<"\n\n 1 TO INSERT ELEMENTS FROM START";
		cout<<"\t\t 2 TO INSERT ELEMENTS FROM MIDDLE";
		cout<<"\t\t 3 TO INSERT ELEMENTS FROM END";
		cout<<"\n 4 TO DELETE ELEMENTS FROM START";
		cout<<"\t\t 5 TO DELETE ELEMENTS FROM MIDDLE";
		cout<<"\t\t 6 TO DELETE ELEMENTS FROM END";
		cout<<"\n 7 TO DISPLAY LINKED LIST";
		cout<<"\t\t\t 8 TO EXIT";
		cout<<"\n\nEnter your choice : ";
		cin>>p;
		switch(p)
		{
			case 1:
			{
				n.insert_start();
				break;
			}
			case 2:
			{
				n.insert_middle();
				break;
			}
			case 3:
			{
				n.insert_end();
				break;
			}
			case 4:
			{
				n.delete_start();
				break;
			}
			case 5:
			{
				n.delete_middle();
				break;
			}
			case 6:
			{
				n.delete_end();
				break;
			}
			case 7:
			{
				n.display();
				break;
			}
			case 8:
			{
				exit(0);	
			}
			default:
			{
				cout<<"\nPress the number betwwen 1 to 8";
			}
		}
	}
	return 0;
}
