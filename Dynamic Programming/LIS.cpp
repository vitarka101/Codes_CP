// Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

int LIS(int *arr,int n)
{
	int *output = new int[n]();
	
	output[0] = 1;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i] > arr[j])
			{
				if(output[i] < output[j] + 1)
					output[i] = output[j] + 1;
			}
		}
	}

	int op =  *max_element(output,output+n);

	delete [] output;

	return op;
}
int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	
	cout<<"Enter " <<n<<" digits : ";

	int *arr = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}


	cout<<LIS(arr,n)<<endl;
	
	delete [] arr;
	return 0;
}
