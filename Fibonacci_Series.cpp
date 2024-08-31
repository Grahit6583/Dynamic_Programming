#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//memoization
int fib(int n, vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n-1, dp)+fib(n-2, dp);

    return dp[n];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    // vector<int>dp(n+1 , -1);

    // cout<<fib(n,dp)<<endl;

    //--------------Tabulation
    // vector<int> dp(n+1, -1);
    // dp[1] = 1;
    // dp[0] = 0;

    // if(n == 0)

    // for(int i=2; i<=n; i++)
    // {
    //     dp[i] = dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;

    //---------------Space Optimization
    int prev1 = 1;
    int prev2 = 0;

    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=2; i<=n; i++)
    {
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1<<endl;

    return 0;
}