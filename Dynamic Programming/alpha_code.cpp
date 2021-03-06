#include<bits/stdc++.h>
using namespace std;

int num_code(int *arr , int n)
{
	// base case
	
	if( n == 0 || n == 1)
		return 1;

	int count  = num_code(arr , n-1);
	
	if( arr[n-2]*10 + arr[n-1] <= 26 )
		count +=  num_code(arr , n-2 );

	return count;
}

int num_code_DP(int *arr , int n ,int *output)
{
        // base case
	// Here n is the remaining number from the start (since we are decreasing the size of array from the end) of the array whose num_code is to be calculated 

        if( n == 0 || n == 1)
                return 1;

	if( output[n] > 0)
		return output[n];

        int count  = num_code_DP(arr , n-1, output);

        if(arr[n-2]*10 + arr[n-1] <= 26)
                count +=  num_code_DP(arr , n-2, output);

	output[n] = count;
        return count;
}

// Best Solution

int num_code_iter(int *arr,int n)
{
        int *output = new int[n+1]();
	
	// 0 , 1,2,3.... are all lengths
        output[0] = 1;
        output[1] = 1;

        for(int i=2;i<=n;i++)
        {
                output[i] = output[i-1];
               // since we are decreasing the size from the end
               if( arr[i-2]*10 + arr[i-1] <= 26)
                output[i] += output[i-2];
        }

        int op = output[n];

        delete [] output;

        return op;
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
	
	int *output = new int[s.size()+1];  // size 0 to n
	cout<< num_code_DP(arr,s.size(),output)<<endl;

	cout<<num_code_iter(arr,s.size())<<endl;
	return 0;
}
