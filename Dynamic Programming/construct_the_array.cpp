// https://www.hackerrank.com/challenges/construct-the-array/problem

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll count_array(int n , int k , int x_val)
{

/*	int *arr = new int[n+1];  // Array will be filled from 1 to n 

	arr[1] = 1;
	arr[2] = k-1;
	int count = 0;
	for(int i=3;i<=n+1;i++)
	{
		arr[i] = int( pow((k-1) , i-1 ));
	}

	int values = arr[n+1];
	int count1 = 0;
//	if(n%2 == 0) // the no of 1 is less 


	if(n%2==0)
	{
		int y = (int( pow((k-1),n-1)) + 1)/k;
       		int x = y-1;

		if( x_val == 1)
			return x;
		else
			return y;
	}
	else
	{
		int y = (int( pow((k-1),n-1)) + 1)/k;
                int x = y+1;

                if( x_val == 1)
                        return x;
                else
                        return y;
	}

*/


	ll oneCount = 1;  // First position always filled with 1
	ll nonOneCount = 0;

	// calculate no of ways to fill the ith position
	
	for(int i=1;i<n;i++)
	{
		// fill the position with 1 or non-1
		
		ll prevOneCount  = oneCount;
		oneCount = (nonOneCount * (k-1)) % MOD;
		nonOneCount = (prevOneCount +((k-2) * nonOneCount) % MOD) % MOD ;
	}

	if(x_val == 1)
	{
		return oneCount;
	}
	else
	{
		return nonOneCount;
	}

}	

int main()
{
	int n,k,x;
	cin>>n>>k>>x;

	cout<< count_array(n,k,x)<<endl;
	return 0;
}
