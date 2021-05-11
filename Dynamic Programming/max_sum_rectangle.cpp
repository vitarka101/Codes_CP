#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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


int max_sum_adv(int **arr , int n , int m)
{
	int max_sum_rectangle = INT_MIN;

	for(int left=0;left<m;left++)
	{
		int *sum_rect = new int[n];
		for(int right=left;right<m;right++)
		{
			for(int i=0;i<n;i++)
			{
				sum_rect[i] = sum_rect[i] + arr[i][right];
				
			}

			int res = kadane(sum_rect,n);

	                if(max_sum_rectangle < res)
        	        {
                	        max_sum_rectangle = res;
               		}
		}
	}

	return max_sum_rectangle;
}


/* Mine */ 

/*
int max_sum_adv(int **arr , int n , int m)
{
	int *sum_rect = new int[n];

	int max_sum_rectangle = INT_MIN;

	for(int left=0;left<m;left++)
	{
		for(int right=left;right<m;right++)
		{
			for(int i=0;i<n;i++)
			{
				sum_rect[i] = 0;
				for(int j=left;j<=right;j++)
				{
					sum_rect[i] = sum_rect[i] + arr[i][j];
				}
			}

			int res = kadane(sum_rect,n);

	                if(max_sum_rectangle < res)
        	        {
                	        max_sum_rectangle = res;
               		}
		}
	}

	return max_sum_rectangle;
}

*/

ll max_sum_base(int **arr , int n ,int m)
{

	// make the size larger so that no out of bound conditions
	
	int **sum = new int*[n+1];

	for(int i=0;i<=n;i++)
        {
                sum[i] = new int[m+1];
        }

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum[i][j] = 0;
			for(int k=i;k<n;k++)
			{
				for(int l=j;l<m;l++)
					sum[i][j] += arr[k][l];
			}

			//cout<<sum[i][j]<<endl;
		}
	}


	int **max_sum = new int*[n];

        for(int i=0;i<n;i++)
        {
               max_sum[i] = new int[m];
        }


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			max_sum[i][j] = sum[i][j];
			for(int k=i;k<n;k++)
                        {
                                for(int l=j;l<m;l++)
				{
					int curr_sum = sum[i][j] - sum[i][l+1] - sum[k+1][j] + sum[k+1][l+1];
					if(curr_sum > max_sum[i][j])
						max_sum[i][j] = curr_sum;
				}
                        }

			//cout<<max_sum[i][j]<<" "<<i<<" "<<j<<endl;
                }
        }
	
	ll max_element = INT_MIN;
       
	for (int i = 0; i < n; i++)
       	{
       		 for (int j = 0; j < m; j++)
		 {
           		 if (max_sum[i][j] > max_element)
			 {
               			 max_element = max_sum[i][j];
           		 }
       		 }
   	 }
 
return max_element;

}


int main()
{
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];

		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<max_sum_adv(arr,n,m)<<endl;
	cout<<max_sum_base(arr,n,m)<<endl;
}

