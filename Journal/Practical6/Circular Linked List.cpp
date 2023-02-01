#include<iostream>
using namespace std;

class node
{
	int data;
	node *pre,*next;
	public:
		void insert_start();
		void insert_middle();
		void insert_end();
		void delete_start();
		void delete_middle();
		void delete_end();
		void display();
}*start=NULL,*ptr=NULL,*temp=NULL,*t=NULL;
void node::insert_start()
{
	temp=new node;
	temp->next=NULL;
	temp->pre=NULL;
	cout<<"\nEnter the element : ";
	cin>>temp->data;
	if(start==NULL)
	{
		start=temp;
		start->next=start;
		start->pre=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		temp->pre=ptr;
		ptr->next=temp;
		temp->next=start;
		start->pre=temp;
		start=temp;
	}
}
void node::insert_middle()
{
	temp=NULL,t=NULL,ptr=NULL;
	int v;
	if(start!=NULL)
	{
		cout<<"Enter the element after which new element is to be inserted : ";
		cin>>v;
	}
	temp=new node;
	temp->next=NULL;
	temp->pre=NULL;
	cout<<"\nEnter the element : ";
	cin>>temp->data;
	if(start==NULL)
	{
		start=temp;
		start->next=start;
		start->pre=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start && ptr->data!=v)
		{
			ptr=ptr->next;
		}
		if(ptr->data==v)
		{
	
			ptr->next->pre=temp;
			temp->next=ptr->next;
			ptr->next=temp;
			temp->pre=ptr;
			
		}
		else
		{
			cout<<"Element not found";
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
		start->next=start;
		start->pre=start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		temp->pre=ptr;
		ptr->next=temp;
		temp->next=start;
		start->pre=temp;
	}
}
void node::delete_start()
{
	if(start==NULL)
	{
		cout<<"List is Empty";
	}
	else
	{
		if(start->next==start)
		{
			start=NULL;
		}
		else
		{
			ptr=start;
			start->pre->next=start->next;
			start=start->next;
			start->pre=ptr->pre;
		}
	}
}
void node::delete_middle()
{
	int val;
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		cout<<"\nEnter the element you want to delete : ";
		cin>>val;
		ptr=start;
		while(ptr->data!=val && ptr->next!=start)
		{
			ptr=ptr->next;
		}
		if(ptr->data!=val)
		{
			cout<<"\nNo such value found";
		}
		else
		{
			if(start->next==start)
			{
				start=NULL;
			}
			else
			{
				if(start->data==val)
				{
					start=start->next;	
				}
				ptr->next->pre=ptr->pre;
				ptr->pre->next=ptr->next;
			}
		}
		
	}
}
void node::delete_end()
{
	if(start==NULL)
	{
		cout<<"List is Empty";
	}
	else
	{
		if(start->next==start)
		{
			start=NULL;
		}
		else{
		
			ptr=start;
			while(ptr->next->next!=start)
			{
				ptr=ptr->next;
			}
			start->pre=ptr;
			ptr->next=start;
		}
	}
}
void node:: display()
{
	temp=NULL,t=NULL,ptr=NULL;
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		ptr=start;
//		if(ptr->pre!=start && ptr->next!=start)
//		{
//			while(ptr->pre!=start)
//			{
//				cout<<ptr->data<<"\t";
//				ptr=ptr->pre;
//			}
//			cout<<"\n\n";
//			ptr=start;
			while(ptr->next!=start)
			{
				cout<<ptr->data<<"\t";
				ptr=ptr->next;
			}
//		}
		cout<<ptr->data<<"\t";
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
			case 1:n.insert_start();
			break;
			case 2:n.insert_middle();
			break;
			case 3:n.insert_end();
			break;
			case 4:n.delete_start();
			break;
			case 5:n.delete_middle();
			break;
			case 6:n.delete_end();
			break;
			case 7:n.display();
			break;
			case 8:exit(0);
			default:cout<<"\nEnter between 1 to 8";
		}
	}
	return 0;
}
