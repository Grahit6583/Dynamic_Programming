#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int start, int end, vector<vector<int>> &dp)
{
    if(start >= end)
    {
        return 0;
    }

    if(dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for(int i=start; i<=end; i++)
    {
        ans = min(ans, i + max(Memoization(start, i-1, dp), Memoization(i+1, end, dp)));
    }

    return dp[start][end] = ans;
}

int Tabualtion(int n)
{
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int start=n; start>=1; start--)
    {
        for(int end=start; end<=n; end++)
        {
            if(end == start)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for(int i=start; i<=end; i++)
                {
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }

                dp[start][end] = ans;
            }
        }
    }

    return dp[1][n]; 
}

int Guess(int n)
{
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return Memoization(1,n,dp);

    return Tabualtion(n);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; 
    cin>>n;

    cout<<Guess(n)<<endl;
    return 0;
}