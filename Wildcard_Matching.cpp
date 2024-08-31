#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool Memoization(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
    {
        return true;
    }

    if(i>0 && j==0)
    {
        return false;
    }

    if(i==0 && j>0)
    {
        for(int k=1; k<=j; k++)
        {
            if(p[k-1] != '*')
            {
                return false;
            }
            return true;
        }
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i-1] == p[j-1] || p[j-1] == '?')
    {
        return Memoization(s, p, i-1, j-1, dp);
    }
    else if(p[j-1] == '*')
    {
        return dp[i][j] = (Memoization(s, p, i-1, j, dp) || Memoization(s, p, i, j-1, dp));
    }
    else
    {
        return false;
    }
}

bool Tabulation(string s, string p)
{
    vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, 0));

    dp[0][0] = true;

    for(int j=1; j<=p.length(); j++)
    {
        bool flag = true;
        for(int k=1; k<=j; k++)
        {
            if(p[k-1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    } 

    for(int i=1; i<=s.length(); i++)
    {
        for(int j=1; j<=p.length(); j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[s.length()][p.length()];
}

bool Space_Opti(string s, string p)
{
    vector<int> prev(p.length()+1, 0);
    vector<int> curr(p.length()+1, 0);

    prev[0] = true;

    for(int j=1; j<=p.length(); j++)
    {
        bool flag = true;
        for(int k=1; k<=j; k++)
        {
            if(p[k-1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for(int i=1; i<=s.length(); i++)
    {
        for(int j=1; j<=p.length(); j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '?')
            {
                curr[j] = prev[j-1];
            }
            else if(p[j-1] == '*')
            {
                curr[j] = (prev[j] || curr[j-1]);
            }
            else
            {
                curr[j] = false;
            }
        }
    }

    return prev[p.length()];
}

bool matching(string s, string p)
{
    // vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
    // return Memoization(s, p, s.length(), p.length(), dp);

    // return Tabulation(s, p);

    return Space_Opti(s, p);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s, p;

    while (cin>>s>>p)
    {
        cout<<matching(s, p)<<endl;
    }

    return 0;    
}