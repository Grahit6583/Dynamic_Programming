#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Memoization(int index, int Op, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
    {
        return 0;
    }

    if (Op == 2 * k)
    {
        return 0;
    }

    if (dp[index][Op] != -1)
    {
        return dp[index][Op];
    }

    int profit = 0;
    if (Op % 2 == 0)
    {
        int buy = -prices[index] + Memoization(index + 1, Op + 1, k, prices, dp);
        int skip = 0 + Memoization(index + 1, Op, k, prices, dp);
        profit = max(buy, skip);
    }
    else
    {
        int sell = prices[index] + Memoization(index + 1, Op + 1, k, prices, dp);
        int skip = 0 + Memoization(index + 1, Op, k, prices, dp);
        profit = max(sell, skip);
    }

    return dp[index][Op] = profit;
}

int Tabualtion(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int Op = 0; Op < 2 * k; Op++)
        {
            if (Op % 2 == 0)
            {
                dp[index][Op] = max((-prices[index] + dp[index + 1][Op + 1]), (0 + dp[index + 1][Op]));
            }
            else
            {
                dp[index][Op] = max((prices[index] + dp[index + 1][Op + 1]), (0 + dp[index + 1][Op]));
            }
        }
    }

    return dp[0][0];
}

int Space_Opti(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int Op = 0; Op < 2 * k; Op++)
        {
            int profit = 0;
            if (Op % 2 == 0)
            {
                profit = max((-prices[index] + next[Op + 1]), (0 + next[Op]));
            }
            else
            {
                profit = max((prices[index] + next[Op + 1]), (0 + next[Op]));
            }

            curr[Op] = profit;
        }
        next = curr;
    }

    return next[0];
}

int Stock(int k, vector<int> &prices)
{
    // int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2*k, -1));
    // return Memoization(0, 0, k, prices, dp);

    return Tabualtion(k, prices);

    // return Space_Opti(k ,prices);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> prices;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        prices.push_back(t);
    }

    cout << Stock(k, prices) << endl;
    return 0;
}