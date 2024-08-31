#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(vector<int> &num, int tar, vector<int> &dp)
{
    if(tar < 0)
    {
        return 0;
    }

    if(tar == 0)
    {
        return 1;
    }

    if(dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++)
    {
        ans = ans + Memoization(num, tar-num[i], dp);
    }

    dp[tar] = ans;

    return dp[tar];
}

int Tabulation(vector<int> &num, int tar)
{
    vector<int> dp(tar+1, 0);
    dp[0] = 1;

    for(int i=1; i<=tar; i++)
    {
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j] >= 0)
            {
                dp[i] = dp[i] + dp[i-num[j]];
            }
        }
    }

    return dp[tar];
}

int Combi_Sum(vector<int> &num, int tar)
{
    // vector<int> dp(tar+1, -1);
    // return Memoization(num, tar, dp);

    return Tabulation(num, tar);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,tar;
    cin>>n>>tar;

    vector<int> num;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        num.push_back(t);
    }

    cout<<Combi_Sum(num, tar)<<endl;

    return 0;
}