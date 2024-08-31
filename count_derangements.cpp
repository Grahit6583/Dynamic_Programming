#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int Memoization(int n , vector<long long int> &dp)
{
    if(n == 1)
    {
        return 0;
    }

    if(n == 2)
    {
        return 1;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (((n-1)%MOD)*((Memoization(n-1,dp)%MOD)+(Memoization(n-2,dp)%MOD))%MOD);

    return dp[n];
}

long long int Tabulation(int n)
{
    vector<long long int>dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++)
    {
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first+second)%MOD;
        long long int ans = ((i-1)*sum)%MOD;

        dp[i] = ans;
    }

    return dp[n];
}

long long int Space_opti(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for(int i=3; i<=n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second)%MOD;
        long long int ans = ((i-1)*sum)%MOD;

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int CountDerangements(int n)
{
    // vector<long long int> dp(n+1,-1);
    // return Memoization(n,dp);

    // return Tabulation(n);

    return Space_opti(n);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    cout<<CountDerangements(n);

    return 0;
}