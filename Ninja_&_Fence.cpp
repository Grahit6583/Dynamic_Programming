#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int add(int a, int b)
{
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b)
{
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

int Memoization(int n, int k, vector<int> &dp)
{
    if(n == 1)
    {
        return k;
    }

    if(n == 2)
    {
        return add(mul(k,k-1),k);
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = add(mul(Memoization(n-2,k,dp),k-1),mul(Memoization(n-1,k,dp),k-1));

    return dp[n];
}

int Tabulation(int n, int k)
{
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(mul(k,k-1),k);

    for(int i=3; i<=n; i++)
    {
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }

    return dp[n];
}

int Space_opti(int n, int k)
{
    int prev2 = k;
    int prev1 = add(mul(k,k-1),k);

    for(int i=3; i<=n; i++)
    {
        int ans = add(mul(prev2,k-1),mul(prev1,k-1));
        prev2  = prev1;
        prev1 = ans;
    }

    return prev1;
}

int Ninja(int n, int k)
{
    // vector<int> dp(n+1, -1);
    // return Memoization(n,k,dp);

    // return Tabulation(n,k);

    return Space_opti(n , k);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;

    int ans = Ninja(n,k);
    cout<<ans;

    return 0;
}