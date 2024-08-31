#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if(index == prices.size())
    {
        return 0;
    }

    if(limit == 0)
    {
        return 0;
    }

    if(dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }
    int profit = 0;

    if(buy)
    {
        int Dobuy = -prices[index] + Memoization(index+1, 0, limit, prices, dp);
        int Skip = 0 + Memoization(index+1, 1, limit, prices, dp);
        profit = max(Dobuy, Skip);
    }
    else
    {
        int Sell = prices[index] + Memoization(index+1, 1, limit-1, prices, dp);
        int Skip = 0 + Memoization(index+1, 0, limit, prices, dp);
        profit = max(Sell, Skip);
    }

    return dp[index][buy][limit] = profit;
}

int Tabulation(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int index = n-1; index>=0; index--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            for(int limit=1; limit<=2; limit++)
            {
                int profit = 0;

                if(buy)
                {
                    profit = max((-prices[index] + dp[index+1][0][limit]),(0 + dp[index+1][1][limit]));
                }
                else
                {
                    profit = max((prices[index] + dp[index+1][1][limit-1]),(0 + dp[index+1][0][limit]));
                }

                dp[index][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int Space_Opti(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for(int index=n-1; index>=0; index--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            for(int limit=1; limit<=2; limit++)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max((-prices[index] + next[0][limit]),(0 + next[1][limit]));
                }
                else
                {
                    profit = max((prices[index] + next[1][limit-1]),(0 + next[0][limit]));
                }

                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }

    return next[1][2];
}

int Stock(vector<int> &prices)
{
    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return Memoization(0, 1, 2, prices, dp);

    // return Tabulation(prices);

    Space_Opti(prices);
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