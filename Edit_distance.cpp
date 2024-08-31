#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(string &a,string &b, int i, int j, vector<vector<int>> &dp)
{
    if(i == a.length())
    {
        return b.length()-j;
    }

    if(j == b.length())
    {
        return a.length()-i;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(a[i] == b[j])
    {
        return Memoization(a, b, i+1, j+1, dp);
    }
    else
    {
        int insertAns = 1 + Memoization(a, b, i, j+1, dp);
        int deleteAns = 1 + Memoization(a, b, i+1, j, dp);
        int replaceAns = 1 + Memoization(a, b, i+1, j+1, dp);

        dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
    }

    return dp[i][j];
}

int Tabulation(string &a, string &b)
{
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int j=0; j<b.length(); j++)
    {
        dp[a.length()][j] = b.length()-j; 
    }

    for(int i=0; i<a.length(); i++)
    {
        dp[i][b.length()] = a.length()-i;
    }

    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = min(1+dp[i+1][j], min(1+dp[i][j+1], 1+dp[i+1][j+1]));
            }
        }
    }

    return dp[0][0];
}

int Space_Opti(string &a, string &b)
{
    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int j=0; j<b.length(); j++)
    {
        next[j] = b.length()-j;
    }

    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            curr[b.length()] = a.length()-i;

            if(a[i] == b[j])
            {
                curr[j] = next[j+1];
            }
            else
            {
                curr[j] = min(1+curr[j+1], min(1+next[j], 1+next[j+1]));
            }
        }
        next = curr;
    }

    return next[0];
}

int distance(string &a, string &b)
{
    // vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    // return Memoization(a, b, 0, 0, dp);

    // return Tabulation(a,b);

    if(a.length() == 0)
    {
        return b.length();
    }

    if(b.length() == 0)
    {
        return a.length();
    }
    return Space_Opti(a, b);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string a,b;
    // cin>>a>>b;
    while(cin>>a>>b)
    {
        cout<<distance(a, b)<<endl;
    }

    return 0;
}