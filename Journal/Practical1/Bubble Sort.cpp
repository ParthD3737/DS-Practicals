#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the Elements of an Array: \n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bubbleSort(arr,n);
	cout<<"\nAfter Bubble Sorting Array: ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	return 0;
}

