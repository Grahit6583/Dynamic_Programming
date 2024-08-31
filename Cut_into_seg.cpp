#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int n, int x, int y, int z, vector<int> &dp)
{
    if(n == 0)
    {
        return 0;
    }

    if(n < 0)
    {
        return INT_MIN;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int a = Memoization(n-x, x,y,z, dp)+1;
    int b = Memoization(n-y, x,y,z, dp)+1;
    int c = Memoization(n-z, x,y,z, dp)+1;

    dp[n] = max(a,max(b,c));

    return dp[n];
}

int Tabulation(int n, int x, int y, int z)
{
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        if(i-x >= 0 )
        {
            dp[i] = max(dp[i], dp[i-x]+1);
        }

        if(i-y >= 0)
        {
            dp[i] = max(dp[i], dp[i-y]+1);
        }

        if(i-z >= 0)
        {
            dp[i] = max(dp[i], dp[i-z]+1);
        }
    }

    if(dp[n] < 0)
    {
        return 0;
    }
    else
    {
        return dp[n];
    }
}

int Segments(int n, int x, int y, int z)
{
    // vector<int> dp(n+1, -1);
    // int ans = Memoization(n,x,y,z,dp);
    // if(ans < 0)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return ans;
    // }

    return Tabulation(n,x,y,z);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x,y,z;
    cin>>n>>x>>y>>z;

    cout<<Segments(n,x,y,z);

    return 0;
}