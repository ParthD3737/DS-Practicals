#include<iostream>
using namespace std;
int p,arr[5],n,top=-1;
void push()
{
	top++;
	if(top<5)
	{
		cout<<"Enter the number : ";
		cin>>arr[top];
	}
	else
	{
		cout<<"Stack Overflow";
		top=4;
	}
}
void pop()
{
	if(top<0)
	{
		cout<<"Stack Underflow";
	}
	else
	{
		cout<<"Element poped from stack :"<<arr[top];
		top--;
	}
}
void peek()
{ 
	if(top==-1)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else{
		cout<<"Top element: "<<arr[top]<<endl;
	}
}
void display()
{
	if(top<0)
	{
		cout<<"Stack Underflow";
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			cout<<arr[i]<<"\t";
		}
	}
}
int main()
{
	
	while(1)
	{
		cout<<"\n\n1.) Push in stack.";
		cout<<"\n2.) Pop from stack.";
		cout<<"\n3.) Peek top from stack";
		cout<<"\n4.) Display the stack.";
		cout<<"\n5.) Exit.";
		cout<<"\n\nEnter your choice : ";
		cin>>p;
		switch(p)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: peek();
			break;
			case 4: display();
			break;
			case 5: exit(0);
			default: cout<<"Enter the valid choice";
		}
		
	}
	return 0;
}
