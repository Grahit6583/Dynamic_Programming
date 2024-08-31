#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if(i == a.length())
    {
        return 0;
    }

    if(j == b.length())
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(a[i] == b[j])
    {
        dp[i][j] = 1+Memoization(a,b, i+1, j+1, dp);
    }
    else
    {
        dp[i][j] = max(Memoization(a, b, i+1, j, dp), Memoization(a,b, i, j+1, dp));
    }

    return dp[i][j];
}

int Tabulation(string a, string b)
{
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = 1+ dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

int Space_Opti(string a, string b)
{
    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            if(a[i] == b[j])
            {
                curr[j] = 1+next[j+1];
            }
            else
            {
                curr[j] = max(next[j], next[j+1]);
            }
        }
        next = curr;
    }

    return next[0];
}

int longest_seq(string &a, string &b)
{
    // vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    // return Memoization(a,b, 0, 0, dp);

    // return Tabulation(a,b);

    return Space_Opti(a, b);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string a;
    cin>>a;
    
    string b;
    cin>>b;

    cout<<longest_seq(a,b)<<endl;
    return 0;
}