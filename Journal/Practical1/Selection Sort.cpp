#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		if(min!=i){
			int temp = arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
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
	selectionSort(arr,n);
	cout<<"\nAfter Selection Sorting Array: ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	return 0;
}

