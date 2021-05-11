#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr , int n)
{
	int max_sum = INT_MIN;
	int curr_sum = 0;

	for(int i=0;i<n;i++)
	{
		curr_sum = curr_sum + arr[i];

		if(max_sum < curr_sum)
		{
			max_sum = curr_sum;
		}

		if(curr_sum < 0)
		{
			curr_sum = 0;
		}
	}

	return max_sum;
}

int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;

	int *arr = new int[n];

	cout<<"Enter the array elements :"<<endl;

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<kadane(arr,n)<<endl;

	return 0;
}
