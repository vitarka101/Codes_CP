#include<bits/stdc++.h>
using namespace std;

int staircase_rec(int n)
{
	if(n==0)
		return 1;
	if(n<0)
		return 0;

	return staircase_rec(n-1)+staircase_rec(n-2)+staircase_rec(n-3);

}


int staircase_recDP(int n,int *arr)
{
        if(n==0)
                return 1;
        if(n<0)
                return 0;

	if(arr[n] > 0)
		return arr[n];

	int output =  staircase_recDP(n-1,arr)+staircase_recDP(n-2,arr)+staircase_recDP(n-3,arr);

	arr[n] = output;

	return output;
}

int staircase_iter(int n)
{
	int *arr = new int[n+1];
	
	arr[0] = 1; // Ways to take 0 steps;
	arr[1] = 1;
	arr[2] = 2;

	for(int i=3;i<=n;i++)
	{
		arr[i] =arr[i-1] + arr[i-2] + arr[i-3]; // IMP
	}

	return arr[n];
}


int main()
{
	cout<<"Enter the Number of Steps : ";
	int n;
	cin>>n;
	

	cout<<"No of ways using Iteration O(n) :"<<staircase_iter(n)<<endl;

	int *arr = new int[n+1]();

	cout<<"No of ways using Recursion+DP O(2n) :"<<staircase_recDP(n,arr)<<endl;
	cout<<"No of ways using Recursion O(3^n) :"<<staircase_rec(n)<<endl;
	return 0;
}

