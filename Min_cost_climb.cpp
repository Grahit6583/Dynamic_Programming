#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if(n == 0)
    {
        return cost[0];
    }

    if(n == 1)
    {
        return cost[1];
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = cost[n] + min(solve(cost,n-1, dp), solve(cost, n-2, dp));

    return dp[n];
}

int tabulation(vector<int> &cost, int n)
{
    vector<int> dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<n; i++)
    {
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int Space_Optimization(vector<int> &cost, int n)
{
    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i=2; i<n; i++) 
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int min_cost_climb_stairs(vector<int> &cost)
{
    int n = cost.size();
    //memoization
    // vector<int> dp(n+1, -1);
    // int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    // return ans;

    //tabulation
    // int ans  = tabulation(cost, n);
    // return ans;

    //space optimzation
    int ans = Space_Optimization(cost, n);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    vector<int> cost;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        cost.push_back(t);
    }

    for(int i=0; i<n; i++)
    {
        cout<<cost[i]<<"  ";
    }
    cout<<endl;
    cout<<min_cost_climb_stairs(cost);
    return 0;
}