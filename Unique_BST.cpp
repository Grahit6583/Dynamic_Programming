#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int n, vector<int> &dp)
{
    if(n<=1)
    {
        return 1;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += Memoization(i-1, dp)*Memoization(n-i, dp);
    }

    return dp[n] = ans;
}

int Tabulation(int n)
{
    vector<int> dp(n+1, 0);
    dp[0]=dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i] += dp[j-1]*dp[i-j];
        }
    }

    return dp[n];
}

int unique_bst(int n)
{
    // vector<int> dp(n+1, -1);
    // return Memoization(n,dp);

    return Tabulation(n);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    cout<<unique_bst(n);
    return 0;
}