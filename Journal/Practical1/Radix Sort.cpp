#include<iostream>
using namespace std;
int getMax(int arr[],int n)
{  
        int max= arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i]>max)
                max=arr[i];
        }
        return max;
}

void countSort(int arr[],int n,int pos)
{
        int count[10]={0};
        int b[n];
        for (int i=0;i<n;i++)
		{
            ++count[(arr[i]/pos)%10];
        }
        for (int i=1;i<10;i++)
		{
            count[i]=count[i]+count[i-1];
        }
        for (int i=n-1;i>=0;i--) 
		{
            b[count[((arr[i] / pos) % 10)] - 1] = arr[i];
            count[(arr[i] / pos) % 10]--;
        }
        for (int i=0;i<n;i++)
        {
        	 arr[i]=b[i];
		}
           
    }
void radixSort(int arr[],int n)
{
	int maxval = getMax(arr,n);
	for (int pos=1;maxval/pos>0;pos*=10)
	{
        countSort(arr,n,pos);
    }
}

int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements of an Array: \n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	radixSort(arr,n);
	cout<<"\nAfter Radix Sorting Array: ";
	{
		for (int j= 0; j < n; j++)
	    cout << arr[j] << " ";
	}
}

