#include<bits/stdc++.h>
using namespace std;

int getStrength(int **grid,int n,int m,int si,int sj)
{
   	int cost1 = INT_MAX;
	int cost2 = INT_MAX;
    if(si == n-1 && sj == m-1)
    {
        return 1;
    }

    // Causes ERROR

    /*if(si == n-1 && sj == m-2)
    {
        if(grid[si][sj] <= 0)
        return 1 - grid[si][sj];
        else
            return 1;
    }
       
    if(si == n-2 && sj == m-1)
    {
        if(grid[si][sj] <= 0)
        return 1 - grid[si][sj];
        else
            return 1;
    }*/

    if(sj+1 < m)
    {
        cost1 = getStrength(grid,n,m,si,sj+1) - grid[si][sj+1];
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
        cost2 = getStrength(grid,n,m,si+1,sj) - grid[si+1][sj];
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

int getMinimumStrength(int** grid, int n, int m) {

    int ans = getStrength(grid,n,m,0,0);
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
