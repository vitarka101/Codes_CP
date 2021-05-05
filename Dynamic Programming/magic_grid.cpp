// Test case 4 wrong for recursive and recursive DP

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
    
int getMinimumStrength_iter(int** grid, int n, int m) {
	// Write your code here
    
    int **arr = new int*[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[m];
    }
    
    arr[n-1][m-1] = 1;
    arr[n-1][m-2] = 1;
    arr[n-2][m-1] = 1;
    
    for(int j=m-3;j>=0;j--)
    {
        arr[n-1][j] = arr[n-1][j+1] - grid[n-1][j+1];
        if(arr[n-1][j] <= 0)
            arr[n-1][j] = 1;
    }
    
    for(int i=n-3;i>=0;i--)
    {
        arr[i][m-1] = arr[i+1][m-1] - grid[i+1][m-1];
        if(arr[i][m-1] <= 0)
            arr[i][m-1] = 1;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int right = arr[i][j+1] - grid[i][j+1];
            if(right<=0)
                right=1;
            
            int bottom = arr[i+1][j] - grid[i+1][j];
            if(bottom<=0)
                bottom=1;
            
            arr[i][j] = min(right,bottom);
        }
    }
    
    return arr[0][0];
}


int getMinimumStrength_DP(int **grid,int n,int m,int si,int sj,int **health)
{
   	int cost1 = INT_MAX;
	int cost2 = INT_MAX;
    
    if(si == n-1 && sj == m-1)
    {
        return 1;
    }
    
    if(health[si][sj] > 0)
        return health[si][sj];

    if(sj+1 < m)
    {
        cost1 = getMinimumStrength_DP(grid,n,m,si,sj+1,health) - grid[si][sj];
        if(cost1 <= 0)
        {
            cost1 = 1;
        }
    }
     
    if(si+1 < n)
    {
        cost2 = getMinimumStrength_DP(grid,n,m,si+1,sj,health) - grid[si][sj];
        if(cost2 <= 0)
        {
            cost2 = 1;
        }
    }
     

    health[si][sj] =  min(cost1,cost2);
    
    return health[si][sj];


}


int getMinimumStrength(int **grid,int n,int m,int si,int sj)
{
   	int cost1 = INT_MAX;
	int cost2 = INT_MAX;
    if(si == n-1 && sj == m-1)
    {
        return 1;
    }

 
    if(sj+1 < m)
    {
        cost1 = getMinimumStrength(grid,n,m,si,sj+1) - grid[si][sj+1];
        if(cost1 == 0)
        {
            cost1 = 1;
        }
        if(cost1 < 0)
        {
            cost1 = -1*cost1;
        }
    }
     
    if(si+1 < n)
    {
        cost2 = getMinimumStrength(grid,n,m,si+1,sj) - grid[si+1][sj];
        if(cost2 == 0)
        {
            cost2 = 1;
        }
        if(cost2 < 0)
        {
            cost2 = -1*cost2;
        }
    }
     

    return min(cost1,cost2);


}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

	int **health = new int*[n];
	for(int i=0;i<n;i++)
	{
		health[i] = new int[m];
	}


	cout<<"Iteartive Solution -----> "<<getMinimumStrength_iter(grid,n,m)<<endl;
	cout<<"Recursive Solution with DP -------> "<<getMinimumStrength_DP(grid,n,m,0,0,health)<<endl;
	// Using basic recursion
        cout <<"Bsic Recursive Solution ------> "<< getMinimumStrength(grid, n, m,0,0) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}
