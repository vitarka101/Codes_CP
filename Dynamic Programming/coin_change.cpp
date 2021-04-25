#include<bits/stdc++.h>
using namespace std;

int coin_change(int n,int *d,int numD)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(numD==0 || numD<0)
		return 0;

	int first = coin_change(n-d[0],d,numD); 
	int second = coin_change(n,d+1,numD-1);

	return first+second;
}

int main()
{
	cout<<"Enter the change value : ";
	int n;
	cin>>n;
	
	cout<<"Enter the size of coin array : ";
	int numD;
	cin>>numD;

	int *arr= new int[numD];

	cout<<"Enter the coin values : ";
	for(int i=0;i<numD;i++)
		cin>>arr[i];

	cout<<"No of ways for coin change : "<<coin_change(n,arr,numD)<<endl;

	return 0;
}

