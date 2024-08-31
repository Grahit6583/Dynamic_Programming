#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if(index == prices.size())
    {
        return 0;
    }

    if(dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    int profit=0;

    if(buy)
    {
        profit = max((-prices[index] + Memoization(index+1, 0, prices, dp)),(0 + Memoization(index+1, 1, prices, dp)));
    }
    else
    {
        profit = max((prices[index] + Memoization(index+1, 1, prices, dp)),(0 + Memoization(index+1, 0, prices, dp)));
    }

    return dp[index][buy] = profit;
}

int Tabualtion(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
            }
            else
            {
                profit = max((prices[i] + dp[i+1][1]), (0 + dp[i+1][0]));
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

int Space_Opti(vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int i=n-1; i>=0; i--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max((-prices[i] + next[0]),(0 + next[1]));
            }
            else
            {
                profit = max((prices[i] + next[1]),(0 + next[0]));
            }

            curr[buy] = profit;
        }

        next = curr;
    }

    return next[1];
}

int Stock(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return Memoization(0, 1, prices, dp);

    // return Tabualtion(prices);

    // return Space_Opti(prices);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n; 

    vector<int> prices;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        prices.push_back(t);
    }

    cout<<Stock(prices)<<endl;
    return 0;
}