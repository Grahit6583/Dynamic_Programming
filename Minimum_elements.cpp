#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

int Memoization(vector<int> &num, int x, vector<int> &dp)
{
    if(x == 0)
    {
        return 0;
    }

    if( x < 0)
    {
        return INT_MAX;
    }

    if(dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++)
    {
        int ans = Memoization(num, x-num[i], dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1+ans);
        }
    }

    dp[x] = mini;

    return mini;
}

int Tabulation(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)
    {
        return -1;
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, -1);
    int ans = Memoization(num, x, dp);

    if(ans  == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }

    // return Tabulation(num, x);

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    int x;
    cin>>x;

    vector<int> num;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        num.push_back(t);
    }

    int ans = minimumElements(num, x);
    cout<<ans<<endl;

    return 0;

}