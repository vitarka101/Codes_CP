#include<bits/stdc++.h>
using namespace std;

int num_code(int *arr , int n)
{
	// base case
	
	if( n == 0 || n == 1)
		return 1;

	int count  = num_code(arr , n-1);
	
	if(arr[n-2]*10 + arr[n-1] <= 26)
		count +=  num_code(arr , n-2 );

	return count;
}


int main()
{
	string s;
	cout<<"Enter a number to decode : ";
	cin>>s;

	int *arr = new int[s.size()];

	for(int i=0;i<s.size();i++)
	{
		arr[i] = s[i] - '0';
		//cout<<arr[i];
	}

	cout<< num_code(arr,s.size())<<endl;
	return 0;
}
