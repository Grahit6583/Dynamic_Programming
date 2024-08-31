#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int n, vector<int> days, vector<int> cost, vector<int> &dp, int index)
{
    if(index >= n)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    int option1 = cost[0] + Memoization(n, days, cost, dp, index+1);

    int i;
    for(i=index; i<n && days[i] < days[index] + 7; i++);

    int option2 = cost[1] + Memoization(n,days,cost,dp, i);

    for(i=index; i<n && days[i] < days[index] + 30; i++);

    int option3 = cost[2] + Memoization(n, days, cost, dp, i);

    dp[index] = min(option1, min(option2, option3));

    return dp[index];
}

int Tabulation(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k = n-1; k>=0; k--)
    {
        int option1 = cost[0] + dp[k+1];

        int i;
        for(i=k; i<n && days[i] < days[k]+7; i++);
        int option2 = cost[1] + dp[i];

        for(i=k; i<n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int Space_opti(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int day : days)
    {
        while(!month.empty() && month.front().first +30 <= day)
        {
            month.pop();
        }

        while(!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }

        month.push(make_pair(day, ans+cost[2]));
        week.push(make_pair(day, ans+cost[1]));

        ans = min(ans+cost[0], min(month.front().second, week.front().second));
    }

    return ans;
}

int Trip(int n, vector<int> days, vector<int> cost)
{
    // vector<int> dp(n+1, -1);
    // return Memoization(n, days, cost, dp, 0);

    // return Tabulation(n, days, cost);

    return Space_opti(n,days,cost);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> days;
    vector<int> cost;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        days.push_back(t);
    }

    for(int i=0; i<=2; i++)
    {
        int t;
        cin>>t;
        cost.push_back(t);
    }

    cout<<Trip(n,days,cost)<<endl;

    return 0;
}