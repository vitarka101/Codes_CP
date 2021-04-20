#include<bits/stdc++.h>
using namespace std;

int fib_recursion(int n)
{
	if( n == 0 || n == 1 )
		return 1;
	
	return ( fib_recursion(n-1) + fib_recursion(n-2) );
}

int fib_recursionDP(int n,int *arr)
{
	if( n == 0 || n == 1 )
		return 1;

	if(arr[n]>0)
		return arr[n];

	int output = fib_recursionDP(n-1,arr) + fib_recursionDP(n-2,arr);
	arr[n] = output;

	return output;
}

int fib_iter(int n)
{
	int *arr = new int[n+1];

	arr[0] = 1;
	arr[1] = 1;

	for(int i=2 ; i<=n ; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	int output = arr[n];

	delete [] arr;

	return output;
}

int main()
{
	int n;
	cout<<"Enter the number for fibonacci series : ";
	cin>>n;
	
	cout<<"Fibonacci using recursion "<<endl;
	cout<<fib_recursion(n)<<endl;

	cout<<"Fibonacci using recursion but with optimized Dymanic programming "<<endl;
	int *arr = new int[n+1];  // 0 to n values to be filled
	cout<<fib_recursionDP(n,arr)<<endl;

	cout<<"Fibonacci Iterative  best solution "<<endl;
	cout<<fib_iter(n)<<endl;

	return 0;
}
