#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int longest_Subsequence(vector<int> &arr)
{
    int n = arr.size();

    if(n <= 2)
    {
        return n;
    }
    
    int ans = 0;
    unordered_map<int,int> dp[n+1];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            int diff = arr[i]-arr[j];
            int cnt = 1;

            if(dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }

            dp[i][diff] = 1+cnt;
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<int> dp;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;

        dp.push_back(t);
    }

    cout<<longest_Subsequence(dp);

    return 0;
}