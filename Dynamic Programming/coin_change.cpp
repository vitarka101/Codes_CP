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


int coin_changeDP(int n,int *d,int numD,int **arr)
{
        if(n<0)
                return 0;
        if(n==0)
                return 1;
        if(numD==0 || numD<0)
                return 0;
	if(arr[n][numD] > -1) // 0 is a possibility
		return arr[n][numD];

        int first = coin_changeDP(n-d[0],d,numD,arr);
        int second = coin_changeDP(n,d+1,numD-1,arr);

	int output = first + second;
	
	arr[n][numD] = output;

        return output;
}




int main()
{
	cout<<"Enter the change value : ";
	int n;
	cin>>n;
	
	cout<<"Enter the size of coin array : ";
	int numD;
	cin>>numD;

	int *arr= new int[numD]();

	cout<<"Enter the coin values : ";
	for(int i=0;i<numD;i++)
		cin>>arr[i];
	
	int **dp = new int*[n+1];
        for(int i=0;i<n+1;i++)
                dp[i] = new int[numD+1];

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<numD+1;j++)
			dp[i][j] = -1;
	}

        cout<<"No of ways for coin change using DP : "<<coin_changeDP(n,arr,numD,dp)<<endl;

	cout<<"No of ways for coin change : "<<coin_change(n,arr,numD)<<endl;
	
	return 0;
}

