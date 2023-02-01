#include<iostream>
using namespace std;
void shellSort(int arr[],int n)
{
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i+=1)
		{
			int temp=arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
				arr[j]=arr[j-gap];
			arr[j]=temp;	
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the Elements of an Array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	shellSort(arr,n);
	cout<<"\nSorted Array: ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	return 0;
}

