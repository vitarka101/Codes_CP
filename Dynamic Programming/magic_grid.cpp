// Test case 4 wrong

#include<bits/stdc++.h>
using namespace std;

int getStrength(int **grid,int n,int m,int si,int sj,int **health)
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
        cost1 = getStrength(grid,n,m,si,sj+1,health) - grid[si][sj];
        if(cost1 <= 0)
        {
            cost1 = 1;
        }
    }
     
    if(si+1 < n)
    {
        cost2 = getStrength(grid,n,m,si+1,sj,health) - grid[si][sj];
        if(cost2 <= 0)
        {
            cost2 = 1;
        }
    }
     

    health[si][sj] =  min(cost1,cost2);
    
    return health[si][sj];


}

int getMinimumStrength(int** grid, int n, int m) {
	// Write your code here
    if(n==0 || m==0)
        return 1;
    if(n==1 && m==1)
    {
        if(grid[0][0]>0)
            return 1;
        else
            return 1-grid[0][0];
    }
    
    int **health = new int *[n];

        for (int i = 0; i < n; ++i) {
            health[i] = new int[m];
        }

    int ans = getStrength(grid,n,m,0,0,health);
    return ans;
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

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}
