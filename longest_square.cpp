#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp )
{
    if(i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int right = Memoization(mat, i, j+1, maxi, dp);
    int diagonal = Memoization(mat, i+1, j+1, maxi, dp);
    int down = Memoization(mat, i+1, j, maxi, dp);

    if(mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int Tabulation(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

    for(int i = row-1; i>=0; i--)
    {
        for(int j = col-1; j>=0; j--)
        {
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[0][0];
}

int space_opti(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<int> curr(col+1, 0);
    vector<int> next(col+1, 0);

    for(int i = row-1; i>=0; i--)
    {
        for(int j=col-1; j>=0; j--)
        {
            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];

            if(mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}    

int longest_square(vector<vector<int>> mat, int n, int m)
{
    int maxi = 0;
    // vector<vector<int>> dp(n, vector<int>(m ,-1));
    // Memoization(mat,0,0,maxi,dp);
    // return maxi;

    // Tabulation(mat,maxi);
    // return maxi;

    space_opti(mat, maxi);
    return maxi;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        mat.push_back(temp);
    }

    cout<<longest_square(mat,n,m)<<endl;
    return 0;
}