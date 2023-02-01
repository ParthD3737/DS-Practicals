#include <iostream>
using namespace std;

//Structure of the Node
struct Node
{
	int data;
	Node *link;
};

// top pointer to keep track of the top of the stack
Node *top = 0;

//Function to check if stack is empty or not
bool isempty()
{
 	if(top == NULL)
 		return true; 
 	else
 		return false;
}

//Function to insert an element in stack
void push (int value)
{
  	Node *temp = new Node();
  	temp->data = value;
  	temp->link = top;
  	top = temp;
  	
}

//Function to delete an element from the stack
void pop ( )
{
 	Node *temp = top;
 	if ( isempty() )
 		cout<<"Stack is Empty";
 	else
 	{
  		cout<<"Deleted node is: "<<top->data<<endl;
  		top = top -> link;
  		delete(temp);
 	}
}

// Function to show the element at the top of the stack
void showTop()
{
 	if ( isempty() )
  		cout<<"Stack is Empty";
 	else
		cout<<"Element at top is: "<< top->data<<endl;
}

// Function to Display the stack
void displayStack()
{
 	if ( isempty() )
  		cout<<"Stack is Empty\n";
 	else
 	{
 		cout<<"Stack Elements: ";
  		Node *temp=top;
  		while(temp!=0)
  		{   
   			cout<<temp->data<<" ";
   			temp=temp->link;
  		}	
  		cout<<"\n";
 	}
}

// Main function
int main()
{
	int choice,value;
 //Menu Driven Program using Switch
 	while(1)
 	{
		cout<<"\n1.Push \n2.Pop \n3.ShowTop \n4.DisplayStack \n5.Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
 		switch (choice)
 		{
 			case 1: cout<<"Enter Value: ";
         	cin>>value;
         	push(value);
         	break;
 			case 2: pop();
         	break;
 			case 3: showTop();
         	break;
 			case 4: displayStack();
         	break;
 			case 5: exit(0);
         	default:cout<<"Enter a valid choice";
 		}
 	}
	return 0;
}
