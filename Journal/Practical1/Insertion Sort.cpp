#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int sorted=arr[i];
		int j=i;
		while(j>0 && arr[j-1]>sorted)
		{
			arr[j]=arr[j-1];
			j=j-1;
		}
		arr[j]=sorted;
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
	insertionSort(arr,n);
	cout<<"\nAfter Insertion Sorting Array: ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	return 0;
}

