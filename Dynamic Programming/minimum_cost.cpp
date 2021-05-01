// IMP Question

#include<bits/stdc++.h>
using namespace std;

int min_cost(int **arr , int si , int sj , int ei , int ej)
{
	if( si== ei && sj==ej)
		return arr[ei][ej];

	if( si>ei || sj>ej )
		return INT_MAX;

	int option1 = min_cost(arr, si+1 , sj , ei , ej);
	int option2 = min_cost(arr, si+1 , sj+1 , ei , ej);
	int option3 = min_cost(arr, si , sj+1 , ei , ej);

	int min_val = min(option1 , min(option2 , option3));

	return arr[si][sj] + min_val;
}

int min_costDP(int **arr , int si , int sj , int ei , int ej,int **output)
{
        if( si== ei && sj==ej)
                return arr[ei][ej];

        if( si>ei || sj>ej )
                return INT_MAX;

	if(output[si][sj] > -1)
		return output[si][sj];

        int option1 = min_cost(arr, si+1 , sj , ei , ej);
        int option2 = min_cost(arr, si+1 , sj+1 , ei , ej);
        int option3 = min_cost(arr, si , sj+1 , ei , ej);

        int min_val = min(option1 , min(option2 , option3));

        int op = arr[si][sj] + min_val;

	output[si][sj] = op;

	return op;
}


int min_cost_iter(int **arr , int si , int sj , int ei , int ej)
{
	int m = ei + 1;
	int n = ej + 1;

	int **output = new int*[m];
        for(int i=0;i<m;i++)
        {
                output[i] = new int[n];
        }

	
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        output[i][j] = -1;
                }
        }

        output[m-1][n-1] = arr[m-1][n-1];
        int i = m-1;
        for(int j=n-2;j>=0;j--)
        {
                output[i][j] = arr[i][j] + output[i][j+1];
		//cout<<output[i][j]<<endl;
        }

        int j = n-1;
        for(int i=m-2;i>=0;i--)
        {
                output[i][j] = arr[i][j] + output[i+1][j];
		//cout<<output[i][j]<<endl;
        }

	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
			output[i][j] = arr[i][j] + min(output[i+1][j] , min(output[i+1][j+1] , output[i][j+1]));
	}

	int op = output[si][sj];

	delete [] output;

	return op;
}


int main()
{
	cout<<"Enter the size of array (m,n) : ";
	int m,n;
	cin>>m>>n;

	int **arr = new int*[m];
	int **output = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i] = new int[n];
		output[i] = new int[n];
	}

	cout<<"Enter the array : "<<endl;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			output[i][j] = -1;
		}
	}


	cout<<"Minimum cost using Iteration( O(n)) : "<<min_cost_iter(arr,0,0,m-1,n-1)<<endl;
	cout<<"Minimum cost using Recursion with DP ( O(3n)) : "<<min_costDP(arr,0,0,m-1,n-1,output)<<endl;
	cout<<"Minimum cost using Recursion( O(3^n)) : "<<min_cost(arr,0,0,m-1,n-1)<<endl;

	return 0;
}
